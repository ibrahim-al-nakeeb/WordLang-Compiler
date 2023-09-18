%{
	#include "../headers/wordlang.hpp"
	
	int yylex();

	list<Statement*> *program = nullptr;

	extern FILE *yyin;
%}

%union {
	char	CHARACTER;
	int		INTEGER;
	char	*STRING;
	void	*VOID;
}

%start prog

%token MINUS	PLUS	CONCAT	INDEX
%token INT		CHAR	WORD	SENTENCE 
%token IF		ELSE	WHILE	LOOP	INPUT	OUTPUT
%token LT		GT		LE		GE		EQ		NE		NOT 
%token COMMA	ASSIGN	LPAREN	RPAREN	LBRACE	RBRACE	SEMICOLON

%nonassoc PREC_ELSE
%nonassoc ELSE

%token <INTEGER> INTEGER_LITERAL
%token <CHARACTER> CHAR_LITERAL
%token <STRING> IDENTIFIER WORD_LITERAL SENTENCE_LITERAL

%left PLUS MINUS
%left CONCAT
%left INDEX

