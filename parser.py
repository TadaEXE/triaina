from __future__ import annotations
from typing import Literal, Optional, Union


class Ast:
    pass


class Program(Ast):
    instructions: list[Instruction]


class Instruction(Ast):
    inner: Union[Scope, FuncDef, GateDef, WhileLoop, ForLoop, IfElse, Statement]


class Scope(Ast):
    instructions: list[Instruction]


class GateDef(Ast):
    name: str
    channels: int
    body: GateBody


class GateBody(Ast):
    arms: list[GateArm]


class GateArm(Ast):
    pattern: list[Optional[Trit]]
    result: Trit


class WhileLoop(Ast):
    guard: CtrlGuard
    expr: Expression
    body: Scope


class ForLoop(Ast):
    loop_var: str
    data: Expression
    body: Scope


class IfElse(Ast):
    if_block: IfBlock
    elif_block: ElifBlock


class FuncDef(Ast):
    name: str
    out_len: Optional[FNum]
    body: Scope


class ArgList(Ast):
    args: list[Arg]


class Arg(Ast):
    decl: VarDecl


class VarDecl(Ast):
    name: str
    len: Optional[int]
    meta_var: Optional[str]

class Statement(Ast):
    pass

class Expression(Ast):
    pass


class Trit(Ast):
    val: Union[Literal["+"], Literal["0"], Literal["-"]]


class FNum(Ast):
    val: int
