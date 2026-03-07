# LARA(1) Grammar
## PROGRAM LEVEL

```js
program
  : source_segment_list EOF
  ;

source_segment_list
  : /* empty */
  | source_segment_list source_segment
  ;

source_segment
  : scope
  | gate_def
  | func_def
  | if_else
  | while_loop
  | statement
  ;
```

---

## SCOPE

```
scope
  : LCURL source_segment_list RCURL
  ;
```

---

## GATES

```js
gate_def
  : GATE_KW LPAREN NUM RPAREN WORD gate_body
  ;

gate_body
  : gate_arm
  | gate_body gate_arm
  ;

gate_arm
  : LPAREN trit_match_list RPAREN RARROW trit SEMI
  ;

trit_match_list
  : trit_match
  | trit_match_list COMMA trit_match
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
```

---

## FUNCTIONS

```js
func_def
  : FUNC_KW arg_list opt_cell_set WORD ret_list scope
  ;

lambda
  : FUNC_KW arg_list opt_cell_set ret_list scope
  ;

opt_cell_set
  : /* empty */
  | cell_set
  ;

arg_list
  : LPAREN opt_arg_seq RPAREN
  ;

opt_arg_seq
  : /* empty */
  | arg_seq
  ;

arg_seq
  : arg
  | arg_seq COMMA arg
  ;

arg
  : WORD COLON size_spec opt_default
  ;

opt_default
  : /* empty */
  | EQUALS expr
  ;

ret_list
  : PIPE opt_ret_seq PIPE
  ;

opt_ret_seq
  : /* empty */
  | ret_seq
  ;

ret_seq
  : ret_item
  | ret_seq COMMA ret_item
  ;

ret_item
  : WORD COLON size_spec
  | expr
  ;
```

---

## CELL SET

```js
cell_set
  : SLASH cell_decl_seq SLASH
  ;

cell_decl_seq
  : cell_decl
  | cell_decl_seq COMMA cell_decl
  ;

cell_decl
  : AMP WORD COLON size_spec
  | WORD COLON size_spec opt_default
  ;
```

---

## CELL OVERRIDE (CHAIN CONTEXT ONLY)

```js
cell_override
  : EQUALS SLASH cell_actual_seq SLASH GT
  ;

cell_actual_seq
  : cell_actual
  | cell_actual_seq COMMA cell_actual
  ;

cell_actual
  : AMP WORD
  | expr
  ;
```

---

## CONTROL FLOW

```js
if_else
  : IF_KW cguard expr scope if_arm_list
  ;

if_arm_list
  : /* empty */
  | if_arm_list if_arm
  ;

if_arm
  : ELIF_KW cguard expr scope
  | ELSE_KW cguard scope
  ;

while_loop
  : WHILE_KW cguard expr scope
  ;

cguard
  : LT trit opt_trit GT
  ;

opt_trit
  : /* empty */
  | COMMA trit
  ;
```

---

## STATEMENTS

```js
statement
  : reg_dec SEMI
  | var_dec SEMI
  | chain SEMI
  ;
```

---

## DECLARATIONS

```js
reg_dec
  : REG_KW WORD COLON NUM
  ;

var_dec
  : VAR_KW WORD COLON size_spec
  ;

size_spec
  : NUM
  | QMARK
  ;
```

---

## CHAINS

```js
chain
  : expr chain_hop_list
  ;

chain_hop_list
  : chain_hop
  | chain_hop_list chain_hop
  ;

chain_hop
  : RARROW expr
  | cell_override expr
  ;
```

Because `cell_override` starts with `=`, and `RARROW` starts with `=>`,
the lookahead token resolves it without ambiguity.

---

## EXPRESSIONS

Precedence:

* `%` lowest
* slice binds tighter than `%`
* mem_op binds tighter than slice

```js
expr
  : cat
  ;

cat
  : braccess
  | cat PRCNT braccess
  ;
```

Left-recursive is fine for LALR(1).

---

## BRACCESS AND SLICING

```js
braccess
  : mem_op opt_slice
  ;

opt_slice
  : /* empty */
  | LBRACK opt_rnum slice_dir opt_rnum RBRACK
  ;

slice_dir
  : GT
  | LT
  ;

opt_rnum
  : /* empty */
  | rnum
  | NUM
  ;
```

---

## MEM OP

```js
mem_op
  : atom
  | STAR atom
  | AMP atom
  ;
```

No ambiguity here because STAR/AMP cannot start an atom.

---

## ATOMS

```js
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
```

---

LIST

```js
list
  : PIPE expr_list PIPE
  ;

expr_list
  : expr
  | expr_list COMMA expr
  ;
```

---

## LITERALS

```js
literal
  : trit
  | literal trit
  ;

decimal
  : BTICK rnum BTICK
  ;

char
  : SQUOTE WORD SQUOTE
  ;

rnum
  : MINUS opt_zero NUM
  | opt_zero NUM
  ;

opt_zero
  : /* empty */
  | ZERO
  ;
```

---

## Lexical Tokens

```js
GATE_KW   : "gate";
VAR_KW    : "var";
REG_KW    : "reg";
FUNC_KW   : "func";
IF_KW     : "if";
ELIF_KW   : "elif";
ELSE_KW   : "else";
WHILE_KW  : "while";

PLUS      : "+";
ZERO      : "0";
MINUS     : "-";

RARROW    : "=>";
LT        : "<";
GT        : ">";

AMP       : "&";
STAR      : "*";
PRCNT     : "%";

LPAREN    : "(";
RPAREN    : ")";
LCURL     : "{";
RCURL     : "}";
LBRACK    : "[";
RBRACK    : "]";
PIPE      : "|";

COLON     : ":";
SEMI      : ";";
COMMA     : ",";
QMARK     : "?";
UNDER     : "_";

BTICK     : "`";
SQUOTE    : "'";
DQUOTE    : """;

SLASH     : "/";
EQUALS    : "=";
DOLLAR    : "$";

WORD      : [a-zA-Z_][a-zA-Z_0-9]*;
NUM       : [1-9][0-9]*;

EOF       : end of file;
```
