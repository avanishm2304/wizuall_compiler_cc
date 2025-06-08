/* A Bison parser, made by GNU Bison 3.8.2.  */

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
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "src/wizuall.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // For strcmp, strdup

#include "symtab.h"    // Symbol table functions
#include "codegen.h"   // Code generation functions

// External declarations from Flex
extern int yylex();
extern char *yytext;
extern int yylineno;
extern FILE *yyin;

// Error handling function
void yyerror(const char *s);

// Global symbol table
SymbolTable *symbol_table;

// Root of the generated code
CodeFragment final_code;

// Bison error count
extern int yynerrs;


#line 99 "src/wizuall.tab.c"

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

#include "wizuall.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_IDENTIFIER = 3,               /* T_IDENTIFIER  */
  YYSYMBOL_T_NATIVE_CODE = 4,              /* T_NATIVE_CODE  */
  YYSYMBOL_T_NUMBER = 5,                   /* T_NUMBER  */
  YYSYMBOL_T_STRING_LITERAL = 6,           /* T_STRING_LITERAL  */
  YYSYMBOL_T_IF = 7,                       /* T_IF  */
  YYSYMBOL_T_ELSE = 8,                     /* T_ELSE  */
  YYSYMBOL_T_WHILE = 9,                    /* T_WHILE  */
  YYSYMBOL_T_PLOT_HISTOGRAM = 10,          /* T_PLOT_HISTOGRAM  */
  YYSYMBOL_T_PLOT_SCATTER = 11,            /* T_PLOT_SCATTER  */
  YYSYMBOL_T_PLOT_XY = 12,                 /* T_PLOT_XY  */
  YYSYMBOL_T_CALC_STAT = 13,               /* T_CALC_STAT  */
  YYSYMBOL_T_SLICE_VECTOR = 14,            /* T_SLICE_VECTOR  */
  YYSYMBOL_T_REVERSE_VECTOR = 15,          /* T_REVERSE_VECTOR  */
  YYSYMBOL_T_FIND_CLUSTERS = 16,           /* T_FIND_CLUSTERS  */
  YYSYMBOL_T_ASSIGN = 17,                  /* T_ASSIGN  */
  YYSYMBOL_T_PLUS = 18,                    /* T_PLUS  */
  YYSYMBOL_T_MINUS = 19,                   /* T_MINUS  */
  YYSYMBOL_T_MULTIPLY = 20,                /* T_MULTIPLY  */
  YYSYMBOL_T_DIVIDE = 21,                  /* T_DIVIDE  */
  YYSYMBOL_T_LOAD_CSV = 22,                /* T_LOAD_CSV  */
  YYSYMBOL_T_GET_COLUMN = 23,              /* T_GET_COLUMN  */
  YYSYMBOL_T_LPAREN = 24,                  /* T_LPAREN  */
  YYSYMBOL_T_RPAREN = 25,                  /* T_RPAREN  */
  YYSYMBOL_T_LBRACE = 26,                  /* T_LBRACE  */
  YYSYMBOL_T_RBRACE = 27,                  /* T_RBRACE  */
  YYSYMBOL_T_LBRACKET = 28,                /* T_LBRACKET  */
  YYSYMBOL_T_RBRACKET = 29,                /* T_RBRACKET  */
  YYSYMBOL_T_COMMA = 30,                   /* T_COMMA  */
  YYSYMBOL_T_SEMICOLON = 31,               /* T_SEMICOLON  */
  YYSYMBOL_T_LT = 32,                      /* T_LT  */
  YYSYMBOL_T_GT = 33,                      /* T_GT  */
  YYSYMBOL_T_LTE = 34,                     /* T_LTE  */
  YYSYMBOL_T_GTE = 35,                     /* T_GTE  */
  YYSYMBOL_T_EQ = 36,                      /* T_EQ  */
  YYSYMBOL_T_NEQ = 37,                     /* T_NEQ  */
  YYSYMBOL_UMINUS = 38,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 39,                  /* $accept  */
  YYSYMBOL_Program = 40,                   /* Program  */
  YYSYMBOL_StatementList = 41,             /* StatementList  */
  YYSYMBOL_Statement = 42,                 /* Statement  */
  YYSYMBOL_Block = 43,                     /* Block  */
  YYSYMBOL_AuxiliaryBlock = 44,            /* AuxiliaryBlock  */
  YYSYMBOL_AssignmentStmt = 45,            /* AssignmentStmt  */
  YYSYMBOL_IfStmt = 46,                    /* IfStmt  */
  YYSYMBOL_WhileStmt = 47,                 /* WhileStmt  */
  YYSYMBOL_ExternalCallStmt = 48,          /* ExternalCallStmt  */
  YYSYMBOL_VisualizationStmt = 49,         /* VisualizationStmt  */
  YYSYMBOL_CsvLoadExpr = 50,               /* CsvLoadExpr  */
  YYSYMBOL_PlotHistogramStmt = 51,         /* PlotHistogramStmt  */
  YYSYMBOL_PlotScatterStmt = 52,           /* PlotScatterStmt  */
  YYSYMBOL_PlotXYStmt = 53,                /* PlotXYStmt  */
  YYSYMBOL_CalculateStatsStmt = 54,        /* CalculateStatsStmt  */
  YYSYMBOL_VectorOpStmt = 55,              /* VectorOpStmt  */
  YYSYMBOL_ClusterStmt = 56,               /* ClusterStmt  */
  YYSYMBOL_Expression = 57,                /* Expression  */
  YYSYMBOL_ComparisonExpr = 58,            /* ComparisonExpr  */
  YYSYMBOL_Term = 59,                      /* Term  */
  YYSYMBOL_Factor = 60,                    /* Factor  */
  YYSYMBOL_VectorLiteral = 61,             /* VectorLiteral  */
  YYSYMBOL_OptionalArgumentList = 62,      /* OptionalArgumentList  */
  YYSYMBOL_ArgumentList = 63               /* ArgumentList  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  36
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   173

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  61
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  140

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   293


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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    70,    70,    81,    82,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    98,   102,   106,   113,   123,   129,
     138,   146,   157,   158,   159,   160,   161,   162,   164,   168,
     172,   176,   180,   192,   201,   212,   227,   232,   233,   234,
     235,   236,   237,   238,   242,   243,   244,   245,   246,   250,
     264,   265,   266,   267,   268,   269,   279,   290,   294,   295,
     298,   299
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
  "\"end of file\"", "error", "\"invalid token\"", "T_IDENTIFIER",
  "T_NATIVE_CODE", "T_NUMBER", "T_STRING_LITERAL", "T_IF", "T_ELSE",
  "T_WHILE", "T_PLOT_HISTOGRAM", "T_PLOT_SCATTER", "T_PLOT_XY",
  "T_CALC_STAT", "T_SLICE_VECTOR", "T_REVERSE_VECTOR", "T_FIND_CLUSTERS",
  "T_ASSIGN", "T_PLUS", "T_MINUS", "T_MULTIPLY", "T_DIVIDE", "T_LOAD_CSV",
  "T_GET_COLUMN", "T_LPAREN", "T_RPAREN", "T_LBRACE", "T_RBRACE",
  "T_LBRACKET", "T_RBRACKET", "T_COMMA", "T_SEMICOLON", "T_LT", "T_GT",
  "T_LTE", "T_GTE", "T_EQ", "T_NEQ", "UMINUS", "$accept", "Program",
  "StatementList", "Statement", "Block", "AuxiliaryBlock",
  "AssignmentStmt", "IfStmt", "WhileStmt", "ExternalCallStmt",
  "VisualizationStmt", "CsvLoadExpr", "PlotHistogramStmt",
  "PlotScatterStmt", "PlotXYStmt", "CalculateStatsStmt", "VectorOpStmt",
  "ClusterStmt", "Expression", "ComparisonExpr", "Term", "Factor",
  "VectorLiteral", "OptionalArgumentList", "ArgumentList", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-76)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-4)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      69,   -29,    -7,   -76,   -16,   -13,     2,     8,     9,   102,
     -76,    24,   -76,    27,   -76,   -76,    -6,   -76,   -76,    -2,
       4,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   133,   139,
     139,   139,   139,   139,   139,    13,   -76,   -76,   -76,   -76,
     -76,    21,   -76,    22,    31,    32,    33,   139,    35,    37,
     139,   139,   -76,   -76,   -76,    50,     1,    36,   -76,   -76,
      38,    41,    43,    49,    45,    47,    58,   -76,   139,   139,
     139,   139,   -76,    83,   139,    67,    64,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   -76,   139,
     114,   114,   139,   139,   139,    72,    71,    74,    77,    79,
      80,   -76,   -76,     1,     1,     1,     1,     1,     1,    36,
      36,    36,    36,    73,   -76,   108,   -76,    94,    95,    97,
     -76,   139,   -76,   139,   -76,   139,   -76,   114,   -76,   -76,
     -76,   100,   106,   107,   -76,   139,   -76,   -76,   109,   -76
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,    15,     0,     0,     0,     0,     0,     0,
      13,     0,     2,     0,    10,    11,     0,     6,     7,     0,
       0,    22,    23,    24,    25,    26,    27,    12,     0,    58,
       0,     0,     0,     0,     0,     0,     1,     4,     5,     8,
       9,    49,    50,     0,     0,     0,     0,     0,     0,     0,
       0,    58,    52,    17,    16,    36,    37,    44,    51,    60,
       0,    59,     0,     0,     0,     0,     0,    14,     0,     0,
       0,     0,    54,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    53,    57,    38,    39,    40,    41,    42,    43,    45,
      46,    47,    48,     0,    61,    18,    20,     0,     0,     0,
      32,     0,    34,     0,    28,     0,    55,     0,    29,    30,
      31,     0,     0,     0,    19,     0,    35,    56,     0,    33
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -76,   -76,     5,   -75,   -76,   -76,   -76,   -76,   -76,     0,
     -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -27,   -76,
      91,   -35,   -76,    84,   -76
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    11,    12,    13,    14,    15,    16,    17,    18,    52,
      20,    53,    21,    22,    23,    24,    25,    26,    59,    55,
      56,    57,    58,    60,    61
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      19,    54,    27,    62,    63,    64,    65,    66,    30,    19,
      28,    31,    72,    19,    35,   115,   116,    29,    37,    83,
      84,    85,    86,    75,    36,    38,    32,    -3,     1,    39,
       2,     3,    33,    34,     4,    40,     5,     6,     7,     8,
      67,    95,    96,    97,    98,    29,    68,   100,   109,   110,
     111,   112,   134,     9,    -3,    69,    70,    71,    10,    73,
     113,    74,   114,    88,    87,   117,   118,   119,    90,    -3,
       1,    89,     2,     3,    91,    92,     4,    93,     5,     6,
       7,     8,    77,    78,    79,    80,    81,    82,    94,    99,
      19,    19,   101,   102,   131,     9,   132,   120,   133,   122,
      10,   121,   126,     1,   124,     2,     3,   123,   138,     4,
     125,     5,     6,     7,     8,     1,   127,     2,     3,   128,
     129,     4,   130,     5,     6,     7,     8,    19,     9,    -3,
     135,   136,   137,    10,   139,    76,    41,     0,    42,     0,
       9,     0,    41,     0,    42,    10,    43,    44,    45,    46,
       0,     0,    47,     0,     0,    48,    49,    50,    47,     0,
       0,    51,    49,    50,     0,     0,     0,    51,   103,   104,
     105,   106,   107,   108
};

static const yytype_int16 yycheck[] =
{
       0,    28,    31,    30,    31,    32,    33,    34,    24,     9,
      17,    24,    47,    13,     9,    90,    91,    24,    13,    18,
      19,    20,    21,    50,     0,    31,    24,     0,     1,    31,
       3,     4,    24,    24,     7,    31,     9,    10,    11,    12,
      27,    68,    69,    70,    71,    24,    24,    74,    83,    84,
      85,    86,   127,    26,    27,    24,    24,    24,    31,    24,
      87,    24,    89,    25,    28,    92,    93,    94,    25,     0,
       1,    30,     3,     4,    25,    30,     7,    30,     9,    10,
      11,    12,    32,    33,    34,    35,    36,    37,    30,     6,
      90,    91,    25,    29,   121,    26,   123,    25,   125,    25,
      31,    30,    29,     1,    25,     3,     4,    30,   135,     7,
      30,     9,    10,    11,    12,     1,     8,     3,     4,    25,
      25,     7,    25,     9,    10,    11,    12,   127,    26,    27,
      30,    25,    25,    31,    25,    51,     3,    -1,     5,    -1,
      26,    -1,     3,    -1,     5,    31,    13,    14,    15,    16,
      -1,    -1,    19,    -1,    -1,    22,    23,    24,    19,    -1,
      -1,    28,    23,    24,    -1,    -1,    -1,    28,    77,    78,
      79,    80,    81,    82
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,     4,     7,     9,    10,    11,    12,    26,
      31,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    51,    52,    53,    54,    55,    56,    31,    17,    24,
      24,    24,    24,    24,    24,    41,     0,    41,    31,    31,
      31,     3,     5,    13,    14,    15,    16,    19,    22,    23,
      24,    28,    48,    50,    57,    58,    59,    60,    61,    57,
      62,    63,    57,    57,    57,    57,    57,    27,    24,    24,
      24,    24,    60,    24,    24,    57,    62,    32,    33,    34,
      35,    36,    37,    18,    19,    20,    21,    28,    25,    30,
      25,    25,    30,    30,    30,    57,    57,    57,    57,     6,
      57,    25,    29,    59,    59,    59,    59,    59,    59,    60,
      60,    60,    60,    57,    57,    42,    42,    57,    57,    57,
      25,    30,    25,    30,    25,    30,    29,     8,    25,    25,
      25,    57,    57,    57,    42,    30,    25,    25,    57,    25
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    39,    40,    41,    41,    42,    42,    42,    42,    42,
      42,    42,    42,    42,    43,    44,    45,    45,    46,    46,
      47,    48,    49,    49,    49,    49,    49,    49,    50,    51,
      52,    53,    54,    55,    55,    56,    57,    58,    58,    58,
      58,    58,    58,    58,    59,    59,    59,    59,    59,    60,
      60,    60,    60,    60,    60,    60,    60,    61,    62,    62,
      63,    63
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     2,     1,     1,     2,     2,
       1,     1,     2,     1,     3,     1,     3,     3,     5,     7,
       5,     4,     1,     1,     1,     1,     1,     1,     4,     6,
       6,     6,     6,    10,     6,     8,     1,     1,     3,     3,
       3,     3,     3,     3,     1,     3,     3,     3,     3,     1,
       1,     1,     1,     3,     2,     4,     6,     3,     0,     1,
       1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
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
  case 2: /* Program: StatementList  */
#line 71 "src/wizuall.y"
    {
        // Prepend imports to the final code
        CodeFragment imports = gen_initial_imports();
        final_code = gen_statement_list(imports, (yyvsp[0].code));
        // Code in final_code.code is now ready
        // No need to free imports or $1 here as gen_statement_list handles memory
    }
#line 1252 "src/wizuall.tab.c"
    break;

  case 3: /* StatementList: %empty  */
#line 81 "src/wizuall.y"
    { (yyval.code) = create_code_fragment(""); }
#line 1258 "src/wizuall.tab.c"
    break;

  case 4: /* StatementList: Statement StatementList  */
#line 83 "src/wizuall.y"
    { (yyval.code) = gen_statement_list((yyvsp[-1].code), (yyvsp[0].code)); }
#line 1264 "src/wizuall.tab.c"
    break;

  case 5: /* Statement: AssignmentStmt T_SEMICOLON  */
#line 86 "src/wizuall.y"
                                      { (yyval.code) = (yyvsp[-1].code); }
#line 1270 "src/wizuall.tab.c"
    break;

  case 6: /* Statement: IfStmt  */
#line 87 "src/wizuall.y"
                                  { (yyval.code) = (yyvsp[0].code); }
#line 1276 "src/wizuall.tab.c"
    break;

  case 7: /* Statement: WhileStmt  */
#line 88 "src/wizuall.y"
                                  { (yyval.code) = (yyvsp[0].code); }
#line 1282 "src/wizuall.tab.c"
    break;

  case 8: /* Statement: ExternalCallStmt T_SEMICOLON  */
#line 89 "src/wizuall.y"
                                   { (yyval.code) = (yyvsp[-1].code); }
#line 1288 "src/wizuall.tab.c"
    break;

  case 9: /* Statement: VisualizationStmt T_SEMICOLON  */
#line 90 "src/wizuall.y"
                                    { (yyval.code) = (yyvsp[-1].code); }
#line 1294 "src/wizuall.tab.c"
    break;

  case 10: /* Statement: Block  */
#line 91 "src/wizuall.y"
                                  { (yyval.code) = (yyvsp[0].code); }
#line 1300 "src/wizuall.tab.c"
    break;

  case 11: /* Statement: AuxiliaryBlock  */
#line 92 "src/wizuall.y"
                                  { (yyval.code) = (yyvsp[0].code); }
#line 1306 "src/wizuall.tab.c"
    break;

  case 12: /* Statement: error T_SEMICOLON  */
#line 93 "src/wizuall.y"
                                  { yyerrok; (yyval.code) = create_code_fragment(""); /* Error recovery */ }
#line 1312 "src/wizuall.tab.c"
    break;

  case 13: /* Statement: T_SEMICOLON  */
#line 94 "src/wizuall.y"
                                  { (yyval.code) = create_code_fragment(""); /* Allow empty statements */ }
#line 1318 "src/wizuall.tab.c"
    break;

  case 14: /* Block: T_LBRACE StatementList T_RBRACE  */
#line 99 "src/wizuall.y"
    { (yyval.code) = gen_block((yyvsp[-1].code)); }
#line 1324 "src/wizuall.tab.c"
    break;

  case 15: /* AuxiliaryBlock: T_NATIVE_CODE  */
#line 103 "src/wizuall.y"
    { (yyval.code) = gen_native_code((yyvsp[0].sval)); free((yyvsp[0].sval)); }
#line 1330 "src/wizuall.tab.c"
    break;

  case 16: /* AssignmentStmt: T_IDENTIFIER T_ASSIGN Expression  */
#line 107 "src/wizuall.y"
    {
        const char *py_name = symtab_insert(symbol_table, (yyvsp[-2].sval)); // Get/create Python var name
        (yyval.code) = gen_assignment(py_name, (yyvsp[0].code));
        free((yyvsp[-2].sval)); // Free WizuALL identifier name string
        free_code_fragment((yyvsp[0].code)); // Free expression code fragment
    }
#line 1341 "src/wizuall.tab.c"
    break;

  case 17: /* AssignmentStmt: T_IDENTIFIER T_ASSIGN CsvLoadExpr  */
#line 114 "src/wizuall.y"
    {
        const char *py_name = symtab_insert(symbol_table, (yyvsp[-2].sval));
        // $3 is the CodeFragment from CsvLoadExpr, containing the call to pandas/numpy
        (yyval.code) = gen_assignment(py_name, (yyvsp[0].code));
        free((yyvsp[-2].sval)); // Free the identifier string
        free_code_fragment((yyvsp[0].code)); // Free the CodeFragment returned by CsvLoadExpr action
    }
#line 1353 "src/wizuall.tab.c"
    break;

  case 18: /* IfStmt: T_IF T_LPAREN Expression T_RPAREN Statement  */
#line 124 "src/wizuall.y"
    {
        (yyval.code) = gen_if((yyvsp[-2].code), (yyvsp[0].code));
        free_code_fragment((yyvsp[-2].code));
        free_code_fragment((yyvsp[0].code));
    }
#line 1363 "src/wizuall.tab.c"
    break;

  case 19: /* IfStmt: T_IF T_LPAREN Expression T_RPAREN Statement T_ELSE Statement  */
#line 130 "src/wizuall.y"
    {
        (yyval.code) = gen_if_else((yyvsp[-4].code), (yyvsp[-2].code), (yyvsp[0].code));
        free_code_fragment((yyvsp[-4].code));
        free_code_fragment((yyvsp[-2].code));
        free_code_fragment((yyvsp[0].code));
    }
#line 1374 "src/wizuall.tab.c"
    break;

  case 20: /* WhileStmt: T_WHILE T_LPAREN Expression T_RPAREN Statement  */
#line 139 "src/wizuall.y"
    {
        (yyval.code) = gen_while((yyvsp[-2].code), (yyvsp[0].code));
        free_code_fragment((yyvsp[-2].code));
        free_code_fragment((yyvsp[0].code));
    }
#line 1384 "src/wizuall.tab.c"
    break;

  case 21: /* ExternalCallStmt: T_IDENTIFIER T_LPAREN OptionalArgumentList T_RPAREN  */
#line 147 "src/wizuall.y"
    {
        // Check if identifier exists. If so, assume it's a Python function (maybe from aux block)
        // Otherwise, assume it's a direct Python call (like built-ins print())
        const char *py_name = symtab_lookup(symbol_table, (yyvsp[-3].sval));
        (yyval.code) = gen_external_call(py_name ? py_name : (yyvsp[-3].sval), (yyvsp[-1].code)); // Use looked-up name or original name
        free((yyvsp[-3].sval));
        free_code_fragment((yyvsp[-1].code)); // Free combined argument list code
    }
#line 1397 "src/wizuall.tab.c"
    break;

  case 28: /* CsvLoadExpr: T_LOAD_CSV T_LPAREN T_STRING_LITERAL T_RPAREN  */
#line 165 "src/wizuall.y"
    { (yyval.code) = gen_load_csv((yyvsp[-1].sval)); free((yyvsp[-1].sval)); /* Free the filename string */ }
#line 1403 "src/wizuall.tab.c"
    break;

  case 29: /* PlotHistogramStmt: T_PLOT_HISTOGRAM T_LPAREN Expression T_COMMA Expression T_RPAREN  */
#line 169 "src/wizuall.y"
    { (yyval.code) = gen_plot_histogram((yyvsp[-3].code), (yyvsp[-1].code)); free_code_fragment((yyvsp[-3].code)); free_code_fragment((yyvsp[-1].code)); }
#line 1409 "src/wizuall.tab.c"
    break;

  case 30: /* PlotScatterStmt: T_PLOT_SCATTER T_LPAREN Expression T_COMMA Expression T_RPAREN  */
#line 173 "src/wizuall.y"
    { (yyval.code) = gen_plot_scatter((yyvsp[-3].code), (yyvsp[-1].code)); free_code_fragment((yyvsp[-3].code)); free_code_fragment((yyvsp[-1].code)); }
#line 1415 "src/wizuall.tab.c"
    break;

  case 31: /* PlotXYStmt: T_PLOT_XY T_LPAREN Expression T_COMMA Expression T_RPAREN  */
#line 177 "src/wizuall.y"
    { (yyval.code) = gen_plot_xy((yyvsp[-3].code), (yyvsp[-1].code)); free_code_fragment((yyvsp[-3].code)); free_code_fragment((yyvsp[-1].code)); }
#line 1421 "src/wizuall.tab.c"
    break;

  case 32: /* CalculateStatsStmt: T_IDENTIFIER T_ASSIGN T_CALC_STAT T_LPAREN Expression T_RPAREN  */
#line 181 "src/wizuall.y"
    {
        const char *py_name = symtab_insert(symbol_table, (yyvsp[-5].sval));
        CodeFragment stat_call = gen_calculate_stat((yyvsp[-3].sval), (yyvsp[-1].code)); // $3 is the stat function name ("calculate_average", etc.)
        (yyval.code) = gen_assignment(py_name, stat_call);
        free((yyvsp[-5].sval)); // WizuALL ID
        free((yyvsp[-3].sval)); // Stat func name string from lexer
        free_code_fragment((yyvsp[-1].code)); // Expression code
        free_code_fragment(stat_call);
    }
#line 1435 "src/wizuall.tab.c"
    break;

  case 33: /* VectorOpStmt: T_IDENTIFIER T_ASSIGN T_SLICE_VECTOR T_LPAREN Expression T_COMMA Expression T_COMMA Expression T_RPAREN  */
#line 193 "src/wizuall.y"
    {
        const char *py_name = symtab_insert(symbol_table, (yyvsp[-9].sval));
        CodeFragment slice_call = gen_slice_vector((yyvsp[-5].code), (yyvsp[-3].code), (yyvsp[-1].code));
        (yyval.code) = gen_assignment(py_name, slice_call);
        free((yyvsp[-9].sval));
        free_code_fragment((yyvsp[-5].code)); free_code_fragment((yyvsp[-3].code)); free_code_fragment((yyvsp[-1].code));
        free_code_fragment(slice_call);
    }
#line 1448 "src/wizuall.tab.c"
    break;

  case 34: /* VectorOpStmt: T_IDENTIFIER T_ASSIGN T_REVERSE_VECTOR T_LPAREN Expression T_RPAREN  */
#line 202 "src/wizuall.y"
    {
        const char *py_name = symtab_insert(symbol_table, (yyvsp[-5].sval));
        CodeFragment reverse_call = gen_reverse_vector((yyvsp[-1].code));
        (yyval.code) = gen_assignment(py_name, reverse_call);
        free((yyvsp[-5].sval));
        free_code_fragment((yyvsp[-1].code));
        free_code_fragment(reverse_call);
    }
#line 1461 "src/wizuall.tab.c"
    break;

  case 35: /* ClusterStmt: T_IDENTIFIER T_ASSIGN T_FIND_CLUSTERS T_LPAREN Expression T_COMMA Expression T_RPAREN  */
#line 213 "src/wizuall.y"
    {
        const char *py_name = symtab_insert(symbol_table, (yyvsp[-7].sval));
        CodeFragment cluster_call = gen_find_clusters((yyvsp[-3].code), (yyvsp[-1].code));
        (yyval.code) = gen_assignment(py_name, cluster_call);
        free((yyvsp[-7].sval));
        free_code_fragment((yyvsp[-3].code));
        free_code_fragment((yyvsp[-1].code));
        free_code_fragment(cluster_call);
    }
#line 1475 "src/wizuall.tab.c"
    break;

  case 36: /* Expression: ComparisonExpr  */
#line 227 "src/wizuall.y"
                               { (yyval.code) = (yyvsp[0].code); }
#line 1481 "src/wizuall.tab.c"
    break;

  case 37: /* ComparisonExpr: Term  */
#line 232 "src/wizuall.y"
                                      { (yyval.code) = (yyvsp[0].code); }
#line 1487 "src/wizuall.tab.c"
    break;

  case 38: /* ComparisonExpr: ComparisonExpr T_LT Term  */
#line 233 "src/wizuall.y"
                                  { (yyval.code) = gen_binary_op((yyvsp[-2].code), "<",  (yyvsp[0].code)); free_code_fragment((yyvsp[-2].code)); free_code_fragment((yyvsp[0].code)); }
#line 1493 "src/wizuall.tab.c"
    break;

  case 39: /* ComparisonExpr: ComparisonExpr T_GT Term  */
#line 234 "src/wizuall.y"
                                  { (yyval.code) = gen_binary_op((yyvsp[-2].code), ">",  (yyvsp[0].code)); free_code_fragment((yyvsp[-2].code)); free_code_fragment((yyvsp[0].code)); }
#line 1499 "src/wizuall.tab.c"
    break;

  case 40: /* ComparisonExpr: ComparisonExpr T_LTE Term  */
#line 235 "src/wizuall.y"
                                  { (yyval.code) = gen_binary_op((yyvsp[-2].code), "<=", (yyvsp[0].code)); free_code_fragment((yyvsp[-2].code)); free_code_fragment((yyvsp[0].code)); }
#line 1505 "src/wizuall.tab.c"
    break;

  case 41: /* ComparisonExpr: ComparisonExpr T_GTE Term  */
#line 236 "src/wizuall.y"
                                  { (yyval.code) = gen_binary_op((yyvsp[-2].code), ">=", (yyvsp[0].code)); free_code_fragment((yyvsp[-2].code)); free_code_fragment((yyvsp[0].code)); }
#line 1511 "src/wizuall.tab.c"
    break;

  case 42: /* ComparisonExpr: ComparisonExpr T_EQ Term  */
#line 237 "src/wizuall.y"
                                  { (yyval.code) = gen_binary_op((yyvsp[-2].code), "==", (yyvsp[0].code)); free_code_fragment((yyvsp[-2].code)); free_code_fragment((yyvsp[0].code)); }
#line 1517 "src/wizuall.tab.c"
    break;

  case 43: /* ComparisonExpr: ComparisonExpr T_NEQ Term  */
#line 238 "src/wizuall.y"
                                  { (yyval.code) = gen_binary_op((yyvsp[-2].code), "!=", (yyvsp[0].code)); free_code_fragment((yyvsp[-2].code)); free_code_fragment((yyvsp[0].code)); }
#line 1523 "src/wizuall.tab.c"
    break;

  case 44: /* Term: Factor  */
#line 242 "src/wizuall.y"
                           { (yyval.code) = (yyvsp[0].code); }
#line 1529 "src/wizuall.tab.c"
    break;

  case 45: /* Term: Term T_PLUS Factor  */
#line 243 "src/wizuall.y"
                            { (yyval.code) = gen_binary_op((yyvsp[-2].code), "+", (yyvsp[0].code)); free_code_fragment((yyvsp[-2].code)); free_code_fragment((yyvsp[0].code)); }
#line 1535 "src/wizuall.tab.c"
    break;

  case 46: /* Term: Term T_MINUS Factor  */
#line 244 "src/wizuall.y"
                            { (yyval.code) = gen_binary_op((yyvsp[-2].code), "-", (yyvsp[0].code)); free_code_fragment((yyvsp[-2].code)); free_code_fragment((yyvsp[0].code)); }
#line 1541 "src/wizuall.tab.c"
    break;

  case 47: /* Term: Term T_MULTIPLY Factor  */
#line 245 "src/wizuall.y"
                            { (yyval.code) = gen_binary_op((yyvsp[-2].code), "*", (yyvsp[0].code)); free_code_fragment((yyvsp[-2].code)); free_code_fragment((yyvsp[0].code)); }
#line 1547 "src/wizuall.tab.c"
    break;

  case 48: /* Term: Term T_DIVIDE Factor  */
#line 246 "src/wizuall.y"
                            { (yyval.code) = gen_binary_op((yyvsp[-2].code), "/", (yyvsp[0].code)); free_code_fragment((yyvsp[-2].code)); free_code_fragment((yyvsp[0].code)); }
#line 1553 "src/wizuall.tab.c"
    break;

  case 49: /* Factor: T_IDENTIFIER  */
#line 251 "src/wizuall.y"
    {
        const char *py_name = symtab_lookup(symbol_table, (yyvsp[0].sval));
        if (!py_name) {
            // Use fprintf for errors, yyerror might try to print yytext which isn't relevant here
            fprintf(stderr, "Error line %d: Undeclared variable '%s'\n", yylineno, (yyvsp[0].sval));
            yynerrs++; // Increment error count manually
            free((yyvsp[0].sval));
            (yyval.code) = create_code_fragment("None"); // Return dummy code on error
        } else {
            (yyval.code) = gen_variable_access(py_name);
            free((yyvsp[0].sval)); // Free WizuALL identifier string
        }
    }
#line 1571 "src/wizuall.tab.c"
    break;

  case 50: /* Factor: T_NUMBER  */
#line 264 "src/wizuall.y"
                             { (yyval.code) = gen_number_literal((yyvsp[0].dval)); }
#line 1577 "src/wizuall.tab.c"
    break;

  case 51: /* Factor: VectorLiteral  */
#line 265 "src/wizuall.y"
                             { (yyval.code) = (yyvsp[0].code); }
#line 1583 "src/wizuall.tab.c"
    break;

  case 52: /* Factor: ExternalCallStmt  */
#line 266 "src/wizuall.y"
                             { (yyval.code) = (yyvsp[0].code); }
#line 1589 "src/wizuall.tab.c"
    break;

  case 53: /* Factor: T_LPAREN Expression T_RPAREN  */
#line 267 "src/wizuall.y"
                                   { (yyval.code) = (yyvsp[-1].code); }
#line 1595 "src/wizuall.tab.c"
    break;

  case 54: /* Factor: T_MINUS Factor  */
#line 268 "src/wizuall.y"
                                  { (yyval.code) = gen_unary_minus((yyvsp[0].code)); free_code_fragment((yyvsp[0].code)); }
#line 1601 "src/wizuall.tab.c"
    break;

  case 55: /* Factor: Factor T_LBRACKET Expression T_RBRACKET  */
#line 270 "src/wizuall.y"
    {
        // Generate Python code like vector_code[int(index_code)]
        // Ensure index is treated as integer if necessary by Python slice rules
        char* code_str = format_string("%s[int(%s)]", (yyvsp[-3].code).code, (yyvsp[-1].code).code);
        (yyval.code) = create_code_fragment(code_str);
        free(code_str);
        free_code_fragment((yyvsp[-3].code)); // Free the vector variable code
        free_code_fragment((yyvsp[-1].code)); // Free the index expression code
    }
#line 1615 "src/wizuall.tab.c"
    break;

  case 56: /* Factor: T_GET_COLUMN T_LPAREN Expression T_COMMA Expression T_RPAREN  */
#line 280 "src/wizuall.y"
    {
        // Expression $3 is the data source (e.g., variable name fragment)
        // Expression $5 is the column index fragment
        (yyval.code) = gen_get_column((yyvsp[-3].code), (yyvsp[-1].code));
        free_code_fragment((yyvsp[-3].code)); // Free fragment used for data arg
        free_code_fragment((yyvsp[-1].code)); // Free fragment used for index arg
    }
#line 1627 "src/wizuall.tab.c"
    break;

  case 57: /* VectorLiteral: T_LBRACKET OptionalArgumentList T_RBRACKET  */
#line 291 "src/wizuall.y"
    { (yyval.code) = gen_vector_literal((yyvsp[-1].code)); free_code_fragment((yyvsp[-1].code)); }
#line 1633 "src/wizuall.tab.c"
    break;

  case 58: /* OptionalArgumentList: %empty  */
#line 294 "src/wizuall.y"
                                  { (yyval.code) = create_code_fragment(""); }
#line 1639 "src/wizuall.tab.c"
    break;

  case 59: /* OptionalArgumentList: ArgumentList  */
#line 295 "src/wizuall.y"
                                { (yyval.code) = (yyvsp[0].code); }
#line 1645 "src/wizuall.tab.c"
    break;

  case 60: /* ArgumentList: Expression  */
#line 298 "src/wizuall.y"
                                          { (yyval.code) = (yyvsp[0].code); }
#line 1651 "src/wizuall.tab.c"
    break;

  case 61: /* ArgumentList: ArgumentList T_COMMA Expression  */
#line 299 "src/wizuall.y"
                                      { // Changed order for left-recursion & easier combining
        // Combine C strings: $1.code + ", " + $3.code
        char *combined = malloc(strlen((yyvsp[-2].code).code) + strlen((yyvsp[0].code).code) + 3); // Code1 + ", " + Code3 + \0
        if (!combined) { yyerror("Memory allocation failed for args"); YYABORT; }
        sprintf(combined, "%s, %s", (yyvsp[-2].code).code, (yyvsp[0].code).code);
        (yyval.code) = create_code_fragment(combined);
        free(combined);
        free_code_fragment((yyvsp[-2].code)); // Free the code for the list part
        free_code_fragment((yyvsp[0].code)); // Free the code for the new expression part
     }
#line 1666 "src/wizuall.tab.c"
    break;


#line 1670 "src/wizuall.tab.c"

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
  ++yynerrs;

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
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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

#line 311 "src/wizuall.y"


/* Error Handling Function */
void yyerror(const char *s) {
    // yytext contains the token that caused the syntax error
    fprintf(stderr, "Syntax Error: %s at line %d near '%s'\n", s, yylineno, yytext);
}
