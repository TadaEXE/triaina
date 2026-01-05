%language "c++"
%define api.namespace {parser}
%define api.parser.class {Parser}
%define api.value.type variant
%define api.token.constructor
%define parse.error detailed
%locations

%code requires {
  #include "parser/ast.hpp"
  #include "parser/driver.hpp"
  #include <memory>
  #include <string>
  #include <vector>

  using NodeList = std::vector<NodePtr>;
}

%parse-param { Driver& driver }
%lex-param   { Driver& driver }

%code {
  parser::Parser::symbol_type yylex(Driver& driver);
}

%token <std::string> WORD
%token <std::string> NUM

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

%token ERROR
%token END 0

%type <NodePtr> program statement chain hop atom bus_ref list braccess mem_op cat literal expr scope source_segment var_dec reg_dec
%type <NodeList> hop_list br_list source_segment_list
%type <char> trit 
%type <std::string> trit_seq opt_rnum rnum size_spec

%left ELSE
%%

program
  : source_segment_list END
    {
      auto p = Node::make(NodeType::Program);
      p->add_all(std::move($1));
      $$ = std::move(p);
      driver.set_program(std::move($$));
    }
  ;

source_segment_list
  : { $$ = NodeList{}; }
  | source_segment_list source_segment
    {
      $1.push_back(std::move($2));
      $$ = std::move($1);
    }
  ;

source_segment
  : scope { $$ = std::move($1); }
  | statement { $$ = std::move ($1); }
  ;

scope
  : LCURL source_segment_list RCURL
    {
      auto s = Node::make(NodeType::Scope);
      s->add_all(std::move($2));
      $$ = std::move(s);
    }
  ;

size_spec
  : NUM { $$ = std::move($1); }
  | QMARK { $$ = "?"; }
  ;

statement
  : chain SEMI { $$ = std::move($1); }
  | reg_dec SEMI { $$ = std::move($1); }
  | var_dec SEMI { $$ = std::move($1); }
  | error SEMI
    {
      $$ = Node::make(NodeType::ErrorStatement);
      yyerrok;
    }
  | ERROR SEMI
    {
      $$ = Node::make(NodeType::ErrorStatement);
      yyerrok;
    }
  ;

reg_dec
  : REG WORD COLON NUM
    {
      auto r = Node::make(NodeType::RegDec);
      r->set("name", std::move($2));
      r->set("size", std::move($4));
      $$ = std::move(r);
    }
  ;

var_dec
  : VAR WORD COLON size_spec
    {
      auto v = Node::make(NodeType::VarDec);
      v->set("name", std::move($2));
      v->set("size", std::move($4));
      $$ = std::move(v);
    }

chain
  : expr hop_list
    {
      auto n = Node::make(NodeType::Chain);
      n->add(std::move($1));
      n->add_all(std::move($2));
      $$ = std::move(n);
    }
  ;

hop_list
  : hop { $$ = NodeList{}; $$.push_back(std::move($1)); }
  | hop_list hop
    {
      $1.push_back(std::move($2));
      $$ = std::move($1);
    }
  ;

hop
  : ARROW expr
    {
      auto h = Node::make(NodeType::ChainHop);
      h->set("kind", std::string("Arrow"));
      h->add(std::move($2));
      $$ = std::move(h);
    }
  | ARROW error
    {
      driver.on_error(@2.begin.line, @2.begin.column, "invalid chain member");
      yyerrok;
      $$ = Node::make(NodeType::List);
    }
  ;

expr
  : cat
    {
      auto e = Node::make(NodeType::Expr);
      e->add(std::move($1));
      $$ = std::move(e);
    }
  ;

cat
  : braccess { $$ = std::move($1); }
  | cat PRCNT braccess
    {
      auto c = Node::make(NodeType::Cat);
      c->add(std::move($1));
      c->add(std::move($3));
      $$ = std::move(c);
    }
  ;

braccess
  : mem_op { $$ = std::move($1); }
  | mem_op LBRACK opt_rnum COLON opt_rnum RBRACK
    {
      auto s = Node::make(NodeType::Slice);
      s->add(std::move($1));
      if (!$3.empty()) s->set("lo", std::move($3));
      if (!$5.empty()) s->set("hi", std::move($5));
      $$ = std::move(s);
    }
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
  : atom { $$ = std::move($1); }
  | STAR atom
    {
      auto u = Node::make(NodeType::MemOp);
      u->set("op", std::string("*"));
      u->add(std::move($2));
      $$ = std::move(u);
    }
  | AMP atom
    {
      auto u = Node::make(NodeType::MemOp);
      u->set("op", std::string("&"));
      u->add(std::move($2));
      $$ = std::move(u);
    }
  ;

atom
  : WORD
    {
      auto n = Node::make(NodeType::Word);
      n->set("name", std::move($1));
      $$ = std::move(n);
    }
  | bus_ref { $$ = std::move($1); }
  | list { $$ = std::move($1); }
  | literal { $$ = std::move($1); }
  ;

bus_ref
  : DOLLAR ZERO
    {
      auto n = Node::make(NodeType::BusRef);
      n->set("index", 0L);
      $$ = std::move(n);
    }
  | DOLLAR NUM
    {
      auto n = Node::make(NodeType::BusRef);
      n->set("index", $2);
      $$ = std::move(n);
    }
  ;

list
  : PIPE br_list PIPE
    {
      auto n = Node::make(NodeType::List);
      n->add_all(std::move($2));
      $$ = std::move(n);
    }
  ;

br_list
  : braccess { $$ = NodeList{}; $$.push_back(std::move($1)); }
  | br_list COMMA braccess
    {
      $1.push_back(std::move($3));
      $$ = std::move($1);
    }
  ;

literal
  : trit_seq
    {
      auto n = Node::make(NodeType::Literal);
      n->set("text", std::move($1));
      $$ = std::move(n);
    }
  ;

trit_seq
  : trit { $$ = std::string(1, $1); }
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

