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

