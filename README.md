# Triaina

Triaina is a declarative block-diagram language for balanced ternary circuits.

## Build

```bash
cmake -S . -B build
cmake --build build
```

## Run

```bash
```

## Tests

```bash
cmake -S . -B build -DBUILD_TESTING=ON
cmake --build build --target triaina_tests
ctest --test-dir build --output-on-failure
```

## Triaina — Language Specification

Triaina is a declarative functional block-diagram language for balanced ternary circuits. Gates define logic, blocks compose circuits, and connections carry signals between ports. The compiler fixes circuit topology and widths; the runtime evaluates affected computational nodes in discrete ticks. Feedback and registers can retain state across ticks.

### 1. Trits, vectors, and widths

A **TritVector** has positive width. Each output-port trit has one of six states:

| State | Meaning |
| --- | --- |
| `-`, `0`, `+` | Known balanced ternary values |
| `u` | Unknown |
| `e` | Fault |
| `z` | Released driver (high impedance) |

Adjacent trit symbols form a vector literal, such as `+u0z`. A scalar is a width-one vector. `0` is actively driven.

**Output ports** contribute six-state vectors to connections. **Connections** resolve these contributions to five-state vectors (`-`, `0`, `+`, `u`, `e`). **Input ports** read resolved connection values. Each trit position resolves independently; see §3. Block boundaries forward connections and preserve their attached drivers.

Ports specify fixed widths (`:4`), inferred widths (`:?`), or shared positive width parameters (`:?n`). Each block instance specializes its parameters independently. Literal widths, port declarations, register initializers, and named-connection annotations constrain width inference. An unresolved width is a compilation error. A shorter vector zero-extends on the left when connected to a wider destination; each added trit is `0`. Longer vectors require explicit selection.

`a % b` concatenates vectors in written order. The rightmost trit has index `0`. `v[i]` selects one trit; `v[lo:hi]` selects a nonempty half-open range, with result index `0` corresponding to `v[lo]`. Omitted bounds default to `0` and the width. `v[:-1]` reverses a vector.

Compile-time numeric expressions support integer literals, width parameters, parentheses, unary `+`/`-`, and binary `+ - * /`, evaluated as exact rationals. Widths, indices, and tick counts resolve to valid integers. Computed widths use `:(n + 1)`. Numeric and signal contexts determine whether a token such as `0` is an integer or a trit. Signal values do not determine widths or topology.

Identifiers follow `[A-Za-z_][A-Za-z_0-9]*`. Literal and identifier recognition follows longest-token rules; `u`, `e`, and `z` are reserved trit symbols.

### 2. Gates

A `gate(N)` defines a truth table with `N` inputs, where `N` is a positive compile-time integer. Each pattern position contains `-`, `0`, `+`, or `_`, where `_` matches any known logical trit. Rows apply in source order: wildcard rows assign still-unassigned combinations; explicit rows must identify an unassigned combination; every known input combination must be covered. An exhausted wildcard row is permitted.

A row may emit `-`, `0`, `+`, or `z`. Each gate occurrence in a chain creates one stateless computational node.

```tri
gate(1) rot {
  (-) >> 0;
  (0) >> +;
  (+) >> -;
}

gate(2) hs {
  (+, +) >> -;
  (-, -) >> +;
  (+, -) >> 0;
  (-, +) >> 0;
  (+, 0) >> +;
  (-, 0) >> -;
  (0, +) >> +;
  (0, -) >> -;
  (_, _) >> 0;
}

gate(3) carry {
  (+, +, +) >> +;
  (+, +, 0) >> +;
  (+, 0, +) >> +;
  (0, +, +) >> +;
  (-, -, -) >> -;
  (-, -, 0) >> -;
  (-, 0, -) >> -;
  (0, -, -) >> -;
  (_, _, _) >> 0;
}

gate(1) pull_low {
  (+) >> 0;
  (_) >> z;
}
```

Gates operate independently at each trit position, zero-extending shorter inputs to the greatest input width. Each input reads its connection's resolved five-state value. An `e` input yields `e`. For `u`, the gate evaluates all independent substitutions from `-`, `0`, `+`; a unanimous result is emitted, including `z`, and otherwise the result is `u`. An unknown trit does not correlate with another unknown trit.

Gates are invoked as stages of `>>` chains, with one computational tick per gate stage. Nested gate-call syntax is not part of the language.

### 3. Chains, connections, and resolution

A **chain** is an ordered, flat bundle of vectors. `>>` connects corresponding members to ports or into a component's ordered input interface. A vector is a one-member chain. Component ports use declaration order, and chain arity must match the target interface.

```tri
block(in a:1, in b:1, out result:1)
combine_pair {
  |a, b| >> hs >> result;
}

block(in a:1, in b:1, out result:2)
join_pair {
  a % b >> result;
}
```

Instance ports use `instance.in.N` and `instance.out.N`, numbered from zero; `instance.out` abbreviates the sole output. Every instantiated input port and declared block output is attached to a connection. An input port belongs to exactly one connection. Each connection may have multiple input and output endpoints. Wiring statements sharing an endpoint join the participating connections. Component input and output interfaces remain separate through computation.

#### Inline adapters

An adapter builds a new chain from members of the incoming chain. `$n` selects incoming member `n`, starting at zero. Entries may contain literals, `$n`, named connections and their members, or slices of these.

```tri
block(in a:1, in b:1, in c:1, out x:1, out y:1)
adapter_demo {
  |a, b, c| >> @signals:(1, 1, 1);
  @signals >> |$2, $0| >> hs >> x;
  @signals >> |@signals.1, $0| >> hs >> y;
}
```

Adapters select, reorder, duplicate, omit, or insert members through static wiring. They preserve driver identity, release, and provenance; duplicating a member shares its producer. Adapters introduce no computational tick.

#### Named connections

`>> @name` labels the current chain. The name is available throughout its enclosing scope, including in earlier statements. `@name` references the whole chain, `@name.0` its first member, and `@name.0[2]` trit index `2` of that member. Names have one declaration and arbitrary references.

```tri
block(in a:1, in b:1, out x:1, out y:1)
sharing_demo {
  a >> rot >> @shifted >> x;
  |@shifted.0, b| >> hs >> y;
}
```

Annotations fix the widths of named chains: `@single:4` describes one width-four member; `@bus:(1, 4, 2)` describes three members. Width parameters and numeric width expressions are valid in annotations.

```tri
block(in value:?n, out result:?n)
forward {
  value >> @signal:n >> result;
}
```

#### Trit-wise connection resolution

Each connection has a statically determined width. Attached output ports contribute vectors of that width, with any required left zero-extension performed before resolution. **For each trit position independently**, the connection resolves its drivers as follows:

1. Any `e` contribution or conflicting known active contributions yield `e`.
2. Otherwise, any `u` contribution yields `u`.
3. Otherwise, the agreeing known active contributions yield their common value.
4. A connection whose contributions are all `z`, or which has no output contributors, yields `u`.

A released `z` contributes no active drive. Multiple drivers are structurally valid; conflicts depend on runtime values. Contention diagnostics identify the drivers and affected trit positions. Resolution is part of connection propagation and adds no computational node or tick.

```text
Driver A:  +0-z
Driver B:  z0+-
Connection: +0e-
```

A multi-driver circuit uses ordinary shared wiring:

```tri
block(in enable_a:1, in enable_b:1, out bus:1)
shared_pull_low {
  enable_a >> pull_low >> bus;
  enable_b >> pull_low >> bus;
}
```

Both `pull_low` outputs contribute to the same connection. It resolves to `0` when either gate pulls low and to `u` when both release it.

### 4. Blocks and feedback

A block defines reusable ports and a network of connections. `with(Type name, ...)` declares named instances of blocks or registers. Gates appear directly in chains. An anonymous block occurrence creates a new instance; references to a named instance share it. Definitions cannot instantiate themselves recursively.

```tri
block(in a:1, in b:1, in cin:1, out sum:1, out cout:1)
full_adder {
  |a, b| >> hs >> @ab;
  |@ab.0, cin| >> hs >> sum;
  |a, b, cin| >> carry >> cout;
}
```

The compiler classifies flattened block graphs:

| Class | Structure | Use |
| --- | --- | --- |
| Combinational | Acyclic, with no registers | Inline stages, named instances, table tests |
| Feedback | Contains a cycle through computational nodes | Named instances, sequential tests |
| Clocked | Contains a register transitively | Named instances, sequential tests |

A block may be both clocked and feedback-containing. Register outputs break combinational dependency paths. Each instance has its own output-port state; named references share the same instance.

Feedback connections preserve previous resolved values between ticks. For example, a gate can store a known value through self-feedback:

```tri
gate(2) latch_logic {
  (+, _) >> +;
  (-, _) >> -;
  (0, -) >> -;
  (0, 0) >> 0;
  (0, +) >> +;
}

block(in s:1, out q:1)
latch {
  |s, q| >> latch_logic >> q;
}
```

Driving `s` to `+` or `-` sets `q`; driving `s` to `0` holds its known value. From an unknown initial `q`, the latch remains unknown until a known set input arrives. Cyclic networks are valid and can continue changing on successive ticks.

### 5. Tick scheduler and registers

**One tick is one scheduler step.** The compiled graph contains gate and register nodes connected by transparent wiring. A tick evaluates affected nodes once and commits their outputs simultaneously. Blocks expand into their component nodes. Wiring, concatenation, slicing, adapters, block port forwarding, and connection resolution add no computational tick.

The scheduler maintains deduplicated **current** and **next** node queues. Tick `k` proceeds:

1. Apply input events and clock transitions assigned to `k`, resolve affected connections, and enqueue consumers affected by changed input values.
2. Evaluate each node in the current queue once against the same post-source connection snapshot. Registers with rising clock edges sample their data in this phase.
3. Commit computed output-port values simultaneously, resolve affected connections trit-wise, and enqueue consumers for tick `k + 1` when their observed input values change.
4. Emit post-tick output observations and advance the next tick index.

Only changes to **resolved five-state input values** schedule consumers. An output changing between `z` and another value need not schedule a consumer if the shared connection's resolved value stays the same. Provenance-only changes likewise do not schedule computation. Identical tick-indexed inputs yield identical results regardless of node evaluation order.

Initialization is the theoretical tick **`-1`**. Input endpoints use declared initial values (default `0`), clocks start at `-`, registers use their initializers, literals supply constant drivers, and gate outputs start as `u`. Connections resolve their initial contributions. Every gate enters the first evaluation queue. The host may observe the tick-`-1` snapshot; tick `0` performs the first evaluation. Known values propagate through successive gate stages over successive ticks.

An empty queue remains idle until another source event; cyclic circuits may continue to schedule work indefinitely.

#### Clocks and registers

`clock(50, 50) sys_clk;` defines a period of 50 ticks and a 50% duty cycle. Let `P` be the period and `D` the duty percentage. High and low phase lengths `H = P × D / 100` and `L = P − H` are positive integers. The first rising edge occurs at tick `L`, the first falling edge at tick `P`, and subsequent edges repeat each period.

`register(initial)` has data input `instance.in.0`, clock input `instance.in.1`, and output `instance.out`. Its initializer fixes its data width. A rising clock edge from `-` to `+` samples the pre-commit resolved data value during that tick; all triggered registers commit simultaneously. The register retains its output between edges. Its initialized output may be `z`, and its input reads resolved five-state values.

A register clock input must have one identifiable clock-generator origin, forwarded through transparent connections, adapters, and block ports. A clock net with multiple output contributors or computational transformations is ineligible.

```tri
gate(2) counter_logic {
  (-, _) >> 0;
  (0, -) >> -;
  (0, 0) >> 0;
  (0, +) >> +;
  (+, -) >> 0;
  (+, 0) >> +;
  (+, +) >> -;
}

block(in t:1, in clk:1, out q:1)
counter
with(register(0) state) {
  |t, state.out| >> counter_logic >> state.in.0;
  clk >> state.in.1;
  state.out >> q;
}
```

### 6. Benches, I/O, and runtime control

A **bench** is an execution entrypoint. It declares its input, output, and clock endpoints locally and wires them to a network. Endpoints are independent for each bench run.

```tri
bench("count") with(counter ff) {
  input('t') t_key;
  clock(50, 50) sys_clk;
  output("Q") q_out;

  t_key >> ff.in.0;
  sys_clk >> ff.in.1;
  ff.out >> q_out;
}
```

`input('key') name;` defines a width-one source initialized to `0`. `input('key', initial) name;` defines a source initialized to the supplied TritVector, which fixes its width. Inputs can emit `z`. Keyboard records contain the key followed by exactly the source width's trit symbols and a newline, such as `t+`. Malformed records produce diagnostics without changing the input. Output endpoints infer their width and observe resolved connection values.

`changes` output mode emits the tick-`-1` snapshot and subsequent value changes; `every_step` emits the tick-`-1` snapshot and a record after every tick. Records include the completed tick index, output name and value, and a deterministic ordering for simultaneous records. Output order follows declaration order. When multiple events target one input on a tick, the last event in source-record order wins.

The runtime API exposes single-tick advancement, advancement by a specified number of ticks, input injection, inspection of declared outputs, and diagnostic retrieval. Hosts may subscribe to output changes, start and pause paced execution, and inspect the completed tick index. An input arriving during a tick is assigned to a later tick boundary. Recorded tick-indexed inputs support deterministic replay.

The host controls pacing in wall-clock time: a requested interval sets the minimum target between tick starts. Every tick completes fully, including when execution exceeds the requested interval. A minimal interactive terminal host provides watched outputs, fault diagnostics, input control, and step/advance commands. A visual editor can use the same runtime API.

### 7. Namespaces and imports

Declarations may occupy the global namespace or explicit namespaces. Namespace syntax and lookup use C++-style qualification: `namespace logic { ... }`, nested `namespace outer::inner { ... }`, `logic::name`, and absolute `::logic::name`. Namespaces can be reopened. Unqualified lookup checks the current namespace and enclosing namespaces.

```tri
namespace logic {
  gate(1) neg {
    (-) >> +;
    (0) >> 0;
    (+) >> -;
  }
}

namespace circuits::demo {
  block(in value:1, out result:1) invert {
    value >> ::logic::neg >> result;
  }
}
```

`import "name.tri";` makes declarations from another file available within their namespaces. Imports are acyclic, and names are not re-exported. Duplicate qualified definitions and ambiguous references are diagnostics. Bench and test entrypoints are discoverable throughout the import closure; they are selected by the host or test runner, rather than instantiated as components.

### 8. Tests

**Table tests** construct a fresh instance of a combinational block for each input row, advance until its queue empties, and compare final outputs:

```tri
test("full_adder table") full_adder {
  (|+, 0, -|) >> (|0, 0|);
  (|+, +, +|) >> (|0, +|);
  (|-, -, -|) >> (|0, -|);
  (|+, +, 0|) >> (|-, +|);
}
```

**Sequential tests** run through an inclusive final tick. Their `script` entries create local input sources and assign values on numbered ticks; local clock and output declarations behave like bench endpoints. `expect` lists post-tick output changes and excludes the tick-`-1` snapshot.

```tri
test("counter steps") until 100 with(counter ff) {
  clock(50, 50) sys_clk;
  output("Q") q_out;
  script {
    0:  t 0;
    20: t +;
    45: t 0;
  }
  t >> ff.in.0;
  sys_clk >> ff.in.1;
  ff.out >> q_out;
  expect {
    25: Q +;
  }
}
```

Expectations compare emitted changes under `changes` mode. Mismatch diagnostics identify the endpoint, tick, expected value, and actual value. Test tools may capture a trace and insert the resulting expectations. Compilation-failure tests are an external runner convention.

### 9. Diagnostics and tooling

Fault `e` carries diagnostic origins, including the source, tick, and reason. Connection contention records its contributing output ports and affected trit indices. Node outputs retain provenance from their most recent evaluation; connection diagnostics reflect their current drivers. Provenance-only changes do not schedule nodes or change value-based output emissions.

Text and visual editors operate on an authored semantic graph containing definitions, instances, hierarchy, connections, port orders, adapters, widths, and endpoints. Layout data occupies a separate sidecar, whose format can be designed with the visual editor. The compiler produces an executable graph with concrete node identities, persistent port states, resolved connections, and source mappings. Graph transformations preserve tick-observable computational stages and authored sharing.

Conformance tests cover gate truth-table coverage and unknown lifting (including unanimous `z`); width inference; chain routing and fan-out; trit-wise multi-driver resolution; feedback; deterministic queue scheduling; clock edges and register sampling; tick-`-1` initialization; bench-local endpoints; sequential and table tests; namespaces; and runtime observation and diagnostics.

Reserved keywords: `gate`, `block`, `with`, `namespace`, `in`, `out`, `register`, `clock`, `input`, `output`, `bench`, `test`, `script`, `expect`, `until`, `import`. `@name` and `$n` are connection syntax.
