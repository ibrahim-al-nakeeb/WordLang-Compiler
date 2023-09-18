%{
	#include <string>
	#include <iostream>
	#include "../headers/bison/wordlang.tab.hpp"
	void yyerror (const std::string message);
	int yylex();
%}

%%

	/* Control tokens */
"sentence"					{ return SENTENCE;				}
"int"						{ return INT;					}
"char"						{ return CHAR;					}
"word"						{ return WORD;					}


	/* Data type tokens */
"if"						{ return IF;					}
"else"						{ return ELSE;					}
"while"						{ return WHILE;					}
"loop"						{ return LOOP;					}

	/* Input/Output tokens */
"input"						{ return INPUT;					}
"output"					{ return OUTPUT;				}

	/* Punctuation tokens */
","							{ return COMMA;					}
"="							{ return ASSIGN;				}
"("							{ return LPAREN;				}
")"							{ return RPAREN;				}
"{"							{ return LBRACE;				}
"}"							{ return RBRACE;				}
";"							{ return SEMICOLON;				}

	/* Arithmetic and String manipulation tokens */
"#"							{ return CONCAT;				}
"-"							{ return MINUS;					}
"+"							{ return PLUS;					}
":"							{ return INDEX;					}


	/* Comparison operators */
"!="						{ return NE;					}
"<"							{ return LT;					}
">"							{ return GT;					}
"=="						{ return EQ;					}
">="						{ return GE;					}
"<="						{ return LE;					}


	/* Logical operators */
"!"							{ return NOT;					}



	/* TERMINALS */


	/* String literals (sentence) */
\^[^\^]*\^ 					{
								yytext[strlen(yytext)-1] = '\0';
								yylval.STRING = (char*) malloc(strlen(yytext+1) + 2);
								strcpy(yylval.STRING, yytext+1);
								strcat(yylval.STRING, "\n");
								return SENTENCE_LITERAL;
							}

	/* Character literals */
'[^']?' 					{
								if (strlen(yytext) == 2)
									yylval.CHARACTER = '\0';
								else
									yylval.CHARACTER = yytext[1];
								return CHAR_LITERAL;
							}

	/* String literals (word) */
\"[^\"\ ]*\" 				{
								yytext[strlen(yytext)-1] = '\0';
								yylval.STRING = strdup(yytext+1);
								return WORD_LITERAL;
							}

	/* Identifier */
[a-zA-Z_][a-zA-Z0-9_]* 		{
								if (strlen(yytext) > 32)
									yyerror("Error: The variable cannot exceed 32 characters.");
								yylval.STRING = strdup(yytext);
								return IDENTIFIER;
							}

	/* Integer literals */
[0-9]+ 						{
								yylval.INTEGER = atoi(yytext);
								return INTEGER_LITERAL;
							}


	/* Comments and whitespace */
\/\/.*						{ }
[ \t\n]						{ }

%%

int yywrap(void) {
	return 1;
}