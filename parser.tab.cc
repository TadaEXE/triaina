// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





// "%code requires" blocks.
#line 9 "src/grammar/parser.y"

  #include <memory>
  #include <string>
  #include <vector>
  #include <cstdint>
  #include <cstddef>

  #include "parser/ast/ast.hpp"
  #include "parser/driver.hpp"

  using ExprId = ast::NodeId<ast::Expr>;
  using ScopeId = ast::NodeId<ast::Scope>;
  using SegId = ast::NodeId<ast::SourceSegment>;
  using ProgId = ast::NodeId<ast::Program>;

  using SegList = std::vector<SegId>;
  using HopList = std::vector<ast::ChainHop>;
  using ExprList = std::vector<ExprId>;

  using ArgList = std::vector<ast::Arg>;
  using RetList = std::vector<ast::RetItem>;
  using CellDeclList = std::vector<ast::CellDecl>;
  using CellActualList = std::vector<ast::CellActual>;
  using GateArmList = std::vector<ast::GateArm>;
  using TritMatchList = std::vector<ast::TritMatch>;
  using IfArmList = std::vector<ast::IfArm>;

#line 71 "parser.tab.cc"


# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif



#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

#line 2 "src/grammar/parser.y"
namespace parser {
#line 207 "parser.tab.cc"


  /// A point in a source file.
  class position
  {
  public:
    /// Type for file name.
    typedef const std::string filename_type;
    /// Type for line and column numbers.
    typedef int counter_type;

    /// Construct a position.
    explicit position (filename_type* f = YY_NULLPTR,
                       counter_type l = 1,
                       counter_type c = 1)
      : filename (f)
      , line (l)
      , column (c)
    {}


    /// Initialization.
    void initialize (filename_type* fn = YY_NULLPTR,
                     counter_type l = 1,
                     counter_type c = 1)
    {
      filename = fn;
      line = l;
      column = c;
    }

    /** \name Line and Column related manipulators
     ** \{ */
    /// (line related) Advance to the COUNT next lines.
    void lines (counter_type count = 1)
    {
      if (count)
        {
          column = 1;
          line = add_ (line, count, 1);
        }
    }

    /// (column related) Advance to the COUNT next columns.
    void columns (counter_type count = 1)
    {
      column = add_ (column, count, 1);
    }
    /** \} */

    /// File name to which this position refers.
    filename_type* filename;
    /// Current line number.
    counter_type line;
    /// Current column number.
    counter_type column;

  private:
    /// Compute max (min, lhs+rhs).
    static counter_type add_ (counter_type lhs, counter_type rhs, counter_type min)
    {
      return lhs + rhs < min ? min : lhs + rhs;
    }
  };

  /// Add \a width columns, in place.
  inline position&
  operator+= (position& res, position::counter_type width)
  {
    res.columns (width);
    return res;
  }

  /// Add \a width columns.
  inline position
  operator+ (position res, position::counter_type width)
  {
    return res += width;
  }

  /// Subtract \a width columns, in place.
  inline position&
  operator-= (position& res, position::counter_type width)
  {
    return res += -width;
  }

  /// Subtract \a width columns.
  inline position
  operator- (position res, position::counter_type width)
  {
    return res -= width;
  }

  /** \brief Intercept output stream redirection.
   ** \param ostr the destination output stream
   ** \param pos a reference to the position to redirect
   */
  template <typename YYChar>
  std::basic_ostream<YYChar>&
  operator<< (std::basic_ostream<YYChar>& ostr, const position& pos)
  {
    if (pos.filename)
      ostr << *pos.filename << ':';
    return ostr << pos.line << '.' << pos.column;
  }

  /// Two points in a source file.
  class location
  {
  public:
    /// Type for file name.
    typedef position::filename_type filename_type;
    /// Type for line and column numbers.
    typedef position::counter_type counter_type;

    /// Construct a location from \a b to \a e.
    location (const position& b, const position& e)
      : begin (b)
      , end (e)
    {}

    /// Construct a 0-width location in \a p.
    explicit location (const position& p = position ())
      : begin (p)
      , end (p)
    {}

    /// Construct a 0-width location in \a f, \a l, \a c.
    explicit location (filename_type* f,
                       counter_type l = 1,
                       counter_type c = 1)
      : begin (f, l, c)
      , end (f, l, c)
    {}


    /// Initialization.
    void initialize (filename_type* f = YY_NULLPTR,
                     counter_type l = 1,
                     counter_type c = 1)
    {
      begin.initialize (f, l, c);
      end = begin;
    }

    /** \name Line and Column related manipulators
     ** \{ */
  public:
    /// Reset initial location to final location.
    void step ()
    {
      begin = end;
    }

    /// Extend the current location to the COUNT next columns.
    void columns (counter_type count = 1)
    {
      end += count;
    }

    /// Extend the current location to the COUNT next lines.
    void lines (counter_type count = 1)
    {
      end.lines (count);
    }
    /** \} */


  public:
    /// Beginning of the located region.
    position begin;
    /// End of the located region.
    position end;
  };

  /// Join two locations, in place.
  inline location&
  operator+= (location& res, const location& end)
  {
    res.end = end.end;
    return res;
  }

  /// Join two locations.
  inline location
  operator+ (location res, const location& end)
  {
    return res += end;
  }

  /// Add \a width columns to the end position, in place.
  inline location&
  operator+= (location& res, location::counter_type width)
  {
    res.columns (width);
    return res;
  }

  /// Add \a width columns to the end position.
  inline location
  operator+ (location res, location::counter_type width)
  {
    return res += width;
  }

  /// Subtract \a width columns to the end position, in place.
  inline location&
  operator-= (location& res, location::counter_type width)
  {
    return res += -width;
  }

  /// Subtract \a width columns to the end position.
  inline location
  operator- (location res, location::counter_type width)
  {
    return res -= width;
  }

  /** \brief Intercept output stream redirection.
   ** \param ostr the destination output stream
   ** \param loc a reference to the location to redirect
   **
   ** Avoid duplicate information.
   */
  template <typename YYChar>
  std::basic_ostream<YYChar>&
  operator<< (std::basic_ostream<YYChar>& ostr, const location& loc)
  {
    location::counter_type end_col
      = 0 < loc.end.column ? loc.end.column - 1 : 0;
    ostr << loc.begin;
    if (loc.end.filename
        && (!loc.begin.filename
            || *loc.begin.filename != *loc.end.filename))
      ostr << '-' << loc.end.filename << ':' << loc.end.line << '.' << end_col;
    else if (loc.begin.line < loc.end.line)
      ostr << '-' << loc.end.line << '.' << end_col;
    else if (loc.begin.column < end_col)
      ostr << '-' << end_col;
    return ostr;
  }


  /// A Bison parser.
  class Parser
  {
  public:
#ifdef YYSTYPE
# ifdef __GNUC__
#  pragma GCC message "bison: do not #define YYSTYPE in C++, use %define api.value.type"
# endif
    typedef YYSTYPE value_type;
#else
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class value_type
  {
  public:
    /// Type of *this.
    typedef value_type self_type;

    /// Empty construction.
    value_type () YY_NOEXCEPT
      : yyraw_ ()
    {}

    /// Construct and fill.
    template <typename T>
    value_type (YY_RVREF (T) t)
    {
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    value_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~value_type () YY_NOEXCEPT
    {}

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
    }

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    value_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yyraw_;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yyraw_;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // arg_list
      // arg_list_items
      char dummy1[sizeof (ArgList)];

      // cell_decl_list
      char dummy2[sizeof (CellDeclList)];

      // expr
      // cat
      // braccess
      char dummy3[sizeof (ExprId)];

      // expr_list
      char dummy4[sizeof (ExprList)];

      // gate_body
      char dummy5[sizeof (GateArmList)];

      // hop_list
      char dummy6[sizeof (HopList)];

      // if_arm_list
      char dummy7[sizeof (IfArmList)];

      // program
      char dummy8[sizeof (ProgId)];

      // ret_list
      // ret_list_items
      char dummy9[sizeof (RetList)];

      // scope
      char dummy10[sizeof (ScopeId)];

      // source_segment
      // statement
      char dummy11[sizeof (SegId)];

      // source_segment_list
      char dummy12[sizeof (SegList)];

      // trit_match_list
      char dummy13[sizeof (TritMatchList)];

      // arg
      char dummy14[sizeof (ast::Arg)];

      // atom
      char dummy15[sizeof (ast::Atom)];

      // bus_ref
      char dummy16[sizeof (ast::BusRef)];

      // cguard
      char dummy17[sizeof (ast::CGuard)];

      // cell_decl
      char dummy18[sizeof (ast::CellDecl)];

      // cell_override
      char dummy19[sizeof (ast::CellOverride)];

      // cell_set
      char dummy20[sizeof (ast::CellSet)];

      // chain
      char dummy21[sizeof (ast::Chain)];

      // hop
      char dummy22[sizeof (ast::ChainHop)];

      // char_lit
      char dummy23[sizeof (ast::CharLit)];

      // decimal
      char dummy24[sizeof (ast::Decimal)];

      // func_def
      char dummy25[sizeof (ast::FuncDef)];

      // gate_arm
      char dummy26[sizeof (ast::GateArm)];

      // gate_def
      char dummy27[sizeof (ast::GateDef)];

      // if_arm
      char dummy28[sizeof (ast::IfArm)];

      // if_else
      char dummy29[sizeof (ast::IfElse)];

      // lambda
      char dummy30[sizeof (ast::Lambda)];

      // list
      char dummy31[sizeof (ast::List)];

      // literal
      char dummy32[sizeof (ast::Literal)];

      // mem_op
      char dummy33[sizeof (ast::MemOp)];

      // reg_dec
      char dummy34[sizeof (ast::RegDec)];

      // ret_item
      char dummy35[sizeof (ast::RetItem)];

      // size_spec
      char dummy36[sizeof (ast::SizeSpec)];

      // var_dec
      char dummy37[sizeof (ast::VarDec)];

      // while_loop
      char dummy38[sizeof (ast::WhileLoop)];

      // trit_match
      // trit
      char dummy39[sizeof (char)];

      // slice_dir
      char dummy40[sizeof (int8_t)];

      // WORD
      // NUM
      // CHARS
      // opt_rnum
      // rnum
      // trit_seq
      char dummy41[sizeof (std::string)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me_;
      /// A buffer large enough to store any of the semantic values.
      char yyraw_[size];
    };
  };

#endif
    /// Backward compatibility (Bison 3.8).
    typedef value_type semantic_type;

    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        YYEMPTY = -2,
    END = 0,                       // END
    YYerror = 256,                 // error
    YYUNDEF = 257,                 // "invalid token"
    WORD = 258,                    // WORD
    NUM = 259,                     // NUM
    CHARS = 260,                   // CHARS
    ZERO = 261,                    // "0"
    PLUS = 262,                    // "+"
    MINUS = 263,                   // "-"
    ARROW = 264,                   // "=>"
    LT = 265,                      // "<"
    GT = 266,                      // ">"
    STAR = 267,                    // "*"
    AMP = 268,                     // "&"
    PRCNT = 269,                   // "%"
    LPAREN = 270,                  // "("
    RPAREN = 271,                  // ")"
    LCURL = 272,                   // "{"
    RCURL = 273,                   // "}"
    LBRACK = 274,                  // "["
    RBRACK = 275,                  // "]"
    PIPE = 276,                    // "|"
    COLON = 277,                   // ":"
    SEMI = 278,                    // ";"
    COMMA = 279,                   // ","
    QMARK = 280,                   // "?"
    UNDER = 281,                   // "_"
    BTICK = 282,                   // "`"
    SQUOTE = 283,                  // "'"
    DQUOTE = 284,                  // "\""
    SLASH = 285,                   // "/"
    EQUALS = 286,                  // "="
    DOLLAR = 287,                  // "$"
    FUNC = 288,                    // "func"
    VAR = 289,                     // "var"
    REG = 290,                     // "reg"
    GATE = 291,                    // "gate"
    IF = 292,                      // "if"
    ELIF = 293,                    // "elif"
    ELSE = 294,                    // "else"
    WHILE = 295,                   // "while"
    NODE = 296,                    // "node"
    ERROR = 297                    // ERROR
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::token_kind_type token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 43, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // END
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_WORD = 3,                              // WORD
        S_NUM = 4,                               // NUM
        S_CHARS = 5,                             // CHARS
        S_ZERO = 6,                              // "0"
        S_PLUS = 7,                              // "+"
        S_MINUS = 8,                             // "-"
        S_ARROW = 9,                             // "=>"
        S_LT = 10,                               // "<"
        S_GT = 11,                               // ">"
        S_STAR = 12,                             // "*"
        S_AMP = 13,                              // "&"
        S_PRCNT = 14,                            // "%"
        S_LPAREN = 15,                           // "("
        S_RPAREN = 16,                           // ")"
        S_LCURL = 17,                            // "{"
        S_RCURL = 18,                            // "}"
        S_LBRACK = 19,                           // "["
        S_RBRACK = 20,                           // "]"
        S_PIPE = 21,                             // "|"
        S_COLON = 22,                            // ":"
        S_SEMI = 23,                             // ";"
        S_COMMA = 24,                            // ","
        S_QMARK = 25,                            // "?"
        S_UNDER = 26,                            // "_"
        S_BTICK = 27,                            // "`"
        S_SQUOTE = 28,                           // "'"
        S_DQUOTE = 29,                           // "\""
        S_SLASH = 30,                            // "/"
        S_EQUALS = 31,                           // "="
        S_DOLLAR = 32,                           // "$"
        S_FUNC = 33,                             // "func"
        S_VAR = 34,                              // "var"
        S_REG = 35,                              // "reg"
        S_GATE = 36,                             // "gate"
        S_IF = 37,                               // "if"
        S_ELIF = 38,                             // "elif"
        S_ELSE = 39,                             // "else"
        S_WHILE = 40,                            // "while"
        S_NODE = 41,                             // "node"
        S_ERROR = 42,                            // ERROR
        S_YYACCEPT = 43,                         // $accept
        S_program = 44,                          // program
        S_source_segment_list = 45,              // source_segment_list
        S_source_segment = 46,                   // source_segment
        S_scope = 47,                            // scope
        S_gate_def = 48,                         // gate_def
        S_gate_body = 49,                        // gate_body
        S_gate_arm = 50,                         // gate_arm
        S_trit_match_list = 51,                  // trit_match_list
        S_trit_match = 52,                       // trit_match
        S_func_def = 53,                         // func_def
        S_lambda = 54,                           // lambda
        S_arg_list = 55,                         // arg_list
        S_arg_list_items = 56,                   // arg_list_items
        S_arg = 57,                              // arg
        S_ret_list = 58,                         // ret_list
        S_ret_list_items = 59,                   // ret_list_items
        S_ret_item = 60,                         // ret_item
        S_cell_set = 61,                         // cell_set
        S_cell_decl_list = 62,                   // cell_decl_list
        S_cell_decl = 63,                        // cell_decl
        S_cell_override = 64,                    // cell_override
        S_if_else = 65,                          // if_else
        S_if_arm_list = 66,                      // if_arm_list
        S_if_arm = 67,                           // if_arm
        S_while_loop = 68,                       // while_loop
        S_cguard = 69,                           // cguard
        S_size_spec = 70,                        // size_spec
        S_statement = 71,                        // statement
        S_reg_dec = 72,                          // reg_dec
        S_var_dec = 73,                          // var_dec
        S_chain = 74,                            // chain
        S_hop_list = 75,                         // hop_list
        S_hop = 76,                              // hop
        S_expr = 77,                             // expr
        S_cat = 78,                              // cat
        S_braccess = 79,                         // braccess
        S_slice_dir = 80,                        // slice_dir
        S_opt_rnum = 81,                         // opt_rnum
        S_rnum = 82,                             // rnum
        S_mem_op = 83,                           // mem_op
        S_atom = 84,                             // atom
        S_bus_ref = 85,                          // bus_ref
        S_list = 86,                             // list
        S_expr_list = 87,                        // expr_list
        S_decimal = 88,                          // decimal
        S_char_lit = 89,                         // char_lit
        S_literal = 90,                          // literal
        S_trit_seq = 91,                         // trit_seq
        S_trit = 92                              // trit
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol () YY_NOEXCEPT
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
        , location (std::move (that.location))
      {
        switch (this->kind ())
    {
      case symbol_kind::S_arg_list: // arg_list
      case symbol_kind::S_arg_list_items: // arg_list_items
        value.move< ArgList > (std::move (that.value));
        break;

      case symbol_kind::S_cell_decl_list: // cell_decl_list
        value.move< CellDeclList > (std::move (that.value));
        break;

      case symbol_kind::S_expr: // expr
      case symbol_kind::S_cat: // cat
      case symbol_kind::S_braccess: // braccess
        value.move< ExprId > (std::move (that.value));
        break;

      case symbol_kind::S_expr_list: // expr_list
        value.move< ExprList > (std::move (that.value));
        break;

      case symbol_kind::S_gate_body: // gate_body
        value.move< GateArmList > (std::move (that.value));
        break;

      case symbol_kind::S_hop_list: // hop_list
        value.move< HopList > (std::move (that.value));
        break;

      case symbol_kind::S_if_arm_list: // if_arm_list
        value.move< IfArmList > (std::move (that.value));
        break;

      case symbol_kind::S_program: // program
        value.move< ProgId > (std::move (that.value));
        break;

      case symbol_kind::S_ret_list: // ret_list
      case symbol_kind::S_ret_list_items: // ret_list_items
        value.move< RetList > (std::move (that.value));
        break;

      case symbol_kind::S_scope: // scope
        value.move< ScopeId > (std::move (that.value));
        break;

      case symbol_kind::S_source_segment: // source_segment
      case symbol_kind::S_statement: // statement
        value.move< SegId > (std::move (that.value));
        break;

      case symbol_kind::S_source_segment_list: // source_segment_list
        value.move< SegList > (std::move (that.value));
        break;

      case symbol_kind::S_trit_match_list: // trit_match_list
        value.move< TritMatchList > (std::move (that.value));
        break;

      case symbol_kind::S_arg: // arg
        value.move< ast::Arg > (std::move (that.value));
        break;

      case symbol_kind::S_atom: // atom
        value.move< ast::Atom > (std::move (that.value));
        break;

      case symbol_kind::S_bus_ref: // bus_ref
        value.move< ast::BusRef > (std::move (that.value));
        break;

      case symbol_kind::S_cguard: // cguard
        value.move< ast::CGuard > (std::move (that.value));
        break;

      case symbol_kind::S_cell_decl: // cell_decl
        value.move< ast::CellDecl > (std::move (that.value));
        break;

      case symbol_kind::S_cell_override: // cell_override
        value.move< ast::CellOverride > (std::move (that.value));
        break;

      case symbol_kind::S_cell_set: // cell_set
        value.move< ast::CellSet > (std::move (that.value));
        break;

      case symbol_kind::S_chain: // chain
        value.move< ast::Chain > (std::move (that.value));
        break;

      case symbol_kind::S_hop: // hop
        value.move< ast::ChainHop > (std::move (that.value));
        break;

      case symbol_kind::S_char_lit: // char_lit
        value.move< ast::CharLit > (std::move (that.value));
        break;

      case symbol_kind::S_decimal: // decimal
        value.move< ast::Decimal > (std::move (that.value));
        break;

      case symbol_kind::S_func_def: // func_def
        value.move< ast::FuncDef > (std::move (that.value));
        break;

      case symbol_kind::S_gate_arm: // gate_arm
        value.move< ast::GateArm > (std::move (that.value));
        break;

      case symbol_kind::S_gate_def: // gate_def
        value.move< ast::GateDef > (std::move (that.value));
        break;

      case symbol_kind::S_if_arm: // if_arm
        value.move< ast::IfArm > (std::move (that.value));
        break;

      case symbol_kind::S_if_else: // if_else
        value.move< ast::IfElse > (std::move (that.value));
        break;

      case symbol_kind::S_lambda: // lambda
        value.move< ast::Lambda > (std::move (that.value));
        break;

      case symbol_kind::S_list: // list
        value.move< ast::List > (std::move (that.value));
        break;

      case symbol_kind::S_literal: // literal
        value.move< ast::Literal > (std::move (that.value));
        break;

      case symbol_kind::S_mem_op: // mem_op
        value.move< ast::MemOp > (std::move (that.value));
        break;

      case symbol_kind::S_reg_dec: // reg_dec
        value.move< ast::RegDec > (std::move (that.value));
        break;

      case symbol_kind::S_ret_item: // ret_item
        value.move< ast::RetItem > (std::move (that.value));
        break;

      case symbol_kind::S_size_spec: // size_spec
        value.move< ast::SizeSpec > (std::move (that.value));
        break;

      case symbol_kind::S_var_dec: // var_dec
        value.move< ast::VarDec > (std::move (that.value));
        break;

      case symbol_kind::S_while_loop: // while_loop
        value.move< ast::WhileLoop > (std::move (that.value));
        break;

      case symbol_kind::S_trit_match: // trit_match
      case symbol_kind::S_trit: // trit
        value.move< char > (std::move (that.value));
        break;

      case symbol_kind::S_slice_dir: // slice_dir
        value.move< int8_t > (std::move (that.value));
        break;

      case symbol_kind::S_WORD: // WORD
      case symbol_kind::S_NUM: // NUM
      case symbol_kind::S_CHARS: // CHARS
      case symbol_kind::S_opt_rnum: // opt_rnum
      case symbol_kind::S_rnum: // rnum
      case symbol_kind::S_trit_seq: // trit_seq
        value.move< std::string > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructors for typed symbols.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ArgList&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ArgList& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, CellDeclList&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const CellDeclList& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ExprId&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ExprId& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ExprList&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ExprList& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, GateArmList&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const GateArmList& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, HopList&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const HopList& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, IfArmList&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const IfArmList& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ProgId&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ProgId& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, RetList&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const RetList& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ScopeId&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ScopeId& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, SegId&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const SegId& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, SegList&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const SegList& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, TritMatchList&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const TritMatchList& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ast::Arg&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ast::Arg& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ast::Atom&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ast::Atom& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ast::BusRef&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ast::BusRef& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ast::CGuard&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ast::CGuard& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ast::CellDecl&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ast::CellDecl& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ast::CellOverride&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ast::CellOverride& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ast::CellSet&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ast::CellSet& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ast::Chain&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ast::Chain& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ast::ChainHop&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ast::ChainHop& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ast::CharLit&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ast::CharLit& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ast::Decimal&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ast::Decimal& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ast::FuncDef&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ast::FuncDef& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ast::GateArm&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ast::GateArm& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ast::GateDef&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ast::GateDef& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ast::IfArm&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ast::IfArm& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ast::IfElse&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ast::IfElse& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ast::Lambda&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ast::Lambda& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ast::List&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ast::List& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ast::Literal&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ast::Literal& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ast::MemOp&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ast::MemOp& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ast::RegDec&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ast::RegDec& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ast::RetItem&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ast::RetItem& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ast::SizeSpec&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ast::SizeSpec& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ast::VarDec&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ast::VarDec& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ast::WhileLoop&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ast::WhileLoop& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, char&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const char& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, int8_t&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const int8_t& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }



      /// Destroy contents, and record that is empty.
      void clear () YY_NOEXCEPT
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
    {
      case symbol_kind::S_arg_list: // arg_list
      case symbol_kind::S_arg_list_items: // arg_list_items
        value.template destroy< ArgList > ();
        break;

      case symbol_kind::S_cell_decl_list: // cell_decl_list
        value.template destroy< CellDeclList > ();
        break;

      case symbol_kind::S_expr: // expr
      case symbol_kind::S_cat: // cat
      case symbol_kind::S_braccess: // braccess
        value.template destroy< ExprId > ();
        break;

      case symbol_kind::S_expr_list: // expr_list
        value.template destroy< ExprList > ();
        break;

      case symbol_kind::S_gate_body: // gate_body
        value.template destroy< GateArmList > ();
        break;

      case symbol_kind::S_hop_list: // hop_list
        value.template destroy< HopList > ();
        break;

      case symbol_kind::S_if_arm_list: // if_arm_list
        value.template destroy< IfArmList > ();
        break;

      case symbol_kind::S_program: // program
        value.template destroy< ProgId > ();
        break;

      case symbol_kind::S_ret_list: // ret_list
      case symbol_kind::S_ret_list_items: // ret_list_items
        value.template destroy< RetList > ();
        break;

      case symbol_kind::S_scope: // scope
        value.template destroy< ScopeId > ();
        break;

      case symbol_kind::S_source_segment: // source_segment
      case symbol_kind::S_statement: // statement
        value.template destroy< SegId > ();
        break;

      case symbol_kind::S_source_segment_list: // source_segment_list
        value.template destroy< SegList > ();
        break;

      case symbol_kind::S_trit_match_list: // trit_match_list
        value.template destroy< TritMatchList > ();
        break;

      case symbol_kind::S_arg: // arg
        value.template destroy< ast::Arg > ();
        break;

      case symbol_kind::S_atom: // atom
        value.template destroy< ast::Atom > ();
        break;

      case symbol_kind::S_bus_ref: // bus_ref
        value.template destroy< ast::BusRef > ();
        break;

      case symbol_kind::S_cguard: // cguard
        value.template destroy< ast::CGuard > ();
        break;

      case symbol_kind::S_cell_decl: // cell_decl
        value.template destroy< ast::CellDecl > ();
        break;

      case symbol_kind::S_cell_override: // cell_override
        value.template destroy< ast::CellOverride > ();
        break;

      case symbol_kind::S_cell_set: // cell_set
        value.template destroy< ast::CellSet > ();
        break;

      case symbol_kind::S_chain: // chain
        value.template destroy< ast::Chain > ();
        break;

      case symbol_kind::S_hop: // hop
        value.template destroy< ast::ChainHop > ();
        break;

      case symbol_kind::S_char_lit: // char_lit
        value.template destroy< ast::CharLit > ();
        break;

      case symbol_kind::S_decimal: // decimal
        value.template destroy< ast::Decimal > ();
        break;

      case symbol_kind::S_func_def: // func_def
        value.template destroy< ast::FuncDef > ();
        break;

      case symbol_kind::S_gate_arm: // gate_arm
        value.template destroy< ast::GateArm > ();
        break;

      case symbol_kind::S_gate_def: // gate_def
        value.template destroy< ast::GateDef > ();
        break;

      case symbol_kind::S_if_arm: // if_arm
        value.template destroy< ast::IfArm > ();
        break;

      case symbol_kind::S_if_else: // if_else
        value.template destroy< ast::IfElse > ();
        break;

      case symbol_kind::S_lambda: // lambda
        value.template destroy< ast::Lambda > ();
        break;

      case symbol_kind::S_list: // list
        value.template destroy< ast::List > ();
        break;

      case symbol_kind::S_literal: // literal
        value.template destroy< ast::Literal > ();
        break;

      case symbol_kind::S_mem_op: // mem_op
        value.template destroy< ast::MemOp > ();
        break;

      case symbol_kind::S_reg_dec: // reg_dec
        value.template destroy< ast::RegDec > ();
        break;

      case symbol_kind::S_ret_item: // ret_item
        value.template destroy< ast::RetItem > ();
        break;

      case symbol_kind::S_size_spec: // size_spec
        value.template destroy< ast::SizeSpec > ();
        break;

      case symbol_kind::S_var_dec: // var_dec
        value.template destroy< ast::VarDec > ();
        break;

      case symbol_kind::S_while_loop: // while_loop
        value.template destroy< ast::WhileLoop > ();
        break;

      case symbol_kind::S_trit_match: // trit_match
      case symbol_kind::S_trit: // trit
        value.template destroy< char > ();
        break;

      case symbol_kind::S_slice_dir: // slice_dir
        value.template destroy< int8_t > ();
        break;

      case symbol_kind::S_WORD: // WORD
      case symbol_kind::S_NUM: // NUM
      case symbol_kind::S_CHARS: // CHARS
      case symbol_kind::S_opt_rnum: // opt_rnum
      case symbol_kind::S_rnum: // rnum
      case symbol_kind::S_trit_seq: // trit_seq
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// The user-facing name of this symbol.
      const char *name () const YY_NOEXCEPT
      {
        return Parser::symbol_name (this->kind ());
      }

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      value_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Default constructor.
      by_kind () YY_NOEXCEPT;

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that) YY_NOEXCEPT;
#endif

      /// Copy constructor.
      by_kind (const by_kind& that) YY_NOEXCEPT;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t) YY_NOEXCEPT;



      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () YY_NOEXCEPT {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type (token_kind_type (tok), std::move (l))
#else
      symbol_type (int tok, const location_type& l)
        : super_type (token_kind_type (tok), l)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const std::string& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {}
    };

    /// Build a parser object.
    Parser (parser::Driver& driver_yyarg);
    virtual ~Parser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    Parser (const Parser&) = delete;
    /// Non copyable.
    Parser& operator= (const Parser&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static const char *symbol_name (symbol_kind_type yysymbol);

    // Implementation of make_symbol for each token kind.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_END (location_type l)
      {
        return symbol_type (token::END, std::move (l));
      }
#else
      static
      symbol_type
      make_END (const location_type& l)
      {
        return symbol_type (token::END, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYerror (location_type l)
      {
        return symbol_type (token::YYerror, std::move (l));
      }
#else
      static
      symbol_type
      make_YYerror (const location_type& l)
      {
        return symbol_type (token::YYerror, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYUNDEF (location_type l)
      {
        return symbol_type (token::YYUNDEF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYUNDEF (const location_type& l)
      {
        return symbol_type (token::YYUNDEF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WORD (std::string v, location_type l)
      {
        return symbol_type (token::WORD, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_WORD (const std::string& v, const location_type& l)
      {
        return symbol_type (token::WORD, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NUM (std::string v, location_type l)
      {
        return symbol_type (token::NUM, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NUM (const std::string& v, const location_type& l)
      {
        return symbol_type (token::NUM, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CHARS (std::string v, location_type l)
      {
        return symbol_type (token::CHARS, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CHARS (const std::string& v, const location_type& l)
      {
        return symbol_type (token::CHARS, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ZERO (location_type l)
      {
        return symbol_type (token::ZERO, std::move (l));
      }
#else
      static
      symbol_type
      make_ZERO (const location_type& l)
      {
        return symbol_type (token::ZERO, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PLUS (location_type l)
      {
        return symbol_type (token::PLUS, std::move (l));
      }
#else
      static
      symbol_type
      make_PLUS (const location_type& l)
      {
        return symbol_type (token::PLUS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MINUS (location_type l)
      {
        return symbol_type (token::MINUS, std::move (l));
      }
#else
      static
      symbol_type
      make_MINUS (const location_type& l)
      {
        return symbol_type (token::MINUS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ARROW (location_type l)
      {
        return symbol_type (token::ARROW, std::move (l));
      }
#else
      static
      symbol_type
      make_ARROW (const location_type& l)
      {
        return symbol_type (token::ARROW, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LT (location_type l)
      {
        return symbol_type (token::LT, std::move (l));
      }
#else
      static
      symbol_type
      make_LT (const location_type& l)
      {
        return symbol_type (token::LT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GT (location_type l)
      {
        return symbol_type (token::GT, std::move (l));
      }
#else
      static
      symbol_type
      make_GT (const location_type& l)
      {
        return symbol_type (token::GT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STAR (location_type l)
      {
        return symbol_type (token::STAR, std::move (l));
      }
#else
      static
      symbol_type
      make_STAR (const location_type& l)
      {
        return symbol_type (token::STAR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AMP (location_type l)
      {
        return symbol_type (token::AMP, std::move (l));
      }
#else
      static
      symbol_type
      make_AMP (const location_type& l)
      {
        return symbol_type (token::AMP, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PRCNT (location_type l)
      {
        return symbol_type (token::PRCNT, std::move (l));
      }
#else
      static
      symbol_type
      make_PRCNT (const location_type& l)
      {
        return symbol_type (token::PRCNT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LPAREN (location_type l)
      {
        return symbol_type (token::LPAREN, std::move (l));
      }
#else
      static
      symbol_type
      make_LPAREN (const location_type& l)
      {
        return symbol_type (token::LPAREN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RPAREN (location_type l)
      {
        return symbol_type (token::RPAREN, std::move (l));
      }
#else
      static
      symbol_type
      make_RPAREN (const location_type& l)
      {
        return symbol_type (token::RPAREN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LCURL (location_type l)
      {
        return symbol_type (token::LCURL, std::move (l));
      }
#else
      static
      symbol_type
      make_LCURL (const location_type& l)
      {
        return symbol_type (token::LCURL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RCURL (location_type l)
      {
        return symbol_type (token::RCURL, std::move (l));
      }
#else
      static
      symbol_type
      make_RCURL (const location_type& l)
      {
        return symbol_type (token::RCURL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LBRACK (location_type l)
      {
        return symbol_type (token::LBRACK, std::move (l));
      }
#else
      static
      symbol_type
      make_LBRACK (const location_type& l)
      {
        return symbol_type (token::LBRACK, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RBRACK (location_type l)
      {
        return symbol_type (token::RBRACK, std::move (l));
      }
#else
      static
      symbol_type
      make_RBRACK (const location_type& l)
      {
        return symbol_type (token::RBRACK, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PIPE (location_type l)
      {
        return symbol_type (token::PIPE, std::move (l));
      }
#else
      static
      symbol_type
      make_PIPE (const location_type& l)
      {
        return symbol_type (token::PIPE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COLON (location_type l)
      {
        return symbol_type (token::COLON, std::move (l));
      }
#else
      static
      symbol_type
      make_COLON (const location_type& l)
      {
        return symbol_type (token::COLON, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SEMI (location_type l)
      {
        return symbol_type (token::SEMI, std::move (l));
      }
#else
      static
      symbol_type
      make_SEMI (const location_type& l)
      {
        return symbol_type (token::SEMI, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMMA (location_type l)
      {
        return symbol_type (token::COMMA, std::move (l));
      }
#else
      static
      symbol_type
      make_COMMA (const location_type& l)
      {
        return symbol_type (token::COMMA, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_QMARK (location_type l)
      {
        return symbol_type (token::QMARK, std::move (l));
      }
#else
      static
      symbol_type
      make_QMARK (const location_type& l)
      {
        return symbol_type (token::QMARK, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UNDER (location_type l)
      {
        return symbol_type (token::UNDER, std::move (l));
      }
#else
      static
      symbol_type
      make_UNDER (const location_type& l)
      {
        return symbol_type (token::UNDER, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BTICK (location_type l)
      {
        return symbol_type (token::BTICK, std::move (l));
      }
#else
      static
      symbol_type
      make_BTICK (const location_type& l)
      {
        return symbol_type (token::BTICK, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SQUOTE (location_type l)
      {
        return symbol_type (token::SQUOTE, std::move (l));
      }
#else
      static
      symbol_type
      make_SQUOTE (const location_type& l)
      {
        return symbol_type (token::SQUOTE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DQUOTE (location_type l)
      {
        return symbol_type (token::DQUOTE, std::move (l));
      }
#else
      static
      symbol_type
      make_DQUOTE (const location_type& l)
      {
        return symbol_type (token::DQUOTE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SLASH (location_type l)
      {
        return symbol_type (token::SLASH, std::move (l));
      }
#else
      static
      symbol_type
      make_SLASH (const location_type& l)
      {
        return symbol_type (token::SLASH, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQUALS (location_type l)
      {
        return symbol_type (token::EQUALS, std::move (l));
      }
#else
      static
      symbol_type
      make_EQUALS (const location_type& l)
      {
        return symbol_type (token::EQUALS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOLLAR (location_type l)
      {
        return symbol_type (token::DOLLAR, std::move (l));
      }
#else
      static
      symbol_type
      make_DOLLAR (const location_type& l)
      {
        return symbol_type (token::DOLLAR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FUNC (location_type l)
      {
        return symbol_type (token::FUNC, std::move (l));
      }
#else
      static
      symbol_type
      make_FUNC (const location_type& l)
      {
        return symbol_type (token::FUNC, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VAR (location_type l)
      {
        return symbol_type (token::VAR, std::move (l));
      }
#else
      static
      symbol_type
      make_VAR (const location_type& l)
      {
        return symbol_type (token::VAR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_REG (location_type l)
      {
        return symbol_type (token::REG, std::move (l));
      }
#else
      static
      symbol_type
      make_REG (const location_type& l)
      {
        return symbol_type (token::REG, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GATE (location_type l)
      {
        return symbol_type (token::GATE, std::move (l));
      }
#else
      static
      symbol_type
      make_GATE (const location_type& l)
      {
        return symbol_type (token::GATE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IF (location_type l)
      {
        return symbol_type (token::IF, std::move (l));
      }
#else
      static
      symbol_type
      make_IF (const location_type& l)
      {
        return symbol_type (token::IF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELIF (location_type l)
      {
        return symbol_type (token::ELIF, std::move (l));
      }
#else
      static
      symbol_type
      make_ELIF (const location_type& l)
      {
        return symbol_type (token::ELIF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELSE (location_type l)
      {
        return symbol_type (token::ELSE, std::move (l));
      }
#else
      static
      symbol_type
      make_ELSE (const location_type& l)
      {
        return symbol_type (token::ELSE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WHILE (location_type l)
      {
        return symbol_type (token::WHILE, std::move (l));
      }
#else
      static
      symbol_type
      make_WHILE (const location_type& l)
      {
        return symbol_type (token::WHILE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NODE (location_type l)
      {
        return symbol_type (token::NODE, std::move (l));
      }
#else
      static
      symbol_type
      make_NODE (const location_type& l)
      {
        return symbol_type (token::NODE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ERROR (location_type l)
      {
        return symbol_type (token::ERROR, std::move (l));
      }
#else
      static
      symbol_type
      make_ERROR (const location_type& l)
      {
        return symbol_type (token::ERROR, l);
      }
#endif


    class context
    {
    public:
      context (const Parser& yyparser, const symbol_type& yyla);
      const symbol_type& lookahead () const YY_NOEXCEPT { return yyla_; }
      symbol_kind_type token () const YY_NOEXCEPT { return yyla_.kind (); }
      const location_type& location () const YY_NOEXCEPT { return yyla_.location; }

      /// Put in YYARG at most YYARGN of the expected tokens, and return the
      /// number of tokens stored in YYARG.  If YYARG is null, return the
      /// number of expected tokens (guaranteed to be less than YYNTOKENS).
      int expected_tokens (symbol_kind_type yyarg[], int yyargn) const;

    private:
      const Parser& yyparser_;
      const symbol_type& yyla_;
    };

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    Parser (const Parser&);
    /// Non copyable.
    Parser& operator= (const Parser&);
#endif


    /// Stored state numbers (used for stacks).
    typedef unsigned char state_type;

    /// The arguments of the error message.
    int yy_syntax_error_arguments_ (const context& yyctx,
                                    symbol_kind_type yyarg[], int yyargn) const;

    /// Generate an error message.
    /// \param yyctx     the context in which the error occurred.
    virtual std::string yysyntax_error_ (const context& yyctx) const;
    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT;

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT;

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_kind_type enum.
    static symbol_kind_type yytranslate_ (int t) YY_NOEXCEPT;



    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const signed char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const short yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const unsigned char yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const unsigned char yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
    // state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.
    static const signed char yyr1_[];

    // YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.
    static const signed char yyr2_[];


#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200) YY_NOEXCEPT
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range) YY_NOEXCEPT
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1) YY_NOEXCEPT;

    /// Constants.
    enum
    {
      yylast_ = 296,     ///< Last index in yytable_.
      yynnts_ = 50,  ///< Number of nonterminal symbols.
      yyfinal_ = 3 ///< Termination state number.
    };


    // User arguments.
    parser::Driver& driver;

  };

  Parser::symbol_kind_type
  Parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42
    };
    // Last valid token kind.
    const int code_max = 297;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

  // basic_symbol.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_arg_list: // arg_list
      case symbol_kind::S_arg_list_items: // arg_list_items
        value.copy< ArgList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_cell_decl_list: // cell_decl_list
        value.copy< CellDeclList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr: // expr
      case symbol_kind::S_cat: // cat
      case symbol_kind::S_braccess: // braccess
        value.copy< ExprId > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_list: // expr_list
        value.copy< ExprList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_gate_body: // gate_body
        value.copy< GateArmList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_hop_list: // hop_list
        value.copy< HopList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_if_arm_list: // if_arm_list
        value.copy< IfArmList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_program: // program
        value.copy< ProgId > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ret_list: // ret_list
      case symbol_kind::S_ret_list_items: // ret_list_items
        value.copy< RetList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_scope: // scope
        value.copy< ScopeId > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_source_segment: // source_segment
      case symbol_kind::S_statement: // statement
        value.copy< SegId > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_source_segment_list: // source_segment_list
        value.copy< SegList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_trit_match_list: // trit_match_list
        value.copy< TritMatchList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_arg: // arg
        value.copy< ast::Arg > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_atom: // atom
        value.copy< ast::Atom > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_bus_ref: // bus_ref
        value.copy< ast::BusRef > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_cguard: // cguard
        value.copy< ast::CGuard > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_cell_decl: // cell_decl
        value.copy< ast::CellDecl > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_cell_override: // cell_override
        value.copy< ast::CellOverride > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_cell_set: // cell_set
        value.copy< ast::CellSet > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_chain: // chain
        value.copy< ast::Chain > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_hop: // hop
        value.copy< ast::ChainHop > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_char_lit: // char_lit
        value.copy< ast::CharLit > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_decimal: // decimal
        value.copy< ast::Decimal > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_func_def: // func_def
        value.copy< ast::FuncDef > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_gate_arm: // gate_arm
        value.copy< ast::GateArm > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_gate_def: // gate_def
        value.copy< ast::GateDef > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_if_arm: // if_arm
        value.copy< ast::IfArm > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_if_else: // if_else
        value.copy< ast::IfElse > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_lambda: // lambda
        value.copy< ast::Lambda > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_list: // list
        value.copy< ast::List > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_literal: // literal
        value.copy< ast::Literal > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_mem_op: // mem_op
        value.copy< ast::MemOp > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_reg_dec: // reg_dec
        value.copy< ast::RegDec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ret_item: // ret_item
        value.copy< ast::RetItem > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_size_spec: // size_spec
        value.copy< ast::SizeSpec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_var_dec: // var_dec
        value.copy< ast::VarDec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_while_loop: // while_loop
        value.copy< ast::WhileLoop > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_trit_match: // trit_match
      case symbol_kind::S_trit: // trit
        value.copy< char > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_slice_dir: // slice_dir
        value.copy< int8_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_WORD: // WORD
      case symbol_kind::S_NUM: // NUM
      case symbol_kind::S_CHARS: // CHARS
      case symbol_kind::S_opt_rnum: // opt_rnum
      case symbol_kind::S_rnum: // rnum
      case symbol_kind::S_trit_seq: // trit_seq
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  Parser::symbol_kind_type
  Parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_arg_list: // arg_list
      case symbol_kind::S_arg_list_items: // arg_list_items
        value.move< ArgList > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_cell_decl_list: // cell_decl_list
        value.move< CellDeclList > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_expr: // expr
      case symbol_kind::S_cat: // cat
      case symbol_kind::S_braccess: // braccess
        value.move< ExprId > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_expr_list: // expr_list
        value.move< ExprList > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_gate_body: // gate_body
        value.move< GateArmList > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_hop_list: // hop_list
        value.move< HopList > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_if_arm_list: // if_arm_list
        value.move< IfArmList > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_program: // program
        value.move< ProgId > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ret_list: // ret_list
      case symbol_kind::S_ret_list_items: // ret_list_items
        value.move< RetList > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_scope: // scope
        value.move< ScopeId > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_source_segment: // source_segment
      case symbol_kind::S_statement: // statement
        value.move< SegId > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_source_segment_list: // source_segment_list
        value.move< SegList > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_trit_match_list: // trit_match_list
        value.move< TritMatchList > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_arg: // arg
        value.move< ast::Arg > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_atom: // atom
        value.move< ast::Atom > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_bus_ref: // bus_ref
        value.move< ast::BusRef > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_cguard: // cguard
        value.move< ast::CGuard > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_cell_decl: // cell_decl
        value.move< ast::CellDecl > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_cell_override: // cell_override
        value.move< ast::CellOverride > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_cell_set: // cell_set
        value.move< ast::CellSet > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_chain: // chain
        value.move< ast::Chain > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_hop: // hop
        value.move< ast::ChainHop > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_char_lit: // char_lit
        value.move< ast::CharLit > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_decimal: // decimal
        value.move< ast::Decimal > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_func_def: // func_def
        value.move< ast::FuncDef > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_gate_arm: // gate_arm
        value.move< ast::GateArm > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_gate_def: // gate_def
        value.move< ast::GateDef > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_if_arm: // if_arm
        value.move< ast::IfArm > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_if_else: // if_else
        value.move< ast::IfElse > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_lambda: // lambda
        value.move< ast::Lambda > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_list: // list
        value.move< ast::List > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_literal: // literal
        value.move< ast::Literal > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_mem_op: // mem_op
        value.move< ast::MemOp > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_reg_dec: // reg_dec
        value.move< ast::RegDec > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ret_item: // ret_item
        value.move< ast::RetItem > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_size_spec: // size_spec
        value.move< ast::SizeSpec > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_var_dec: // var_dec
        value.move< ast::VarDec > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_while_loop: // while_loop
        value.move< ast::WhileLoop > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_trit_match: // trit_match
      case symbol_kind::S_trit: // trit
        value.move< char > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_slice_dir: // slice_dir
        value.move< int8_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_WORD: // WORD
      case symbol_kind::S_NUM: // NUM
      case symbol_kind::S_CHARS: // CHARS
      case symbol_kind::S_opt_rnum: // opt_rnum
      case symbol_kind::S_rnum: // rnum
      case symbol_kind::S_trit_seq: // trit_seq
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  Parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  Parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  Parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  Parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  Parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  Parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  Parser::symbol_kind_type
  Parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  Parser::symbol_kind_type
  Parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


#line 2 "src/grammar/parser.y"
} // parser
#line 3617 "parser.tab.cc"






// Unqualified %code blocks.
#line 40 "src/grammar/parser.y"

  parser::Parser::symbol_type yylex(parser::Driver& driver);

  static inline ast::Span sp(parser::Driver& d, const parser::location& l) {
    return d.span_from(l);
  }

  static inline uint32_t to_u32(const std::string& s) {
    return static_cast<uint32_t>(std::stoul(s));
  }

  static inline size_t to_st(const std::string& s) {
    return static_cast<size_t>(std::stoull(s));
  }

  static inline int64_t to_i64(const std::string& s) {
    return static_cast<int64_t>(std::stoll(s));
  }

  static inline ast::Trit to_trit(char c) {
    if (c == '+') return ast::Trit::Plus;
    if (c == '-') return ast::Trit::Minus;
    return ast::Trit::Zero;
  }

  static inline ast::TritMatch to_trit_match(char c) {
    if (c == '+') return ast::TritMatch::Plus;
    if (c == '-') return ast::TritMatch::Minus;
    if (c == '0') return ast::TritMatch::Zero;
    return ast::TritMatch::Wild;
  }

#line 3658 "parser.tab.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 2 "src/grammar/parser.y"
namespace parser {
#line 3751 "parser.tab.cc"

  /// Build a parser object.
  Parser::Parser (parser::Driver& driver_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      driver (driver_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_kind_type
  Parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_arg_list: // arg_list
      case symbol_kind::S_arg_list_items: // arg_list_items
        value.YY_MOVE_OR_COPY< ArgList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_cell_decl_list: // cell_decl_list
        value.YY_MOVE_OR_COPY< CellDeclList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr: // expr
      case symbol_kind::S_cat: // cat
      case symbol_kind::S_braccess: // braccess
        value.YY_MOVE_OR_COPY< ExprId > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_list: // expr_list
        value.YY_MOVE_OR_COPY< ExprList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_gate_body: // gate_body
        value.YY_MOVE_OR_COPY< GateArmList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_hop_list: // hop_list
        value.YY_MOVE_OR_COPY< HopList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_if_arm_list: // if_arm_list
        value.YY_MOVE_OR_COPY< IfArmList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_program: // program
        value.YY_MOVE_OR_COPY< ProgId > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ret_list: // ret_list
      case symbol_kind::S_ret_list_items: // ret_list_items
        value.YY_MOVE_OR_COPY< RetList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_scope: // scope
        value.YY_MOVE_OR_COPY< ScopeId > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_source_segment: // source_segment
      case symbol_kind::S_statement: // statement
        value.YY_MOVE_OR_COPY< SegId > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_source_segment_list: // source_segment_list
        value.YY_MOVE_OR_COPY< SegList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_trit_match_list: // trit_match_list
        value.YY_MOVE_OR_COPY< TritMatchList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_arg: // arg
        value.YY_MOVE_OR_COPY< ast::Arg > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_atom: // atom
        value.YY_MOVE_OR_COPY< ast::Atom > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_bus_ref: // bus_ref
        value.YY_MOVE_OR_COPY< ast::BusRef > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_cguard: // cguard
        value.YY_MOVE_OR_COPY< ast::CGuard > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_cell_decl: // cell_decl
        value.YY_MOVE_OR_COPY< ast::CellDecl > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_cell_override: // cell_override
        value.YY_MOVE_OR_COPY< ast::CellOverride > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_cell_set: // cell_set
        value.YY_MOVE_OR_COPY< ast::CellSet > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_chain: // chain
        value.YY_MOVE_OR_COPY< ast::Chain > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_hop: // hop
        value.YY_MOVE_OR_COPY< ast::ChainHop > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_char_lit: // char_lit
        value.YY_MOVE_OR_COPY< ast::CharLit > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_decimal: // decimal
        value.YY_MOVE_OR_COPY< ast::Decimal > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_func_def: // func_def
        value.YY_MOVE_OR_COPY< ast::FuncDef > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_gate_arm: // gate_arm
        value.YY_MOVE_OR_COPY< ast::GateArm > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_gate_def: // gate_def
        value.YY_MOVE_OR_COPY< ast::GateDef > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_if_arm: // if_arm
        value.YY_MOVE_OR_COPY< ast::IfArm > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_if_else: // if_else
        value.YY_MOVE_OR_COPY< ast::IfElse > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_lambda: // lambda
        value.YY_MOVE_OR_COPY< ast::Lambda > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_list: // list
        value.YY_MOVE_OR_COPY< ast::List > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_literal: // literal
        value.YY_MOVE_OR_COPY< ast::Literal > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_mem_op: // mem_op
        value.YY_MOVE_OR_COPY< ast::MemOp > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_reg_dec: // reg_dec
        value.YY_MOVE_OR_COPY< ast::RegDec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ret_item: // ret_item
        value.YY_MOVE_OR_COPY< ast::RetItem > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_size_spec: // size_spec
        value.YY_MOVE_OR_COPY< ast::SizeSpec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_var_dec: // var_dec
        value.YY_MOVE_OR_COPY< ast::VarDec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_while_loop: // while_loop
        value.YY_MOVE_OR_COPY< ast::WhileLoop > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_trit_match: // trit_match
      case symbol_kind::S_trit: // trit
        value.YY_MOVE_OR_COPY< char > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_slice_dir: // slice_dir
        value.YY_MOVE_OR_COPY< int8_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_WORD: // WORD
      case symbol_kind::S_NUM: // NUM
      case symbol_kind::S_CHARS: // CHARS
      case symbol_kind::S_opt_rnum: // opt_rnum
      case symbol_kind::S_rnum: // rnum
      case symbol_kind::S_trit_seq: // trit_seq
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_arg_list: // arg_list
      case symbol_kind::S_arg_list_items: // arg_list_items
        value.move< ArgList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_cell_decl_list: // cell_decl_list
        value.move< CellDeclList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr: // expr
      case symbol_kind::S_cat: // cat
      case symbol_kind::S_braccess: // braccess
        value.move< ExprId > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_list: // expr_list
        value.move< ExprList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_gate_body: // gate_body
        value.move< GateArmList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_hop_list: // hop_list
        value.move< HopList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_if_arm_list: // if_arm_list
        value.move< IfArmList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_program: // program
        value.move< ProgId > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ret_list: // ret_list
      case symbol_kind::S_ret_list_items: // ret_list_items
        value.move< RetList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_scope: // scope
        value.move< ScopeId > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_source_segment: // source_segment
      case symbol_kind::S_statement: // statement
        value.move< SegId > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_source_segment_list: // source_segment_list
        value.move< SegList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_trit_match_list: // trit_match_list
        value.move< TritMatchList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_arg: // arg
        value.move< ast::Arg > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_atom: // atom
        value.move< ast::Atom > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_bus_ref: // bus_ref
        value.move< ast::BusRef > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_cguard: // cguard
        value.move< ast::CGuard > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_cell_decl: // cell_decl
        value.move< ast::CellDecl > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_cell_override: // cell_override
        value.move< ast::CellOverride > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_cell_set: // cell_set
        value.move< ast::CellSet > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_chain: // chain
        value.move< ast::Chain > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_hop: // hop
        value.move< ast::ChainHop > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_char_lit: // char_lit
        value.move< ast::CharLit > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_decimal: // decimal
        value.move< ast::Decimal > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_func_def: // func_def
        value.move< ast::FuncDef > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_gate_arm: // gate_arm
        value.move< ast::GateArm > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_gate_def: // gate_def
        value.move< ast::GateDef > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_if_arm: // if_arm
        value.move< ast::IfArm > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_if_else: // if_else
        value.move< ast::IfElse > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_lambda: // lambda
        value.move< ast::Lambda > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_list: // list
        value.move< ast::List > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_literal: // literal
        value.move< ast::Literal > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_mem_op: // mem_op
        value.move< ast::MemOp > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_reg_dec: // reg_dec
        value.move< ast::RegDec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ret_item: // ret_item
        value.move< ast::RetItem > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_size_spec: // size_spec
        value.move< ast::SizeSpec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_var_dec: // var_dec
        value.move< ast::VarDec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_while_loop: // while_loop
        value.move< ast::WhileLoop > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_trit_match: // trit_match
      case symbol_kind::S_trit: // trit
        value.move< char > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_slice_dir: // slice_dir
        value.move< int8_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_WORD: // WORD
      case symbol_kind::S_NUM: // NUM
      case symbol_kind::S_CHARS: // CHARS
      case symbol_kind::S_opt_rnum: // opt_rnum
      case symbol_kind::S_rnum: // rnum
      case symbol_kind::S_trit_seq: // trit_seq
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_arg_list: // arg_list
      case symbol_kind::S_arg_list_items: // arg_list_items
        value.copy< ArgList > (that.value);
        break;

      case symbol_kind::S_cell_decl_list: // cell_decl_list
        value.copy< CellDeclList > (that.value);
        break;

      case symbol_kind::S_expr: // expr
      case symbol_kind::S_cat: // cat
      case symbol_kind::S_braccess: // braccess
        value.copy< ExprId > (that.value);
        break;

      case symbol_kind::S_expr_list: // expr_list
        value.copy< ExprList > (that.value);
        break;

      case symbol_kind::S_gate_body: // gate_body
        value.copy< GateArmList > (that.value);
        break;

      case symbol_kind::S_hop_list: // hop_list
        value.copy< HopList > (that.value);
        break;

      case symbol_kind::S_if_arm_list: // if_arm_list
        value.copy< IfArmList > (that.value);
        break;

      case symbol_kind::S_program: // program
        value.copy< ProgId > (that.value);
        break;

      case symbol_kind::S_ret_list: // ret_list
      case symbol_kind::S_ret_list_items: // ret_list_items
        value.copy< RetList > (that.value);
        break;

      case symbol_kind::S_scope: // scope
        value.copy< ScopeId > (that.value);
        break;

      case symbol_kind::S_source_segment: // source_segment
      case symbol_kind::S_statement: // statement
        value.copy< SegId > (that.value);
        break;

      case symbol_kind::S_source_segment_list: // source_segment_list
        value.copy< SegList > (that.value);
        break;

      case symbol_kind::S_trit_match_list: // trit_match_list
        value.copy< TritMatchList > (that.value);
        break;

      case symbol_kind::S_arg: // arg
        value.copy< ast::Arg > (that.value);
        break;

      case symbol_kind::S_atom: // atom
        value.copy< ast::Atom > (that.value);
        break;

      case symbol_kind::S_bus_ref: // bus_ref
        value.copy< ast::BusRef > (that.value);
        break;

      case symbol_kind::S_cguard: // cguard
        value.copy< ast::CGuard > (that.value);
        break;

      case symbol_kind::S_cell_decl: // cell_decl
        value.copy< ast::CellDecl > (that.value);
        break;

      case symbol_kind::S_cell_override: // cell_override
        value.copy< ast::CellOverride > (that.value);
        break;

      case symbol_kind::S_cell_set: // cell_set
        value.copy< ast::CellSet > (that.value);
        break;

      case symbol_kind::S_chain: // chain
        value.copy< ast::Chain > (that.value);
        break;

      case symbol_kind::S_hop: // hop
        value.copy< ast::ChainHop > (that.value);
        break;

      case symbol_kind::S_char_lit: // char_lit
        value.copy< ast::CharLit > (that.value);
        break;

      case symbol_kind::S_decimal: // decimal
        value.copy< ast::Decimal > (that.value);
        break;

      case symbol_kind::S_func_def: // func_def
        value.copy< ast::FuncDef > (that.value);
        break;

      case symbol_kind::S_gate_arm: // gate_arm
        value.copy< ast::GateArm > (that.value);
        break;

      case symbol_kind::S_gate_def: // gate_def
        value.copy< ast::GateDef > (that.value);
        break;

      case symbol_kind::S_if_arm: // if_arm
        value.copy< ast::IfArm > (that.value);
        break;

      case symbol_kind::S_if_else: // if_else
        value.copy< ast::IfElse > (that.value);
        break;

      case symbol_kind::S_lambda: // lambda
        value.copy< ast::Lambda > (that.value);
        break;

      case symbol_kind::S_list: // list
        value.copy< ast::List > (that.value);
        break;

      case symbol_kind::S_literal: // literal
        value.copy< ast::Literal > (that.value);
        break;

      case symbol_kind::S_mem_op: // mem_op
        value.copy< ast::MemOp > (that.value);
        break;

      case symbol_kind::S_reg_dec: // reg_dec
        value.copy< ast::RegDec > (that.value);
        break;

      case symbol_kind::S_ret_item: // ret_item
        value.copy< ast::RetItem > (that.value);
        break;

      case symbol_kind::S_size_spec: // size_spec
        value.copy< ast::SizeSpec > (that.value);
        break;

      case symbol_kind::S_var_dec: // var_dec
        value.copy< ast::VarDec > (that.value);
        break;

      case symbol_kind::S_while_loop: // while_loop
        value.copy< ast::WhileLoop > (that.value);
        break;

      case symbol_kind::S_trit_match: // trit_match
      case symbol_kind::S_trit: // trit
        value.copy< char > (that.value);
        break;

      case symbol_kind::S_slice_dir: // slice_dir
        value.copy< int8_t > (that.value);
        break;

      case symbol_kind::S_WORD: // WORD
      case symbol_kind::S_NUM: // NUM
      case symbol_kind::S_CHARS: // CHARS
      case symbol_kind::S_opt_rnum: // opt_rnum
      case symbol_kind::S_rnum: // rnum
      case symbol_kind::S_trit_seq: // trit_seq
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_arg_list: // arg_list
      case symbol_kind::S_arg_list_items: // arg_list_items
        value.move< ArgList > (that.value);
        break;

      case symbol_kind::S_cell_decl_list: // cell_decl_list
        value.move< CellDeclList > (that.value);
        break;

      case symbol_kind::S_expr: // expr
      case symbol_kind::S_cat: // cat
      case symbol_kind::S_braccess: // braccess
        value.move< ExprId > (that.value);
        break;

      case symbol_kind::S_expr_list: // expr_list
        value.move< ExprList > (that.value);
        break;

      case symbol_kind::S_gate_body: // gate_body
        value.move< GateArmList > (that.value);
        break;

      case symbol_kind::S_hop_list: // hop_list
        value.move< HopList > (that.value);
        break;

      case symbol_kind::S_if_arm_list: // if_arm_list
        value.move< IfArmList > (that.value);
        break;

      case symbol_kind::S_program: // program
        value.move< ProgId > (that.value);
        break;

      case symbol_kind::S_ret_list: // ret_list
      case symbol_kind::S_ret_list_items: // ret_list_items
        value.move< RetList > (that.value);
        break;

      case symbol_kind::S_scope: // scope
        value.move< ScopeId > (that.value);
        break;

      case symbol_kind::S_source_segment: // source_segment
      case symbol_kind::S_statement: // statement
        value.move< SegId > (that.value);
        break;

      case symbol_kind::S_source_segment_list: // source_segment_list
        value.move< SegList > (that.value);
        break;

      case symbol_kind::S_trit_match_list: // trit_match_list
        value.move< TritMatchList > (that.value);
        break;

      case symbol_kind::S_arg: // arg
        value.move< ast::Arg > (that.value);
        break;

      case symbol_kind::S_atom: // atom
        value.move< ast::Atom > (that.value);
        break;

      case symbol_kind::S_bus_ref: // bus_ref
        value.move< ast::BusRef > (that.value);
        break;

      case symbol_kind::S_cguard: // cguard
        value.move< ast::CGuard > (that.value);
        break;

      case symbol_kind::S_cell_decl: // cell_decl
        value.move< ast::CellDecl > (that.value);
        break;

      case symbol_kind::S_cell_override: // cell_override
        value.move< ast::CellOverride > (that.value);
        break;

      case symbol_kind::S_cell_set: // cell_set
        value.move< ast::CellSet > (that.value);
        break;

      case symbol_kind::S_chain: // chain
        value.move< ast::Chain > (that.value);
        break;

      case symbol_kind::S_hop: // hop
        value.move< ast::ChainHop > (that.value);
        break;

      case symbol_kind::S_char_lit: // char_lit
        value.move< ast::CharLit > (that.value);
        break;

      case symbol_kind::S_decimal: // decimal
        value.move< ast::Decimal > (that.value);
        break;

      case symbol_kind::S_func_def: // func_def
        value.move< ast::FuncDef > (that.value);
        break;

      case symbol_kind::S_gate_arm: // gate_arm
        value.move< ast::GateArm > (that.value);
        break;

      case symbol_kind::S_gate_def: // gate_def
        value.move< ast::GateDef > (that.value);
        break;

      case symbol_kind::S_if_arm: // if_arm
        value.move< ast::IfArm > (that.value);
        break;

      case symbol_kind::S_if_else: // if_else
        value.move< ast::IfElse > (that.value);
        break;

      case symbol_kind::S_lambda: // lambda
        value.move< ast::Lambda > (that.value);
        break;

      case symbol_kind::S_list: // list
        value.move< ast::List > (that.value);
        break;

      case symbol_kind::S_literal: // literal
        value.move< ast::Literal > (that.value);
        break;

      case symbol_kind::S_mem_op: // mem_op
        value.move< ast::MemOp > (that.value);
        break;

      case symbol_kind::S_reg_dec: // reg_dec
        value.move< ast::RegDec > (that.value);
        break;

      case symbol_kind::S_ret_item: // ret_item
        value.move< ast::RetItem > (that.value);
        break;

      case symbol_kind::S_size_spec: // size_spec
        value.move< ast::SizeSpec > (that.value);
        break;

      case symbol_kind::S_var_dec: // var_dec
        value.move< ast::VarDec > (that.value);
        break;

      case symbol_kind::S_while_loop: // while_loop
        value.move< ast::WhileLoop > (that.value);
        break;

      case symbol_kind::S_trit_match: // trit_match
      case symbol_kind::S_trit: // trit
        value.move< char > (that.value);
        break;

      case symbol_kind::S_slice_dir: // slice_dir
        value.move< int8_t > (that.value);
        break;

      case symbol_kind::S_WORD: // WORD
      case symbol_kind::S_NUM: // NUM
      case symbol_kind::S_CHARS: // CHARS
      case symbol_kind::S_opt_rnum: // opt_rnum
      case symbol_kind::S_rnum: // rnum
      case symbol_kind::S_trit_seq: // trit_seq
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (driver));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_arg_list: // arg_list
      case symbol_kind::S_arg_list_items: // arg_list_items
        yylhs.value.emplace< ArgList > ();
        break;

      case symbol_kind::S_cell_decl_list: // cell_decl_list
        yylhs.value.emplace< CellDeclList > ();
        break;

      case symbol_kind::S_expr: // expr
      case symbol_kind::S_cat: // cat
      case symbol_kind::S_braccess: // braccess
        yylhs.value.emplace< ExprId > ();
        break;

      case symbol_kind::S_expr_list: // expr_list
        yylhs.value.emplace< ExprList > ();
        break;

      case symbol_kind::S_gate_body: // gate_body
        yylhs.value.emplace< GateArmList > ();
        break;

      case symbol_kind::S_hop_list: // hop_list
        yylhs.value.emplace< HopList > ();
        break;

      case symbol_kind::S_if_arm_list: // if_arm_list
        yylhs.value.emplace< IfArmList > ();
        break;

      case symbol_kind::S_program: // program
        yylhs.value.emplace< ProgId > ();
        break;

      case symbol_kind::S_ret_list: // ret_list
      case symbol_kind::S_ret_list_items: // ret_list_items
        yylhs.value.emplace< RetList > ();
        break;

      case symbol_kind::S_scope: // scope
        yylhs.value.emplace< ScopeId > ();
        break;

      case symbol_kind::S_source_segment: // source_segment
      case symbol_kind::S_statement: // statement
        yylhs.value.emplace< SegId > ();
        break;

      case symbol_kind::S_source_segment_list: // source_segment_list
        yylhs.value.emplace< SegList > ();
        break;

      case symbol_kind::S_trit_match_list: // trit_match_list
        yylhs.value.emplace< TritMatchList > ();
        break;

      case symbol_kind::S_arg: // arg
        yylhs.value.emplace< ast::Arg > ();
        break;

      case symbol_kind::S_atom: // atom
        yylhs.value.emplace< ast::Atom > ();
        break;

      case symbol_kind::S_bus_ref: // bus_ref
        yylhs.value.emplace< ast::BusRef > ();
        break;

      case symbol_kind::S_cguard: // cguard
        yylhs.value.emplace< ast::CGuard > ();
        break;

      case symbol_kind::S_cell_decl: // cell_decl
        yylhs.value.emplace< ast::CellDecl > ();
        break;

      case symbol_kind::S_cell_override: // cell_override
        yylhs.value.emplace< ast::CellOverride > ();
        break;

      case symbol_kind::S_cell_set: // cell_set
        yylhs.value.emplace< ast::CellSet > ();
        break;

      case symbol_kind::S_chain: // chain
        yylhs.value.emplace< ast::Chain > ();
        break;

      case symbol_kind::S_hop: // hop
        yylhs.value.emplace< ast::ChainHop > ();
        break;

      case symbol_kind::S_char_lit: // char_lit
        yylhs.value.emplace< ast::CharLit > ();
        break;

      case symbol_kind::S_decimal: // decimal
        yylhs.value.emplace< ast::Decimal > ();
        break;

      case symbol_kind::S_func_def: // func_def
        yylhs.value.emplace< ast::FuncDef > ();
        break;

      case symbol_kind::S_gate_arm: // gate_arm
        yylhs.value.emplace< ast::GateArm > ();
        break;

      case symbol_kind::S_gate_def: // gate_def
        yylhs.value.emplace< ast::GateDef > ();
        break;

      case symbol_kind::S_if_arm: // if_arm
        yylhs.value.emplace< ast::IfArm > ();
        break;

      case symbol_kind::S_if_else: // if_else
        yylhs.value.emplace< ast::IfElse > ();
        break;

      case symbol_kind::S_lambda: // lambda
        yylhs.value.emplace< ast::Lambda > ();
        break;

      case symbol_kind::S_list: // list
        yylhs.value.emplace< ast::List > ();
        break;

      case symbol_kind::S_literal: // literal
        yylhs.value.emplace< ast::Literal > ();
        break;

      case symbol_kind::S_mem_op: // mem_op
        yylhs.value.emplace< ast::MemOp > ();
        break;

      case symbol_kind::S_reg_dec: // reg_dec
        yylhs.value.emplace< ast::RegDec > ();
        break;

      case symbol_kind::S_ret_item: // ret_item
        yylhs.value.emplace< ast::RetItem > ();
        break;

      case symbol_kind::S_size_spec: // size_spec
        yylhs.value.emplace< ast::SizeSpec > ();
        break;

      case symbol_kind::S_var_dec: // var_dec
        yylhs.value.emplace< ast::VarDec > ();
        break;

      case symbol_kind::S_while_loop: // while_loop
        yylhs.value.emplace< ast::WhileLoop > ();
        break;

      case symbol_kind::S_trit_match: // trit_match
      case symbol_kind::S_trit: // trit
        yylhs.value.emplace< char > ();
        break;

      case symbol_kind::S_slice_dir: // slice_dir
        yylhs.value.emplace< int8_t > ();
        break;

      case symbol_kind::S_WORD: // WORD
      case symbol_kind::S_NUM: // NUM
      case symbol_kind::S_CHARS: // CHARS
      case symbol_kind::S_opt_rnum: // opt_rnum
      case symbol_kind::S_rnum: // rnum
      case symbol_kind::S_trit_seq: // trit_seq
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // program: source_segment_list END
#line 183 "src/grammar/parser.y"
    {
      ast::Program p{
        .segments = std::move(yystack_[1].value.as < SegList > ()),
        .sp = sp(driver, yylhs.location),
      };

      auto pid = driver.arena.emplace<ast::Program>(std::move(p));
      driver.set_program(pid);
      yylhs.value.as < ProgId > () = pid;
    }
#line 5029 "parser.tab.cc"
    break;

  case 3: // source_segment_list: %empty
#line 196 "src/grammar/parser.y"
    { yylhs.value.as < SegList > () = SegList{}; }
#line 5035 "parser.tab.cc"
    break;

  case 4: // source_segment_list: source_segment_list source_segment
#line 198 "src/grammar/parser.y"
    {
      yystack_[1].value.as < SegList > ().push_back(yystack_[0].value.as < SegId > ());
      yylhs.value.as < SegList > () = std::move(yystack_[1].value.as < SegList > ());
    }
#line 5044 "parser.tab.cc"
    break;

  case 5: // source_segment: scope
#line 206 "src/grammar/parser.y"
    {
      ast::SourceSegment s{
        .inner = driver.arena.get(yystack_[0].value.as < ScopeId > ()),
        .sp = sp(driver, yylhs.location),
      };
      yylhs.value.as < SegId > () = driver.arena.emplace<ast::SourceSegment>(std::move(s));
    }
#line 5056 "parser.tab.cc"
    break;

  case 6: // source_segment: gate_def
#line 214 "src/grammar/parser.y"
    {
      ast::SourceSegment seg{
        .inner = std::move(yystack_[0].value.as < ast::GateDef > ()),
        .sp = sp(driver, yylhs.location),
      };
      yylhs.value.as < SegId > () = driver.arena.emplace<ast::SourceSegment>(std::move(seg));
    }
#line 5068 "parser.tab.cc"
    break;

  case 7: // source_segment: func_def
#line 222 "src/grammar/parser.y"
    {
      ast::SourceSegment seg{
        .inner = std::move(yystack_[0].value.as < ast::FuncDef > ()),
        .sp = sp(driver, yylhs.location),
      };
      yylhs.value.as < SegId > () = driver.arena.emplace<ast::SourceSegment>(std::move(seg));
    }
#line 5080 "parser.tab.cc"
    break;

  case 8: // source_segment: if_else
#line 230 "src/grammar/parser.y"
    {
      ast::SourceSegment seg{
        .inner = std::move(yystack_[0].value.as < ast::IfElse > ()),
        .sp = sp(driver, yylhs.location),
      };
      yylhs.value.as < SegId > () = driver.arena.emplace<ast::SourceSegment>(std::move(seg));
    }
#line 5092 "parser.tab.cc"
    break;

  case 9: // source_segment: while_loop
#line 238 "src/grammar/parser.y"
    {
      ast::SourceSegment seg{
        .inner = std::move(yystack_[0].value.as < ast::WhileLoop > ()),
        .sp = sp(driver, yylhs.location),
      };
      yylhs.value.as < SegId > () = driver.arena.emplace<ast::SourceSegment>(std::move(seg));
    }
#line 5104 "parser.tab.cc"
    break;

  case 10: // source_segment: statement
#line 245 "src/grammar/parser.y"
              { yylhs.value.as < SegId > () = yystack_[0].value.as < SegId > (); }
#line 5110 "parser.tab.cc"
    break;

  case 11: // scope: "{" source_segment_list "}"
#line 250 "src/grammar/parser.y"
    {
      ast::Scope s{
        .segments = std::move(yystack_[1].value.as < SegList > ()),
        .sp = sp(driver, yylhs.location),
      };
      yylhs.value.as < ScopeId > () = driver.arena.emplace<ast::Scope>(std::move(s));
    }
#line 5122 "parser.tab.cc"
    break;

  case 12: // gate_def: "gate" "(" NUM ")" WORD "{" gate_body "}"
#line 261 "src/grammar/parser.y"
    {
      ast::GateDef g{
        .arity = to_st(yystack_[5].value.as < std::string > ()),
        .name = {
          .text = std::move(yystack_[3].value.as < std::string > ()),
          .sp = sp(driver, yystack_[3].location),
        },
        .arms = std::move(yystack_[1].value.as < GateArmList > ()),
        .sp = sp(driver, yylhs.location),
      };
      yylhs.value.as < ast::GateDef > () = std::move(g);
    }
#line 5139 "parser.tab.cc"
    break;

  case 13: // gate_body: gate_arm
#line 277 "src/grammar/parser.y"
    {
      GateArmList gal{};
      gal.push_back(std::move(yystack_[0].value.as < ast::GateArm > ()));
      yylhs.value.as < GateArmList > () = std::move(gal);
    }
#line 5149 "parser.tab.cc"
    break;

  case 14: // gate_body: gate_body gate_arm
#line 283 "src/grammar/parser.y"
    {
      yystack_[1].value.as < GateArmList > ().push_back(std::move(yystack_[0].value.as < ast::GateArm > ()));
      yylhs.value.as < GateArmList > () = std::move(yystack_[1].value.as < GateArmList > ());
    }
#line 5158 "parser.tab.cc"
    break;

  case 15: // gate_arm: "(" trit_match_list ")" "=>" trit ";"
#line 291 "src/grammar/parser.y"
    {
      ast::GateArm a{
        .pattern = std::move(yystack_[4].value.as < TritMatchList > ()),
        .result = to_trit(yystack_[1].value.as < char > ()),
        .sp = sp(driver, yylhs.location),
      };
      yylhs.value.as < ast::GateArm > () = std::move(a);
    }
#line 5171 "parser.tab.cc"
    break;

  case 16: // trit_match_list: trit_match
#line 303 "src/grammar/parser.y"
    {
      TritMatchList tml{};
      tml.push_back(to_trit_match(yystack_[0].value.as < char > ()));
      yylhs.value.as < TritMatchList > () = std::move(tml);
    }
#line 5181 "parser.tab.cc"
    break;

  case 17: // trit_match_list: trit_match_list "," trit_match
#line 309 "src/grammar/parser.y"
    {
      yystack_[2].value.as < TritMatchList > ().push_back(to_trit_match(yystack_[0].value.as < char > ()));
      yylhs.value.as < TritMatchList > () = std::move(yystack_[2].value.as < TritMatchList > ());
    }
#line 5190 "parser.tab.cc"
    break;

  case 18: // trit_match: trit
#line 316 "src/grammar/parser.y"
         { yylhs.value.as < char > () = yystack_[0].value.as < char > (); }
#line 5196 "parser.tab.cc"
    break;

  case 19: // trit_match: "_"
#line 317 "src/grammar/parser.y"
          { yylhs.value.as < char > () = '_'; }
#line 5202 "parser.tab.cc"
    break;

  case 20: // func_def: "func" arg_list WORD ret_list scope
#line 322 "src/grammar/parser.y"
    {
      ast::FuncDef f{
        .name = {
          .text = std::move(yystack_[2].value.as < std::string > ()),
          .sp = sp(driver, yystack_[2].location),
        },
        .args = std::move(yystack_[3].value.as < ArgList > ()),
        .cells = std::nullopt,
        .rets = std::move(yystack_[1].value.as < RetList > ()),
        .body = yystack_[0].value.as < ScopeId > (),
        .sp = sp(driver, yylhs.location),
      };
      yylhs.value.as < ast::FuncDef > () = std::move(f);
    }
#line 5221 "parser.tab.cc"
    break;

  case 21: // func_def: "func" arg_list cell_set WORD ret_list scope
#line 337 "src/grammar/parser.y"
    {
      ast::FuncDef f{
        .name = {
          .text = std::move(yystack_[2].value.as < std::string > ()),
          .sp = sp(driver, yystack_[2].location),
        },
        .args = std::move(yystack_[4].value.as < ArgList > ()),
        .cells = std::move(yystack_[3].value.as < ast::CellSet > ()),
        .rets = std::move(yystack_[1].value.as < RetList > ()),
        .body = yystack_[0].value.as < ScopeId > (),
        .sp = sp(driver, yylhs.location),
      };
      yylhs.value.as < ast::FuncDef > () = std::move(f);
    }
#line 5240 "parser.tab.cc"
    break;

  case 22: // lambda: "func" arg_list ret_list scope
#line 355 "src/grammar/parser.y"
    {
      ast::Lambda l{
        .args = std::move(yystack_[2].value.as < ArgList > ()),
        .cells = std::nullopt,
        .rets = std::move(yystack_[1].value.as < RetList > ()),
        .body = yystack_[0].value.as < ScopeId > (),
        .sp = sp(driver, yylhs.location),
      };
      yylhs.value.as < ast::Lambda > () = std::move(l);
    }
#line 5255 "parser.tab.cc"
    break;

  case 23: // lambda: "func" arg_list cell_set ret_list scope
#line 366 "src/grammar/parser.y"
    {
      ast::Lambda l{
        .args = std::move(yystack_[3].value.as < ArgList > ()),
        .cells = std::move(yystack_[2].value.as < ast::CellSet > ()),
        .rets = std::move(yystack_[1].value.as < RetList > ()),
        .body = yystack_[0].value.as < ScopeId > (),
        .sp = sp(driver, yylhs.location),
      };
      yylhs.value.as < ast::Lambda > () = std::move(l);
    }
#line 5270 "parser.tab.cc"
    break;

  case 24: // arg_list: "(" ")"
#line 379 "src/grammar/parser.y"
                  { yylhs.value.as < ArgList > () = ArgList{}; }
#line 5276 "parser.tab.cc"
    break;

  case 25: // arg_list: "(" arg_list_items ")"
#line 380 "src/grammar/parser.y"
                                 { yylhs.value.as < ArgList > () = std::move(yystack_[1].value.as < ArgList > ()); }
#line 5282 "parser.tab.cc"
    break;

  case 26: // arg_list_items: arg
#line 385 "src/grammar/parser.y"
    {
      ArgList al{};
      al.push_back(std::move(yystack_[0].value.as < ast::Arg > ()));
      yylhs.value.as < ArgList > () = std::move(al);
    }
#line 5292 "parser.tab.cc"
    break;

  case 27: // arg_list_items: arg_list_items "," arg
#line 391 "src/grammar/parser.y"
    {
      yystack_[2].value.as < ArgList > ().push_back(std::move(yystack_[0].value.as < ast::Arg > ()));
      yylhs.value.as < ArgList > () = std::move(yystack_[2].value.as < ArgList > ());
    }
#line 5301 "parser.tab.cc"
    break;

  case 28: // arg: WORD ":" size_spec
#line 399 "src/grammar/parser.y"
    {
      ast::Arg a{
        .name = {
          .text = std::move(yystack_[2].value.as < std::string > ()),
          .sp = sp(driver, yylhs.location),
        },
        .width = std::move(yystack_[0].value.as < ast::SizeSpec > ()),
        .def = std::nullopt,
        .sp = sp(driver, yylhs.location),
      };
      yylhs.value.as < ast::Arg > () = std::move(a);
    }
#line 5318 "parser.tab.cc"
    break;

  case 29: // arg: WORD ":" size_spec "=" expr
#line 412 "src/grammar/parser.y"
    {
      ast::Arg a{
        .name = {
          .text = std::move(yystack_[4].value.as < std::string > ()),
          .sp = sp(driver, yylhs.location),
        },
        .width = std::move(yystack_[2].value.as < ast::SizeSpec > ()),
        .def = yystack_[0].value.as < ExprId > (),
        .sp = sp(driver, yylhs.location),
      };
      yylhs.value.as < ast::Arg > () = std::move(a);
    }
#line 5335 "parser.tab.cc"
    break;

  case 30: // ret_list: "|" "|"
#line 427 "src/grammar/parser.y"
              { yylhs.value.as < RetList > () = RetList{}; }
#line 5341 "parser.tab.cc"
    break;

  case 31: // ret_list: "|" ret_list_items "|"
#line 428 "src/grammar/parser.y"
                             { yylhs.value.as < RetList > () = std::move(yystack_[1].value.as < RetList > ()); }
#line 5347 "parser.tab.cc"
    break;

  case 32: // ret_list_items: ret_item
#line 433 "src/grammar/parser.y"
    {
      RetList rl{};
      rl.push_back(std::move(yystack_[0].value.as < ast::RetItem > ()));
      yylhs.value.as < RetList > () = std::move(rl);
    }
#line 5357 "parser.tab.cc"
    break;

  case 33: // ret_list_items: ret_list_items "," ret_item
#line 439 "src/grammar/parser.y"
    {
      yystack_[2].value.as < RetList > ().push_back(std::move(yystack_[0].value.as < ast::RetItem > ()));
      yylhs.value.as < RetList > () = std::move(yystack_[2].value.as < RetList > ());
    }
#line 5366 "parser.tab.cc"
    break;

  case 34: // ret_item: WORD ":" size_spec
#line 447 "src/grammar/parser.y"
    {
      ast::RetNamed rn{
        .name = {
          .text = std::move(yystack_[2].value.as < std::string > ()),
          .sp = sp(driver, yystack_[2].location),
        },
        .width = std::move(yystack_[0].value.as < ast::SizeSpec > ()),
        .sp = sp(driver, yylhs.location),
      };
      yylhs.value.as < ast::RetItem > () = ast::RetItem{std::move(rn)};
    }
#line 5382 "parser.tab.cc"
    break;

  case 35: // ret_item: expr
#line 459 "src/grammar/parser.y"
    {
      ast::RetExpr re{
        .expr = yystack_[0].value.as < ExprId > (),
        .sp = sp(driver, yylhs.location),
      };
      yylhs.value.as < ast::RetItem > () = ast::RetItem{std::move(re)};
    }
#line 5394 "parser.tab.cc"
    break;

  case 36: // cell_set: "/" cell_decl_list "/"
#line 470 "src/grammar/parser.y"
    {
      ast::CellSet cs{
        .decls = std::move(yystack_[1].value.as < CellDeclList > ()),
        .sp = sp(driver, yylhs.location),
      };
      yylhs.value.as < ast::CellSet > () = std::move(cs);
    }
#line 5406 "parser.tab.cc"
    break;

  case 37: // cell_decl_list: cell_decl
#line 481 "src/grammar/parser.y"
    {
      CellDeclList cdl{};
      cdl.push_back(std::move(yystack_[0].value.as < ast::CellDecl > ()));
      yylhs.value.as < CellDeclList > () = std::move(cdl);
    }
#line 5416 "parser.tab.cc"
    break;

  case 38: // cell_decl_list: cell_decl_list "," cell_decl
#line 487 "src/grammar/parser.y"
    {
      yystack_[2].value.as < CellDeclList > ().push_back(std::move(yystack_[0].value.as < ast::CellDecl > ()));
      yylhs.value.as < CellDeclList > () = std::move(yystack_[2].value.as < CellDeclList > ());
    }
#line 5425 "parser.tab.cc"
    break;

  case 39: // cell_decl: "&" WORD ":" size_spec
#line 495 "src/grammar/parser.y"
    {
      ast::CellDeclReg r{
        .reg = {
          .text = std::move(yystack_[2].value.as < std::string > ()),
          .sp = sp(driver, yystack_[2].location),
        },
        .width = std::move(yystack_[0].value.as < ast::SizeSpec > ()),
        .sp = sp(driver, yylhs.location),
      };
      yylhs.value.as < ast::CellDecl > () = ast::CellDecl{std::move(r)};
    }
#line 5441 "parser.tab.cc"
    break;

  case 40: // cell_decl: WORD ":" size_spec
#line 507 "src/grammar/parser.y"
    {
      ast::CellDeclCell c{
        .name = {
          .text = std::move(yystack_[2].value.as < std::string > ()),
          .sp = sp(driver, yystack_[2].location),
        },
        .width = std::move(yystack_[0].value.as < ast::SizeSpec > ()),
        .def = std::nullopt,
        .sp = sp(driver, yylhs.location),
      };
      yylhs.value.as < ast::CellDecl > () = ast::CellDecl{std::move(c)};
    }
#line 5458 "parser.tab.cc"
    break;

  case 41: // cell_decl: WORD ":" size_spec "=" expr
#line 520 "src/grammar/parser.y"
    {
      ast::CellDeclCell c{
        .name = {
          .text = std::move(yystack_[4].value.as < std::string > ()),
          .sp = sp(driver, yystack_[4].location),
        },
        .width = std::move(yystack_[2].value.as < ast::SizeSpec > ()),
        .def = yystack_[0].value.as < ExprId > (),
        .sp = sp(driver, yylhs.location),
      };
      yylhs.value.as < ast::CellDecl > () = ast::CellDecl{std::move(c)};
    }
#line 5475 "parser.tab.cc"
    break;

  case 42: // cell_override: "=" "/" expr_list "/" ">"
#line 536 "src/grammar/parser.y"
    {
      ast::CellOverride ov{
        .actuals = std::move(yystack_[2].value.as < ExprList > ()),
        .sp = sp(driver, yylhs.location),
      };
      yylhs.value.as < ast::CellOverride > () = std::move(ov);
    }
#line 5487 "parser.tab.cc"
    break;

  case 43: // if_else: "if" cguard expr scope if_arm_list
#line 590 "src/grammar/parser.y"
    {
      ast::IfElse ie{
        .guard = std::move(yystack_[3].value.as < ast::CGuard > ()),
        .cond = yystack_[2].value.as < ExprId > (),
        .then_scope = yystack_[1].value.as < ScopeId > (),
        .arms = std::move(yystack_[0].value.as < IfArmList > ()),
        .sp = sp(driver, yylhs.location),
      };
      yylhs.value.as < ast::IfElse > () = std::move(ie);
    }
#line 5502 "parser.tab.cc"
    break;

  case 44: // if_else: "if" cguard expr scope
#line 601 "src/grammar/parser.y"
    {
      ast::IfElse ie{
        .guard = std::move(yystack_[2].value.as < ast::CGuard > ()),
        .cond = yystack_[1].value.as < ExprId > (),
        .then_scope = yystack_[0].value.as < ScopeId > (),
        .arms = std::nullopt,
        .sp = sp(driver, yylhs.location),
      };
      yylhs.value.as < ast::IfElse > () = std::move(ie);
    }
#line 5517 "parser.tab.cc"
    break;

  case 45: // if_arm_list: if_arm
#line 615 "src/grammar/parser.y"
    {
      IfArmList ial{};
      ial.push_back(std::move(yystack_[0].value.as < ast::IfArm > ()));
      yylhs.value.as < IfArmList > () = std::move(ial);
    }
#line 5527 "parser.tab.cc"
    break;

  case 46: // if_arm_list: if_arm_list if_arm
#line 621 "src/grammar/parser.y"
    {
      yystack_[1].value.as < IfArmList > ().push_back(std::move(yystack_[0].value.as < ast::IfArm > ()));
      yylhs.value.as < IfArmList > () = std::move(yystack_[1].value.as < IfArmList > ());
    }
#line 5536 "parser.tab.cc"
    break;

  case 47: // if_arm: "elif" cguard expr scope
#line 629 "src/grammar/parser.y"
    {
      ast::IfArm a{
        .kind = ast::IfArm::Kind::Elif,
        .guard = std::move(yystack_[2].value.as < ast::CGuard > ()),
        .cond = yystack_[1].value.as < ExprId > (),
        .scope = yystack_[0].value.as < ScopeId > (),
        .sp = sp(driver, yylhs.location),
      };
      yylhs.value.as < ast::IfArm > () = std::move(a);
    }
#line 5551 "parser.tab.cc"
    break;

  case 48: // if_arm: "else" cguard scope
#line 640 "src/grammar/parser.y"
    {
      ast::IfArm a{
        .kind = ast::IfArm::Kind::Else,
        .guard = std::move(yystack_[1].value.as < ast::CGuard > ()),
        .cond = std::nullopt,
        .scope = yystack_[0].value.as < ScopeId > (),
        .sp = sp(driver, yylhs.location),
      };
      yylhs.value.as < ast::IfArm > () = std::move(a);
    }
#line 5566 "parser.tab.cc"
    break;

  case 49: // while_loop: "while" cguard expr scope
#line 654 "src/grammar/parser.y"
    {
      ast::WhileLoop wl{
        .guard = std::move(yystack_[2].value.as < ast::CGuard > ()),
        .cond = yystack_[1].value.as < ExprId > (),
        .scope = yystack_[0].value.as < ScopeId > (),
        .sp = sp(driver, yylhs.location),
      };
      yylhs.value.as < ast::WhileLoop > () = std::move(wl);
    }
#line 5580 "parser.tab.cc"
    break;

  case 50: // cguard: "<" trit ">"
#line 667 "src/grammar/parser.y"
    {
      ast::CGuard g{
        .a = to_trit(yystack_[1].value.as < char > ()),
        .b = std::nullopt,
        .sp = sp(driver, yylhs.location),
      };
      yylhs.value.as < ast::CGuard > () = std::move(g);
    }
#line 5593 "parser.tab.cc"
    break;

  case 51: // cguard: "<" trit "," trit ">"
#line 676 "src/grammar/parser.y"
    {
      ast::CGuard g{
        .a = to_trit(yystack_[3].value.as < char > ()),
        .b = to_trit(yystack_[1].value.as < char > ()),
        .sp = sp(driver, yylhs.location),
      };
      yylhs.value.as < ast::CGuard > () = std::move(g);
    }
#line 5606 "parser.tab.cc"
    break;

  case 52: // size_spec: NUM
#line 688 "src/grammar/parser.y"
    {
      ast::SizeSpec sz{
        .is_dynamic = false,
        .fixed = to_st(yystack_[0].value.as < std::string > ()),
        .sp = sp(driver, yylhs.location),
      };
      yylhs.value.as < ast::SizeSpec > () = std::move(sz);
    }
#line 5619 "parser.tab.cc"
    break;

  case 53: // size_spec: "?"
#line 697 "src/grammar/parser.y"
    {
      ast::SizeSpec sz{
        .is_dynamic = true,
        .fixed = 0,
        .sp = sp(driver, yylhs.location),
      };
      yylhs.value.as < ast::SizeSpec > () = std::move(sz);
    }
#line 5632 "parser.tab.cc"
    break;

  case 54: // statement: chain ";"
#line 709 "src/grammar/parser.y"
    {
      ast::Statement st{
        .inner = std::move(yystack_[1].value.as < ast::Chain > ()),
        .sp = sp(driver, yylhs.location),
      };

      ast::SourceSegment seg {
        .inner = std::move(st),
        .sp = sp(driver, yylhs.location),
      };

      yylhs.value.as < SegId > () = driver.arena.emplace<ast::SourceSegment>(std::move(seg));
    }
#line 5650 "parser.tab.cc"
    break;

  case 55: // statement: reg_dec ";"
#line 723 "src/grammar/parser.y"
    {
      ast::Statement st{
        .inner = std::move(yystack_[1].value.as < ast::RegDec > ()),
        .sp = sp(driver, yylhs.location),
      };

      ast::SourceSegment seg {
        .inner = std::move(st),
        .sp = sp(driver, yylhs.location),
      };

      yylhs.value.as < SegId > () = driver.arena.emplace<ast::SourceSegment>(std::move(seg));
    }
#line 5668 "parser.tab.cc"
    break;

  case 56: // statement: var_dec ";"
#line 737 "src/grammar/parser.y"
    {
      ast::Statement st{
        .inner = std::move(yystack_[1].value.as < ast::VarDec > ()),
        .sp = sp(driver, yylhs.location),
      };

      ast::SourceSegment seg {
        .inner = std::move(st),
        .sp = sp(driver, yylhs.location),
      };

      yylhs.value.as < SegId > () = driver.arena.emplace<ast::SourceSegment>(std::move(seg));
    }
#line 5686 "parser.tab.cc"
    break;

  case 57: // statement: error ";"
#line 751 "src/grammar/parser.y"
    {
      driver.on_error((int)yystack_[1].location.begin.line, (int)yystack_[1].location.begin.column, "invalid statement");
      yyerrok;

      ast::Statement st{
        .inner = ast::Chain{},
        .sp = sp(driver, yylhs.location),
      };

      ast::SourceSegment seg{
        .inner = std::move(st),
        .sp = sp(driver, yylhs.location),
      };

      yylhs.value.as < SegId > () = driver.arena.emplace<ast::SourceSegment>(std::move(seg));
    }
#line 5707 "parser.tab.cc"
    break;

  case 58: // statement: ERROR ";"
#line 768 "src/grammar/parser.y"
    {
      driver.on_error((int)yystack_[1].location.begin.line, (int)yystack_[1].location.begin.column, "invalid statement");
      yyerrok;

      ast::Statement st{
        .inner = ast::Chain{},
        .sp = sp(driver, yylhs.location),
      };

      ast::SourceSegment seg{
        .inner = std::move(st),
        .sp = sp(driver, yylhs.location),
      };

      yylhs.value.as < SegId > () = driver.arena.emplace<ast::SourceSegment>(std::move(seg));
    }
#line 5728 "parser.tab.cc"
    break;

  case 59: // reg_dec: "reg" WORD ":" NUM
#line 788 "src/grammar/parser.y"
    {
      ast::RegDec r{
        .name = {
          .text = std::move(yystack_[2].value.as < std::string > ()),
          .sp = sp(driver, yystack_[2].location),
        },
        .width = to_st(yystack_[0].value.as < std::string > ()),
        .sp = sp(driver, yylhs.location),
      };

      yylhs.value.as < ast::RegDec > () = std::move(r);
    }
#line 5745 "parser.tab.cc"
    break;

  case 60: // var_dec: "var" WORD ":" size_spec
#line 804 "src/grammar/parser.y"
    {
      ast::VarDec v{
        .name = {
          .text = std::move(yystack_[2].value.as < std::string > ()),
          .sp = sp(driver, yystack_[2].location),
        },
        .width = std::move(yystack_[0].value.as < ast::SizeSpec > ()),
        .sp = sp(driver, yylhs.location),
      };

      yylhs.value.as < ast::VarDec > () = std::move(v);
    }
#line 5762 "parser.tab.cc"
    break;

  case 61: // chain: expr hop_list
#line 819 "src/grammar/parser.y"
    {
      ast::Chain c{
        .start = yystack_[1].value.as < ExprId > (),
        .hops = std::move(yystack_[0].value.as < HopList > ()),
        .sp = sp(driver, yylhs.location),
      };

      yylhs.value.as < ast::Chain > () = std::move(c);
    }
#line 5776 "parser.tab.cc"
    break;

  case 62: // hop_list: hop
#line 832 "src/grammar/parser.y"
    {
      HopList hs{};
      hs.push_back(std::move(yystack_[0].value.as < ast::ChainHop > ()));
      yylhs.value.as < HopList > () = std::move(hs);
    }
#line 5786 "parser.tab.cc"
    break;

  case 63: // hop_list: hop_list hop
#line 838 "src/grammar/parser.y"
    {
      yystack_[1].value.as < HopList > ().push_back(std::move(yystack_[0].value.as < ast::ChainHop > ()));
      yylhs.value.as < HopList > () = std::move(yystack_[1].value.as < HopList > ());
    }
#line 5795 "parser.tab.cc"
    break;

  case 64: // hop: "=>" expr
#line 846 "src/grammar/parser.y"
    {
      ast::ChainHop h{
        .ovrd = std::nullopt,
        .expr = yystack_[0].value.as < ExprId > (),
        .sp = sp(driver, yylhs.location),
      };

      yylhs.value.as < ast::ChainHop > () = std::move(h);
    }
#line 5809 "parser.tab.cc"
    break;

  case 65: // hop: cell_override expr
#line 856 "src/grammar/parser.y"
    {
      ast::ChainHop h{
        .ovrd = std::move(yystack_[1].value.as < ast::CellOverride > ()),
        .expr = yystack_[0].value.as < ExprId > (),
        .sp = sp(driver, yylhs.location),
      };
      yylhs.value.as < ast::ChainHop > () = std::move(h);
    }
#line 5822 "parser.tab.cc"
    break;

  case 66: // hop: "=>" error
#line 865 "src/grammar/parser.y"
    {
      driver.on_error((int)yystack_[0].location.begin.line, (int)yystack_[0].location.begin.column, "invalid chain member");
      yyerrok;

      ast::Literal l{
        .trits = "",
        .sp = sp(driver, yystack_[0].location),
      };
      
      ast::MemOp m{
        .op = ast::MemOpKind::None,
        .atom = ast::Atom{std::move(l)},
        .sp = sp(driver, yystack_[0].location),
      };

      ast::Braccess br{
        .base = std::move(m),
        .slice = std::nullopt,
        .sp = sp(driver, yystack_[0].location),
      };

      ast::Expr e{
        .cat = {
          .left = std::move(br),
          .right = std::nullopt,
          .sp = sp(driver, yystack_[0].location),
        },
        .sp = sp(driver, yystack_[0].location),
      };

      auto eid = driver.arena.emplace<ast::Expr>(std::move(e));

      ast::ChainHop h{
        .ovrd = std::nullopt,
        .expr = eid,
        .sp = sp(driver, yylhs.location),
      };

      yylhs.value.as < ast::ChainHop > () = std::move(h);
    }
#line 5867 "parser.tab.cc"
    break;

  case 67: // expr: cat
#line 908 "src/grammar/parser.y"
        { yylhs.value.as < ExprId > () = yystack_[0].value.as < ExprId > (); }
#line 5873 "parser.tab.cc"
    break;

  case 68: // cat: braccess
#line 912 "src/grammar/parser.y"
             { yylhs.value.as < ExprId > () = yystack_[0].value.as < ExprId > (); }
#line 5879 "parser.tab.cc"
    break;

  case 69: // cat: cat "%" braccess
#line 914 "src/grammar/parser.y"
    {
      const auto& l = driver.arena.get(yystack_[2].value.as < ExprId > ());
      const auto& r = driver.arena.get(yystack_[0].value.as < ExprId > ());

      ast::Expr e{
        .cat = {
          .left = l.cat.left,
          .right = r.cat.left,
          .sp = sp(driver, yylhs.location),
        },
        .sp = sp(driver, yylhs.location),
      };

      yylhs.value.as < ExprId > () = driver.arena.emplace<ast::Expr>(std::move(e));
    }
#line 5899 "parser.tab.cc"
    break;

  case 70: // braccess: mem_op
#line 933 "src/grammar/parser.y"
    {
      ast::Braccess br{
        .base = std::move(yystack_[0].value.as < ast::MemOp > ()),
        .slice = std::nullopt,
        .sp = sp(driver, yylhs.location),
      };

      ast::Expr e{
        .cat = {
          .left = std::move(br),
          .right = std::nullopt,
          .sp = sp(driver, yylhs.location),
        },
        .sp = sp(driver, yylhs.location),
      };

      yylhs.value.as < ExprId > () = driver.arena.emplace<ast::Expr>(std::move(e));
    }
#line 5922 "parser.tab.cc"
    break;

  case 71: // braccess: mem_op "[" opt_rnum slice_dir opt_rnum "]"
#line 952 "src/grammar/parser.y"
    {
      ast::Slice sl{};
      if (!yystack_[3].value.as < std::string > ().empty()) sl.lo = to_i64(yystack_[3].value.as < std::string > ());
      if (!yystack_[1].value.as < std::string > ().empty()) sl.hi = to_i64(yystack_[1].value.as < std::string > ());
      sl.dir = (yystack_[2].value.as < int8_t > () > 0) ? ast::SliceDir::Forward : ast::SliceDir::Backward;
      sl.sp = sp(driver, yylhs.location);

      ast::Braccess br{
        .base = std::move(yystack_[5].value.as < ast::MemOp > ()),
        .slice = std::move(sl),
        .sp = sp(driver, yylhs.location),
      };

      ast::Expr e{
        .cat = {
          .left = std::move(br),
          .right = std::nullopt,
          .sp = sp(driver, yylhs.location),
        },
        .sp = sp(driver, yylhs.location),
      };

      yylhs.value.as < ExprId > () = driver.arena.emplace<ast::Expr>(std::move(e));
    }
#line 5951 "parser.tab.cc"
    break;

  case 72: // slice_dir: ">"
#line 979 "src/grammar/parser.y"
       { yylhs.value.as < int8_t > () = 1; }
#line 5957 "parser.tab.cc"
    break;

  case 73: // slice_dir: "<"
#line 980 "src/grammar/parser.y"
       { yylhs.value.as < int8_t > () = -1; }
#line 5963 "parser.tab.cc"
    break;

  case 74: // opt_rnum: %empty
#line 984 "src/grammar/parser.y"
                { yylhs.value.as < std::string > () = std::string{}; }
#line 5969 "parser.tab.cc"
    break;

  case 75: // opt_rnum: rnum
#line 985 "src/grammar/parser.y"
         { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 5975 "parser.tab.cc"
    break;

  case 76: // opt_rnum: NUM
#line 986 "src/grammar/parser.y"
        { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 5981 "parser.tab.cc"
    break;

  case 77: // rnum: "-" "0" NUM
#line 990 "src/grammar/parser.y"
                   { yylhs.value.as < std::string > () = "-" + std::move(yystack_[0].value.as < std::string > ()); }
#line 5987 "parser.tab.cc"
    break;

  case 78: // rnum: "-" NUM
#line 991 "src/grammar/parser.y"
              { yylhs.value.as < std::string > () = "-" + std::move(yystack_[0].value.as < std::string > ()); }
#line 5993 "parser.tab.cc"
    break;

  case 79: // rnum: "0" NUM
#line 992 "src/grammar/parser.y"
             { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 5999 "parser.tab.cc"
    break;

  case 80: // rnum: "0"
#line 993 "src/grammar/parser.y"
         { yylhs.value.as < std::string > () = "0"; }
#line 6005 "parser.tab.cc"
    break;

  case 81: // mem_op: atom
#line 998 "src/grammar/parser.y"
    {
      ast::MemOp m{
        .op = ast::MemOpKind::None,
        .atom = std::move(yystack_[0].value.as < ast::Atom > ()),
        .sp = sp(driver, yylhs.location),
      };
      yylhs.value.as < ast::MemOp > () = std::move(m);
    }
#line 6018 "parser.tab.cc"
    break;

  case 82: // mem_op: "*" atom
#line 1007 "src/grammar/parser.y"
    {
      ast::MemOp m{
        .op = ast::MemOpKind::WaitForChange,
        .atom = std::move(yystack_[0].value.as < ast::Atom > ()),
        .sp = sp(driver, yylhs.location),
      };
      yylhs.value.as < ast::MemOp > () = std::move(m);
    }
#line 6031 "parser.tab.cc"
    break;

  case 83: // mem_op: "&" atom
#line 1016 "src/grammar/parser.y"
    {
      ast::MemOp m{
        .op = ast::MemOpKind::Direct,
        .atom = std::move(yystack_[0].value.as < ast::Atom > ()),
        .sp = sp(driver, yylhs.location),
      };
      yylhs.value.as < ast::MemOp > () = std::move(m);
    }
#line 6044 "parser.tab.cc"
    break;

  case 84: // atom: "(" expr ")"
#line 1028 "src/grammar/parser.y"
    {
      ast::AtomParen p{
        .expr = yystack_[1].value.as < ExprId > (),
        .sp = sp(driver, yylhs.location),
      };
      yylhs.value.as < ast::Atom > () = ast::Atom{std::move(p)};
    }
#line 6056 "parser.tab.cc"
    break;

  case 85: // atom: list
#line 1035 "src/grammar/parser.y"
         { yylhs.value.as < ast::Atom > () = ast::Atom{std::move(yystack_[0].value.as < ast::List > ())}; }
#line 6062 "parser.tab.cc"
    break;

  case 86: // atom: lambda
#line 1036 "src/grammar/parser.y"
           { yylhs.value.as < ast::Atom > () = ast::Atom{std::move(yystack_[0].value.as < ast::Lambda > ())}; }
#line 6068 "parser.tab.cc"
    break;

  case 87: // atom: bus_ref
#line 1037 "src/grammar/parser.y"
            { yylhs.value.as < ast::Atom > () = ast::Atom{std::move(yystack_[0].value.as < ast::BusRef > ())}; }
#line 6074 "parser.tab.cc"
    break;

  case 88: // atom: WORD
#line 1039 "src/grammar/parser.y"
    {
        ast::Word w{
          .text = std::move(yystack_[0].value.as < std::string > ()),
          .sp = sp(driver, yystack_[0].location),
        };
      yylhs.value.as < ast::Atom > () = ast::Atom{std::move(w)};
    }
#line 6086 "parser.tab.cc"
    break;

  case 89: // atom: char_lit
#line 1046 "src/grammar/parser.y"
             { yylhs.value.as < ast::Atom > () = ast::Atom{std::move(yystack_[0].value.as < ast::CharLit > ())}; }
#line 6092 "parser.tab.cc"
    break;

  case 90: // atom: decimal
#line 1047 "src/grammar/parser.y"
            { yylhs.value.as < ast::Atom > () = ast::Atom{std::move(yystack_[0].value.as < ast::Decimal > ())}; }
#line 6098 "parser.tab.cc"
    break;

  case 91: // atom: literal
#line 1048 "src/grammar/parser.y"
            { yylhs.value.as < ast::Atom > () = ast::Atom{std::move(yystack_[0].value.as < ast::Literal > ())}; }
#line 6104 "parser.tab.cc"
    break;

  case 92: // bus_ref: "$" "0"
#line 1053 "src/grammar/parser.y"
    {
      ast::BusRef br{
        .idx = 0,
        .sp = sp(driver, yylhs.location)
      };
      yylhs.value.as < ast::BusRef > () = std::move(br);
    }
#line 6116 "parser.tab.cc"
    break;

  case 93: // bus_ref: "$" NUM
#line 1061 "src/grammar/parser.y"
    {
      ast::BusRef br{
        .idx = to_st(yystack_[0].value.as < std::string > ()),
        .sp = sp(driver, yylhs.location),
      };
      yylhs.value.as < ast::BusRef > () = std::move(br);
    }
#line 6128 "parser.tab.cc"
    break;

  case 94: // list: "|" expr_list "|"
#line 1072 "src/grammar/parser.y"
    {
      ast::List l{
        .elems = std::move(yystack_[1].value.as < ExprList > ()),
        .sp = sp(driver, yylhs.location),
      };
      yylhs.value.as < ast::List > () = std::move(l);
    }
#line 6140 "parser.tab.cc"
    break;

  case 95: // expr_list: expr
#line 1083 "src/grammar/parser.y"
    {
      ExprList xl{};
      xl.push_back(yystack_[0].value.as < ExprId > ());
      yylhs.value.as < ExprList > () = std::move(xl);
    }
#line 6150 "parser.tab.cc"
    break;

  case 96: // expr_list: expr_list "," expr
#line 1089 "src/grammar/parser.y"
    {
      yystack_[2].value.as < ExprList > ().push_back(yystack_[0].value.as < ExprId > ());
      yylhs.value.as < ExprList > () = std::move(yystack_[2].value.as < ExprList > ());
    }
#line 6159 "parser.tab.cc"
    break;

  case 97: // decimal: "`" rnum "`"
#line 1097 "src/grammar/parser.y"
    {
      ast::Decimal d{
        .value = {
          .v = to_i64(yystack_[1].value.as < std::string > ()),
          .sp = sp(driver, yystack_[1].location),
        },
        .sp = sp(driver, yylhs.location),
      };
      yylhs.value.as < ast::Decimal > () = std::move(d);
    }
#line 6174 "parser.tab.cc"
    break;

  case 98: // char_lit: "'" CHARS "'"
#line 1111 "src/grammar/parser.y"
    {
      ast::CharLit cl{
        .chars = std::move(yystack_[1].value.as < std::string > ()),
        .sp = sp(driver, yylhs.location),
      };
      yylhs.value.as < ast::CharLit > () = std::move(cl);
    }
#line 6186 "parser.tab.cc"
    break;

  case 99: // literal: trit_seq
#line 1122 "src/grammar/parser.y"
    {
      ast::Literal l{
        .trits = std::move(yystack_[0].value.as < std::string > ()),
        .sp = sp(driver, yylhs.location),
      };
      yylhs.value.as < ast::Literal > () = std::move(l);
    }
#line 6198 "parser.tab.cc"
    break;

  case 100: // trit_seq: trit
#line 1132 "src/grammar/parser.y"
         { yylhs.value.as < std::string > () = std::string{1, yystack_[0].value.as < char > ()}; }
#line 6204 "parser.tab.cc"
    break;

  case 101: // trit_seq: trit_seq trit
#line 1134 "src/grammar/parser.y"
    {
      yystack_[1].value.as < std::string > ().push_back(yystack_[0].value.as < char > ());
      yylhs.value.as < std::string > () = std::move(yystack_[1].value.as < std::string > ());
    }
#line 6213 "parser.tab.cc"
    break;

  case 102: // trit: "+"
#line 1141 "src/grammar/parser.y"
         { yylhs.value.as < char > () = '+'; }
#line 6219 "parser.tab.cc"
    break;

  case 103: // trit: "0"
#line 1142 "src/grammar/parser.y"
         { yylhs.value.as < char > () = '0'; }
#line 6225 "parser.tab.cc"
    break;

  case 104: // trit: "-"
#line 1143 "src/grammar/parser.y"
          { yylhs.value.as < char > () = '-'; }
#line 6231 "parser.tab.cc"
    break;


#line 6235 "parser.tab.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  const char *
  Parser::symbol_name (symbol_kind_type yysymbol)
  {
    static const char *const yy_sname[] =
    {
    "END", "error", "invalid token", "WORD", "NUM", "CHARS", "0", "+", "-",
  "=>", "<", ">", "*", "&", "%", "(", ")", "{", "}", "[", "]", "|", ":",
  ";", ",", "?", "_", "`", "'", "\"", "/", "=", "$", "func", "var", "reg",
  "gate", "if", "elif", "else", "while", "node", "ERROR", "$accept",
  "program", "source_segment_list", "source_segment", "scope", "gate_def",
  "gate_body", "gate_arm", "trit_match_list", "trit_match", "func_def",
  "lambda", "arg_list", "arg_list_items", "arg", "ret_list",
  "ret_list_items", "ret_item", "cell_set", "cell_decl_list", "cell_decl",
  "cell_override", "if_else", "if_arm_list", "if_arm", "while_loop",
  "cguard", "size_spec", "statement", "reg_dec", "var_dec", "chain",
  "hop_list", "hop", "expr", "cat", "braccess", "slice_dir", "opt_rnum",
  "rnum", "mem_op", "atom", "bus_ref", "list", "expr_list", "decimal",
  "char_lit", "literal", "trit_seq", "trit", YY_NULLPTR
    };
    return yy_sname[yysymbol];
  }



  // Parser::context.
  Parser::context::context (const Parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  Parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  Parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char Parser::yypact_ninf_ = -117;

  const signed char Parser::yytable_ninf_ = -1;

  const short
  Parser::yypact_[] =
  {
    -117,     6,   156,  -117,  -117,   -12,  -117,  -117,  -117,  -117,
      22,    22,   217,  -117,   217,    77,    21,    83,    55,    43,
      88,    62,    76,    76,    70,  -117,  -117,  -117,  -117,  -117,
    -117,  -117,  -117,    71,    84,    87,    -4,    98,  -117,    97,
    -117,  -117,  -117,  -117,  -117,  -117,    74,  -117,  -117,    55,
    -117,  -117,    99,    96,  -117,    38,   114,    86,    92,    93,
    -117,  -117,    31,    10,   100,   103,   116,    74,   217,   217,
    -117,  -117,  -117,  -117,   194,   104,   217,    -4,  -117,   217,
      65,  -117,    -7,  -117,  -117,  -117,   217,  -117,  -117,   122,
    -117,  -117,   105,  -117,    36,  -117,   118,   240,     4,   120,
      15,     8,   131,   127,    34,   120,   120,  -117,  -117,   217,
    -117,  -117,  -117,  -117,    90,  -117,   118,  -117,  -117,     8,
    -117,   141,   120,   123,   217,    54,  -117,  -117,   124,   144,
      18,  -117,  -117,   118,   120,  -117,  -117,  -117,  -117,   145,
    -117,    74,    26,  -117,    33,  -117,  -117,    65,   119,  -117,
    -117,     8,  -117,   263,     8,   130,     4,  -117,   120,  -117,
     132,   142,    76,    76,    26,  -117,   147,   140,   217,  -117,
    -117,   134,     8,  -117,  -117,   146,  -117,   217,   120,  -117,
    -117,  -117,  -117,   217,  -117,    13,    61,  -117,   120,  -117,
    -117,  -117,    37,  -117,  -117,  -117,  -117,  -117,   158,    13,
      74,  -117,   149,  -117
  };

  const signed char
  Parser::yydefact_[] =
  {
       3,     0,     0,     1,     2,     0,    88,   103,   102,   104,
       0,     0,     0,     3,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     4,     5,     6,     7,    86,
       8,     9,    10,     0,     0,     0,     0,    67,    68,    70,
      81,    87,    85,    90,    89,    91,    99,   100,    57,     0,
      82,    83,     0,     0,    95,     0,    80,     0,     0,     0,
      93,    92,     0,     0,     0,     0,     0,     0,     0,     0,
      58,    55,    56,    54,     0,     0,     0,    61,    62,     0,
      74,   101,     0,    84,    11,    94,     0,    79,    78,     0,
      97,    98,     0,    24,     0,    26,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    66,    64,     0,
      65,    63,    69,    76,     0,    75,     0,    96,    77,     0,
      25,     0,     0,    88,    30,     0,    32,    35,     0,     0,
       0,    37,    22,     0,     0,    52,    53,    60,    59,     0,
      50,     0,    44,    49,     0,    73,    72,    74,    28,    27,
      20,     0,    31,     0,     0,     0,     0,    36,     0,    23,
       0,     0,     0,     0,    43,    45,     0,     0,     0,    34,
      33,    40,     0,    38,    21,     0,    51,     0,     0,    46,
      42,    71,    29,     0,    39,     0,     0,    13,     0,    48,
      41,    19,     0,    16,    18,    12,    14,    47,     0,     0,
       0,    17,     0,    15
  };

  const short
  Parser::yypgoto_[] =
  {
    -117,  -117,   157,  -117,   -90,  -117,  -117,   -10,  -117,   -25,
    -117,  -117,   129,  -117,    58,   -92,  -117,    27,   112,  -117,
      29,  -117,  -117,  -117,    23,  -117,   -21,  -116,  -117,  -117,
    -117,  -117,  -117,   109,    -2,  -117,   125,  -117,    35,   184,
    -117,    95,  -117,  -117,    94,  -117,  -117,  -117,  -117,   -45
  };

  const unsigned char
  Parser::yydefgoto_[] =
  {
       0,     1,     2,    25,    26,    27,   186,   187,   192,   193,
      28,    29,    63,    94,    95,    99,   125,   126,   100,   130,
     131,    76,    30,   164,   165,    31,    68,   137,    32,    33,
      34,    35,    77,    78,    54,    37,    38,   147,   114,   115,
      39,    40,    41,    42,    55,    43,    44,    45,    46,    47
  };

  const unsigned char
  Parser::yytable_[] =
  {
      36,    81,    69,   148,   122,    74,     3,   128,   134,   132,
      52,    48,   135,    96,    97,   142,   143,   129,   133,     7,
       8,     9,   104,    98,   134,     6,    59,    75,     7,     8,
       9,    97,   150,   136,    92,   169,    97,    12,   171,   191,
      98,   158,   156,    14,   159,   140,    64,    93,   157,    15,
      16,    36,   120,   198,    17,    49,   184,    86,   141,    85,
     121,   199,    86,   166,   162,   163,   105,   106,   174,   113,
      62,    56,   108,    57,   110,   152,   185,    66,   153,   195,
       7,     8,     9,    56,   117,    57,    67,    60,   189,    61,
      88,    65,    89,    70,    71,   127,   161,     5,   197,     6,
     145,   146,     7,     8,     9,    50,    51,    72,    10,    11,
      73,    12,    79,    13,    84,    83,    80,    14,    87,    90,
     103,    91,   101,    15,    16,   102,   118,   119,    17,    18,
      19,    20,    21,    22,   109,   138,    23,    13,    24,    97,
     194,   177,   178,   139,    92,   151,   154,   155,   160,   175,
     168,   127,   172,   176,   194,   202,     4,     5,   180,     6,
     181,   185,     7,     8,     9,   183,   182,   200,    10,    11,
      53,    12,   203,    13,   201,   188,   196,    14,    82,   149,
     170,   190,   167,    15,    16,   173,   111,   179,    17,    18,
      19,    20,    21,    22,   116,   107,    23,     6,    24,    58,
       7,     8,     9,   144,   112,     0,    10,    11,     0,    12,
       0,     0,     0,     0,     0,    14,     0,     0,     0,     0,
       6,    15,    16,     7,     8,     9,    17,    49,     0,    10,
      11,     0,    12,     0,     0,     0,     0,     0,    14,     0,
       0,     0,     0,   123,    15,    16,     7,     8,     9,    17,
      49,     0,    10,    11,     0,    12,     0,     0,     0,     0,
       0,   124,     0,     0,     0,     0,   123,    15,    16,     7,
       8,     9,    17,    49,     0,    10,    11,     0,    12,     0,
       0,     0,     0,     0,    14,     0,     0,     0,     0,     0,
      15,    16,     0,     0,     0,    17,    49
  };

  const short
  Parser::yycheck_[] =
  {
       2,    46,    23,   119,    96,     9,     0,     3,   100,    99,
      12,    23,     4,     3,    21,   105,   106,    13,     3,     6,
       7,     8,    67,    30,   116,     3,     5,    31,     6,     7,
       8,    21,   122,    25,     3,   151,    21,    15,   154,    26,
      30,   133,    24,    21,   134,    11,     3,    16,    30,    27,
      28,    53,    16,    16,    32,    33,   172,    24,    24,    21,
      24,    24,    24,    30,    38,    39,    68,    69,   158,     4,
      15,     6,    74,     8,    76,    21,    15,    15,    24,    18,
       6,     7,     8,     6,    86,     8,    10,     4,   178,     6,
       4,     3,     6,    23,    23,    97,   141,     1,   188,     3,
      10,    11,     6,     7,     8,    10,    11,    23,    12,    13,
      23,    15,    14,    17,    18,    16,    19,    21,     4,    27,
       4,    28,    22,    27,    28,    22,     4,    22,    32,    33,
      34,    35,    36,    37,    30,     4,    40,    17,    42,    21,
     185,   162,   163,    16,     3,    22,    22,     3,     3,    17,
      31,   153,    22,    11,   199,   200,     0,     1,    11,     3,
      20,    15,     6,     7,     8,    31,   168,     9,    12,    13,
      13,    15,    23,    17,   199,   177,   186,    21,    49,   121,
     153,   183,   147,    27,    28,   156,    77,   164,    32,    33,
      34,    35,    36,    37,    82,     1,    40,     3,    42,    15,
       6,     7,     8,   109,    79,    -1,    12,    13,    -1,    15,
      -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,
       3,    27,    28,     6,     7,     8,    32,    33,    -1,    12,
      13,    -1,    15,    -1,    -1,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    -1,     3,    27,    28,     6,     7,     8,    32,
      33,    -1,    12,    13,    -1,    15,    -1,    -1,    -1,    -1,
      -1,    21,    -1,    -1,    -1,    -1,     3,    27,    28,     6,
       7,     8,    32,    33,    -1,    12,    13,    -1,    15,    -1,
      -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,    -1,
      27,    28,    -1,    -1,    -1,    32,    33
  };

  const signed char
  Parser::yystos_[] =
  {
       0,    44,    45,     0,     0,     1,     3,     6,     7,     8,
      12,    13,    15,    17,    21,    27,    28,    32,    33,    34,
      35,    36,    37,    40,    42,    46,    47,    48,    53,    54,
      65,    68,    71,    72,    73,    74,    77,    78,    79,    83,
      84,    85,    86,    88,    89,    90,    91,    92,    23,    33,
      84,    84,    77,    45,    77,    87,     6,     8,    82,     5,
       4,     6,    15,    55,     3,     3,    15,    10,    69,    69,
      23,    23,    23,    23,     9,    31,    64,    75,    76,    14,
      19,    92,    55,    16,    18,    21,    24,     4,     4,     6,
      27,    28,     3,    16,    56,    57,     3,    21,    30,    58,
      61,    22,    22,     4,    92,    77,    77,     1,    77,    30,
      77,    76,    79,     4,    81,    82,    61,    77,     4,    22,
      16,    24,    58,     3,    21,    59,    60,    77,     3,    13,
      62,    63,    47,     3,    58,     4,    25,    70,     4,    16,
      11,    24,    47,    47,    87,    10,    11,    80,    70,    57,
      47,    22,    21,    24,    22,     3,    24,    30,    58,    47,
       3,    92,    38,    39,    66,    67,    30,    81,    31,    70,
      60,    70,    22,    63,    47,    17,    11,    69,    69,    67,
      11,    20,    77,    31,    70,    15,    49,    50,    77,    47,
      77,    26,    51,    52,    92,    18,    50,    47,    16,    24,
       9,    52,    92,    23
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    43,    44,    45,    45,    46,    46,    46,    46,    46,
      46,    47,    48,    49,    49,    50,    51,    51,    52,    52,
      53,    53,    54,    54,    55,    55,    56,    56,    57,    57,
      58,    58,    59,    59,    60,    60,    61,    62,    62,    63,
      63,    63,    64,    65,    65,    66,    66,    67,    67,    68,
      69,    69,    70,    70,    71,    71,    71,    71,    71,    72,
      73,    74,    75,    75,    76,    76,    76,    77,    78,    78,
      79,    79,    80,    80,    81,    81,    81,    82,    82,    82,
      82,    83,    83,    83,    84,    84,    84,    84,    84,    84,
      84,    84,    85,    85,    86,    87,    87,    88,    89,    90,
      91,    91,    92,    92,    92
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     2,     0,     2,     1,     1,     1,     1,     1,
       1,     3,     8,     1,     2,     6,     1,     3,     1,     1,
       5,     6,     4,     5,     2,     3,     1,     3,     3,     5,
       2,     3,     1,     3,     3,     1,     3,     1,     3,     4,
       3,     5,     5,     5,     4,     1,     2,     4,     3,     4,
       3,     5,     1,     1,     2,     2,     2,     2,     2,     4,
       4,     2,     1,     2,     2,     2,     2,     1,     1,     3,
       1,     6,     1,     1,     0,     1,     1,     3,     2,     2,
       1,     1,     2,     2,     3,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     3,     1,     3,     3,     3,     1,
       1,     2,     1,     1,     1
  };




#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,   182,   182,   196,   197,   205,   213,   221,   229,   237,
     245,   249,   260,   276,   282,   290,   302,   308,   316,   317,
     321,   336,   354,   365,   379,   380,   384,   390,   398,   411,
     427,   428,   432,   438,   446,   458,   469,   480,   486,   494,
     506,   519,   535,   589,   600,   614,   620,   628,   639,   653,
     666,   675,   687,   696,   708,   722,   736,   750,   767,   787,
     803,   818,   831,   837,   845,   855,   864,   908,   912,   913,
     932,   951,   979,   980,   984,   985,   986,   990,   991,   992,
     993,   997,  1006,  1015,  1027,  1035,  1036,  1037,  1038,  1046,
    1047,  1048,  1052,  1060,  1071,  1082,  1088,  1096,  1110,  1121,
    1132,  1133,  1141,  1142,  1143
  };

  void
  Parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  Parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


#line 2 "src/grammar/parser.y"
} // parser
#line 6817 "parser.tab.cc"

#line 1146 "src/grammar/parser.y"


void parser::Parser::error(const location_type& loc, const std::string& msg) {
  driver.on_error((int)loc.begin.line, (int)loc.begin.column, msg);
}

