// ast/dump.hpp
#pragma once

#include <ostream>
#include <string>
#include <variant>
#include <vector>

#include "parser/ast/nodes.hpp"
#include "parser/ast/arena.hpp"

namespace ast {

class Dumper {
 public:
  Dumper(const Arena& a, std::ostream& os)
      : a_(a), os_(os) {}

  void set_verbose_atoms(bool v) { verbose_atoms_ = v; }
  void set_show_spans(bool v) { show_spans_ = v; }

  void dump_program(NodeId<Program> p) {
    root(hdr("Program", p.id, a_.get(p).sp));
    const auto& n = a_.get(p);

    for (size_t i = 0; i < n.segments.size(); ++i) {
      branch("segment[" + std::to_string(i) + "]:",
             i + 1 == n.segments.size(),
             [&] { dump(n.segments[i]); });
    }
  }

  void dump_arena() {
    root("ArenaDump");
    branch("size: " + std::to_string(a_.size()),
           a_.size() == 0,
           [&] {});

    for (size_t i = 0; i < a_.size(); ++i) {
      branch("node[" + std::to_string(i) + "]:",
             i + 1 == a_.size(),
             [&] {
               a_.visit_node(i, [&](const auto& x) {
                 dump_inline_node(i, x);
               });
             });
    }
  }

 private:
  const Arena& a_;
  std::ostream& os_;

  bool verbose_atoms_{false};
  bool show_spans_{false};

  std::vector<bool> last_stack_;

  static constexpr size_t none_id = static_cast<size_t>(-1);

  void root(const std::string& s) { os_ << s << "\n"; }

  void branch(const std::string& label,
              bool is_last,
              const auto& fn) {
    print_prefix();
    os_ << (is_last ? "╚" : "╠") << label << "\n";
    last_stack_.push_back(is_last);
    fn();
    last_stack_.pop_back();
  }

  void leaf(const std::string& label, bool is_last) {
    print_prefix();
    os_ << (is_last ? "╚" : "╠") << label << "\n";
  }

  void line(const std::string& label) {
    print_prefix();
    os_ << "║ " << label << "\n";
  }

  void print_prefix() {
    for (size_t i = 0; i < last_stack_.size(); ++i) {
      if (i + 1 == last_stack_.size()) {
        os_ << (last_stack_[i] ? "  " : "║ ");
      } else {
        os_ << (last_stack_[i] ? "  " : "║ ");
      }
    }
  }

  std::string hdr(const char* name,
                  size_t id,
                  const Span& spn) const {
    std::string out = name;
    if (id != none_id) out += "#" + std::to_string(id);
    if (show_spans_) out += " sp=" + span_to_str(spn);
    return out;
  }

  static std::string span_to_str(const Span& s) {
    return std::to_string(s.begin.line) + ":" +
           std::to_string(s.begin.col) + "-" +
           std::to_string(s.end.line) + ":" +
           std::to_string(s.end.col);
  }

  static std::string size_to_str(const SizeSpec& s) {
    if (s.is_dynamic) return "?";
    return std::to_string(s.fixed);
  }

  static std::string trit_to_str(Trit t) {
    switch (t) {
      case Trit::Plus: return "+";
      case Trit::Zero: return "0";
      case Trit::Minus: return "-";
    }
    return "?";
  }

  static std::string match_to_str(TritMatch t) {
    switch (t) {
      case TritMatch::Plus: return "+";
      case TritMatch::Zero: return "0";
      case TritMatch::Minus: return "-";
      case TritMatch::Wild: return "_";
    }
    return "?";
  }

  static std::string guard_to_str(const CGuard& g) {
    if (!g.b) return "<" + trit_to_str(g.a) + ">";
    return "<" + trit_to_str(g.a) + "," + trit_to_str(*g.b) + ">";
  }

  static std::string pattern_to_str(
      const std::vector<TritMatch>& p) {
    std::string out = "(";
    for (size_t i = 0; i < p.size(); ++i) {
      if (i) out += ", ";
      out += match_to_str(p[i]);
    }
    out += ")";
    return out;
  }

  void dump(NodeId<SourceSegment> s) {
    const auto& seg = a_.get(s);
    branch(hdr("SourceSegment", s.id, seg.sp),
           true,
           [&] {
             std::visit([&](const auto& x) { dump(x); }, seg.inner);
           });
  }

  void dump(const Scope& n) {
    branch(hdr("Scope", none_id, n.sp),
           true,
           [&] {
             for (size_t i = 0; i < n.segments.size(); ++i) {
               branch("segment[" + std::to_string(i) + "]:",
                      i + 1 == n.segments.size(),
                      [&] { dump(n.segments[i]); });
             }
           });
  }

  void dump(const Statement& n) {
    branch(hdr("Statement", none_id, n.sp),
           true,
           [&] {
             std::visit([&](const auto& x) { dump(x); }, n.inner);
           });
  }

  void dump(const RegDec& n) {
    leaf(hdr("RegDec", none_id, n.sp) + " name=" + n.name.text +
             " width=" + std::to_string(n.width),
         true);
  }

  void dump(const VarDec& n) {
    leaf(hdr("VarDec", none_id, n.sp) + " name=" + n.name.text +
             " width=" + size_to_str(n.width),
         true);
  }

  void dump(const Chain& n) {
    branch(hdr("Chain", none_id, n.sp),
           true,
           [&] {
             branch("start:",
                    false,
                    [&] { dump_expr(n.start); });

             branch("hops[" + std::to_string(n.hops.size()) + "]:",
                    true,
                    [&] {
                      for (size_t i = 0; i < n.hops.size(); ++i) {
                        dump(n.hops[i], i,
                             i + 1 == n.hops.size());
                      }
                    });
           });
  }

  void dump(const ChainHop& n,
            size_t idx,
            bool is_last) {
    branch(hdr("Hop", idx, n.sp),
           is_last,
           [&] {
             if (n.ovrd) {
               branch("override:",
                      false,
                      [&] { dump(*n.ovrd); });
             }

             branch("expr:",
                    true,
                    [&] { dump_expr(n.expr); });
           });
  }

  void dump(const CellOverride& n) {
    branch(hdr("CellOverride", none_id, n.sp),
           true,
           [&] {
             for (size_t i = 0; i < n.actuals.size(); ++i) {
               branch("actual[" + std::to_string(i) + "]:",
                      i + 1 == n.actuals.size(),
                      [&] { dump_expr(n.actuals[i]); });
             }
           });
  }

  void dump(const IfElse& n) {
    branch(hdr("IfElse", none_id, n.sp) +
               " guard=" + guard_to_str(n.guard),
           true,
           [&] {
             branch("cond:", false, [&] { dump_expr(n.cond); });
             branch("then:", false, [&] { dump(n.then_scope); });

             if (n.arms) {
               branch("arms[" + std::to_string(n.arms->size()) + "]:",
                      true,
                      [&] {
                        for (size_t i = 0; i < n.arms->size(); ++i) {
                          dump((*n.arms)[i], i,
                               i + 1 == n.arms->size());
                        }
                      });
             }
           });
  }

  void dump(const IfArm& n, size_t idx, bool is_last) {
    std::string k = (n.kind == IfArm::Kind::Elif) ? "Elif" : "Else";
    branch(hdr("IfArm", idx, n.sp) +
               " kind=" + k +
               " guard=" + guard_to_str(n.guard),
           is_last,
           [&] {
             if (n.cond) {
               branch("cond:", false, [&] { dump_expr(*n.cond); });
             }
             branch("scope:", true, [&] { dump(n.scope); });
           });
  }

  void dump(const WhileLoop& n) {
    branch(hdr("WhileLoop", none_id, n.sp) +
               " guard=" + guard_to_str(n.guard),
           true,
           [&] {
             branch("cond:", false, [&] { dump_expr(n.cond); });
             branch("body:", true, [&] { dump(n.scope); });
           });
  }

  void dump(const GateDef& n) {
    branch(hdr("GateDef", none_id, n.sp) +
               " name=" + n.name.text +
               " arity=" + std::to_string(n.arity),
           true,
           [&] {
             branch("arms[" + std::to_string(n.arms.size()) + "]:",
                    true,
                    [&] {
                      for (size_t i = 0; i < n.arms.size(); ++i) {
                        dump(n.arms[i], i,
                             i + 1 == n.arms.size());
                      }
                    });
           });
  }

  void dump(const GateArm& n, size_t idx, bool is_last) {
    branch(hdr("GateArm", idx, n.sp) +
               " result=" + trit_to_str(n.result),
           is_last,
           [&] {
             leaf("pattern: " + pattern_to_str(n.pattern), true);
           });
  }

  void dump(const FuncDef& n) {
    branch(hdr("FuncDef", none_id, n.sp) +
               " name=" + n.name.text,
           true,
           [&] {
             branch("args[" + std::to_string(n.args.size()) + "]:",
                    false,
                    [&] {
                      for (size_t i = 0; i < n.args.size(); ++i) {
                        dump(n.args[i], i,
                             i + 1 == n.args.size());
                      }
                    });

             if (n.cells) {
               branch("cells:", false, [&] { dump(*n.cells); });
             }

             branch("rets[" + std::to_string(n.rets.size()) + "]:",
                    false,
                    [&] {
                      for (size_t i = 0; i < n.rets.size(); ++i) {
                        dump(n.rets[i], i,
                             i + 1 == n.rets.size());
                      }
                    });

             branch("body:", true, [&] { dump(n.body); });
           });
  }

  void dump(const Arg& n, size_t idx, bool is_last) {
    branch(hdr("Arg", idx, n.sp) +
               " name=" + n.name.text +
               " width=" + size_to_str(n.width),
           is_last,
           [&] {
             if (n.def) branch("def:", true, [&] { dump_expr(*n.def); });
           });
  }

  void dump(const CellSet& n) {
    branch(hdr("CellSet", none_id, n.sp),
           true,
           [&] {
             for (size_t i = 0; i < n.decls.size(); ++i) {
               leaf("decl[" + std::to_string(i) + "]: " +
                        cell_decl_head(n.decls[i]),
                    i + 1 == n.decls.size());
             }
           });
  }

  void dump(const RetItem& n, size_t idx, bool is_last) {
    leaf("ret[" + std::to_string(idx) + "]: " + ret_item_head(n),
         is_last);
  }

  void dump(NodeId<Scope> s) { dump(a_.get(s)); }

  void dump_expr(NodeId<Expr> id) {
    const auto& e = a_.get(id);
    branch("Expr#" + std::to_string(id.id) +
               (show_spans_ ? " sp=" + span_to_str(e.sp) : ""),
           true,
           [&] {
             leaf("left:  " + braccess_head(e.cat.left),
                  !e.cat.right && !verbose_atoms_);

             if (e.cat.right) {
               leaf("right: " + braccess_head(*e.cat.right),
                    !verbose_atoms_);
             }

             if (verbose_atoms_) {
               branch("detail:", true, [&] { dump_expr_detail(e); });
             }
           });
  }

  void dump_expr_detail(const Expr& e) {
    dump_braccess_detail("left", e.cat.left,
                         !e.cat.right);
    if (e.cat.right) dump_braccess_detail("right", *e.cat.right, true);
  }

  void dump_braccess_detail(const char* label,
                            const Braccess& b,
                            bool is_last) {
    branch(std::string(label) + ":",
           is_last,
           [&] {
             leaf("braccess_sp: " + span_to_str(b.sp), false);
             leaf("memop_sp: " + span_to_str(b.base.sp), false);
             leaf("memop_op: " + std::string(memop_kind(b.base.op)), false);
             leaf("atom_kind: " + atom_kind(b.base.atom), false);
             leaf("atom_sp: " + atom_span(b.base.atom), !b.slice);
             if (b.slice) {
               branch("slice:", true, [&] {
                 leaf("sp: " + span_to_str(b.slice->sp), false);
                 if (b.slice->lo)
                   leaf("lo: " + std::to_string(*b.slice->lo), false);
                 if (b.slice->hi)
                   leaf("hi: " + std::to_string(*b.slice->hi), false);
                 leaf(std::string("dir: ") +
                          (b.slice->dir == SliceDir::Forward ? ">" : "<"),
                      true);
               });
             }
           });
  }

  static std::string cell_decl_head(const CellDecl& d) {
    return std::visit([&](const auto& x) -> std::string {
      using X = std::decay_t<decltype(x)>;
      if constexpr (std::is_same_v<X, CellDeclReg>) {
        return "&" + x.reg.text + ":" + size_to_str(x.width);
      } else {
        std::string s =
            x.name.text + ":" + size_to_str(x.width);
        if (x.def) s += "=<Expr>";
        return s;
      }
    }, d);
  }

  std::string ret_item_head(const RetItem& r) {
    return std::visit([&](const auto& x) -> std::string {
      using X = std::decay_t<decltype(x)>;
      if constexpr (std::is_same_v<X, RetNamed>) {
        return x.name.text + ":" + size_to_str(x.width);
      } else {
        return "Expr#" + std::to_string(x.expr.id);
      }
    }, r);
  }

  static std::string braccess_head(const Braccess& b) {
    return memop_head(b.base) + slice_head(b.slice);
  }

  static std::string slice_head(const std::optional<Slice>& s) {
    if (!s) return "";
    std::string out = "[";
    if (s->lo) out += std::to_string(*s->lo);
    out += (s->dir == SliceDir::Forward) ? ">" : "<";
    if (s->hi) out += std::to_string(*s->hi);
    out += "]";
    return out;
  }

  static std::string memop_head(const MemOp& m) {
    std::string p;
    if (m.op == MemOpKind::Direct) p = "&";
    if (m.op == MemOpKind::WaitForChange) p = "*";
    return p + atom_head(m.atom);
  }

  static std::string atom_head(const Atom& a) {
    return std::visit([&](const auto& x) { return atom_head(x); }, a);
  }

  static std::string atom_head(const Word& w) { return w.text; }
  static std::string atom_head(const BusRef& r) {
    return "$" + std::to_string(r.idx);
  }
  static std::string atom_head(const Literal& l) { return l.trits; }
  static std::string atom_head(const Decimal& d) {
    return "`" + std::to_string(d.value.v) + "`";
  }
  static std::string atom_head(const CharLit& c) {
    return "'" + c.chars + "'";
  }
  static std::string atom_head(const AtomParen&) { return "(...)"; }
  static std::string atom_head(const List&) { return "|...|"; }
  static std::string atom_head(const Lambda&) { return "func(...)"; }

  static const char* memop_kind(MemOpKind k) {
    switch (k) {
      case MemOpKind::None: return "none";
      case MemOpKind::Direct: return "&";
      case MemOpKind::WaitForChange: return "*";
    }
    return "?";
  }

  static std::string atom_kind(const Atom& a) {
    return std::visit([&](const auto& x) { return atom_kind(x); }, a);
  }

  static std::string atom_kind(const Word&) { return "Word"; }
  static std::string atom_kind(const BusRef&) { return "BusRef"; }
  static std::string atom_kind(const Literal&) { return "Literal"; }
  static std::string atom_kind(const Decimal&) { return "Decimal"; }
  static std::string atom_kind(const CharLit&) { return "Char"; }
  static std::string atom_kind(const AtomParen&) { return "Paren"; }
  static std::string atom_kind(const List&) { return "List"; }
  static std::string atom_kind(const Lambda&) { return "Lambda"; }

  static std::string atom_span(const Atom& a) {
    return std::visit([&](const auto& x) {
      return span_to_str(x.sp);
    }, a);
  }

  template <class T>
  void dump_inline_node(size_t idx, const T& n) {
    leaf(std::string("unknown node kind at ") + std::to_string(idx), true);
    (void)n;
  }

  void dump_inline_node(size_t idx, const Expr& n) {
    leaf(hdr("Expr", idx, n.sp), true);
  }

  void dump_inline_node(size_t idx, const Scope& n) {
    leaf(hdr("Scope", idx, n.sp), true);
  }

  void dump_inline_node(size_t idx, const SourceSegment& n) {
    leaf(hdr("SourceSegment", idx, n.sp), true);
  }

  void dump_inline_node(size_t idx, const Program& n) {
    leaf(hdr("Program", idx, n.sp), true);
  }
};

}  // namespace ast

