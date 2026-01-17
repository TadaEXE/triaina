%language "c++"
%define api.namespace {parser}
%define api.parser.class {Parser}
%define api.value.type variant
%define api.token.constructor
%define parse.error detailed
%locations

%code requires {
  #include <memory>
  #include <string>
  #include <vector>
  #include <cstdint>
  #include <cstddef>

  #include "parser/ast/nodes.hpp"
  #include "parser/driver.hpp"

  using ExprId = ast::NodeId<ast::Expr>;
  using ScopeId = ast::NodeId<ast::Scope>;
  using SegId = ast::NodeId<ast::SourceSegment>;
  using ProgId = ast::NodeId<ast::Program>;

  using SegList = std::vector<SegId>;
  using HopList = std::vector<ast::ChainHop>;
  using ExprList = std::vector<ExprId>;

  using ArgList = std::vector<ast::Arg>;
  using RetList = std::vector<ast::RetItem>;
  using CellDeclList = std::vector<ast::CellDecl>;
  // using CellActualList = std::vector<ast::CellActual>;
  using GateArmList = std::vector<ast::GateArm>;
  using TritMatchList = std::vector<ast::TritMatch>;
  using IfArmList = std::vector<ast::IfArm>;
}

%parse-param { parser::Driver& driver }
%lex-param   { parser::Driver& driver }

%code {
  parser::Parser::symbol_type yylex(parser::Driver& driver);

  static inline ast::Span sp(parser::Driver& d, const parser::location& l) {
    return d.span_from(l);
  }

  static inline uint32_t to_u32(const std::string& s) {
    return static_cast<uint32_t>(std::stoul(s));
  }

  static inline size_t to_st(const std::string& s) {
    return static_cast<size_t>(std::stoull(s));
  }

  static inline int64_t to_i64(const std::string& s) {
    return static_cast<int64_t>(std::stoll(s));
  }

  static inline ast::Trit to_trit(char c) {
    if (c == '+') return ast::Trit::Plus;
    if (c == '-') return ast::Trit::Minus;
    return ast::Trit::Zero;
  }

  static inline ast::TritMatch to_trit_match(char c) {
    if (c == '+') return ast::TritMatch::Plus;
    if (c == '-') return ast::TritMatch::Minus;
    if (c == '0') return ast::TritMatch::Zero;
    return ast::TritMatch::Wild;
  }
}

%token <std::string> WORD
%token <std::string> NUM
%token <std::string> CHARS

%token ZERO "0"
%token PLUS "+"
%token MINUS "-"

%token ARROW "=>"
%token LT "<"
%token GT ">"

%token STAR "*"
%token AMP "&"
%token PRCNT "%"

%token LPAREN "("
%token RPAREN ")"
%token LCURL "{"
%token RCURL "}"
%token LBRACK "["
%token RBRACK "]"
%token PIPE "|"

%token COLON ":"
%token SEMI ";"
%token COMMA ","
%token QMARK "?"
%token UNDER "_"

%token BTICK "`"
%token SQUOTE "'"
%token DQUOTE "\""

%token SLASH "/"
%token EQUALS "="
%token DOLLAR "$"

%token FUNC "func"
%token VAR "var"
%token REG "reg"
%token GATE "gate"
%token IF "if"
%token ELIF "elif"
%token ELSE "else"
%token WHILE "while"
%token NODE "node"

%token ERROR
%token END 0

%type <ProgId> program

%type <SegList> source_segment_list
%type <SegId> source_segment statement
%type <ScopeId> scope

%type <ast::GateDef> gate_def
%type <GateArmList> gate_body
%type <ast::GateArm> gate_arm
%type <TritMatchList> trit_match_list
%type <char> trit_match

%type <ast::FuncDef> func_def
%type <ast::Lambda> lambda
%type <ArgList> arg_list arg_list_items
%type <ast::Arg> arg
%type <RetList> ret_list ret_list_items
%type <ast::RetItem> ret_item

%type <ast::CellSet> cell_set
%type <CellDeclList> cell_decl_list
%type <ast::CellDecl> cell_decl
%type <ast::CellOverride> cell_override
// %type <CellActualList> cell_actual_list
// %type <ast::CellActual> cell_actual

%type <ast::IfElse> if_else
%type <IfArmList> if_arm_list
%type <ast::IfArm> if_arm
%type <ast::WhileLoop> while_loop
%type <ast::CGuard> cguard

%type <ast::RegDec> reg_dec
%type <ast::VarDec> var_dec
%type <ast::SizeSpec> size_spec

%type <ast::Chain> chain
%type <HopList> hop_list
%type <ast::ChainHop> hop

%type <ExprId> expr cat braccess
%type <ast::MemOp> mem_op
%type <ast::Atom> atom
%type <ast::BusRef> bus_ref
%type <ast::List> list
%type <ExprList> expr_list
%type <ast::Decimal> decimal
%type <ast::CharLit> char_lit
%type <ast::Literal> literal

%type <char> trit
%type <std::string> trit_seq rnum opt_rnum
%type <int8_t> slice_dir

%left ELSE
%%

program
  : source_segment_list END
    {
      ast::Program p{
        .segments = std::move($1),
        .sp = sp(driver, @$),
      };

      auto pid = driver.ast.make_id<ast::Program>(std::move(p));
      driver.set_program(pid);
      $$ = pid;
    }
  ;

source_segment_list
  : { $$ = SegList{}; }
  | source_segment_list source_segment
    {
      $1.push_back($2);
      $$ = std::move($1);
    }
  ;

source_segment
  : scope
    {
      ast::SourceSegment s{
        .inner = driver.ast.get($1),
        .sp = sp(driver, @$),
      };
      $$ = driver.ast.make_id<ast::SourceSegment>(std::move(s));
    }
  | gate_def
    {
      ast::SourceSegment seg{
        .inner = std::move($1),
        .sp = sp(driver, @$),
      };
      $$ = driver.ast.make_id<ast::SourceSegment>(std::move(seg));
    }
  | func_def
    {
      ast::SourceSegment seg{
        .inner = std::move($1),
        .sp = sp(driver, @$),
      };
      $$ = driver.ast.make_id<ast::SourceSegment>(std::move(seg));
    }
  | if_else
    {
      ast::SourceSegment seg{
        .inner = std::move($1),
        .sp = sp(driver, @$),
      };
      $$ = driver.ast.make_id<ast::SourceSegment>(std::move(seg));
    }
  | while_loop
    {
      ast::SourceSegment seg{
        .inner = std::move($1),
        .sp = sp(driver, @$),
      };
      $$ = driver.ast.make_id<ast::SourceSegment>(std::move(seg));
    }
  | statement { $$ = $1; }
  ;

scope
  : LCURL source_segment_list RCURL
    {
      ast::Scope s{
        .segments = std::move($2),
        .sp = sp(driver, @$),
      };
      $$ = driver.ast.make_id<ast::Scope>(std::move(s));
    }
  ;

gate_def
  : GATE LPAREN NUM RPAREN WORD LCURL gate_body RCURL
    {
      ast::GateDef g{
        .arity = to_st($3),
        .name = {
          .text = std::move($5),
          .sp = sp(driver, @5),
        },
        .arms = std::move($7),
        .sp = sp(driver, @$),
      };
      $$ = std::move(g);
    }
  ;

gate_body
  : gate_arm
    {
      GateArmList gal{};
      gal.push_back(std::move($1));
      $$ = std::move(gal);
    }
  | gate_body gate_arm
    {
      $1.push_back(std::move($2));
      $$ = std::move($1);
    }
  ;

gate_arm
  : LPAREN trit_match_list RPAREN ARROW trit SEMI
    {
      ast::GateArm a{
        .pattern = std::move($2),
        .result = to_trit($5),
        .sp = sp(driver, @$),
      };
      $$ = std::move(a);
    }
  ;

trit_match_list
  : trit_match
    {
      TritMatchList tml{};
      tml.push_back(to_trit_match($1));
      $$ = std::move(tml);
    }
  | trit_match_list COMMA trit_match
    {
      $1.push_back(to_trit_match($3));
      $$ = std::move($1);
    }
  ;

trit_match
  : trit { $$ = $1; }
  | UNDER { $$ = '_'; }
  ;

func_def
  : FUNC arg_list WORD ret_list scope
    {
      ast::FuncDef f{
        .name = {
          .text = std::move($3),
          .sp = sp(driver, @3),
        },
        .args = std::move($2),
        .cells = std::nullopt,
        .rets = std::move($4),
        .body = $5,
        .sp = sp(driver, @$),
      };
      $$ = std::move(f);
    }
  | FUNC arg_list cell_set WORD ret_list scope
    {
      ast::FuncDef f{
        .name = {
          .text = std::move($4),
          .sp = sp(driver, @4),
        },
        .args = std::move($2),
        .cells = std::move($3),
        .rets = std::move($5),
        .body = $6,
        .sp = sp(driver, @$),
      };
      $$ = std::move(f);
    }
  ;

lambda
  : FUNC arg_list ret_list scope
    {
      ast::Lambda l{
        .args = std::move($2),
        .cells = std::nullopt,
        .rets = std::move($3),
        .body = $4,
        .sp = sp(driver, @$),
      };
      $$ = std::move(l);
    }
  | FUNC arg_list cell_set ret_list scope
    {
      ast::Lambda l{
        .args = std::move($2),
        .cells = std::move($3),
        .rets = std::move($4),
        .body = $5,
        .sp = sp(driver, @$),
      };
      $$ = std::move(l);
    }
  ;

arg_list
  : LPAREN RPAREN { $$ = ArgList{}; }
  | LPAREN arg_list_items RPAREN { $$ = std::move($2); }
  ;

arg_list_items
  : arg
    {
      ArgList al{};
      al.push_back(std::move($1));
      $$ = std::move(al);
    }
  | arg_list_items COMMA arg
    {
      $1.push_back(std::move($3));
      $$ = std::move($1);
    }
  ;

arg
  : WORD COLON size_spec
    {
      ast::Arg a{
        .name = {
          .text = std::move($1),
          .sp = sp(driver, @$),
        },
        .width = std::move($3),
        .def = std::nullopt,
        .sp = sp(driver, @$),
      };
      $$ = std::move(a);
    }
  | WORD COLON size_spec EQUALS expr
    {
      ast::Arg a{
        .name = {
          .text = std::move($1),
          .sp = sp(driver, @$),
        },
        .width = std::move($3),
        .def = $5,
        .sp = sp(driver, @$),
      };
      $$ = std::move(a);
    }
  ;

ret_list
  : PIPE PIPE { $$ = RetList{}; }
  | PIPE ret_list_items PIPE { $$ = std::move($2); }
  ;

ret_list_items
  : ret_item
    {
      RetList rl{};
      rl.push_back(std::move($1));
      $$ = std::move(rl);
    }
  | ret_list_items COMMA ret_item
    {
      $1.push_back(std::move($3));
      $$ = std::move($1);
    }
  ;

ret_item
  : WORD COLON size_spec
    {
      ast::RetNamed rn{
        .name = {
          .text = std::move($1),
          .sp = sp(driver, @1),
        },
        .width = std::move($3),
        .sp = sp(driver, @$),
      };
      $$ = ast::RetItem{std::move(rn)};
    }
  | expr
    {
      ast::RetExpr re{
        .expr = $1,
        .sp = sp(driver, @$),
      };
      $$ = ast::RetItem{std::move(re)};
    }
  ;

cell_set
  : SLASH cell_decl_list SLASH
    {
      ast::CellSet cs{
        .decls = std::move($2),
        .sp = sp(driver, @$),
      };
      $$ = std::move(cs);
    }
  ;

cell_decl_list
  : cell_decl
    {
      CellDeclList cdl{};
      cdl.push_back(std::move($1));
      $$ = std::move(cdl);
    }
  | cell_decl_list COMMA cell_decl
    {
      $1.push_back(std::move($3));
      $$ = std::move($1);
    }
  ;

cell_decl
  : AMP WORD COLON size_spec
    {
      ast::CellDeclReg r{
        .reg = {
          .text = std::move($2),
          .sp = sp(driver, @2),
        },
        .width = std::move($4),
        .sp = sp(driver, @$),
      };
      $$ = ast::CellDecl{std::move(r)};
    }
  | WORD COLON size_spec
    {
      ast::CellDeclCell c{
        .name = {
          .text = std::move($1),
          .sp = sp(driver, @1),
        },
        .width = std::move($3),
        .def = std::nullopt,
        .sp = sp(driver, @$),
      };
      $$ = ast::CellDecl{std::move(c)};
    }
  | WORD COLON size_spec EQUALS expr
    {
      ast::CellDeclCell c{
        .name = {
          .text = std::move($1),
          .sp = sp(driver, @1),
        },
        .width = std::move($3),
        .def = $5,
        .sp = sp(driver, @$),
      };
      $$ = ast::CellDecl{std::move(c)};
    }
  ;

cell_override
  : EQUALS SLASH expr_list SLASH GT
    {
      ast::CellOverride ov{
        .actuals = std::move($3),
        .sp = sp(driver, @$),
      };
      $$ = std::move(ov);
    }
  ;

// cell_actual_list
//   : cell_actual
//     {
//       CellActualList cal{};
//       cal.push_back(std::move($1));
//       $$ = std::move(cal);
//     }
//   | cell_actual_list COMMA cell_actual
//     {
//       $1.push_back(std::move($3));
//       $$ = std::move($1);
//     }
//   ;

// cell_actual
//   : AMP WORD
//     {
//       ast::CellActual a{
//         .kind = ast::CellActual::Kind::RegRef,
//         .reg = {
//           .text = std::move($2),
//           .sp = sp(driver, @2),
//         },
//         .expr = ExprId{0},
//         .sp = sp(driver, @$),
//       };
//       $$ = std::move(a);
//     }
//   | expr
//     {
//       ast::CellActual a{
//         .kind = ast::CellActual::Kind::Expr,
//         .reg = {
//           .text = std::string{},
//           .sp = sp(driver, @$),
//         },
//         .expr = $1,
//         .sp = sp(driver, @$),
//       };
//       $$ = std::move(a);
//     }
//   ;

if_else
  : IF cguard expr scope if_arm_list
    {
      ast::IfElse ie{
        .guard = std::move($2),
        .cond = $3,
        .then_scope = $4,
        .arms = std::move($5),
        .sp = sp(driver, @$),
      };
      $$ = std::move(ie);
    }
  | IF cguard expr scope
    {
      ast::IfElse ie{
        .guard = std::move($2),
        .cond = $3,
        .then_scope = $4,
        .arms = std::nullopt,
        .sp = sp(driver, @$),
      };
      $$ = std::move(ie);
    }
  ;

if_arm_list
  : if_arm
    {
      IfArmList ial{};
      ial.push_back(std::move($1));
      $$ = std::move(ial);
    }
  | if_arm_list if_arm
    {
      $1.push_back(std::move($2));
      $$ = std::move($1);
    }
  ;

if_arm
  : ELIF cguard expr scope
    {
      ast::IfArm a{
        .kind = ast::IfArm::Kind::Elif,
        .guard = std::move($2),
        .cond = $3,
        .scope = $4,
        .sp = sp(driver, @$),
      };
      $$ = std::move(a);
    }
  | ELSE cguard scope
    {
      ast::IfArm a{
        .kind = ast::IfArm::Kind::Else,
        .guard = std::move($2),
        .cond = std::nullopt,
        .scope = $3,
        .sp = sp(driver, @$),
      };
      $$ = std::move(a);
    }
  ;

while_loop
  : WHILE cguard expr scope
    {
      ast::WhileLoop wl{
        .guard = std::move($2),
        .cond = $3,
        .scope = $4,
        .sp = sp(driver, @$),
      };
      $$ = std::move(wl);
    }
  ;

cguard
  : LT trit GT
    {
      ast::CGuard g{
        .a = to_trit($2),
        .b = std::nullopt,
        .sp = sp(driver, @$),
      };
      $$ = std::move(g);
    }
  | LT trit COMMA trit GT
    {
      ast::CGuard g{
        .a = to_trit($2),
        .b = to_trit($4),
        .sp = sp(driver, @$),
      };
      $$ = std::move(g);
    }
  ;

size_spec
  : NUM
    {
      ast::SizeSpec sz{
        .is_dynamic = false,
        .fixed = to_st($1),
        .sp = sp(driver, @$),
      };
      $$ = std::move(sz);
    }
  | QMARK
    {
      ast::SizeSpec sz{
        .is_dynamic = true,
        .fixed = 0,
        .sp = sp(driver, @$),
      };
      $$ = std::move(sz);
    }
  ;

statement
  : chain SEMI
    {
      ast::Statement st{
        .inner = std::move($1),
        .sp = sp(driver, @$),
      };

      ast::SourceSegment seg {
        .inner = std::move(st),
        .sp = sp(driver, @$),
      };

      $$ = driver.ast.make_id<ast::SourceSegment>(std::move(seg));
    }
  | reg_dec SEMI
    {
      ast::Statement st{
        .inner = std::move($1),
        .sp = sp(driver, @$),
      };

      ast::SourceSegment seg {
        .inner = std::move(st),
        .sp = sp(driver, @$),
      };

      $$ = driver.ast.make_id<ast::SourceSegment>(std::move(seg));
    }
  | var_dec SEMI
    {
      ast::Statement st{
        .inner = std::move($1),
        .sp = sp(driver, @$),
      };

      ast::SourceSegment seg {
        .inner = std::move(st),
        .sp = sp(driver, @$),
      };

      $$ = driver.ast.make_id<ast::SourceSegment>(std::move(seg));
    }
  | error SEMI
    {
      driver.on_error((int)@1.begin.line, (int)@1.begin.column, "invalid statement");
      yyerrok;

      ast::Statement st{
        .inner = ast::Chain{},
        .sp = sp(driver, @$),
      };

      ast::SourceSegment seg{
        .inner = std::move(st),
        .sp = sp(driver, @$),
      };

      $$ = driver.ast.make_id<ast::SourceSegment>(std::move(seg));
    }
  | ERROR SEMI
    {
      driver.on_error((int)@1.begin.line, (int)@1.begin.column, "invalid statement");
      yyerrok;

      ast::Statement st{
        .inner = ast::Chain{},
        .sp = sp(driver, @$),
      };

      ast::SourceSegment seg{
        .inner = std::move(st),
        .sp = sp(driver, @$),
      };

      $$ = driver.ast.make_id<ast::SourceSegment>(std::move(seg));
    }
  ;

reg_dec
  : REG WORD COLON NUM
    {
      ast::RegDec r{
        .name = {
          .text = std::move($2),
          .sp = sp(driver, @2),
        },
        .width = to_st($4),
        .sp = sp(driver, @$),
      };

      $$ = std::move(r);
    }
  ;

var_dec
  : VAR WORD COLON size_spec
    {
      ast::VarDec v{
        .name = {
          .text = std::move($2),
          .sp = sp(driver, @2),
        },
        .width = std::move($4),
        .sp = sp(driver, @$),
      };

      $$ = std::move(v);
    }

chain
  : expr hop_list
    {
      ast::Chain c{
        .start = $1,
        .hops = std::move($2),
        .sp = sp(driver, @$),
      };

      $$ = std::move(c);
    }
  ;

hop_list
  : hop
    {
      HopList hs{};
      hs.push_back(std::move($1));
      $$ = std::move(hs);
    }
  | hop_list hop
    {
      $1.push_back(std::move($2));
      $$ = std::move($1);
    }
  ;

hop
  : ARROW expr
    {
      ast::ChainHop h{
        .ovrd = std::nullopt,
        .expr = $2,
        .sp = sp(driver, @$),
      };

      $$ = std::move(h);
    }
  | cell_override expr
    {
      ast::ChainHop h{
        .ovrd = std::move($1),
        .expr = $2,
        .sp = sp(driver, @$),
      };
      $$ = std::move(h);
    }
  | ARROW error
    {
      driver.on_error((int)@2.begin.line, (int)@2.begin.column, "invalid chain member");
      yyerrok;

      ast::Literal l{
        .trits = "",
        .sp = sp(driver, @2),
      };
      
      ast::MemOp m{
        .op = ast::MemOpKind::None,
        .atom = ast::Atom{std::move(l)},
        .sp = sp(driver, @2),
      };

      ast::Braccess br{
        .base = std::move(m),
        .slice = std::nullopt,
        .sp = sp(driver, @2),
      };

      ast::Expr e{
        .cat = {
          .left = std::move(br),
          .right = std::nullopt,
          .sp = sp(driver, @2),
        },
        .sp = sp(driver, @2),
      };

      auto eid = driver.ast.make_id<ast::Expr>(std::move(e));

      ast::ChainHop h{
        .ovrd = std::nullopt,
        .expr = eid,
        .sp = sp(driver, @$),
      };

      $$ = std::move(h);
    }
  ;

expr
  : cat { $$ = $1; }
  ;

cat
  : braccess { $$ = $1; }
  | cat PRCNT braccess
    {
      const auto& l = driver.ast.get($1);
      const auto& r = driver.ast.get($3);

      ast::Expr e{
        .cat = {
          .left = l.cat.left,
          .right = r.cat.left,
          .sp = sp(driver, @$),
        },
        .sp = sp(driver, @$),
      };

      $$ = driver.ast.make_id<ast::Expr>(std::move(e));
    }
  ;

braccess
  : mem_op 
    {
      ast::Braccess br{
        .base = std::move($1),
        .slice = std::nullopt,
        .sp = sp(driver, @$),
      };

      ast::Expr e{
        .cat = {
          .left = std::move(br),
          .right = std::nullopt,
          .sp = sp(driver, @$),
        },
        .sp = sp(driver, @$),
      };

      $$ = driver.ast.make_id<ast::Expr>(std::move(e));
    }
  | mem_op LBRACK opt_rnum slice_dir opt_rnum RBRACK
    {
      ast::Slice sl{};
      if (!$3.empty()) sl.lo = to_i64($3);
      if (!$5.empty()) sl.hi = to_i64($5);
      sl.dir = ($4 > 0) ? ast::SliceDir::Forward : ast::SliceDir::Backward;
      sl.sp = sp(driver, @$);

      ast::Braccess br{
        .base = std::move($1),
        .slice = std::move(sl),
        .sp = sp(driver, @$),
      };

      ast::Expr e{
        .cat = {
          .left = std::move(br),
          .right = std::nullopt,
          .sp = sp(driver, @$),
        },
        .sp = sp(driver, @$),
      };

      $$ = driver.ast.make_id<ast::Expr>(std::move(e));
    }
  ;

slice_dir
  : GT { $$ = 1; }
  | LT { $$ = -1; }
  ;

opt_rnum
  : /* empty */ { $$ = std::string{}; }
  | rnum { $$ = std::move($1); }
  | NUM { $$ = std::move($1); }
  ;

rnum
  : MINUS ZERO NUM { $$ = "-" + std::move($3); }
  | MINUS NUM { $$ = "-" + std::move($2); }
  | ZERO NUM { $$ = std::move($2); }
  | ZERO { $$ = "0"; }
  ;

mem_op
  : atom
    {
      ast::MemOp m{
        .op = ast::MemOpKind::None,
        .atom = std::move($1),
        .sp = sp(driver, @$),
      };
      $$ = std::move(m);
    }
  | STAR atom
    {
      ast::MemOp m{
        .op = ast::MemOpKind::WaitForChange,
        .atom = std::move($2),
        .sp = sp(driver, @$),
      };
      $$ = std::move(m);
    }
  | AMP atom
    {
      ast::MemOp m{
        .op = ast::MemOpKind::Direct,
        .atom = std::move($2),
        .sp = sp(driver, @$),
      };
      $$ = std::move(m);
    }
  ;

atom
  : LPAREN expr RPAREN
    {
      ast::AtomParen p{
        .expr = $2,
        .sp = sp(driver, @$),
      };
      $$ = ast::Atom{std::move(p)};
    }
  | list { $$ = ast::Atom{std::move($1)}; }
  | lambda { $$ = ast::Atom{std::move($1)}; }
  | bus_ref { $$ = ast::Atom{std::move($1)}; }
  | WORD
    {
        ast::Word w{
          .text = std::move($1),
          .sp = sp(driver, @1),
        };
      $$ = ast::Atom{std::move(w)};
    }
  | char_lit { $$ = ast::Atom{std::move($1)}; }
  | decimal { $$ = ast::Atom{std::move($1)}; }
  | literal { $$ = ast::Atom{std::move($1)}; }
  ;

bus_ref
  : DOLLAR ZERO
    {
      ast::BusRef br{
        .idx = 0,
        .sp = sp(driver, @$)
      };
      $$ = std::move(br);
    }
  | DOLLAR NUM
    {
      ast::BusRef br{
        .idx = to_st($2),
        .sp = sp(driver, @$),
      };
      $$ = std::move(br);
    }
  ;

list
  : PIPE expr_list PIPE
    {
      ast::List l{
        .elems = std::move($2),
        .sp = sp(driver, @$),
      };
      $$ = std::move(l);
    }
  ;

expr_list
  : expr
    {
      ExprList xl{};
      xl.push_back($1);
      $$ = std::move(xl);
    }
  | expr_list COMMA expr
    {
      $1.push_back($3);
      $$ = std::move($1);
    }
  ;

decimal
  : BTICK opt_rnum BTICK
    {
      ast::Decimal d{
        .value = {
          .v = to_i64($2),
          .sp = sp(driver, @2),
        },
        .sp = sp(driver, @$),
      };
      $$ = std::move(d);
    }
  ;

char_lit
  : SQUOTE CHARS SQUOTE
    {
      ast::CharLit cl{
        .chars = std::move($2),
        .sp = sp(driver, @$),
      };
      $$ = std::move(cl);
    }
  | SQUOTE WORD SQUOTE
    {
      ast::CharLit cl{
        .chars = std::move($2),
        .sp = sp(driver, @$),
      };
      $$ = std::move(cl);
    }
  | SQUOTE opt_rnum SQUOTE
    {
      ast::CharLit cl{
        .chars = std::move($2),
        .sp = sp(driver, @$),
      };
      $$ = std::move(cl);
    }
  ;

literal
  : trit_seq
    {
      ast::Literal l{
        .trits = std::move($1),
        .sp = sp(driver, @$),
      };
      $$ = std::move(l);
    }
  ;

trit_seq
  : trit { $$ = std::string{1, $1}; }
  | trit_seq trit
    {
      $1.push_back($2);
      $$ = std::move($1);
    }
  ;

trit
  : PLUS { $$ = '+'; }
  | ZERO { $$ = '0'; }
  | MINUS { $$ = '-'; }
  ;

%%

void parser::Parser::error(const location_type& loc, const std::string& msg) {
  driver.on_error((int)loc.begin.line, (int)loc.begin.column, msg);
}

