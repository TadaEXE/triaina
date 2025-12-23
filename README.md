# Triaina

**Triaina** is a complete programming language for balanced ternary logic, without the slightest hint of arithmetic anywhere to be found!

## WTF is balanced ternary logic?

Ternary logic is the same as binary logic, but using a base 3 system. Balanced refers to the representation of the values. Binary is easy, we have 0 and 1, but with ternary we can go two main ways: unbalanced = {0, 1, 2} and balanced = {-1, 0, +1}. I choose to go only with the balanced system, because of purely subjective philosophical preferences.
This opens up an insane amount of possibilities!(and ambiguity which I'll dive into later) With the binary system you have 2^2 = 4 fields in the truth table and there for 2^4 = 16 possible combinations, meaning 16 different logic gates. The ternary system however... oh boy. Mind that we limit this to two inputs, which results in 3^2 = 9 fields for the truth table and 3^9 = 19,683 possible logic gates.

### Trits, Tibbles and Tryts

Eventhough Triaina works with trit vectors of arbitrary lengths, I will quickly go over the termenology we have when working with base 3 values.

| Name | Length | Base 2 equivalent |
| ---- | ------ | ----------------- |
| Trit | 3^0 = 1 | Bit (2^0 = 1) |
| Tibble | 3^2 = 6 | Nibble (2^2 = 4) |
| Tryte | 3^3 = 9 | Byte (2^3 = 8) |

## Syntax

### Variables

To define a variable, the name followed by the length of the trit vector separated by the value must be given. The equal sign is used to assign a value to the variable. It's not possible to simply declare a variable like you would do in C.

```rust
my_var:3 = +-0;
my_extended:3 = -; // '-' will be extended to '-00'
```

It's possible to have the length of a variable deduced by writing a questionmark as the length. This is only possible, if the length can be deduced during assignment.

```rust
foo:? = ++; // foo has length 2
bar:? = cat(++, --); // bar has length 4
```

### The gate keyword

The `gate` keyword allows to define a logicgate and it's truth table. This basically generates an atomic function which executes your gate logic trit-wise. The gate can then be used using normal function syntax you know from other languages.
If a gate function is called with operands of different sizes, the smaller ones will be automatically 0-extended to the length of the biggest one.

```rust
gate right(2) { // the gate called right has takes two inputs
    (?, +) => +;
    (-, +) => +; // error because ? is greedy, so the line above already defined this case
    (?, -) => -;
    (?, 0) => 0;
    (?, ?) => 0; // not an error, but unnecessary because all cases are already defined
}
```

```rust
gate and3(3) { // and3 takes 3 parameters
    (+, +, +) => +;
    (?, ?, ?) => -;
}
```

Without gate definitions, the language is basically useless. But fear not! The included standard library already defines basic gates so you don't have to write everything yourself.

### Control structures

Control structures in Triaina work a bit differently then what you might know from other languages.
You've got your normal `if`, `else` and `while` but they can be followed by a `Control guard`. A control guard sets the expectation for the result of the logical expression. The expectation has to be one of the three states +, 0 or -. It's also possible two expect two different states, which means that the expression can evaluate to either of the two states. This will become more clear with the examples from the following sections. 

#### If else

```rust
// No control guard:
if and(foo, bar)[0] { ... } // same as if<+> and(foo, bar)[0]
else { ... }                // matches all other cases, in this case 0 and -

// One control guard:
if<0> or(foo, bar)[0] { ... }
else<-> { ... }
else<+> { ... }
else<0> { ... } // error: case is already handled

// Two control guards:
if<+,-> and(foo, bar)[0] { ... } // and(foo, bar)[0] can be + or -
else { ... }                     // same as else<0>
```

#### While loops

`while` is the only type of conditional loop Triaina offers. It can also be combined with a control guard.

```rust
while redmax(or(foo, bar)) { ... } // 
while<0> redmax(or(foo, bar)) { ... } // 
```

### For

`for` is used to look at each individual trit in a trit-vector. It's designed to allow trit-wise operations with context, as gates have none between individual trits of the operands.

### Match

`match` is used to preform pattern matching over the given trit-vector

```rust
a:1 := -;
match a {
    + => { a = not(a); }
    0 => {}
    - => { a = +; }
}

b:4 := ++-0;
match b {
    +_ => {} // Match all starting with +
    _-? => {} // Match all with - in the second last position
    +-_ => {} // Match all starting with +-
    +--+ => {} // Match exactly +--+
    _ => {} // Match all

    -_0 => {} // Error: Unsupported until I feel like implementing this
}
```

## Some code examples from the standard library

```rust
fn same:1(lhs:?, rhs:?) {
    ret redmin(eq(lhs, rhs));
}

fn redmax:1(val:?) {
    tmp:1 = -;
    for x : val {
        match x {
            + => { ret +; }
            0 => { tmp = 0; }
            - => { tmp  = or(tmp, -); }
        }
    } 
    ret tmp;
}

fn redmin:1(val:?) {
    tmp:1 = +;
    for x, val {
        if<-> x { ret -; }
        else<0> x { tmp = 0; }
        else<+> x { tmp = and(tmp, +); }
    }
    ret tmp;
}

fn shl:?(op:?n) {
    ret cat(op, 0)[1:];
}

fn shr:?(op:?n) {
    ret cat(0, op)[:n];
}

fn cat:?(lhs:?l, rhs:?r) {
  lhs = lhs[l:0]; // flip trits
  res:? = 0;

  // put flipped lhs in res and flip the whole thing
  // -> lhs is now in front
  tmp:?n = sepo(res, lhs);
  res = tmp[n:0];
  res = sepo(res, rhs);
  ret res;
}

// Seeks to have a polarity, if possible
gate sepo(2) {
  (+, 0) => +;
  (-, 0) => -;
  (0, +) => +;
  (0, -) => -;
  (?, ?) => 0;
}
```

