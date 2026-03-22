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
#line 9 "./src/grammar/parser.y"

  #include <memory>
  #include <string>
#include <vector>
  #include <cstdint>
  #include <cstddef>

  #include "parser/ast/nodes.hpp"
  #include "parser/driver.hpp"

  // using ExprId = ast::NodeId<ast::Expr>;
  // using ScopeId = ast::NodeId<ast::Scope>;
  // using SegId = ast::NodeId<ast::SourceSegment>;
  // using ProgId = ast::NodeId<ast::Program>;
  //
  // using SegList = std::vector<SegId>;
  // using HopList = std::vector<ast::ChainHop>;
  // using ExprList = std::vector<ExprId>;
  //
  // using ArgList = std::vector<ast::Arg>;
  // using RetList = std::vector<ast::RetItem>;
  // using CellDeclList = std::vector<ast::CellDecl>;
  // // using CellActualList = std::vector<ast::CellActual>;
  // using GateArmList = std::vector<ast::GateArm>;
  // using TritMatchList = std::vector<ast::TritMatch>;
  // using IfArmList = std::vector<ast::IfArm>;

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

#line 2 "./src/grammar/parser.y"
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
      // bench_def
      char dummy1[sizeof (ast::Bench)];

      // bus
      char dummy2[sizeof (ast::Bus)];

      // chain
      char dummy3[sizeof (ast::Chain)];

      // char_literal
      char dummy4[sizeof (ast::CharLiteral)];

      // decimal_literal
      char dummy5[sizeof (ast::DecimalLiteral)];

      // expr
      char dummy6[sizeof (ast::Expression)];

      // qualified
      char dummy7[sizeof (ast::Qualified)];

      // string_literal
      char dummy8[sizeof (ast::StringLiteral)];

      // trit_match
      // trit
      char dummy9[sizeof (char)];

      // WORD
      // NUM
      char dummy10[sizeof (std::string)];

      // primary
      char dummy11[sizeof (std::variant<std::string, ast::Qualified, ast::Bus, ast::TritLiteral>)];

      // chain_list
      char dummy12[sizeof (std::vector<ast::Chain>)];

      // chain_tail
      // expr_list
      char dummy13[sizeof (std::vector<ast::Expression>)];
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
    INPUT = 260,                   // "input"
    OUTPUT = 261,                  // "output"
    CLOCK = 262,                   // "clock"
    IN = 263,                      // "in"
    OUT = 264,                     // "out"
    GATE = 265,                    // "gate"
    NODE = 266,                    // "node"
    WITH = 267,                    // "with"
    BENCH = 268,                   // "bench"
    ZERO = 269,                    // "0"
    PLUS = 270,                    // "+"
    MINUS = 271,                   // "-"
    UNDER = 272,                   // "_"
    SHIFT = 273,                   // ">>"
    DOT = 274,                     // "."
    LPAREN = 275,                  // "("
    RPAREN = 276,                  // ")"
    LCURL = 277,                   // "{"
    RCURL = 278,                   // "}"
    PIPE = 279,                    // "|"
    SEMI = 280,                    // ";"
    COMMA = 281,                   // ","
    BTICK = 282,                   // "`"
    SQUOTE = 283,                  // "'"
    DQUOTE = 284,                  // "\""
    ERROR = 285                    // ERROR
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
        YYNTOKENS = 31, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // END
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_WORD = 3,                              // WORD
        S_NUM = 4,                               // NUM
        S_INPUT = 5,                             // "input"
        S_OUTPUT = 6,                            // "output"
        S_CLOCK = 7,                             // "clock"
        S_IN = 8,                                // "in"
        S_OUT = 9,                               // "out"
        S_GATE = 10,                             // "gate"
        S_NODE = 11,                             // "node"
        S_WITH = 12,                             // "with"
        S_BENCH = 13,                            // "bench"
        S_ZERO = 14,                             // "0"
        S_PLUS = 15,                             // "+"
        S_MINUS = 16,                            // "-"
        S_UNDER = 17,                            // "_"
        S_SHIFT = 18,                            // ">>"
        S_DOT = 19,                              // "."
        S_LPAREN = 20,                           // "("
        S_RPAREN = 21,                           // ")"
        S_LCURL = 22,                            // "{"
        S_RCURL = 23,                            // "}"
        S_PIPE = 24,                             // "|"
        S_SEMI = 25,                             // ";"
        S_COMMA = 26,                            // ","
        S_BTICK = 27,                            // "`"
        S_SQUOTE = 28,                           // "'"
        S_DQUOTE = 29,                           // "\""
        S_ERROR = 30,                            // ERROR
        S_YYACCEPT = 31,                         // $accept
        S_program = 32,                          // program
        S_item_list = 33,                        // item_list
        S_item = 34,                             // item
        S_input_decl = 35,                       // input_decl
        S_output_decl = 36,                      // output_decl
        S_clock_decl = 37,                       // clock_decl
        S_gate_def = 38,                         // gate_def
        S_gate_arm_list = 39,                    // gate_arm_list
        S_gate_arm = 40,                         // gate_arm
        S_trit_match_list = 41,                  // trit_match_list
        S_trit_match = 42,                       // trit_match
        S_node_def = 43,                         // node_def
        S_port_list = 44,                        // port_list
        S_port = 45,                             // port
        S_opt_with = 46,                         // opt_with
        S_inst_list = 47,                        // inst_list
        S_inst = 48,                             // inst
        S_bench_def = 49,                        // bench_def
        S_chain_list = 50,                       // chain_list
        S_chain = 51,                            // chain
        S_chain_tail = 52,                       // chain_tail
        S_expr = 53,                             // expr
        S_primary = 54,                          // primary
        S_qualified = 55,                        // qualified
        S_bus = 56,                              // bus
        S_expr_list = 57,                        // expr_list
        S_trit = 58,                             // trit
        S_char_literal = 59,                     // char_literal
        S_decimal_literal = 60,                  // decimal_literal
        S_string_literal = 61                    // string_literal
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
      case symbol_kind::S_bench_def: // bench_def
        value.move< ast::Bench > (std::move (that.value));
        break;

      case symbol_kind::S_bus: // bus
        value.move< ast::Bus > (std::move (that.value));
        break;

      case symbol_kind::S_chain: // chain
        value.move< ast::Chain > (std::move (that.value));
        break;

      case symbol_kind::S_char_literal: // char_literal
        value.move< ast::CharLiteral > (std::move (that.value));
        break;

      case symbol_kind::S_decimal_literal: // decimal_literal
        value.move< ast::DecimalLiteral > (std::move (that.value));
        break;

      case symbol_kind::S_expr: // expr
        value.move< ast::Expression > (std::move (that.value));
        break;

      case symbol_kind::S_qualified: // qualified
        value.move< ast::Qualified > (std::move (that.value));
        break;

      case symbol_kind::S_string_literal: // string_literal
        value.move< ast::StringLiteral > (std::move (that.value));
        break;

      case symbol_kind::S_trit_match: // trit_match
      case symbol_kind::S_trit: // trit
        value.move< char > (std::move (that.value));
        break;

      case symbol_kind::S_WORD: // WORD
      case symbol_kind::S_NUM: // NUM
        value.move< std::string > (std::move (that.value));
        break;

      case symbol_kind::S_primary: // primary
        value.move< std::variant<std::string, ast::Qualified, ast::Bus, ast::TritLiteral> > (std::move (that.value));
        break;

      case symbol_kind::S_chain_list: // chain_list
        value.move< std::vector<ast::Chain> > (std::move (that.value));
        break;

      case symbol_kind::S_chain_tail: // chain_tail
      case symbol_kind::S_expr_list: // expr_list
        value.move< std::vector<ast::Expression> > (std::move (that.value));
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
      basic_symbol (typename Base::kind_type t, ast::Bench&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ast::Bench& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ast::Bus&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ast::Bus& v, const location_type& l)
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
      basic_symbol (typename Base::kind_type t, ast::CharLiteral&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ast::CharLiteral& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ast::DecimalLiteral&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ast::DecimalLiteral& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ast::Expression&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ast::Expression& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ast::Qualified&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ast::Qualified& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ast::StringLiteral&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ast::StringLiteral& v, const location_type& l)
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

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::variant<std::string, ast::Qualified, ast::Bus, ast::TritLiteral>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::variant<std::string, ast::Qualified, ast::Bus, ast::TritLiteral>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<ast::Chain>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<ast::Chain>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<ast::Expression>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<ast::Expression>& v, const location_type& l)
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
      case symbol_kind::S_bench_def: // bench_def
        value.template destroy< ast::Bench > ();
        break;

      case symbol_kind::S_bus: // bus
        value.template destroy< ast::Bus > ();
        break;

      case symbol_kind::S_chain: // chain
        value.template destroy< ast::Chain > ();
        break;

      case symbol_kind::S_char_literal: // char_literal
        value.template destroy< ast::CharLiteral > ();
        break;

      case symbol_kind::S_decimal_literal: // decimal_literal
        value.template destroy< ast::DecimalLiteral > ();
        break;

      case symbol_kind::S_expr: // expr
        value.template destroy< ast::Expression > ();
        break;

      case symbol_kind::S_qualified: // qualified
        value.template destroy< ast::Qualified > ();
        break;

      case symbol_kind::S_string_literal: // string_literal
        value.template destroy< ast::StringLiteral > ();
        break;

      case symbol_kind::S_trit_match: // trit_match
      case symbol_kind::S_trit: // trit
        value.template destroy< char > ();
        break;

      case symbol_kind::S_WORD: // WORD
      case symbol_kind::S_NUM: // NUM
        value.template destroy< std::string > ();
        break;

      case symbol_kind::S_primary: // primary
        value.template destroy< std::variant<std::string, ast::Qualified, ast::Bus, ast::TritLiteral> > ();
        break;

      case symbol_kind::S_chain_list: // chain_list
        value.template destroy< std::vector<ast::Chain> > ();
        break;

      case symbol_kind::S_chain_tail: // chain_tail
      case symbol_kind::S_expr_list: // expr_list
        value.template destroy< std::vector<ast::Expression> > ();
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
      make_INPUT (location_type l)
      {
        return symbol_type (token::INPUT, std::move (l));
      }
#else
      static
      symbol_type
      make_INPUT (const location_type& l)
      {
        return symbol_type (token::INPUT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OUTPUT (location_type l)
      {
        return symbol_type (token::OUTPUT, std::move (l));
      }
#else
      static
      symbol_type
      make_OUTPUT (const location_type& l)
      {
        return symbol_type (token::OUTPUT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CLOCK (location_type l)
      {
        return symbol_type (token::CLOCK, std::move (l));
      }
#else
      static
      symbol_type
      make_CLOCK (const location_type& l)
      {
        return symbol_type (token::CLOCK, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IN (location_type l)
      {
        return symbol_type (token::IN, std::move (l));
      }
#else
      static
      symbol_type
      make_IN (const location_type& l)
      {
        return symbol_type (token::IN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OUT (location_type l)
      {
        return symbol_type (token::OUT, std::move (l));
      }
#else
      static
      symbol_type
      make_OUT (const location_type& l)
      {
        return symbol_type (token::OUT, l);
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
      make_WITH (location_type l)
      {
        return symbol_type (token::WITH, std::move (l));
      }
#else
      static
      symbol_type
      make_WITH (const location_type& l)
      {
        return symbol_type (token::WITH, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BENCH (location_type l)
      {
        return symbol_type (token::BENCH, std::move (l));
      }
#else
      static
      symbol_type
      make_BENCH (const location_type& l)
      {
        return symbol_type (token::BENCH, l);
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
      make_SHIFT (location_type l)
      {
        return symbol_type (token::SHIFT, std::move (l));
      }
#else
      static
      symbol_type
      make_SHIFT (const location_type& l)
      {
        return symbol_type (token::SHIFT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOT (location_type l)
      {
        return symbol_type (token::DOT, std::move (l));
      }
#else
      static
      symbol_type
      make_DOT (const location_type& l)
      {
        return symbol_type (token::DOT, l);
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
    typedef signed char state_type;

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
    static const signed char yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const signed char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const signed char yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const signed char yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const signed char yytable_[];

    static const signed char yycheck_[];

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
      yylast_ = 111,     ///< Last index in yytable_.
      yynnts_ = 31,  ///< Number of nonterminal symbols.
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
      25,    26,    27,    28,    29,    30
    };
    // Last valid token kind.
    const int code_max = 285;

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
      case symbol_kind::S_bench_def: // bench_def
        value.copy< ast::Bench > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_bus: // bus
        value.copy< ast::Bus > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_chain: // chain
        value.copy< ast::Chain > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_char_literal: // char_literal
        value.copy< ast::CharLiteral > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_decimal_literal: // decimal_literal
        value.copy< ast::DecimalLiteral > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr: // expr
        value.copy< ast::Expression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_qualified: // qualified
        value.copy< ast::Qualified > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_string_literal: // string_literal
        value.copy< ast::StringLiteral > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_trit_match: // trit_match
      case symbol_kind::S_trit: // trit
        value.copy< char > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_WORD: // WORD
      case symbol_kind::S_NUM: // NUM
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_primary: // primary
        value.copy< std::variant<std::string, ast::Qualified, ast::Bus, ast::TritLiteral> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_chain_list: // chain_list
        value.copy< std::vector<ast::Chain> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_chain_tail: // chain_tail
      case symbol_kind::S_expr_list: // expr_list
        value.copy< std::vector<ast::Expression> > (YY_MOVE (that.value));
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
      case symbol_kind::S_bench_def: // bench_def
        value.move< ast::Bench > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_bus: // bus
        value.move< ast::Bus > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_chain: // chain
        value.move< ast::Chain > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_char_literal: // char_literal
        value.move< ast::CharLiteral > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_decimal_literal: // decimal_literal
        value.move< ast::DecimalLiteral > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_expr: // expr
        value.move< ast::Expression > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_qualified: // qualified
        value.move< ast::Qualified > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_string_literal: // string_literal
        value.move< ast::StringLiteral > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_trit_match: // trit_match
      case symbol_kind::S_trit: // trit
        value.move< char > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_WORD: // WORD
      case symbol_kind::S_NUM: // NUM
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_primary: // primary
        value.move< std::variant<std::string, ast::Qualified, ast::Bus, ast::TritLiteral> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_chain_list: // chain_list
        value.move< std::vector<ast::Chain> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_chain_tail: // chain_tail
      case symbol_kind::S_expr_list: // expr_list
        value.move< std::vector<ast::Expression> > (YY_MOVE (s.value));
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


#line 2 "./src/grammar/parser.y"
} // parser
#line 2429 "parser.tab.cc"






// Unqualified %code blocks.
#line 93 "./src/grammar/parser.y"

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

#line 2457 "parser.tab.cc"


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

#line 2 "./src/grammar/parser.y"
namespace parser {
#line 2550 "parser.tab.cc"

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
      case symbol_kind::S_bench_def: // bench_def
        value.YY_MOVE_OR_COPY< ast::Bench > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_bus: // bus
        value.YY_MOVE_OR_COPY< ast::Bus > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_chain: // chain
        value.YY_MOVE_OR_COPY< ast::Chain > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_char_literal: // char_literal
        value.YY_MOVE_OR_COPY< ast::CharLiteral > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_decimal_literal: // decimal_literal
        value.YY_MOVE_OR_COPY< ast::DecimalLiteral > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr: // expr
        value.YY_MOVE_OR_COPY< ast::Expression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_qualified: // qualified
        value.YY_MOVE_OR_COPY< ast::Qualified > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_string_literal: // string_literal
        value.YY_MOVE_OR_COPY< ast::StringLiteral > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_trit_match: // trit_match
      case symbol_kind::S_trit: // trit
        value.YY_MOVE_OR_COPY< char > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_WORD: // WORD
      case symbol_kind::S_NUM: // NUM
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_primary: // primary
        value.YY_MOVE_OR_COPY< std::variant<std::string, ast::Qualified, ast::Bus, ast::TritLiteral> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_chain_list: // chain_list
        value.YY_MOVE_OR_COPY< std::vector<ast::Chain> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_chain_tail: // chain_tail
      case symbol_kind::S_expr_list: // expr_list
        value.YY_MOVE_OR_COPY< std::vector<ast::Expression> > (YY_MOVE (that.value));
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
      case symbol_kind::S_bench_def: // bench_def
        value.move< ast::Bench > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_bus: // bus
        value.move< ast::Bus > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_chain: // chain
        value.move< ast::Chain > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_char_literal: // char_literal
        value.move< ast::CharLiteral > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_decimal_literal: // decimal_literal
        value.move< ast::DecimalLiteral > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr: // expr
        value.move< ast::Expression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_qualified: // qualified
        value.move< ast::Qualified > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_string_literal: // string_literal
        value.move< ast::StringLiteral > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_trit_match: // trit_match
      case symbol_kind::S_trit: // trit
        value.move< char > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_WORD: // WORD
      case symbol_kind::S_NUM: // NUM
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_primary: // primary
        value.move< std::variant<std::string, ast::Qualified, ast::Bus, ast::TritLiteral> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_chain_list: // chain_list
        value.move< std::vector<ast::Chain> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_chain_tail: // chain_tail
      case symbol_kind::S_expr_list: // expr_list
        value.move< std::vector<ast::Expression> > (YY_MOVE (that.value));
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
      case symbol_kind::S_bench_def: // bench_def
        value.copy< ast::Bench > (that.value);
        break;

      case symbol_kind::S_bus: // bus
        value.copy< ast::Bus > (that.value);
        break;

      case symbol_kind::S_chain: // chain
        value.copy< ast::Chain > (that.value);
        break;

      case symbol_kind::S_char_literal: // char_literal
        value.copy< ast::CharLiteral > (that.value);
        break;

      case symbol_kind::S_decimal_literal: // decimal_literal
        value.copy< ast::DecimalLiteral > (that.value);
        break;

      case symbol_kind::S_expr: // expr
        value.copy< ast::Expression > (that.value);
        break;

      case symbol_kind::S_qualified: // qualified
        value.copy< ast::Qualified > (that.value);
        break;

      case symbol_kind::S_string_literal: // string_literal
        value.copy< ast::StringLiteral > (that.value);
        break;

      case symbol_kind::S_trit_match: // trit_match
      case symbol_kind::S_trit: // trit
        value.copy< char > (that.value);
        break;

      case symbol_kind::S_WORD: // WORD
      case symbol_kind::S_NUM: // NUM
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_primary: // primary
        value.copy< std::variant<std::string, ast::Qualified, ast::Bus, ast::TritLiteral> > (that.value);
        break;

      case symbol_kind::S_chain_list: // chain_list
        value.copy< std::vector<ast::Chain> > (that.value);
        break;

      case symbol_kind::S_chain_tail: // chain_tail
      case symbol_kind::S_expr_list: // expr_list
        value.copy< std::vector<ast::Expression> > (that.value);
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
      case symbol_kind::S_bench_def: // bench_def
        value.move< ast::Bench > (that.value);
        break;

      case symbol_kind::S_bus: // bus
        value.move< ast::Bus > (that.value);
        break;

      case symbol_kind::S_chain: // chain
        value.move< ast::Chain > (that.value);
        break;

      case symbol_kind::S_char_literal: // char_literal
        value.move< ast::CharLiteral > (that.value);
        break;

      case symbol_kind::S_decimal_literal: // decimal_literal
        value.move< ast::DecimalLiteral > (that.value);
        break;

      case symbol_kind::S_expr: // expr
        value.move< ast::Expression > (that.value);
        break;

      case symbol_kind::S_qualified: // qualified
        value.move< ast::Qualified > (that.value);
        break;

      case symbol_kind::S_string_literal: // string_literal
        value.move< ast::StringLiteral > (that.value);
        break;

      case symbol_kind::S_trit_match: // trit_match
      case symbol_kind::S_trit: // trit
        value.move< char > (that.value);
        break;

      case symbol_kind::S_WORD: // WORD
      case symbol_kind::S_NUM: // NUM
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_primary: // primary
        value.move< std::variant<std::string, ast::Qualified, ast::Bus, ast::TritLiteral> > (that.value);
        break;

      case symbol_kind::S_chain_list: // chain_list
        value.move< std::vector<ast::Chain> > (that.value);
        break;

      case symbol_kind::S_chain_tail: // chain_tail
      case symbol_kind::S_expr_list: // expr_list
        value.move< std::vector<ast::Expression> > (that.value);
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
      case symbol_kind::S_bench_def: // bench_def
        yylhs.value.emplace< ast::Bench > ();
        break;

      case symbol_kind::S_bus: // bus
        yylhs.value.emplace< ast::Bus > ();
        break;

      case symbol_kind::S_chain: // chain
        yylhs.value.emplace< ast::Chain > ();
        break;

      case symbol_kind::S_char_literal: // char_literal
        yylhs.value.emplace< ast::CharLiteral > ();
        break;

      case symbol_kind::S_decimal_literal: // decimal_literal
        yylhs.value.emplace< ast::DecimalLiteral > ();
        break;

      case symbol_kind::S_expr: // expr
        yylhs.value.emplace< ast::Expression > ();
        break;

      case symbol_kind::S_qualified: // qualified
        yylhs.value.emplace< ast::Qualified > ();
        break;

      case symbol_kind::S_string_literal: // string_literal
        yylhs.value.emplace< ast::StringLiteral > ();
        break;

      case symbol_kind::S_trit_match: // trit_match
      case symbol_kind::S_trit: // trit
        yylhs.value.emplace< char > ();
        break;

      case symbol_kind::S_WORD: // WORD
      case symbol_kind::S_NUM: // NUM
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_primary: // primary
        yylhs.value.emplace< std::variant<std::string, ast::Qualified, ast::Bus, ast::TritLiteral> > ();
        break;

      case symbol_kind::S_chain_list: // chain_list
        yylhs.value.emplace< std::vector<ast::Chain> > ();
        break;

      case symbol_kind::S_chain_tail: // chain_tail
      case symbol_kind::S_expr_list: // expr_list
        yylhs.value.emplace< std::vector<ast::Expression> > ();
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
  case 20: // trit_match: trit
#line 169 "./src/grammar/parser.y"
         { yylhs.value.as < char > () = std::move(yystack_[0].value.as < char > ()); }
#line 3219 "parser.tab.cc"
    break;

  case 21: // trit_match: "_"
#line 170 "./src/grammar/parser.y"
          { yylhs.value.as < char > () = '_'; }
#line 3225 "parser.tab.cc"
    break;

  case 32: // bench_def: "bench" "(" string_literal ")" "{" chain_list "}"
#line 207 "./src/grammar/parser.y"
    {
      yylhs.value.as < ast::Bench > () = ast::Bench {
        .sp = sp(driver, yylhs.location),
        .name = std::move(yystack_[4].value.as < ast::StringLiteral > ()),
        .con_list = std::move(yystack_[1].value.as < std::vector<ast::Chain> > ()),
      };
    }
#line 3237 "parser.tab.cc"
    break;

  case 33: // chain_list: %empty
#line 218 "./src/grammar/parser.y"
                { yylhs.value.as < std::vector<ast::Chain> > () = {}; }
#line 3243 "parser.tab.cc"
    break;

  case 34: // chain_list: chain_list chain
#line 219 "./src/grammar/parser.y"
                     { yylhs.value.as < std::vector<ast::Chain> > ().push_back(yystack_[0].value.as < ast::Chain > ()); }
#line 3249 "parser.tab.cc"
    break;

  case 35: // chain: expr chain_tail ";"
#line 224 "./src/grammar/parser.y"
    {
      std::vector<ast::Expression> elems { yystack_[2].value.as < ast::Expression > () };
      elems.append_range(yystack_[1].value.as < std::vector<ast::Expression> > ());

      yylhs.value.as < ast::Chain > () = ast::Chain {
        .sp = sp(driver, yylhs.location),
        .elements = std::move(elems),
      };
    }
#line 3263 "parser.tab.cc"
    break;

  case 36: // chain_tail: ">>" expr
#line 236 "./src/grammar/parser.y"
               { yylhs.value.as < std::vector<ast::Expression> > () = std::vector<ast::Expression> { yystack_[0].value.as < ast::Expression > () }; }
#line 3269 "parser.tab.cc"
    break;

  case 37: // chain_tail: chain_tail ">>" expr
#line 237 "./src/grammar/parser.y"
                          { yylhs.value.as < std::vector<ast::Expression> > ().push_back(yystack_[0].value.as < ast::Expression > ()); }
#line 3275 "parser.tab.cc"
    break;

  case 38: // expr: primary
#line 244 "./src/grammar/parser.y"
    {
      yylhs.value.as < ast::Expression > () = ast::Expression {
        .sp = sp(driver, yylhs.location),
        .primary = std::move(yystack_[0].value.as < std::variant<std::string, ast::Qualified, ast::Bus, ast::TritLiteral> > ()),
      };
    }
#line 3286 "parser.tab.cc"
    break;

  case 39: // primary: WORD
#line 253 "./src/grammar/parser.y"
         { yylhs.value.as < std::variant<std::string, ast::Qualified, ast::Bus, ast::TritLiteral> > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 3292 "parser.tab.cc"
    break;

  case 40: // primary: qualified
#line 254 "./src/grammar/parser.y"
              { yylhs.value.as < std::variant<std::string, ast::Qualified, ast::Bus, ast::TritLiteral> > () = std::move(yystack_[0].value.as < ast::Qualified > ()); }
#line 3298 "parser.tab.cc"
    break;

  case 41: // primary: bus
#line 255 "./src/grammar/parser.y"
        { yylhs.value.as < std::variant<std::string, ast::Qualified, ast::Bus, ast::TritLiteral> > () = std::move(yystack_[0].value.as < ast::Bus > ()); }
#line 3304 "parser.tab.cc"
    break;

  case 42: // primary: trit
#line 257 "./src/grammar/parser.y"
    {
      yylhs.value.as < std::variant<std::string, ast::Qualified, ast::Bus, ast::TritLiteral> > () = ast::TritLiteral {
        .sp = sp(driver, yystack_[0].location),
        .trit = ast::char_to_trit(yystack_[0].value.as < char > ()),
      };
    }
#line 3315 "parser.tab.cc"
    break;

  case 43: // qualified: WORD "." WORD
#line 267 "./src/grammar/parser.y"
    {
      yylhs.value.as < ast::Qualified > () = ast::Qualified {
        .sp = sp(driver, yylhs.location),
        .node_name = std::move(yystack_[2].value.as < std::string > ()),
        .property_name = std::move(yystack_[0].value.as < std::string > ()),
      };
    }
#line 3327 "parser.tab.cc"
    break;

  case 44: // bus: "|" expr_list "|"
#line 278 "./src/grammar/parser.y"
    {
      yylhs.value.as < ast::Bus > () = ast::Bus {
        .sp = sp(driver, yylhs.location),
        .expression_list = std::move(yystack_[1].value.as < std::vector<ast::Expression> > ()),
      };
    }
#line 3338 "parser.tab.cc"
    break;

  case 45: // expr_list: expr
#line 288 "./src/grammar/parser.y"
    {
      yylhs.value.as < std::vector<ast::Expression> > () = std::vector<ast::Expression> { yystack_[0].value.as < ast::Expression > () };
    }
#line 3346 "parser.tab.cc"
    break;

  case 46: // expr_list: expr_list "," expr
#line 292 "./src/grammar/parser.y"
    {
      yylhs.value.as < std::vector<ast::Expression> > ().push_back(yystack_[0].value.as < ast::Expression > ());
    }
#line 3354 "parser.tab.cc"
    break;

  case 47: // trit: "+"
#line 298 "./src/grammar/parser.y"
         { yylhs.value.as < char > () = '+'; }
#line 3360 "parser.tab.cc"
    break;

  case 48: // trit: "0"
#line 299 "./src/grammar/parser.y"
         { yylhs.value.as < char > () = '0'; }
#line 3366 "parser.tab.cc"
    break;

  case 49: // trit: "-"
#line 300 "./src/grammar/parser.y"
          { yylhs.value.as < char > () = '-'; }
#line 3372 "parser.tab.cc"
    break;

  case 50: // char_literal: "'" WORD "'"
#line 307 "./src/grammar/parser.y"
    {
      yylhs.value.as < ast::CharLiteral > () = ast::CharLiteral {
        .sp = sp(driver, yylhs.location),
        .c = yystack_[1].value.as < std::string > ()[0],
      };
    }
#line 3383 "parser.tab.cc"
    break;

  case 51: // decimal_literal: "`" NUM "`"
#line 317 "./src/grammar/parser.y"
    {
      yylhs.value.as < ast::DecimalLiteral > () = ast::DecimalLiteral {
        .sp = sp(driver, yylhs.location),
        .dec = to_i64(yystack_[1].value.as < std::string > ()),
      };
    }
#line 3394 "parser.tab.cc"
    break;

  case 52: // decimal_literal: "`" "-" NUM "`"
#line 324 "./src/grammar/parser.y"
    {
      yylhs.value.as < ast::DecimalLiteral > () = ast::DecimalLiteral {
        .sp = sp(driver, yylhs.location),
        .dec = to_i64(yystack_[1].value.as < std::string > ()) * -1,
      };
    }
#line 3405 "parser.tab.cc"
    break;

  case 53: // string_literal: "\"" WORD "\""
#line 334 "./src/grammar/parser.y"
    {
      yylhs.value.as < ast::StringLiteral > () = ast::StringLiteral {
        .sp = sp(driver, yylhs.location),
        .str = std::move(yystack_[1].value.as < std::string > ()),
      };
    }
#line 3416 "parser.tab.cc"
    break;


#line 3420 "parser.tab.cc"

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
    "END", "error", "invalid token", "WORD", "NUM", "input", "output",
  "clock", "in", "out", "gate", "node", "with", "bench", "0", "+", "-",
  "_", ">>", ".", "(", ")", "{", "}", "|", ";", ",", "`", "'", "\"",
  "ERROR", "$accept", "program", "item_list", "item", "input_decl",
  "output_decl", "clock_decl", "gate_def", "gate_arm_list", "gate_arm",
  "trit_match_list", "trit_match", "node_def", "port_list", "port",
  "opt_with", "inst_list", "inst", "bench_def", "chain_list", "chain",
  "chain_tail", "expr", "primary", "qualified", "bus", "expr_list", "trit",
  "char_literal", "decimal_literal", "string_literal", YY_NULLPTR
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


  const signed char Parser::yypact_ninf_ = -78;

  const signed char Parser::yytable_ninf_ = -1;

  const signed char
  Parser::yypact_[] =
  {
     -78,    32,    31,   -78,   -78,   -14,    20,    29,    30,    41,
      44,   -78,   -78,   -78,   -78,   -78,   -78,   -78,    18,    34,
      38,    38,    21,    34,    63,    46,    65,    48,    35,    45,
      49,    69,    70,    22,   -78,    53,    47,    73,    50,    74,
      51,    76,    38,    78,   -78,   -78,    79,    21,    61,   -78,
      59,   -78,    60,   -78,    62,    66,    64,    80,   -78,   -78,
     -78,   -78,   -78,    85,    71,    75,    68,    -2,    72,    39,
     -12,   -78,    90,   -78,    77,   -78,   -78,   -78,   -78,     4,
     -78,    81,   -78,   -78,   -78,   -78,   -78,   -78,    26,   -78,
     -78,   -78,   -78,    91,     6,   -78,     1,    95,   -78,    36,
       4,   -15,    82,    39,   -78,    83,   -78,   -78,   -78,   -78,
       4,   -78,     4,   -78,    43,   -78,   -78,   -78,   -78,    84,
     -78
  };

  const signed char
  Parser::yydefact_[] =
  {
       3,     0,     0,     1,     2,     0,     0,     0,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    23,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    25,    26,     0,     0,     0,    50,
       0,    53,     0,    51,     0,     0,     0,    27,    24,    33,
      11,    12,    52,     0,     0,     0,     0,     0,     0,     0,
       0,    15,     0,    33,    39,    48,    47,    49,    32,     0,
      34,     0,    38,    40,    41,    42,    13,    21,     0,    18,
      20,    14,    16,     0,     0,    29,     0,     0,    45,     0,
       0,     0,     0,     0,    31,     0,    30,    22,    43,    44,
       0,    36,     0,    35,     0,    19,    28,    46,    37,     0,
      17
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,    33,
     -78,    -1,   -78,   -78,    54,   -78,   -78,    11,   -78,    37,
     -78,   -78,   -77,   -78,   -78,   -78,   -78,   -69,   -78,   -16,
      88
  };

  const signed char
  Parser::yydefgoto_[] =
  {
       0,     1,     2,    11,    12,    13,    14,    15,    70,    71,
      88,    89,    16,    33,    34,    66,    94,    95,    17,    67,
      80,   101,    81,    82,    83,    84,    99,    85,    25,    29,
      27
  };

  const signed char
  Parser::yytable_[] =
  {
      90,    74,    98,   112,    74,    30,    18,    74,    69,    93,
     113,    91,    75,    76,    77,    75,    76,    77,    75,    76,
      77,    78,    79,   111,   107,    79,    55,   105,    79,    31,
      32,     4,     3,   117,    90,   118,     5,     6,     7,    40,
      19,     8,     9,    46,    10,   119,    24,   102,    47,    20,
      21,    41,   103,    75,    76,    77,    87,    75,    76,    77,
     109,    22,   110,    26,    23,    28,    36,    37,    38,    39,
      43,    42,    44,    45,    48,    49,    50,    52,    53,    51,
      54,    56,    57,    59,    60,    61,    64,    63,    68,    62,
      73,    69,    65,    93,   104,    72,    97,    86,   108,   100,
     114,    58,   115,    92,   116,   106,     0,     0,     0,   120,
      96,    35
  };

  const signed char
  Parser::yycheck_[] =
  {
      69,     3,    79,    18,     3,    21,    20,     3,    20,     3,
      25,    23,    14,    15,    16,    14,    15,    16,    14,    15,
      16,    23,    24,   100,    23,    24,    42,    21,    24,     8,
       9,     0,     0,   110,   103,   112,     5,     6,     7,     4,
      20,    10,    11,    21,    13,   114,    28,    21,    26,    20,
      20,    16,    26,    14,    15,    16,    17,    14,    15,    16,
      24,    20,    26,    29,    20,    27,     3,    21,     3,    21,
      21,    26,     3,     3,    21,    28,     3,     3,    27,    29,
       4,     3,     3,    22,    25,    25,    22,    21,     3,    27,
      22,    20,    12,     3,     3,    20,    19,    25,     3,    18,
      18,    47,   103,    70,    21,    94,    -1,    -1,    -1,    25,
      73,    23
  };

  const signed char
  Parser::yystos_[] =
  {
       0,    32,    33,     0,     0,     5,     6,     7,    10,    11,
      13,    34,    35,    36,    37,    38,    43,    49,    20,    20,
      20,    20,    20,    20,    28,    59,    29,    61,    27,    60,
      60,     8,     9,    44,    45,    61,     3,    21,     3,    21,
       4,    16,    26,    21,     3,     3,    21,    26,    21,    28,
       3,    29,     3,    27,     4,    60,     3,     3,    45,    22,
      25,    25,    27,    21,    22,    12,    46,    50,     3,    20,
      39,    40,    20,    22,     3,    14,    15,    16,    23,    24,
      51,    53,    54,    55,    56,    58,    25,    17,    41,    42,
      58,    23,    40,     3,    47,    48,    50,    19,    53,    57,
      18,    52,    21,    26,     3,    21,    48,    23,     3,    24,
      26,    53,    18,    25,    18,    42,    21,    53,    53,    58,
      25
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    31,    32,    33,    33,    34,    34,    34,    34,    34,
      34,    35,    36,    37,    38,    39,    39,    40,    41,    41,
      42,    42,    43,    44,    44,    45,    45,    46,    46,    47,
      47,    48,    49,    50,    50,    51,    52,    52,    53,    54,
      54,    54,    54,    55,    56,    57,    57,    58,    58,    58,
      59,    60,    60,    61
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     2,     0,     2,     1,     1,     1,     1,     1,
       1,     6,     6,     8,     8,     1,     2,     6,     1,     3,
       1,     1,     9,     1,     3,     2,     2,     0,     5,     1,
       2,     2,     7,     0,     2,     3,     2,     3,     1,     1,
       1,     1,     1,     3,     3,     1,     3,     1,     1,     1,
       3,     3,     4,     3
  };




#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,   118,   118,   122,   123,   127,   128,   129,   130,   131,
     132,   137,   141,   145,   151,   155,   156,   160,   164,   165,
     169,   170,   176,   180,   181,   185,   186,   190,   191,   195,
     196,   200,   206,   218,   219,   223,   236,   237,   243,   253,
     254,   255,   256,   266,   277,   287,   291,   298,   299,   300,
     306,   316,   323,   333
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


#line 2 "./src/grammar/parser.y"
} // parser
#line 3921 "parser.tab.cc"

#line 342 "./src/grammar/parser.y"


void parser::Parser::error(const location_type& loc, const std::string& msg) {
  driver.on_error((int)loc.begin.line, (int)loc.begin.column, msg);
}

