%option reentrant noyywrap nodefault yylineno
%option prefix="triaina_"

%{
  #include "parser.tab.hpp"
  #include "parser/driver.hpp"
  #include <cstdlib>
  #include <string>

  using namespace parser;

  #define YY_DECL Parser::symbol_type triaina_lex(yyscan_t yyscanner, Driver& driver)

  static inline void loc_step(location& loc) {
    loc.begin = loc.end;
  }

  static inline void loc_advance(location& loc, const char* text, int len) {
    for (int i = 0; i < len; ++i) {
      if (text[i] == '\n') {
        loc.end.line += 1;
        loc.end.column = 1;
      } else {
        loc.end.column += 1;
      }
    }
  }

  static inline location token_loc(location& cursor, const char* text, int len) {
    location l = cursor;
    l.begin = cursor.end;
    l.end = cursor.end;
    loc_advance(l, text, len);
    cursor.end = l.end;
    cursor.begin = cursor.end;
    return l;
  }

  #define LOC (driver.loc ? token_loc(*driver.loc, yytext, yyleng) : location{})
%}

WS      [ \t\r\n]+
WORD    [a-zA-Z_][a-zA-Z_0-9]*

NUM     [1-9][0-9]*

%%

{WS} {
  if (driver.loc) {
    (void)token_loc(*driver.loc, yytext, yyleng);
  }
}

"0"   { return Parser::make_ZERO(LOC); }
"+"   { return Parser::make_PLUS(LOC); }
"-"   { return Parser::make_MINUS(LOC); }

"=>"  { return Parser::make_ARROW(LOC); }
">"   { return Parser::make_LT(LOC); }
"<"   { return Parser::make_GT(LOC); }

"*"   { return Parser::make_STAR(LOC); }
"&"   { return Parser::make_AMP(LOC); }
"%"   { return Parser::make_PRCNT(LOC); }

"("   { return Parser::make_LPAREN(LOC); }
")"   { return Parser::make_RPAREN(LOC); }
"{"   { return Parser::make_LCURL(LOC); }
"}"   { return Parser::make_RCURL(LOC); }
"["   { return Parser::make_LBRACK(LOC); }
"]"   { return Parser::make_RBRACK(LOC); }
"|"   { return Parser::make_PIPE(LOC); }

":"   { return Parser::make_COLON(LOC); }
";"   { return Parser::make_SEMI(LOC); }
","   { return Parser::make_COMMA(LOC); }
"?"   { return Parser::make_QMARK(LOC); }
"_"   { return Parser::make_UNDER(LOC); }

"`"   { return Parser::make_BTICK(LOC); }
"'"   { return Parser::make_SQUOTE(LOC); }
"\""  { return Parser::make_DQUOTE(LOC); }

"/"   { return Parser::make_SLASH(LOC); }
"="   { return Parser::make_EQUALS(LOC); }
"$"   { return Parser::make_DOLLAR(LOC); }

"var" { return Parser::make_VAR(LOC); }
"reg" { return Parser::make_REG(LOC); }

{NUM} { return Parser::make_NUM(std::string(yytext), LOC); }
{WORD} { return Parser::make_WORD(std::string(yytext), LOC); }
<<EOF>> { return Parser::make_END(LOC); }

. {
  int line = 1;
  int col = 1;
  if (driver.loc) {
    line = (int)driver.loc->end.line;
    col = (int)driver.loc->end.column;
    (void)token_loc(*driver.loc, yytext, yyleng);
  }

  driver.on_error(line, col, std::string("invalid character: ") + yytext);

  return Parser::make_ERROR(LOC);
}

%%

