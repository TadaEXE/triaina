#pragma once

#include <optional>
#include <span>
#include <string_view>

#include "ds/bus.hpp"
#include "ds/slice.hpp"
#include "ds/trivec.hpp"
#include "ds/width.hpp"
#include "resty.hpp"
// #include "runtime/fixpoint.hpp"
#include "runtime/ids.hpp"
// #include "runtime/registry.hpp"
// #include "runtime/source_loc.hpp"
// #include "runtime/signature.hpp"
// #include "runtime/symbol.hpp"

namespace rtm {

/// @brief Visitor-facing API for building and executing Triaina programs.
///
/// The AST interpreter calls into this API to create definitions and to
/// evaluate expressions, chains, sequential calls, and fixpoint calls.
class RuntimeAPI {
 public:
  virtual ~RuntimeAPI() = default;

  /// @brief Sets the active location used for subsequent diagnostics.
  virtual void set_source_loc(std::optional<SourceLoc> loc) = 0;

  /// @brief Produces a runtime error at the current source location.
  virtual res::vexpected fail(std::string_view msg) = 0;

  /// @brief Pushes a new lexical scope for name definitions.
  virtual ScopeId scope_push() = 0;

  /// @brief Pops a lexical scope created by scope_push.
  virtual void scope_pop(ScopeId scope) = 0;

  /// @brief Interns a string into a stable symbol id.
  virtual SymbolId sym(std::string_view name) = 0;

  /// @brief Resolves a symbol in the active environment.
  virtual std::optional<SymbolInfo> lookup(SymbolId name) const = 0;

  /// @brief Defines a gate name and rejects shadowing in active scopes.
  virtual res::vexpected define_gate(SymbolId name, GateId id) = 0;

  /// @brief Defines a function name and rejects shadowing in scopes.
  virtual res::vexpected define_func(SymbolId name, FuncId id) = 0;

  /// @brief Defines a lambda name and rejects shadowing in scopes.
  virtual res::vexpected define_lambda(SymbolId name, LambdaId id) = 0;

  /// @brief Defines a register name and rejects shadowing in scopes.
  virtual res::vexpected define_reg(SymbolId name, RegId id) = 0;

  /// @brief Defines a variable name and rejects shadowing in scopes.
  virtual res::vexpected define_var(SymbolId name, VarId id) = 0;

  /// @brief Builds a value from a literal string of '+', '0', '-'.
  virtual ds::TriVec value_from_literal(std::string_view trits) = 0;

  /// @brief Builds a ternary-encoded value from a decimal integer.
  virtual ds::TriVec value_from_decimal(int64_t n) = 0;

  /// @brief Builds a value from a codepoint using runtime encoding.
  virtual ds::TriVec value_from_char(uint32_t cp) = 0;

  /// @brief Slices a value using Triaina bracket slicing semantics.
  virtual res::expected<ds::TriVec> value_slice(const ds::TriVec& v,
                                                ds::Slice s) = 0;

  /// @brief Concatenates two values as the `%` operator does.
  virtual ds::TriVec value_concat(const ds::TriVec& a,
                                  const ds::TriVec& b) = 0;

  /// @brief Constructs a bus from values as a list literal does.
  virtual ds::Bus bus_make(std::span<const ds::TriVec> values) = 0;

  /// @brief Constructs a one-element bus from a single value.
  virtual ds::Bus bus_single(const ds::TriVec& v) = 0;

  /// @brief Safely reads the k-th element from the given bus.
  virtual res::expected<ds::TriVec> bus_get(const ds::Bus& b,
                                            uint32_t k) const = 0;

  /// @brief Creates a fixed-width register and binds it to a name.
  virtual res::expected<RegId> reg_create(SymbolId name,
                                          uint32_t width) = 0;

  /// @brief Creates a variable with fixed or dynamic declared width.
  virtual res::expected<VarId> var_create(SymbolId name, ds::Width w) = 0;

  /// @brief Reads a register value as seen in sequential execution.
  virtual res::expected<ds::TriVec> reg_read(RegId r) = 0;

  /// @brief Writes a register value as seen in sequential execution.
  virtual res::vexpected reg_write(RegId r, const ds::TriVec& v) = 0;

  /// @brief Reads a variable value as seen in sequential execution.
  virtual res::expected<ds::TriVec> var_read(VarId v) = 0;

  /// @brief Writes a variable value as seen in sequential execution.
  virtual res::vexpected var_write(VarId v, const ds::TriVec& value) = 0;

  /// @brief Produces a cell actual representing `&r` register binding.
  virtual CellActual reg_bind(RegId r) = 0;

  /// @brief Performs `*r` blocking read and samples on change.
  virtual res::expected<ds::TriVec> reg_blocking_read(RegId r) = 0;

  /// @brief Creates a gate definition object in the registry.
  virtual res::expected<GateId> gate_create(SymbolId name,
                                            uint32_t arity) = 0;

  /// @brief Adds one gate arm and enforces coverage constraints.
  virtual res::vexpected gate_add_arm(GateId id,
                                      const ds::GateArm& arm) = 0;

  /// @brief Finalizes a gate so it can be applied during execution.
  virtual res::vexpected gate_init(GateId id) = 0;

  /// @brief Applies a gate to a bus and returns the output bus.
  virtual res::expected<ds::Bus> gate_apply(GateId id,
                                            const ds::Bus& inputs)
      const = 0;

  /// @brief Creates a sequential function and stores its body callback.
  virtual res::expected<FuncId> func_create(SymbolId name,
                                            FuncSignature sig,
                                            Registry::SeqBodyFn body) = 0;

  /// @brief Creates a fixpoint function and stores its step callback.
  virtual res::expected<FuncId> func_create_fix(SymbolId name,
                                                FuncSignature sig,
                                                Registry::FixBodyFn body) = 0;

  /// @brief Creates a sequential lambda and stores its body callback.
  virtual res::expected<LambdaId> lambda_create(FuncSignature sig,
                                                Registry::SeqBodyFn body) = 0;

  /// @brief Creates a fixpoint lambda and stores its step callback.
  virtual res::expected<LambdaId> lambda_create_fix(FuncSignature sig,
                                                    Registry::FixBodyFn body) = 0;

  /// @brief Calls a function with an entry bus for chain evaluation.
  virtual res::expected<CallResult> call(FuncId f,
                                         std::span<const ds::TriVec> args,
                                         ds::Bus initial_bus) = 0;

  /// @brief Calls a lambda with an entry bus for chain evaluation.
  virtual res::expected<CallResult> call(LambdaId c,
                                         std::span<const ds::TriVec> args,
                                         ds::Bus initial_bus) = 0;

  /// @brief Sets fixpoint step limits for subsequent fixpoint runs.
  virtual void set_fixpoint_config(FixpointConfig cfg) = 0;

  /// @brief Begins fixpoint evaluation for a function with `/cells/`.
  virtual res::expected<FixpointEngine::Ctx> fix_begin(
      FuncId f,
      std::span<const ds::TriVec> args,
      std::span<const CellActual> overrides,
      ds::Bus initial_bus) = 0;

  /// @brief Begins fixpoint evaluation for a lambda with `/cells/`.
  virtual res::expected<FixpointEngine::Ctx> fix_begin(
      LambdaId c,
      std::span<const ds::TriVec> args,
      std::span<const CellActual> overrides,
      ds::Bus initial_bus) = 0;

  /// @brief Prepares a microstep by clearing staged writes.
  virtual void fix_step_begin(FixpointEngine::Ctx& ctx) = 0;

  /// @brief Commits staged writes and reports convergence for the step.
  virtual res::expected<bool> fix_step_end(FixpointEngine::Ctx& ctx) = 0;

  /// @brief Ends fixpoint evaluation and extracts return values.
  virtual res::expected<CallResult> fix_end(FixpointEngine::Ctx& ctx) = 0;

  /// @brief Reads a fixpoint state cell from the current snapshot.
  virtual res::expected<ds::TriVec> fix_cell_read(
      FixpointEngine::Ctx& ctx,
      SymbolId cell_name) = 0;

  /// @brief Stages a fixpoint state cell write for step commit.
  virtual res::vexpected fix_cell_stage_write(
      FixpointEngine::Ctx& ctx,
      SymbolId cell_name,
      const ds::TriVec& v) = 0;

  /// @brief Reads a locked register from the fixpoint snapshot.
  virtual res::expected<ds::TriVec> fix_reg_read_locked(
      FixpointEngine::Ctx& ctx,
      RegId r) = 0;

  /// @brief Stages a locked register write for step commit.
  virtual res::vexpected fix_reg_stage_write_locked(
      FixpointEngine::Ctx& ctx,
      RegId r,
      const ds::TriVec& v) = 0;
};

}  // namespace rtm

