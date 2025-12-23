import re
import argparse
from enum import Enum, auto
from typing import Any


class Regex(Enum):
    WORD = r"[a-zA-Z_]+[a-zA-Z_\d]*"
    NUM = r"[1-9]\d*"
    PLUS = r"\+"
    MINUS = r"-"
    ZERO = r"0"
    RARROW = r"=>"
    LT = r"<"
    GT = r">"
    EQ = r"="
    COMMA = r","
    SEMI = r";"
    COL = r":"
    LPAREN = r"\("
    RPAREN = r"\)"
    LCURL = r"{"
    RCURL = r"}"
    LBRAC = r"\["
    RBRAC = r"\]"
    QMARK = r"\?"


COMMENT = r"(//.*\n|/\*(.|\n)*\*/)"


class Ttype(Enum):
    undefined = 0
    eof = auto()
    word = auto()
    num = auto()

    # literals
    plus = auto()
    minus = auto()
    zero = auto()

    # symbols
    lt = auto()
    gt = auto()
    eq = auto()
    rarrow = auto()
    comma = auto()
    semi = auto()
    col = auto()
    lparen = auto()
    rparen = auto()
    lcurl = auto()
    rcurl = auto()
    lbrac = auto()
    rbrac = auto()
    qmark = auto()
    amp = auto()
    under = auto()

    # reserved keywords
    ifkw = auto()
    elsekw = auto()
    whilekw = auto()
    forkw = auto()
    fnkw = auto()
    gatekw = auto()
    retkw = auto()
    matchkw = auto()
    varkw = auto()


SYMBOLS = {
    "<": Ttype.lt,
    ">": Ttype.gt,
    "=": Ttype.eq,
    "=>": Ttype.rarrow,
    ",": Ttype.comma,
    ";": Ttype.semi,
    ":": Ttype.col,
    "(": Ttype.lparen,
    ")": Ttype.rparen,
    "{": Ttype.lcurl,
    "}": Ttype.rcurl,
    "[": Ttype.lbrac,
    "]": Ttype.rbrac,
    "?": Ttype.qmark,
    "_": Ttype.under,
}

LITERALS = {
    "+": Ttype.plus,
    "0": Ttype.zero,
    "-": Ttype.minus,
}

KEYWORDS = {
    "if": Ttype.ifkw,
    "else": Ttype.elsekw,
    "while": Ttype.whilekw,
    "fn": Ttype.fnkw,
    "gate": Ttype.gatekw,
    "ret": Ttype.retkw,
    "match": Ttype.matchkw,
    "var": Ttype.varkw,
}


class Token:
    content: str
    ty: Ttype

    def __init__(self, content: str, ty: Ttype) -> None:
        self.content = content
        self.ty = ty

    def __str__(self) -> str:
        return f"{self.ty.name}('{self.content}')"


class Tokenizer:
    code: str
    tokens: list[Token] = []

    def __init__(self, code: str) -> None:
        self.code = code

    def tokenize(self) -> list[Token]:
        self._sanitize_code()
        filter = f"({str.join("|", (x.value for x in list(Regex)))})(?:\\s*)"
        chunks = [x for x in re.split(filter, self.code) if x != ""]
        for c in chunks:
            self.tokens.append(Token(c, self._get_chunk_type(c)))

        # print(str.join("\n", [str(t) for t in self.tokens]))
        return self.tokens

    def _sanitize_code(self):
        self.code = re.sub(COMMENT, "", self.code)
        self.code = self.code.replace("\r\n", "").replace("\n", "")

    def _get_chunk_type(self, chunk: str) -> Ttype:
        if chunk in KEYWORDS.keys():
            return KEYWORDS[chunk]
        if chunk in SYMBOLS.keys():
            return SYMBOLS[chunk]
        if chunk in LITERALS.keys():
            return LITERALS[chunk]
        if re.fullmatch(str(Regex.NUM.value), chunk) is not None:
            return Ttype.num
        return Ttype.word



class Parser:
    pass


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("file", type=argparse.FileType("r"))
    parser.add_argument("-c", required=False, type=str)
    args = parser.parse_args()
    tokenizer = Tokenizer(args.file.read())
    tokenizer.tokenize()
