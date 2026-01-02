# Grammar rules

```
program        := (instruction)* EOF;

scope          := LCURL (instruction)* RCURL

instruction    := scope
                | func_def
                | gate_def
                | while_loop
                | for_loop
                | if_else
                | statement;
                
statement      :=
                ( var_def
                | var_decl
                | assign
                | return
                ) SEMI;


expr           := LPAREN expr RPAREN
                | func_call
                | braccess
                | brange
                | word
                | literal;

return         := RET_KW expr?=ret_val;

num            := /[1-9]\d*/;
trit           := (ZERO | PLUS | MINUS);
literal        := trit+;
fnum           := ZERO num
                | num
                | ZERO;

cguard         := LT trit (COMMA trit)? GT;

if_else        := if_block elif_block*;
if_cond        := IF_KW cguard expr scope;
else_cond      := ELSE_KW cguard scope;
elif_cond      := ELIF_KW cguard scope;
else_block     := else_cond else_cond
                | else_cond;
if_block       := if_cond else_block?;
elif_block     := elif_cond else_block?;

match          := MATCH_KW expr match_body;
match_body     := LCURL match_arm+ RCURL;
match_arm      := (literal | UNDER | QMARK)+=pattern R_ARR0W scope;

while_loop     := WHILE_KW cguard expr scope;
for_loop       := FOR_KW word COMMA expr scope;

var_decl       := VAR_KW word=var_name COL (num | QMARK word?=meta_var)=var_len;
var_def        := var_decl EQ expr;
assign         := word EQ expr; 
braccess       := expr LBRAC fnum RBRAC; 
brange         := expr LBRAC fnum?=r_from COL fnum?=r_to RBRAC; 

arg            := var_decl;
arg_list       := LPAREN (arg? | arg (COMMA arg)*)=args RPAREN;
param_list     := LPAREN (expr? | expr (COMMA expr)*)=params RPAREN;

func_def       := FN_KW word=fn_name (COL (fnum | QMARK))? arg_list scope;
func_call      := word param_list;

gate_def       := GATE_KW word LPAREN num RPAREN gate_body;
gate_body      := LCURL gate_arm+ RCURL;
gate_arm       := LPAREN (trit | QMARK) (COMMA (trit | QMARK))* RPAREN R_ARROW trit SEMI;
```
