/* A Bison parser, made by GNU Bison 3.7.6.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30706

/* Bison version string.  */
#define YYBISON_VERSION "3.7.6"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

    #define YYPARSER    
    #include "globals.h"
    #include "util.h"
    #include "scan.h"
    #include "parse.h"

    #define YYSTYPE TreeNode *
    static TreeNode * savedTree;   
    static int yylex(void);

#line 83 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IF = 3,                         /* IF  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_WHILE = 5,                      /* WHILE  */
  YYSYMBOL_INT = 6,                        /* INT  */
  YYSYMBOL_VOID = 7,                       /* VOID  */
  YYSYMBOL_RETURN = 8,                     /* RETURN  */
  YYSYMBOL_NUM = 9,                        /* NUM  */
  YYSYMBOL_ID = 10,                        /* ID  */
  YYSYMBOL_ASSIGN = 11,                    /* ASSIGN  */
  YYSYMBOL_EQ = 12,                        /* EQ  */
  YYSYMBOL_NOT_EQUAL = 13,                 /* NOT_EQUAL  */
  YYSYMBOL_LESS_THAN = 14,                 /* LESS_THAN  */
  YYSYMBOL_LESS_THAN_EQUAL = 15,           /* LESS_THAN_EQUAL  */
  YYSYMBOL_GREATER_THAN = 16,              /* GREATER_THAN  */
  YYSYMBOL_GREATER_THAN_EQUAL = 17,        /* GREATER_THAN_EQUAL  */
  YYSYMBOL_SUM = 18,                       /* SUM  */
  YYSYMBOL_SUBTRACT = 19,                  /* SUBTRACT  */
  YYSYMBOL_MULTIPLY = 20,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 21,                    /* DIVIDE  */
  YYSYMBOL_OPEN_PARENTHESES = 22,          /* OPEN_PARENTHESES  */
  YYSYMBOL_CLOSE_PARENTHESES = 23,         /* CLOSE_PARENTHESES  */
  YYSYMBOL_OPEN_BRACKET = 24,              /* OPEN_BRACKET  */
  YYSYMBOL_CLOSE_BRACKET = 25,             /* CLOSE_BRACKET  */
  YYSYMBOL_OPEN_KEYS = 26,                 /* OPEN_KEYS  */
  YYSYMBOL_CLOSE_KEYS = 27,                /* CLOSE_KEYS  */
  YYSYMBOL_COMMA = 28,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 29,                 /* SEMICOLON  */
  YYSYMBOL_ERROR = 30,                     /* ERROR  */
  YYSYMBOL_ENDFILE = 31,                   /* ENDFILE  */
  YYSYMBOL_YYACCEPT = 32,                  /* $accept  */
  YYSYMBOL_program = 33,                   /* program  */
  YYSYMBOL_list_declaration = 34,          /* list_declaration  */
  YYSYMBOL_declaration = 35,               /* declaration  */
  YYSYMBOL_var_declaration = 36,           /* var_declaration  */
  YYSYMBOL_fun_declaration = 37,           /* fun_declaration  */
  YYSYMBOL_params = 38,                    /* params  */
  YYSYMBOL_param_list = 39,                /* param_list  */
  YYSYMBOL_param = 40,                     /* param  */
  YYSYMBOL_compound_decl = 41,             /* compound_decl  */
  YYSYMBOL_local_declarations = 42,        /* local_declarations  */
  YYSYMBOL_statement_list = 43,            /* statement_list  */
  YYSYMBOL_statement = 44,                 /* statement  */
  YYSYMBOL_expression_decl = 45,           /* expression_decl  */
  YYSYMBOL_selection_decl = 46,            /* selection_decl  */
  YYSYMBOL_iterator_decl = 47,             /* iterator_decl  */
  YYSYMBOL_return_decl = 48,               /* return_decl  */
  YYSYMBOL_expression = 49,                /* expression  */
  YYSYMBOL_var = 50,                       /* var  */
  YYSYMBOL_simple_expression = 51,         /* simple_expression  */
  YYSYMBOL_relational = 52,                /* relational  */
  YYSYMBOL_sum_expression = 53,            /* sum_expression  */
  YYSYMBOL_sum = 54,                       /* sum  */
  YYSYMBOL_term = 55,                      /* term  */
  YYSYMBOL_mult = 56,                      /* mult  */
  YYSYMBOL_factor = 57,                    /* factor  */
  YYSYMBOL_activation = 58,                /* activation  */
  YYSYMBOL_arg_list = 59,                  /* arg_list  */
  YYSYMBOL_ident = 60,                     /* ident  */
  YYSYMBOL_num = 61                        /* num  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
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

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   136

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  114

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   286


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    20,    20,    25,    38,    43,    47,    52,    62,    74,
      89,   103,   107,   113,   126,   131,   142,   154,   167,   171,
     175,   179,   192,   197,   210,   215,   219,   223,   227,   231,
     236,   240,   244,   250,   259,   266,   271,   277,   283,   288,
     292,   300,   306,   311,   317,   323,   329,   335,   341,   348,
     354,   359,   364,   370,   376,   381,   386,   392,   396,   400,
     404,   409,   416,   424,   437,   442,   448
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IF", "ELSE", "WHILE",
  "INT", "VOID", "RETURN", "NUM", "ID", "ASSIGN", "EQ", "NOT_EQUAL",
  "LESS_THAN", "LESS_THAN_EQUAL", "GREATER_THAN", "GREATER_THAN_EQUAL",
  "SUM", "SUBTRACT", "MULTIPLY", "DIVIDE", "OPEN_PARENTHESES",
  "CLOSE_PARENTHESES", "OPEN_BRACKET", "CLOSE_BRACKET", "OPEN_KEYS",
  "CLOSE_KEYS", "COMMA", "SEMICOLON", "ERROR", "ENDFILE", "$accept",
  "program", "list_declaration", "declaration", "var_declaration",
  "fun_declaration", "params", "param_list", "param", "compound_decl",
  "local_declarations", "statement_list", "statement", "expression_decl",
  "selection_decl", "iterator_decl", "return_decl", "expression", "var",
  "simple_expression", "relational", "sum_expression", "sum", "term",
  "mult", "factor", "activation", "arg_list", "ident", "num", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286
};
#endif

#define YYPACT_NINF (-45)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      97,     0,     0,    19,    97,   -45,   -45,   -45,   -45,     7,
      21,   -45,   -45,   101,    38,   -45,   101,     0,   -45,     2,
      23,   -45,   -45,    29,    41,    35,    40,    64,    76,    40,
      68,     6,   -45,   -45,   -45,   -45,   -45,    73,    99,     0,
       8,    62,   -45,   -45,   -45,   -45,    47,    36,   -45,   -45,
     -45,   -45,   -45,    91,   111,   -45,    98,    66,   -45,   -45,
      16,   -45,    62,    62,   -22,   -45,    94,   102,   -45,   -45,
      72,   -45,   -45,   -45,    62,   -45,   -45,   -45,   -45,   -45,
     -45,   -45,   -45,    62,    62,   -45,   -45,    62,    69,    62,
     103,   104,   -45,   -45,   -45,   -45,   -45,   100,    66,   -45,
     -45,   -45,   -15,   105,    80,    80,   -45,    62,   -45,   120,
     -45,   -45,    80,   -45
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     2,     4,     5,     6,    65,     0,
       0,     1,     3,     0,     0,     7,     0,     0,    12,     0,
      11,    14,    66,     0,     0,    15,     0,     0,     0,     0,
       0,     0,     9,    13,     8,    10,    16,     0,     0,     0,
       0,     0,    20,    31,    22,    26,     0,     0,    24,    25,
      27,    28,    29,     0,    58,    38,    42,    50,    54,    59,
      39,    60,     0,     0,     0,    35,     0,     0,    18,    21,
       0,    19,    23,    30,     0,    43,    44,    45,    46,    47,
      48,    51,    52,     0,     0,    55,    56,     0,     0,     0,
       0,     0,    36,    57,    17,    37,    58,    41,    49,    53,
      62,    64,     0,     0,     0,     0,    61,     0,    40,    32,
      34,    63,     0,    33
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -45,   -45,   -45,   124,   -25,   -45,   113,   -45,   106,    -2,
     -45,    85,   -44,   -45,   -45,   -45,   -45,   -40,    13,   -45,
     -45,    49,   -45,    50,   -45,    48,   -45,   -45,     3,   122
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,     6,     7,    19,    20,    21,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      83,    56,    84,    57,    87,    58,    59,   102,    60,    61
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      66,    67,    14,    72,     9,    10,    44,    15,   106,    37,
       8,    38,    39,   107,    40,    22,     8,    22,     8,    11,
      25,    69,    90,    91,    32,    26,    72,    35,    41,    13,
      41,    14,    31,    42,    95,    43,    15,    65,    88,    37,
      89,    38,    64,    16,    40,    22,     8,    22,   101,   103,
      37,    27,    38,    39,    28,    40,    22,     8,    41,    30,
     109,   110,    31,    71,    29,    43,    31,   111,   113,    41,
      17,    22,     8,    31,    68,    37,    43,    38,    22,     8,
      40,    22,     8,    37,    41,    38,    85,    86,    40,    22,
       8,    41,   100,    36,    41,    62,    96,    96,    31,    94,
      96,    43,    41,     1,     2,    34,    31,    17,    18,    43,
      75,    76,    77,    78,    79,    80,    81,    82,    81,    82,
      73,    63,    74,    92,   112,    93,   104,   105,    12,    24,
     108,    70,    97,    33,    98,    99,    23
};

static const yytype_int8 yycheck[] =
{
      40,    41,    24,    47,     1,     2,    31,    29,    23,     3,
      10,     5,     6,    28,     8,     9,    10,     9,    10,     0,
      17,    46,    62,    63,    26,    23,    70,    29,    22,    22,
      22,    24,    26,    27,    74,    29,    29,    29,    22,     3,
      24,     5,    39,    22,     8,     9,    10,     9,    88,    89,
       3,    28,     5,     6,    25,     8,     9,    10,    22,    24,
     104,   105,    26,    27,    23,    29,    26,   107,   112,    22,
       6,     9,    10,    26,    27,     3,    29,     5,     9,    10,
       8,     9,    10,     3,    22,     5,    20,    21,     8,     9,
      10,    22,    23,    25,    22,    22,    83,    84,    26,    27,
      87,    29,    22,     6,     7,    29,    26,     6,     7,    29,
      12,    13,    14,    15,    16,    17,    18,    19,    18,    19,
      29,    22,    11,    29,     4,    23,    23,    23,     4,    16,
      25,    46,    83,    27,    84,    87,    14
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,     7,    33,    34,    35,    36,    37,    10,    60,
      60,     0,    35,    22,    24,    29,    22,     6,     7,    38,
      39,    40,     9,    61,    38,    60,    23,    28,    25,    23,
      24,    26,    41,    40,    29,    41,    25,     3,     5,     6,
       8,    22,    27,    29,    36,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    53,    55,    57,    58,
      60,    61,    22,    22,    60,    29,    49,    49,    27,    36,
      43,    27,    44,    29,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    52,    54,    20,    21,    56,    22,    24,
      49,    49,    29,    23,    27,    49,    50,    53,    55,    57,
      23,    49,    59,    49,    23,    23,    23,    28,    25,    44,
      44,    49,     4,    44
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    34,    34,    35,    35,    36,    36,    37,
      37,    38,    38,    39,    39,    40,    40,    41,    41,    41,
      41,    42,    42,    43,    43,    44,    44,    44,    44,    44,
      45,    45,    46,    46,    47,    48,    48,    49,    49,    50,
      50,    51,    51,    52,    52,    52,    52,    52,    52,    53,
      53,    54,    54,    55,    55,    56,    56,    57,    57,    57,
      57,    58,    58,    59,    59,    60,    61
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     6,     6,
       6,     1,     1,     3,     1,     2,     4,     4,     3,     3,
       2,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       2,     1,     5,     7,     5,     2,     3,     3,     1,     1,
       4,     3,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     3,     1,     1,     1,     3,     1,     1,
       1,     4,     3,     3,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: list_declaration  */
#line 21 "parser.y"
                       {
                          savedTree = yyvsp[0];
                       }
#line 1223 "parser.tab.c"
    break;

  case 3: /* list_declaration: list_declaration declaration  */
#line 26 "parser.y"
                        {
                            YYSTYPE t = yyvsp[-1];
                            if(t != NULL)
		   	  			    {
                                while(t->sibling != NULL)
                                    t = t->sibling;
                                t->sibling = yyvsp[0];
                                yyval = yyvsp[-1];
                            }
                            else
                                yyval = yyvsp[0];
                        }
#line 1240 "parser.tab.c"
    break;

  case 4: /* list_declaration: declaration  */
#line 39 "parser.y"
                        {
                           yyval = yyvsp[0];
                        }
#line 1248 "parser.tab.c"
    break;

  case 5: /* declaration: var_declaration  */
#line 44 "parser.y"
                        {
                           yyval = yyvsp[0];
                        }
#line 1256 "parser.tab.c"
    break;

  case 6: /* declaration: fun_declaration  */
#line 48 "parser.y"
                        {
                           yyval = yyvsp[0];
                        }
#line 1264 "parser.tab.c"
    break;

  case 7: /* var_declaration: INT ident SEMICOLON  */
#line 53 "parser.y"
                        {	
                        	yyval = newExpNode(typeK);
                            yyval->type = integerK;
                            yyval->attr.name = "integer";
                            yyval->child[0] = yyvsp[-1];
                            yyvsp[-1]->nodekind = statementK;
                            yyvsp[-1]->kind.stmt = variableK;
							yyvsp[-1]->type = integerK;
                        }
#line 1278 "parser.tab.c"
    break;

  case 8: /* var_declaration: INT ident OPEN_BRACKET num CLOSE_BRACKET SEMICOLON  */
#line 63 "parser.y"
                        {
                        	yyval = newExpNode(typeK);
                            yyval->type = integerK;
                            yyval->attr.name = "integer";
                            yyval->child[0] = yyvsp[-4];
                            yyvsp[-4]->nodekind = statementK;
                            yyvsp[-4]->kind.stmt = variableK;
							yyvsp[-4]->type = integerK; 
                            yyvsp[-4]->attr.len = yyvsp[-2]->attr.val;
                        }
#line 1293 "parser.tab.c"
    break;

  case 9: /* fun_declaration: INT ident OPEN_PARENTHESES params CLOSE_PARENTHESES compound_decl  */
#line 75 "parser.y"
                        {
                        	yyval = newExpNode(typeK);
                            yyval->type = integerK;
                            yyval->attr.name = "integer";
                            yyval->child[0] = yyvsp[-4];
                            yyvsp[-4]->child[0] = yyvsp[-2];
                            yyvsp[-4]->child[1] = yyvsp[0];
                            yyvsp[-4]->nodekind = statementK;
                            yyvsp[-4]->kind.stmt = functionK;
							yyvsp[-4]->type = integerK;
							yyvsp[-2]->type = integerK;
							aggScope(yyvsp[-4]->child[0], yyvsp[-4]->attr.name);
							aggScope(yyvsp[-4]->child[1], yyvsp[-4]->attr.name);
                        }
#line 1312 "parser.tab.c"
    break;

  case 10: /* fun_declaration: VOID ident OPEN_PARENTHESES params CLOSE_PARENTHESES compound_decl  */
#line 90 "parser.y"
                        {
                        	yyval = newExpNode(typeK);
                            yyval->type = voidK;
                            yyval->attr.name = "void";
                            yyval->child[0] = yyvsp[-4];
                            yyvsp[-4]->child[0] = yyvsp[-2];
                            yyvsp[-4]->child[1] = yyvsp[0];
                            yyvsp[-4]->nodekind = statementK;
                            yyvsp[-4]->kind.stmt = functionK;
							aggScope(yyvsp[-4]->child[0], yyvsp[-4]->attr.name);
							aggScope(yyvsp[-4]->child[1], yyvsp[-4]->attr.name);
                        }
#line 1329 "parser.tab.c"
    break;

  case 11: /* params: param_list  */
#line 104 "parser.y"
                        {
                           yyval = yyvsp[0];
                        }
#line 1337 "parser.tab.c"
    break;

  case 12: /* params: VOID  */
#line 108 "parser.y"
                        {
						  yyval = newExpNode(typeK);
           				  yyval->attr.name = "void";
						}
#line 1346 "parser.tab.c"
    break;

  case 13: /* param_list: param_list COMMA param  */
#line 114 "parser.y"
                        {
                           YYSTYPE t = yyvsp[-2];
                           if(t != NULL)
						   {
                              while(t->sibling != NULL)
                                  t = t->sibling;
                              t->sibling = yyvsp[0];
                              yyval = yyvsp[-2];
                            }
                            else
                              yyval = yyvsp[0];
                        }
#line 1363 "parser.tab.c"
    break;

  case 14: /* param_list: param  */
#line 127 "parser.y"
                        {
                            yyval = yyvsp[0];
                        }
#line 1371 "parser.tab.c"
    break;

  case 15: /* param: INT ident  */
#line 132 "parser.y"
                        {
						   	
                           yyval = newExpNode(typeK);
					       yyvsp[0]->nodekind = statementK;
                           yyvsp[0]->kind.stmt = variableK;
                           yyval->type = integerK;
						   yyvsp[0]->type = integerK; 	
                           yyval->attr.name = "integer";
                           yyval->child[0] = yyvsp[0];
                        }
#line 1386 "parser.tab.c"
    break;

  case 16: /* param: INT ident OPEN_BRACKET CLOSE_BRACKET  */
#line 143 "parser.y"
                        {
							
                            yyval = newExpNode(typeK);
							yyvsp[-2]->nodekind = statementK;
                            yyvsp[-2]->kind.stmt = variableK;
                            yyval->type = integerK;
                            yyval->attr.name = "integer";
                            yyval->child[0] = yyvsp[-2];
						    yyvsp[-2]->type = integerK;
                        }
#line 1401 "parser.tab.c"
    break;

  case 17: /* compound_decl: OPEN_KEYS local_declarations statement_list CLOSE_KEYS  */
#line 155 "parser.y"
                        {
                            YYSTYPE t = yyvsp[-2];
                            if(t != NULL)
						    {
                               while(t->sibling != NULL)
                                  t = t->sibling;
                                t->sibling = yyvsp[-1];
                                yyval = yyvsp[-2];
                            }
                            else
                               yyval = yyvsp[-1];
                        }
#line 1418 "parser.tab.c"
    break;

  case 18: /* compound_decl: OPEN_KEYS local_declarations CLOSE_KEYS  */
#line 168 "parser.y"
                        {
                            yyval = yyvsp[-1];
                        }
#line 1426 "parser.tab.c"
    break;

  case 19: /* compound_decl: OPEN_KEYS statement_list CLOSE_KEYS  */
#line 172 "parser.y"
                        {
                            yyval = yyvsp[-1];
                        }
#line 1434 "parser.tab.c"
    break;

  case 20: /* compound_decl: OPEN_KEYS CLOSE_KEYS  */
#line 176 "parser.y"
                        {
			   			}
#line 1441 "parser.tab.c"
    break;

  case 21: /* local_declarations: local_declarations var_declaration  */
#line 180 "parser.y"
                        {
                            YYSTYPE t = yyvsp[-1];
                            if(t != NULL)
							{
                            	while(t->sibling != NULL)
                                	 t = t->sibling;
                             	t->sibling = yyvsp[0];
                             	yyval = yyvsp[-1];
                            }
                            else
                               yyval = yyvsp[0];
                        }
#line 1458 "parser.tab.c"
    break;

  case 22: /* local_declarations: var_declaration  */
#line 193 "parser.y"
                        {
                            yyval = yyvsp[0];
                        }
#line 1466 "parser.tab.c"
    break;

  case 23: /* statement_list: statement_list statement  */
#line 198 "parser.y"
                        {
                           YYSTYPE t = yyvsp[-1];
                           if(t != NULL)
						   {
                              while(t->sibling != NULL)
                                   t = t->sibling;
                              t->sibling = yyvsp[0];
                              yyval = yyvsp[-1];
                           }
                           else
                             yyval = yyvsp[0];
                        }
#line 1483 "parser.tab.c"
    break;

  case 24: /* statement_list: statement  */
#line 211 "parser.y"
                        {
                           yyval = yyvsp[0];
                        }
#line 1491 "parser.tab.c"
    break;

  case 25: /* statement: expression_decl  */
#line 216 "parser.y"
                        {
                           yyval = yyvsp[0];
                        }
#line 1499 "parser.tab.c"
    break;

  case 26: /* statement: compound_decl  */
#line 220 "parser.y"
                        {
                           yyval = yyvsp[0];
                        }
#line 1507 "parser.tab.c"
    break;

  case 27: /* statement: selection_decl  */
#line 224 "parser.y"
                        {
                           yyval = yyvsp[0];
                        }
#line 1515 "parser.tab.c"
    break;

  case 28: /* statement: iterator_decl  */
#line 228 "parser.y"
                        {
                           yyval = yyvsp[0];
                        }
#line 1523 "parser.tab.c"
    break;

  case 29: /* statement: return_decl  */
#line 232 "parser.y"
                        {
                           yyval = yyvsp[0];
                        }
#line 1531 "parser.tab.c"
    break;

  case 30: /* expression_decl: expression SEMICOLON  */
#line 237 "parser.y"
                        {
                           yyval = yyvsp[-1];
                        }
#line 1539 "parser.tab.c"
    break;

  case 31: /* expression_decl: SEMICOLON  */
#line 241 "parser.y"
                        {
						}
#line 1546 "parser.tab.c"
    break;

  case 32: /* selection_decl: IF OPEN_PARENTHESES expression CLOSE_PARENTHESES statement  */
#line 245 "parser.y"
                        {
                             yyval = newStmtNode(ifK);
                             yyval->child[0] = yyvsp[-2];
                             yyval->child[1] = yyvsp[0];
                        }
#line 1556 "parser.tab.c"
    break;

  case 33: /* selection_decl: IF OPEN_PARENTHESES expression CLOSE_PARENTHESES statement ELSE statement  */
#line 251 "parser.y"
                        {
							 
                             yyval = newStmtNode(ifK);
                             yyval->child[0] = yyvsp[-4];
                             yyval->child[1] = yyvsp[-2];
                             yyval->child[2] = yyvsp[0];
                        }
#line 1568 "parser.tab.c"
    break;

  case 34: /* iterator_decl: WHILE OPEN_PARENTHESES expression CLOSE_PARENTHESES statement  */
#line 260 "parser.y"
                        {
                             yyval = newStmtNode(whileK);
                             yyval->child[0] = yyvsp[-2];
                             yyval->child[1] = yyvsp[0];
                        }
#line 1578 "parser.tab.c"
    break;

  case 35: /* return_decl: RETURN SEMICOLON  */
#line 267 "parser.y"
                       {
                            yyval = newStmtNode(returnK);
							yyval->type = voidK;
                       }
#line 1587 "parser.tab.c"
    break;

  case 36: /* return_decl: RETURN expression SEMICOLON  */
#line 272 "parser.y"
                       {
                            yyval = newStmtNode(returnK);
                            yyval->child[0] = yyvsp[-1];
                       }
#line 1596 "parser.tab.c"
    break;

  case 37: /* expression: var ASSIGN expression  */
#line 278 "parser.y"
                       {
                            yyval = newStmtNode(assignK);
                            yyval->child[0] = yyvsp[-2];
                            yyval->child[1] = yyvsp[0];
                       }
#line 1606 "parser.tab.c"
    break;

  case 38: /* expression: simple_expression  */
#line 284 "parser.y"
                       {
                            yyval = yyvsp[0];
                       }
#line 1614 "parser.tab.c"
    break;

  case 39: /* var: ident  */
#line 289 "parser.y"
                       {
                            yyval = yyvsp[0];
                       }
#line 1622 "parser.tab.c"
    break;

  case 40: /* var: ident OPEN_BRACKET expression CLOSE_BRACKET  */
#line 293 "parser.y"
                       {
                            yyval = yyvsp[-3];
                            yyval->child[0] = yyvsp[-1];
                            yyval->kind.exp = vectorK;
							yyval->type = integerK;
                       }
#line 1633 "parser.tab.c"
    break;

  case 41: /* simple_expression: sum_expression relational sum_expression  */
#line 301 "parser.y"
                       {
                            yyval = yyvsp[-1];
                            yyval->child[0] = yyvsp[-2];
                            yyval->child[1] = yyvsp[0];
                       }
#line 1643 "parser.tab.c"
    break;

  case 42: /* simple_expression: sum_expression  */
#line 307 "parser.y"
                       {
                            yyval = yyvsp[0];
                       }
#line 1651 "parser.tab.c"
    break;

  case 43: /* relational: EQ  */
#line 312 "parser.y"
                       {
                            yyval = newExpNode(operationK);
                            yyval->attr.op = EQ;  
							yyval->type = booleanK;                          
                       }
#line 1661 "parser.tab.c"
    break;

  case 44: /* relational: NOT_EQUAL  */
#line 318 "parser.y"
                       {
                            yyval = newExpNode(operationK);
                            yyval->attr.op = NOT_EQUAL;
							yyval->type = booleanK;                            
                       }
#line 1671 "parser.tab.c"
    break;

  case 45: /* relational: LESS_THAN  */
#line 324 "parser.y"
                       {
                            yyval = newExpNode(operationK);
                            yyval->attr.op = LESS_THAN;                            
							yyval->type = booleanK;
                       }
#line 1681 "parser.tab.c"
    break;

  case 46: /* relational: LESS_THAN_EQUAL  */
#line 330 "parser.y"
                       {
                            yyval = newExpNode(operationK);
                            yyval->attr.op = LESS_THAN_EQUAL;                            
							yyval->type = booleanK;
                       }
#line 1691 "parser.tab.c"
    break;

  case 47: /* relational: GREATER_THAN  */
#line 336 "parser.y"
                       {
                            yyval = newExpNode(operationK);
                            yyval->attr.op = GREATER_THAN;                            
							yyval->type = booleanK;
                       }
#line 1701 "parser.tab.c"
    break;

  case 48: /* relational: GREATER_THAN_EQUAL  */
#line 342 "parser.y"
                       {
                            yyval = newExpNode(operationK);
                            yyval->attr.op = GREATER_THAN_EQUAL;                            
							yyval->type = booleanK;
                       }
#line 1711 "parser.tab.c"
    break;

  case 49: /* sum_expression: sum_expression sum term  */
#line 349 "parser.y"
                       {
                            yyval = yyvsp[-1];
                            yyval->child[0] = yyvsp[-2];
                            yyval->child[1] = yyvsp[0];
                       }
#line 1721 "parser.tab.c"
    break;

  case 50: /* sum_expression: term  */
#line 355 "parser.y"
                       {
                            yyval = yyvsp[0];
                       }
#line 1729 "parser.tab.c"
    break;

  case 51: /* sum: SUM  */
#line 360 "parser.y"
                       {
                            yyval = newExpNode(operationK);
                            yyval->attr.op = SUM;                            
                       }
#line 1738 "parser.tab.c"
    break;

  case 52: /* sum: SUBTRACT  */
#line 365 "parser.y"
                       {
                            yyval = newExpNode(operationK);
                            yyval->attr.op = SUBTRACT;                            
                       }
#line 1747 "parser.tab.c"
    break;

  case 53: /* term: term mult factor  */
#line 371 "parser.y"
                       {
                            yyval = yyvsp[-1];
                            yyval->child[0] = yyvsp[-2];
                            yyval->child[1] = yyvsp[0];
                       }
#line 1757 "parser.tab.c"
    break;

  case 54: /* term: factor  */
#line 377 "parser.y"
                       {
                            yyval = yyvsp[0];
                       }
#line 1765 "parser.tab.c"
    break;

  case 55: /* mult: MULTIPLY  */
#line 382 "parser.y"
                       {
                            yyval = newExpNode(operationK);
                            yyval->attr.op = MULTIPLY;                            
                       }
#line 1774 "parser.tab.c"
    break;

  case 56: /* mult: DIVIDE  */
#line 387 "parser.y"
                       {
                            yyval = newExpNode(operationK);
                            yyval->attr.op = DIVIDE;                            
                       }
#line 1783 "parser.tab.c"
    break;

  case 57: /* factor: OPEN_PARENTHESES expression CLOSE_PARENTHESES  */
#line 393 "parser.y"
                       {
                            yyval = yyvsp[-1];
                       }
#line 1791 "parser.tab.c"
    break;

  case 58: /* factor: var  */
#line 397 "parser.y"
                       {
                            yyval = yyvsp[0];
                       }
#line 1799 "parser.tab.c"
    break;

  case 59: /* factor: activation  */
#line 401 "parser.y"
                       {
                            yyval = yyvsp[0];
                       }
#line 1807 "parser.tab.c"
    break;

  case 60: /* factor: num  */
#line 405 "parser.y"
                       {
                            yyval = yyvsp[0];
                       }
#line 1815 "parser.tab.c"
    break;

  case 61: /* activation: ident OPEN_PARENTHESES arg_list CLOSE_PARENTHESES  */
#line 410 "parser.y"
                       {
                            yyval = yyvsp[-3];
                            yyval->child[0] = yyvsp[-1];
                            yyval->nodekind = statementK;
                            yyval->kind.stmt = callK;
                       }
#line 1826 "parser.tab.c"
    break;

  case 62: /* activation: ident OPEN_PARENTHESES CLOSE_PARENTHESES  */
#line 417 "parser.y"
                                           {
                            yyval = yyvsp[-2];
                            yyval->nodekind = statementK;
                            yyval->kind.stmt = callK;
                       }
#line 1836 "parser.tab.c"
    break;

  case 63: /* arg_list: arg_list COMMA expression  */
#line 425 "parser.y"
                       {
                            YYSTYPE t = yyvsp[-2];
                             if(t != NULL)
							 {
                                while(t->sibling != NULL)
                                   t = t->sibling;
                                 t->sibling = yyvsp[0];
                                 yyval = yyvsp[-2];
                             }
                             else
                                 yyval = yyvsp[0];
                        }
#line 1853 "parser.tab.c"
    break;

  case 64: /* arg_list: expression  */
#line 438 "parser.y"
                        {
                             yyval = yyvsp[0];
                        }
#line 1861 "parser.tab.c"
    break;

  case 65: /* ident: ID  */
#line 443 "parser.y"
                        {
                             yyval = newExpNode(idK);
                             yyval->attr.name = copyString(tokenString);
                        }
#line 1870 "parser.tab.c"
    break;

  case 66: /* num: NUM  */
#line 449 "parser.y"
                        {
                             yyval = newExpNode(constantK);
                             yyval->attr.val = atoi(tokenString);
							 yyval->type = integerK;
						}
#line 1880 "parser.tab.c"
    break;


#line 1884 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
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


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 456 "parser.y"


int yyerror(char* message){
    fprintf(listing,"ERRO SINTÁTICO: ");
    printTokenForError(yychar,tokenString);
    fprintf(listing," LINHA: %d\n",lineno);
    Error = TRUE;
    return 0;
}


static int yylex(void){
    return getToken();
}

TreeNode * parse(void){
    yyparse();
    return savedTree;
}
