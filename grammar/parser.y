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
}

%parse-param { parser::Driver& driver }
%lex-param   { parser::Driver& driver }

%token <std::string> WORD
%token <std::string> NUM

%token INPUT "input"
%token OUTPUT "output"
%token CLOCK "clock"
%token IN "in"
%token OUT "out"
%token GATE "gate"
%token NODE "node"
%token WITH "with"
%token BENCH "bench"

%token ZERO "0"
%token PLUS "+"
%token MINUS "-"
%token UNDER "_"

%token SHIFT ">>"
%token DOT "."

%token LPAREN "("
%token RPAREN ")"
%token LCURL "{"
%token RCURL "}"
%token PIPE "|"
%token SEMI ";"
%token COMMA ","

%token BTICK "`"
%token SQUOTE "'"
%token DQUOTE "\""

%token ERROR
%token END 0

%type <char> trit trit_match
%type <ast::StringLiteral> string_literal
%type <ast::DecimalLiteral> decimal_literal
%type <ast::CharLiteral> char_literal

%type <ast::Expression> expr
%type <ast::Bus> bus
%type <ast::Qualified> qualified
%type <std::vector<ast::Expression>> expr_list
%type <std::variant<std::string, ast::Qualified, ast::Bus, ast::TritLiteral>> primary

%type <std::vector<ast::Expression>> chain_tail
%type <ast::Chain> chain
%type <std::vector<ast::Chain>> chain_list
%type <ast::Bench> bench_def

%type <ast::Inst> inst
%type <std::vector<ast::Inst>> inst_list
%type <std::optional<ast::With>> opt_with
%type <ast::Port> port
%type <std::vector<ast::Port>> port_list
%type <ast::Node> node_def

%type <std::vector<ast::TritMatch>> trit_match_list
%type <ast::GateArm> gate_arm
%type <std::vector<ast::GateArm>> gate_arm_list
%type <ast::Gate> gate_def

%type <ast::Input> input_decl
%type <ast::Output> output_decl
%type <ast::Clock> clock_decl

%type <ast::Item> item
%type <std::vector<ast::Item>> item_list
// %type <ast::Program> program

%code {
  parser::Parser::symbol_type yylex(parser::Driver& driver);

  static inline ast::Span sp(parser::Driver& d, const parser::location& l) {
    return d.span_from(l);
  }

  static inline uint32_t to_u32(const std::string& s) {
    return static_cast<uint32_t>(std::stoul(s));
  }

  static inline size_t to_size(const std::string& s) {
    return static_cast<size_t>(std::stoull(s));
  }

  static inline int64_t to_i64(const std::string& s) {
    return static_cast<int64_t>(std::stoll(s));
  }
}

%%

/* STRUCTURE */
program
  : item_list END
    {
      ast::Program prog {
        .sp = sp(driver, @$),
        .item_list = std::move($1),
      };

      driver.ast.set_program(std::move(prog));
      // $$ = driver.ast.program;
    }
  ;

item_list
  : /* empty */ { $$ = {}; }
  | item_list item
    {
      $1.push_back($2);
      $$ = std::move($1);
    }
  ;

item
  : input_decl { $$ = ast::Item{sp(driver, @$), $1}; }
  | output_decl { $$ = ast::Item{sp(driver, @$), $1}; }
  | clock_decl { $$ = ast::Item{sp(driver, @$), $1}; }
  | gate_def { $$ = ast::Item{sp(driver, @$), $1}; }
  | node_def { $$ = ast::Item{sp(driver, @$), $1}; }
  | bench_def { $$ = ast::Item{sp(driver, @$), $1}; }
  | error SEMI
    {
      // driver.on_error(@$.begin.line, @$.begin.column,
      //                 "invalid top-level item");
      yyerrok;
    }
  
  ;

/* IGO */
input_decl
  : INPUT LPAREN char_literal RPAREN WORD SEMI
    {
      $$ = ast::Input {
        .sp = sp(driver, @$),
        .trigger = std::move($3),
        .identifier = std::move($5),
      };
    }
  ;

output_decl
  : OUTPUT LPAREN string_literal RPAREN WORD SEMI
    {
      $$ = ast::Output {
        .sp = sp(driver, @$),
        .name = std::move($3),
        .identifier = std::move($5),
      };
    }
  ;

clock_decl
  : CLOCK LPAREN decimal_literal COMMA decimal_literal RPAREN WORD SEMI
    {
      $$ = ast::Clock {
        .sp = sp(driver, @$),
        .cycle_ms = std::move($3),
        .duty_cycle = std::move($5),
        .identifier = std::move($7),
      };
    }
  ;

/* GATE */

gate_def
  : GATE LPAREN decimal_literal RPAREN WORD LCURL gate_arm_list RCURL
    {
      $$ = ast::Gate {
        .sp = sp(driver, @$),
        .width = std::move($3),
        .identifier = std::move($5),
        .gate_arm_list = std::move($7),
      };
    }
  ;

gate_arm_list
  : gate_arm { $$ = std::vector<ast::GateArm>{$1}; }
  | gate_arm_list gate_arm
    {
      $1.push_back($2); 
      $$ = std::move($1);
    }
  ;

gate_arm
  : LPAREN trit_match_list RPAREN SHIFT trit SEMI
    {
      $$ = ast::GateArm {
        .sp = sp(driver, @$),
        .trit_match_list = std::move($2),
        .result = ast::TritLiteral { 
          .sp = sp(driver, @5),
          .trit = ast::char_to_trit($5),
        },
      };
    }
  ;

trit_match_list
  : trit_match { $$ = std::vector<ast::TritMatch>{ast::char_to_trit_match($1)}; }
  | trit_match_list COMMA trit_match
    {
      $1.push_back(ast::char_to_trit_match($3));
      $$ = std::move($1);
    }
  ;

trit_match
  : trit { $$ = std::move($1); }
  | UNDER { $$ = '_'; }
  ;

/* NODE */

node_def
  : NODE LPAREN port_list RPAREN WORD opt_with LCURL chain_list RCURL
    {
      $$ = ast::Node {
        .sp = sp(driver, @$),
        .port_list = std::move($3),
        .identifier = std::move($5),
        .opt_with = std::move($6),
        .chain_list = std::move($8),
      };
    }
  ;

port_list
  : port { $$ = std::vector<ast::Port>{$1}; }
  | port_list COMMA port
    {
      $1.push_back($3);
      $$ = std::move($1);
    }
  ;

port
  : IN WORD
    {
      $$ = ast::Port {
        .sp = sp(driver, @$),
        .type = ast::PortType::In,
        .identifier = std::move($2),
      };
    }
  | OUT WORD
    {
      $$ = ast::Port {
        .sp = sp(driver, @$),
        .type = ast::PortType::Out,
        .identifier = std::move($2),
      };
    }
  ;

opt_with
  : /* empty */ { $$ = std::nullopt; }
  | WITH LPAREN inst_list RPAREN
    {
      $$ = ast::With {
        .sp = sp(driver, @$),
        .inst_list = std::move($3),
      };
    }
  ;

inst_list
  : inst { $$ = std::vector<ast::Inst>{$1}; }
  | inst_list COMMA inst
    {
      $1.push_back($3);
      $$ = std::move($1);
    }
  ;

inst
  : WORD WORD
    {
      $$ = ast::Inst {
        .sp = sp(driver, @$),
        .type = std::move($1),
        .identifier = std::move($2),
      };
    }
  ;

/* CONNECTION */

bench_def
  : BENCH LPAREN string_literal RPAREN LCURL chain_list RCURL
    {
      $$ = ast::Bench {
        .sp = sp(driver, @$),
        .name = std::move($3),
        .con_list = std::move($6),
      };
    }
  ;


chain_list
  : /* empty */ { $$ = {}; }
  | chain_list chain
    {
      $1.push_back($2);
      $$ = std::move($1);
    }
  ;

chain
  : expr chain_tail SEMI
    {
      std::vector<ast::Expression> elems { $1 };
      elems.append_range($2);

      $$ = ast::Chain {
        .sp = sp(driver, @$),
        .elements = std::move(elems),
      };
    }
  ;

chain_tail
  : SHIFT expr { $$ = std::vector<ast::Expression> { $2 }; }
  | chain_tail SHIFT expr
    {
      $1.push_back($3);
      $$ = std::move($1);
    }
  ;

/* EXPRESSION */

expr
  : primary
    {
      $$ = ast::Expression {
        .sp = sp(driver, @$),
        .primary = std::move($1),
      };
    }
  ;

primary
  : WORD { $$ = std::move($1); }
  | qualified { $$ = std::move($1); }
  | bus { $$ = std::move($1); }
  | trit
    {
      $$ = ast::TritLiteral {
        .sp = sp(driver, @1),
        .trit = ast::char_to_trit($1),
      };
    }
  ;

qualified
  : WORD DOT WORD
    {
      $$ = ast::Qualified {
        .sp = sp(driver, @$),
        .node = std::move($1),
        .property = std::move($3),
      };
    }
  ;

bus
  : PIPE expr_list PIPE
    {
      $$ = ast::Bus {
        .sp = sp(driver, @$),
        .expression_list = std::move($2),
      };
    }
  ;

expr_list
  : expr
    {
      $$ = std::vector<ast::Expression> { $1 };
    }
  | expr_list COMMA expr
    {
      $1.push_back($3);
      $$ = std::move($1);
    }
  ;

trit
  : PLUS { $$ = '+'; }
  | ZERO { $$ = '0'; }
  | MINUS { $$ = '-'; }
  ;

/* LITERALS */

char_literal
  : SQUOTE WORD SQUOTE
    {
      $$ = ast::CharLiteral {
        .sp = sp(driver, @$),
        .c = $2[0],
      };
    }
  ;

decimal_literal
  : BTICK NUM BTICK
    {
      $$ = ast::DecimalLiteral {
        .sp = sp(driver, @$),
        .dec = to_i64($2),
      };
    }
  | BTICK MINUS NUM BTICK
    {
      $$ = ast::DecimalLiteral {
        .sp = sp(driver, @$),
        .dec = to_i64($3) * -1,
      };
    }
  ;

string_literal
  : DQUOTE WORD DQUOTE
    {
      $$ = ast::StringLiteral {
        .sp = sp(driver, @$),
        .str = std::move($2),
      };
    }
  ;

%%

void parser::Parser::error(const location_type& loc, const std::string& msg) {
  driver.on_error((int)loc.begin.line, (int)loc.begin.column, msg);
}

