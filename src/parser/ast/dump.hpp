/* AI-Generated */
#pragma once

#include <ostream>
#include <string>
#include <variant>
#include <vector>

#include "parser/ast/nodes.hpp"
namespace ast {
class Dumper {
 public:
  explicit Dumper(std::ostream& os) : os_(os) {}
  void set_show_spans(bool v) { show_spans_ = v; }
  void dump(const Program& p) {
    root(hdr("Program", p.sp));

    for (size_t i = 0; i < p.item_list.size(); ++i) {
      branch("item[" + std::to_string(i) + "]", i + 1 == p.item_list.size(),
             [&] { dump(p.item_list[i]); });
    }
  }

 private:
  std::ostream& os_;
  bool show_spans_{false};
  std::vector<bool> last_;
  /* ---------- formatting ---------- */

  void root(const std::string& s) { os_ << s << "\n"; }
  void branch(const std::string& label, bool is_last, const auto& fn) {
    prefix();
    os_ << (is_last ? "╚" : "╠") << label << "\n";
    last_.push_back(is_last);
    fn();
    last_.pop_back();
  }
  void leaf(const std::string& label, bool is_last) {
    prefix();
    os_ << (is_last ? "╚" : "╠") << label << "\n";
  }
  void prefix() {
    for (bool l : last_) {
      os_ << (l ? "  " : "║ ");
    }
  }
  std::string hdr(const char* name, const Span& sp) const {
    std::string s = name;
    if (show_spans_)
      s += " [" + span(sp) + "]";
    return s;
  }
  static std::string span(const Span& s) {
    return std::to_string(s.begin.line) + ":" + std::to_string(s.begin.col) +
           "-" + std::to_string(s.end.line) + ":" + std::to_string(s.end.col);
  }
  /* ---------- items ---------- */

  void dump(const Item& it) {
    std::visit([&](const auto& x) { dump(x); }, it.inner);
  }
  void dump(const Input& n) {
    leaf("Input " + n.identifier + " trigger='" + std::string(1, n.trigger.c) +
             "'",
         true);
  }
  void dump(const Output& n) {
    leaf("Output " + n.identifier + " label=\"" + n.name.str + "\"", true);
  }
  void dump(const Clock& n) {
    leaf("Clock " + n.identifier + " period=" + std::to_string(n.cycle_ms.dec) +
             " duty=" + std::to_string(n.duty_cycle.dec),
         true);
  }
  void dump(const Gate& n) {
    branch("Gate " + n.identifier + " width=" + std::to_string(n.width.dec),
           true, [&] {
             for (size_t i = 0; i < n.gate_arm_list.size(); ++i) {
               dump(n.gate_arm_list[i], i, i + 1 == n.gate_arm_list.size());
             }
           });
  }
  void dump(const GateArm& n, size_t idx, bool is_last) {
    leaf("arm[" + std::to_string(idx) + "]: " + pattern(n.trit_match_list) +
             " >> " + trit(n.result.trit),
         is_last);
  }
  void dump(const Block& n) {
    branch("Block " + n.identifier, true, [&] {
      /* ports */
      branch("ports", false, [&] {
        for (size_t i = 0; i < n.port_list.size(); ++i) {
          leaf(port(n.port_list[i]), i + 1 == n.port_list.size());
        }
      });

      /* with */
      if (n.opt_with) {
        branch("with", false, [&] {
          for (size_t i = 0; i < n.opt_with->inst_list.size(); ++i) {
            const auto& inst = n.opt_with->inst_list[i];
            leaf(inst.type + " " + inst.identifier,
                 i + 1 == n.opt_with->inst_list.size());
          }
        });
      }

      /* connections */
      branch("connections", true, [&] {
        for (size_t i = 0; i < n.chain_list.size(); ++i) {
          dump(n.chain_list[i], i, i + 1 == n.chain_list.size());
        }
      });
    });
  }
  void dump(const Bench& n) {
    branch("Bench \"" + n.name.str + "\"", true, [&] {
      for (size_t i = 0; i < n.con_list.size(); ++i) {
        dump(n.con_list[i], i, i + 1 == n.con_list.size());
      }
    });
  }
  /* ---------- chains ---------- */

  void dump(const Chain& c, size_t idx, bool is_last) {
    branch("chain[" + std::to_string(idx) + "]", is_last, [&] {
      for (size_t i = 0; i < c.elements.size(); ++i) {
        leaf(expr(c.elements[i]), i + 1 == c.elements.size());
      }
    });
  }
  /* ---------- expressions ---------- */

  std::string expr(const Expression& e) {
    return std::visit([&](const auto& x) { return expr(x); }, e.primary);
  }
  std::string expr(const std::string& s) { return s; }
  std::string expr(const Qualified& q) { return q.block + "." + q.property; }
  std::string expr(const Bus& b) {
    std::string out = "|";
    for (size_t i = 0; i < b.expression_list.size(); ++i) {
      if (i)
        out += ", ";
      out += expr(b.expression_list[i]);
    }
    out += "|";
    return out;
  }
  std::string expr(const TritLiteral& t) { return trit(t.trit); }
  /* ---------- helpers ---------- */

  static std::string port(const Port& p) {
    return std::string(p.type == PortType::In ? "in " : "out ") + p.identifier;
  }
  static std::string trit(Trit t) {
    switch (t) {
      case Trit::Plus:
        return "+";
      case Trit::Zero:
        return "0";
      case Trit::Minus:
        return "-";
    }
    return "?";
  }
  static std::string match(TritMatch t) {
    switch (t) {
      case TritMatch::Plus:
        return "+";
      case TritMatch::Zero:
        return "0";
      case TritMatch::Minus:
        return "-";
      case TritMatch::Wild:
        return "_";
    }
    return "?";
  }
  static std::string pattern(const std::vector<TritMatch>& p) {
    std::string out = "(";
    for (size_t i = 0; i < p.size(); ++i) {
      if (i)
        out += ", ";
      out += match(p[i]);
    }
    out += ")";
    return out;
  }
};
} // namespace ast
