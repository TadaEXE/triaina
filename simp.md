# Simplefied syntax

```js
// Note: '...' is not part of the grammr and is only used as a placeholder for code
// reg stdout:6; <- available by default
// reg stdin:6; <- available by default
reg foo:9;
reg faa:6;

gate(2) and {
    (+, +) => +;
    (-, -) => -;
    (_, _) => 0;
}

gate(2) sepo {
    (+, 0) => +;
    (-, 0) => -;
    (0, +) => +;
    (0, -) => -;
    (_, _) => 0;
}

gate(2) zrep {
    (0, +) => +;
    (0, -) => -;
    (0, _) => 0;
    (+, _) => +;
    (-, _) => -;
}

func(val:?) shr |res:?| {
    0 % val[1:] => res;
}

func(lhs:?, rhs:?) same |res:1| {
    |lhs, rhs| => eq => redmin => res;
}

var myfelx:?;
var myfix:3;
+00- => myfix; // myfix = 00-
*stdin => shr => mayvar;
`523` % - => &foo;
&foo % 'a' => &faa;

if<+> &foo[0] {
|*stdin[-1:] => shr, bar:3|
    => func(lhs:3, rhs:3) |out:3| {
        |lhs[-1:], rhs| => same => out;
    }
    => &stdout;
}
else<-> { ... }
elif<+,0> &run {...}
else<-> { ... }

while<-> &bar {...}
```
