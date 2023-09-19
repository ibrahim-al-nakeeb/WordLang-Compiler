/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     MINUS = 258,
     PLUS = 259,
     CONCAT = 260,
     INDEX = 261,
     INT = 262,
     CHAR = 263,
     WORD = 264,
     SENTENCE = 265,
     IF = 266,
     ELSE = 267,
     WHILE = 268,
     LOOP = 269,
     INPUT = 270,
     OUTPUT = 271,
     LT = 272,
     GT = 273,
     LE = 274,
     GE = 275,
     EQ = 276,
     NE = 277,
     NOT = 278,
     COMMA = 279,
     ASSIGN = 280,
     LPAREN = 281,
     RPAREN = 282,
     LBRACE = 283,
     RBRACE = 284,
     SEMICOLON = 285,
     PREC_ELSE = 286,
     INTEGER_LITERAL = 287,
     CHAR_LITERAL = 288,
     IDENTIFIER = 289,
     WORD_LITERAL = 290,
     SENTENCE_LITERAL = 291
   };
#endif
/* Tokens.  */
#define MINUS 258
#define PLUS 259
#define CONCAT 260
#define INDEX 261
#define INT 262
#define CHAR 263
#define WORD 264
#define SENTENCE 265
#define IF 266
#define ELSE 267
#define WHILE 268
#define LOOP 269
#define INPUT 270
#define OUTPUT 271
#define LT 272
#define GT 273
#define LE 274
#define GE 275
#define EQ 276
#define NE 277
#define NOT 278
#define COMMA 279
#define ASSIGN 280
#define LPAREN 281
#define RPAREN 282
#define LBRACE 283
#define RBRACE 284
#define SEMICOLON 285
#define PREC_ELSE 286
#define INTEGER_LITERAL 287
#define CHAR_LITERAL 288
#define IDENTIFIER 289
#define WORD_LITERAL 290
#define SENTENCE_LITERAL 291




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 11 "wordlang.y"
{
	char	CHARACTER;
	int		INTEGER;
	char	*STRING;
	void	*VOID;
}
/* Line 1529 of yacc.c.  */
#line 128 "headers/bison/wordlang.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

