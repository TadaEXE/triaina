# Triaina runtime IR

```m
push_scope;
pop_scope;

var (name:word) (val:var|literal) (begin:meta|fnum|'?') (end:meta|fnum|'?');
meta (name:word) (dest:var);
gate (name:word) (channels:num) (row0:ttrow) (row1:ttrow) .. (rown:ttrow);

assign (lhs:var) (rhs:var|literal) (begin:meta|num|'?') (end:meta|num|'?');

@(label)
jmp (dest:label)
jmpp (dest:label) (val:var|trit)
jmpm (dest:label) (val:var|trit)
jmpz (dest:label) (val:var|trit)

fn (name:word)
```

