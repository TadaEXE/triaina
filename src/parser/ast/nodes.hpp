#pragma once

#include <cstddef>
#include <cstdint>
#include <optional>
#include <string>
#include <variant>
#include <vector>
namespace ast {
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
static inline Trit char_to_trit(const char c, const Trit on_err = Trit::Zero) {
  switch (c) {
    case '+':
      return Trit::Plus;
    case '-':
      return Trit::Minus;
    case '0':
      return Trit::Zero;
    default:
      return on_err;
  }
}

enum class TritMatch : int8_t {
  Minus = -1,
  Zero = 0,
  Plus = 1,
  Wild = 2,
};
static inline TritMatch
char_to_trit_match(const char c, const TritMatch on_err = TritMatch::Wild) {
  switch (c) {
    case '+':
      return TritMatch::Plus;
    case '-':
      return TritMatch::Minus;
    case '0':
      return TritMatch::Zero;
    case '_':
      return TritMatch::Wild;
    default:
      return on_err;
  }
}
struct CharLiteral {
  Span sp;
  char c;
};
struct StringLiteral {
  Span sp;
  std::string str;
};
struct DecimalLiteral {
  Span sp;
  int64_t dec;
};
struct TritLiteral {
  Span sp;
  Trit trit;
};

/* Expression */
struct Expression;
struct Bus {
  Span sp;
  std::vector<Expression> expression_list;
};
struct Qualified {
  Span sp;
  std::string block;
  std::string property;
};
struct Expression {
  Span sp;
  std::variant<std::string, Qualified, Bus, TritLiteral> primary;
};
/* Conneciont */
struct Chain {
  Span sp;
  std::vector<Expression> elements;
};
struct Bench {
  Span sp;
  StringLiteral name;
  std::vector<Chain> con_list;
};
/* Block */
struct Inst {
  Span sp;
  std::string type;
  std::string identifier;
};
struct With {
  Span sp;
  std::vector<Inst> inst_list;
};

enum class PortType : uint8_t {
  In,
  Out,
};
struct Port {
  Span sp;
  PortType type;
  std::string identifier;
};
struct Block {
  Span sp;
  std::vector<Port> port_list;
  std::string identifier;
  std::optional<With> opt_with;
  std::vector<Chain> chain_list;
};
/* Gate */
struct GateArm {
  Span sp;
  std::vector<TritMatch> trit_match_list;
  TritLiteral result;
};
struct Gate {
  Span sp;
  DecimalLiteral width;
  std::string identifier;
  std::vector<GateArm> gate_arm_list;
};
/* IGO */
struct Input {
  Span sp;
  CharLiteral trigger;
  std::string identifier;
};
struct Output {
  Span sp;
  StringLiteral name;
  std::string identifier;
};
struct Clock {
  Span sp;
  DecimalLiteral cycle_ms;
  DecimalLiteral duty_cycle;
  std::string identifier;
};
/* Structure */
struct Item {
  Span sp;
  std::variant<Input, Output, Clock, Gate, Block, Bench> inner;
};
struct Program {
  Span sp;
  std::vector<Item> item_list;
};
} // namespace ast
