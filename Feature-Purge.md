Because of reasons, all features which are not described in this file are considered PURGED!
I will remove everything bit by bit, while actually implementing what's left.

node: define a structural component which has named inputs and outputs with body consisting of connections
    when an input changes, the body is invoked
    
gate: define a gate with N inputs and 1 output
    a gate is a node where the inputs are called in0 to inN and the output is called out

input: a special kind of node which is connected to the outside world (e.g. via keypress)
    subtypes like clock and constant are also possible

output: a special kind of node which is connected to the outside world (e.g. via terminal print)

connections: a connection always goes from an output to an input
    when the output (start) changes, the change is porpagated to the input (end)
    it can have the three sates: +, 0, -
    there is no "undefined" state as "undefined" is just 0


syntax:

```js
// Input:
input('a') a_btn; // Listen to stdin for the sequence 'a_' where '_' is +, 0 or -

// Generators:
clock(`50`, `50`) sys_clk; // 50 ms clock with 50% duty-cycle; P0 => -; P1 => +;

// Output:
output("Node_Output") node_out; // Will output the name followed by the new value on every change

gate(`2`) or { // max
    (-, -) >> -;
    (-, 0) >> 0;
    (0, -) >> 0;
    (0, 0) >> 0;
    (_, _) >> +;
}

gate(`1`) not { // neg
    (+) >> -;
    (0) >> 0;
    (-) >> +;
}

block(in in1, in in2, out out1)    // ports
foo
with(or or1, or or2) { // not inliable nodes
    in1 >> inv >> or1.i0; // inlined gate
    in2 >> or2.i1;

    or1 >> or2.i0;
    or2 >> or1.i1;
    // might add unpacking like: |or1.o, or2.o| >> |or2.i0, or1.i1|;

    |or1.o, or2.o| >> or >> out1; // custom bus into inlined gate to output
}

bench("mybench") { // bench is started by giving it to the runtime as an argument
  | a_btn, sys_clk | >> foo >> node_out;
}
```
