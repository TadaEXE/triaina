#pragma once
/*
* GIVE ME SOME MACROS AND CALL ME THE PUNISHER, DADDY UUUUUUUUUUUUUUYYYYYYYYYYYYYYYAAAAAAAAAA
*/

#include <cstddef>
#include <memory>
#include <string>
#include <string_view>
#include <unordered_map>
#include <utility>
#include <variant>
#include <vector>

struct Node;
using NodePtr = std::unique_ptr<Node>;
using AttrVal = std::variant<std::string, long>;

namespace {
// clang-format off
#define NodeTypes(__x)\
  __x(Error)\
  __x(ErrorStatement)\
  __x(ErrorSegment)\
  __x(Program)\
  __x(SourceSegment)\
  __x(Scope)\
  __x(GateDef)\
  __x(GateBody)\
  __x(GateArm)\
  __x(FuncDef)\
  __x(Lambda)\
  __x(ArgList)\
  __x(Arg)\
  __x(RetList)\
  __x(RetItem)\
  __x(CellSet)\
  __x(CellDecl)\
  __x(CellOverride)\
  __x(CellActual)\
  __x(SizeSpec)\
  __x(IfElse)\
  __x(IfArm)\
  __x(WhileLoop)\
  __x(CGuard)\
  __x(Statement)\
  __x(RegDec)\
  __x(VarDec)\
  __x(Chain)\
  __x(ChainHop)\
  __x(Expr)\
  __x(Cat)\
  __x(Braccess)\
  __x(MemOp)\
  __x(Atom)\
  __x(BusRef)\
  __x(List)\
  __x(Decimal)\
  __x(Char)\
  __x(TritMatch)\
  __x(Literal)\
  __x(Trit)\
  __x(RNum)\
  __x(Word)\
  __x(Slice)
// clang-format on
}  // namespace

enum class NodeType : size_t {
#define __x(name) name,
  NodeTypes(__x)
#undef __x
      _Count
};

template <class V>
concept Visitor = requires(V& v, Node& n) {
#define __x(name) v.template visit<NodeType::name>(n);
  NodeTypes(__x)
#undef __x
};

struct Node {
  NodeType kind;
  std::unordered_map<std::string, AttrVal> attrs;
  std::vector<NodePtr> children;

  Node(const Node&) = delete;
  Node& operator=(const Node&) = delete;

  Node(Node&&) = default;
  Node& operator=(Node&&) = default;

  explicit Node(NodeType k) : kind(std::move(k)) {}

  static NodePtr make(NodeType kind) { return std::make_unique<Node>(std::move(kind)); }

  template <Visitor V>
  void accept(V& v) {
    // Fuck you future me! This is readable.
    // Just don't touch it...
    switch (kind) {
#define __x(name)                            \
  case NodeType::name:                       \
    v.template visit<NodeType::name>(*this); \
    break;
      NodeTypes(__x)
#undef __x
          default : break;
    };
  }

  template <class V>
  static inline void dfs_travers(Node& n, V& v) {
    n.accept(v);
    for (const auto& c : n.children) {
      Node::dfs_travers(*c, v);
    }
  }

  template <class T>
  Node& set(std::string key, T&& v) {
    attrs.emplace(std::move(key), AttrVal(std::forward<T>(v)));
    return *this;
  }

  Node& add(NodePtr c) {
    children.push_back(std::move(c));
    return *this;
  }

  Node& add_all(std::vector<NodePtr> cs) {
    for (auto& c : cs)
      children.push_back(std::move(c));
    return *this;
  }
};

namespace {
static constexpr std::string_view names[] = {
#define __x(name) #name,
    NodeTypes(__x)
#undef __x
};
}  // namespace

namespace std {
static constexpr std::string_view to_string(NodeType t) {
  return names[static_cast<size_t>(t)];
}
}  // namespace std
