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

%type <INTEGER> type
%type <VOID> term
%type <VOID> variablesList

%left PLUS MINUS
%left CONCAT
%left INDEX

%%

variablesList:
		variablesList COMMA IDENTIFIER { 
			static_cast<list<string>*>($1)->push_back($3);
			free($3);
			$$ = $1;
		}
	|	{ $$ = new list<string>(); }
	;

term:
		SENTENCE_LITERAL {
			string *str = new string($1);
			$$ = new Terminal(str, Type::sentence);
			free($1);
		}
	|	CHAR_LITERAL { 
			char *ptr = new char($1);
			$$ = new Terminal(ptr, Type::character);
		}
	|	WORD_LITERAL {
			string *str = new string($1);
			$$ = new Terminal(str, Type::word);
			free($1);
		}
	|	IDENTIFIER {
			string *str = new string($1);
			$$ = new Terminal(str, Type::identifier);
			free($1);
		}
	|	INTEGER_LITERAL { 
			int *ptr = new int($1);
			$$ = new Terminal(ptr, Type::integer);
		}
	|	MINUS INTEGER_LITERAL {
			int *ptr = new int(-1*$2);
			$$ = new Terminal(ptr, Type::integer);
		}
	;

type:
		SENTENCE	{ $$ = (int)Type::sentence;		}
	|	INT			{ $$ = (int)Type::integer;		}
	|	CHAR		{ $$ = (int)Type::character;	}
	|	WORD		{ $$ = (int)Type::word;			}
	;

%%

