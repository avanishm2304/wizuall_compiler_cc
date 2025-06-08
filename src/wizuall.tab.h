/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SRC_WIZUALL_TAB_H_INCLUDED
# define YY_YY_SRC_WIZUALL_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    T_IDENTIFIER = 258,            /* T_IDENTIFIER  */
    T_NATIVE_CODE = 259,           /* T_NATIVE_CODE  */
    T_NUMBER = 260,                /* T_NUMBER  */
    T_STRING_LITERAL = 261,        /* T_STRING_LITERAL  */
    T_IF = 262,                    /* T_IF  */
    T_ELSE = 263,                  /* T_ELSE  */
    T_WHILE = 264,                 /* T_WHILE  */
    T_PLOT_HISTOGRAM = 265,        /* T_PLOT_HISTOGRAM  */
    T_PLOT_SCATTER = 266,          /* T_PLOT_SCATTER  */
    T_PLOT_XY = 267,               /* T_PLOT_XY  */
    T_CALC_STAT = 268,             /* T_CALC_STAT  */
    T_SLICE_VECTOR = 269,          /* T_SLICE_VECTOR  */
    T_REVERSE_VECTOR = 270,        /* T_REVERSE_VECTOR  */
    T_FIND_CLUSTERS = 271,         /* T_FIND_CLUSTERS  */
    T_ASSIGN = 272,                /* T_ASSIGN  */
    T_PLUS = 273,                  /* T_PLUS  */
    T_MINUS = 274,                 /* T_MINUS  */
    T_MULTIPLY = 275,              /* T_MULTIPLY  */
    T_DIVIDE = 276,                /* T_DIVIDE  */
    T_LOAD_CSV = 277,              /* T_LOAD_CSV  */
    T_GET_COLUMN = 278,            /* T_GET_COLUMN  */
    T_LPAREN = 279,                /* T_LPAREN  */
    T_RPAREN = 280,                /* T_RPAREN  */
    T_LBRACE = 281,                /* T_LBRACE  */
    T_RBRACE = 282,                /* T_RBRACE  */
    T_LBRACKET = 283,              /* T_LBRACKET  */
    T_RBRACKET = 284,              /* T_RBRACKET  */
    T_COMMA = 285,                 /* T_COMMA  */
    T_SEMICOLON = 286,             /* T_SEMICOLON  */
    T_LT = 287,                    /* T_LT  */
    T_GT = 288,                    /* T_GT  */
    T_LTE = 289,                   /* T_LTE  */
    T_GTE = 290,                   /* T_GTE  */
    T_EQ = 291,                    /* T_EQ  */
    T_NEQ = 292,                   /* T_NEQ  */
    UMINUS = 293                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 30 "src/wizuall.y"

    double dval;        /* For numeric literals */
    char *sval;         /* For identifiers, native code, function names */
    CodeFragment code; /* For generated code fragments */

#line 108 "src/wizuall.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SRC_WIZUALL_TAB_H_INCLUDED  */
