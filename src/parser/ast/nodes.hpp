#pragma once

#include <cstddef>
#include <cstdint>
#include <optional>
#include <string>
#include <variant>
#include <vector>

namespace ast {

template <typename T>
struct NodeId {
  size_t id;

  friend bool operator==(const NodeId& a, const NodeId& b) {
    return a.id == b.id;
  }
};

struct Pos {
  size_t file_id;
  uint32_t line;
  uint32_t col;
};

struct Span {
  Pos begin;
  Pos end;
};

enum class Trit : int8_t {
  Minus = -1,
  Zero = 0,
  Plus = 1,
};

enum class TritMatch : int8_t {
  Minus = -1,
  Zero = 0,
  Plus = 1,
  Wild = 2,
};

enum class SliceDir : uint8_t { Forward, Backward };

struct RNum {
  int64_t v;
  Span sp;
};

struct SizeSpec {
  bool is_dynamic;
  size_t fixed;
  Span sp;
};

struct Word {
  std::string text;
  Span sp;
};

struct Literal {
  std::string trits;
  Span sp;
};

struct Decimal {
  RNum value;
  Span sp;
};

struct CharLit {
  std::string chars;
  Span sp;
};

struct BusRef {
  size_t idx;
  Span sp;
};

struct Slice {
  std::optional<int64_t> lo;
  std::optional<int64_t> hi;
  SliceDir dir;
  Span sp;
};

struct Expr;
struct Chain;
struct Scope;
struct Program;

struct AtomParen {
  NodeId<Expr> expr;
  Span sp;
};

struct List {
  std::vector<NodeId<Expr>> elems;
  Span sp;
};

struct CellDeclReg {
  Word reg;
  SizeSpec width;
  Span sp;
};

struct CellDeclCell {
  Word name;
  SizeSpec width;
  std::optional<NodeId<Expr>> def;
  Span sp;
};

using CellDecl = std::variant<CellDeclReg, CellDeclCell>;

struct CellSet {
  std::vector<CellDecl> decls;
  Span sp;
};

struct RetNamed {
  Word name;
  SizeSpec width;
  Span sp;
};

struct RetExpr {
  NodeId<Expr> expr;
  Span sp;
};

using RetItem = std::variant<RetNamed, RetExpr>;

struct Arg;
struct Lambda {
  std::vector<Arg> args;
  std::optional<CellSet> cells;
  std::vector<RetItem> rets;
  NodeId<Scope> body;
  Span sp;
};

using Atom = std::variant<AtomParen, List, Lambda, BusRef, Word, CharLit,
                          Decimal, Literal>;

enum class MemOpKind : uint8_t {
  None,
  Direct,
  WaitForChange,
};

struct MemOp {
  MemOpKind op;
  Atom atom;
  Span sp;
};

struct Braccess {
  MemOp base;
  std::optional<Slice> slice;
  Span sp;
};

struct Cat {
  Braccess left;
  std::optional<Braccess> right;
  Span sp;
};

struct Expr {
  Cat cat;
  Span sp;
};

// struct CellActual {
//   enum class Kind : uint8_t {
//     RegRef,
//     Expr,
//   };
//
//   Kind kind;
//   Word reg;
//   NodeId<Expr> expr;
//   Span sp;
// };

struct CellOverride {
  std::vector<NodeId<Expr>> actuals;
  Span sp;
};

struct ChainHop {
  std::optional<CellOverride> ovrd;
  NodeId<Expr> expr;
  Span sp;
};

struct Chain {
  NodeId<Expr> start;
  std::vector<ChainHop> hops;
  Span sp;
};

struct RegDec {
  Word name;
  size_t width;
  Span sp;
};

struct VarDec {
  Word name;
  SizeSpec width;
  Span sp;
};

struct Statement {
  std::variant<RegDec, VarDec, Chain> inner;
  Span sp;
};

struct CGuard {
  Trit a;
  std::optional<Trit> b;
  Span sp;
};

struct IfArm {
  enum class Kind : uint8_t {
    Elif,
    Else,
  };

  Kind kind;
  CGuard guard;
  std::optional<NodeId<Expr>> cond;
  NodeId<Scope> scope;
  Span sp;
};

struct IfElse {
  CGuard guard;
  NodeId<Expr> cond;
  NodeId<Scope> then_scope;
  std::optional<std::vector<IfArm>> arms;
  Span sp;
};

struct WhileLoop {
  CGuard guard;
  NodeId<Expr> cond;
  NodeId<Scope> scope;
  Span sp;
};

struct GateArm {
  std::vector<TritMatch> pattern;
  Trit result;
  Span sp;
};

struct GateDef {
  size_t arity;
  Word name;
  std::vector<GateArm> arms;
  Span sp;
};

struct Arg {
  Word name;
  SizeSpec width;
  std::optional<NodeId<Expr>> def;
  Span sp;
};

struct FuncDef {
  Word name;
  std::vector<Arg> args;
  std::optional<CellSet> cells;
  std::vector<RetItem> rets;
  NodeId<Scope> body;
  Span sp;
};

struct SourceSegment;

struct Scope {
  std::vector<NodeId<SourceSegment>> segments;
  Span sp;
};

struct SourceSegment {
  std::variant<Scope, GateDef, FuncDef, IfElse, WhileLoop, Statement> inner;
  Span sp;
};

struct Program {
  std::vector<NodeId<SourceSegment>> segments;
  Span sp;
};

}  // namespace ast
