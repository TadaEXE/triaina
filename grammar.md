program
 : source_segment* EOF
 ;

source_segment
 : scope
 | gate_def
 | func_def
 | if_else
 | while_loop
 | statement
 ;

scope
 : LCURL source_segment* RCURL
 ;

---

gate_def
 : GATE_KW LPAREN NUM RPAREN WORD gate_body
 ;

gate_body
 : gate_arm+
 ;

gate_arm
 : LPAREN trit_match (COMMA trit_match)* RPAREN
   RARROW trit SEMI
 ;

trit_match
 : trit
 | UNDER
 ;

trit
 : PLUS
 | ZERO
 | MINUS
 ;

---

func_def
 : FUNC_KW arg_list cell_set? WORD ret_list scope
 ;

lambda
 : FUNC_KW arg_list cell_set? ret_list scope
 ;

arg_list
 : LPAREN (arg (COMMA arg)*)? RPAREN
 ;

arg
 : WORD COLON size_spec (EQUALS expr)?
 ;

ret_list
 : PIPE (ret_item (COMMA ret_item)*)? PIPE
 ;

ret_item
 : WORD COLON size_spec
 | expr
 ;

cell_set
 : SLASH cell_decl (COMMA cell_decl)* SLASH
 ;

cell_decl
 : AMP WORD COLON size_spec
 | WORD COLON size_spec (EQUALS expr)?
 ;

cell_override
 : EQUALS SLASH cell_actual (COMMA cell_actual)* SLASH GT
 ;

cell_actual
 : AMP WORD
 | expr
 ;

size_spec
 : NUM
 | QMARK
 ;

---

if_else
 : IF_KW cguard expr scope if_arm*
 ;

if_arm
 : ELIF_KW cguard expr scope
 | ELSE_KW cguard scope
 ;

while_loop
 : WHILE_KW cguard expr scope
 ;

cguard
 : LT trit (COMMA trit)? GT
 ;

---

statement
 : ( reg_dec
   | var_dec
   | chain
   ) SEMI
 ;

reg_dec
 : REG_KW WORD COLON NUM
 ;

var_dec
 : VAR_KW WORD COLON (NUM | QMARK)
 ;

---

chain
 : expr chain_hop+
 ;

chain_hop
 : RARROW expr
 | cell_override expr
 ;

---

expr
 : cat
 ;

cat
 : braccess (PRCNT braccess)?
 ;

braccess
 : mem_op (LBRACK opt_rnum slice_dir opt_rnum RBRACK)?
 ;

slice_dir
 : GT
 | LT
 ;

opt_rnum
 : rnum
 | NUM
 | /* empty */
 ;

mem_op
 : (STAR | AMP)? atom
 ;

atom
 : LPAREN expr RPAREN
 | list
 | lambda
 | bus_ref
 | WORD
 | char
 | decimal
 | literal
 ;

bus_ref
 : DOLLAR (ZERO | NUM)
 ;

list
 : PIPE expr (COMMA expr)* PIPE
 ;

decimal
 : BTICK rnum BTICK
 ;

char
 : SQUOTE WORD SQUOTE
 ;

literal
 : trit+
 ;

rnum
 : MINUS? ZERO? NUM
 ;

---

Lexical Tokens

GATE_KW   : "gate"
VAR_KW    : "var"
REG_KW    : "reg"
FUNC_KW   : "func"
IF_KW     : "if"
ELIF_KW   : "elif"
ELSE_KW   : "else"
WHILE_KW  : "while"

PLUS      : "+"
ZERO      : "0"
MINUS     : "-"

RARROW    : "=>"
LT        : "<"
GT        : ">"

AMP       : "&"
STAR      : "*"
PRCNT     : "%"

LPAREN    : "("
RPAREN    : ")"
LCURL     : "{"
RCURL     : "}"
LBRACK    : "["
RBRACK    : "]"
PIPE      : "|"

COLON     : ":"
SEMI      : ";"
COMMA     : ","
QMARK     : "?"
UNDER     : "_"

BTICK     : "`"
SQUOTE    : "'"
DQUOTE    : """

SLASH     : "/"
EQUALS    : "="
DOLLAR    : "$"

WORD      : [a-zA-Z_][a-zA-Z_0-9]*
NUM       : [1-9][0-9]*

EOF       : end of file

