// Rules:
// 1. Group pending evaluator updates by evaluator and convert into combined evaluator updates
// 2. If evaluator.last_update < step_count: Do update; Else enqueue for next step
// 3. Execute all pending wire updates
// 4. If pending evaluator updates exist: go to 1.
// 5. step_count += 1
// 6. wait for next step signal (if enabled)
// 7. go to 1.
