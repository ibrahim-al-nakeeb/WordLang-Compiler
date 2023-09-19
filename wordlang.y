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

%type <VOID> term
%type <VOID> block
%type <INTEGER> type
%type <VOID> control
%type <VOID> statement
%type <VOID> condition
%type <VOID> expression
%type <VOID> statements
%type <VOID> variablesList

%left PLUS MINUS
%left CONCAT
%left INDEX

%%

prog:
		statements	{ program = (list<Statement*>*)$1; }
	|				{}
	;

control:
		IF LPAREN condition RPAREN block %prec PREC_ELSE {
			$$ = new If((Condition*)$3, (list<Statement*>*)$5);
		}
	|	IF LPAREN condition RPAREN block ELSE block {
			$$ = new IfElse((Condition*)$3, (list<Statement*>*)$5, (list<Statement*>*)$7);
		}
	|	WHILE LPAREN condition RPAREN block {
			$$ = new While((Condition*)$3, (list<Statement*>*)$5);
		}
	|	LOOP LPAREN expression RPAREN block {
			$$ = new Loop((Expression*)$3, (list<Statement*>*)$5);
		}
	;



block:
		LBRACE statements RBRACE { $$ = $2; }
	|	statement { 
			list<Statement*> *list = new ::list<Statement*>();
			list->push_back((Statement*)$1);
			$$ = list;
	 	}
	;



statements:
		statements statement {
			static_cast<list<Statement*>*>($1)->push_back((Statement*)$2); 
			$$ = $1;
		}
	|	statement { 
			list<Statement*> *list = new ::list<Statement*>();
			list->push_back((Statement*)$1);
			$$ = list;
		}
	;



statement:
		type IDENTIFIER variablesList SEMICOLON {
			list<string> *ptr = static_cast<list<string>*>($3);
			ptr->push_back($2);
			free($2);
			$$ = new VariablesDeclaration((Type)$1, *ptr);
			delete ptr;
			
		}
	|	IDENTIFIER ASSIGN expression SEMICOLON {
			$$ = new Assign($1, (Expression*)$3);
			free($1);
		}
	|	OUTPUT expression SEMICOLON {
			$$ = new Output((Expression*)$2); 
		}
	|	OUTPUT condition SEMICOLON {
			$$ =new Output((Condition*)$2);
		}
	|	INPUT expression IDENTIFIER SEMICOLON {
			$$ = new Input($3, (Expression*)$2);
			free($3);
		}
	|	control {
			$$ = new ControlStatement((Control*)$1);
		}
	;


condition:
		expression NE expression {
			$$ = new BinaryCondition((Expression*)$1, (Expression*)$3, ComparisonOperator::NotEqual);
		}
	|	expression LT expression {
			$$ = new BinaryCondition((Expression*)$1, (Expression*)$3, ComparisonOperator::LessThan);
		}
	|	expression GT expression {
			$$ = new BinaryCondition((Expression*)$1, (Expression*)$3,  ComparisonOperator::GreaterThan);
		}
	|	expression EQ expression {
			$$ = new BinaryCondition((Expression*)$1, (Expression*)$3, ComparisonOperator::Equal);
		}
	|	expression GE expression {
			$$ = new BinaryCondition((Expression*)$1, (Expression*)$3, ComparisonOperator::GreaterThanOrEqual);
		}
	|	expression LE expression {
			$$ = new BinaryCondition((Expression*)$1, (Expression*)$3, ComparisonOperator::LessThanOrEqual);
		}
	|	expression {
			$$ = new UnaryCondition((Expression*)$1);
		}
	
	|	NOT condition {
			$$ = new UnaryCondition((Condition*)$2);
		}
	;

expression:	
		expression CONCAT expression {
			$$ = new BinaryExpression((Expression*)$1, Action::concat, (Expression*)$3);
		}		
	|	expression MINUS expression {
			$$ = new BinaryExpression((Expression*)$1, Action::minus, (Expression*)$3);
		}
	|	expression PLUS expression {
			$$ = new BinaryExpression((Expression*)$1, Action::plus, (Expression*)$3);	
		}
	|	expression INDEX expression {
			$$ = new BinaryExpression((Expression*)$1, Action::index, (Expression*)$3);
		}
	|	LPAREN expression RPAREN {
			$$ = $2;
		}
	|	term {
			$$ = new UnaryExpression((term*)$1);
		}
	;

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


nt main(int argc, char *argv[]) {

	// Check if there's at least one argument provided (besides the program name itself)
	if (argc < 2) {
		cout << "Please specify an input file" << endl << "Usage: \033[32m./wordlang <file>\033[0m" << endl; 
		return EXIT_FAILURE;
	}

	// Try to open the file provided as an argument
	yyin = fopen(argv[1], "r");
	if (yyin == nullptr) {
		// Print an error message if the file couldn't be opened
		cerr << "Error: Unable to open file '" << argv[1] << "'." << endl;
		return EXIT_FAILURE;
	}

	// Parse the input
	yyparse();

	// Build the program
	build(program);

	// Close the input file
	fclose(yyin);

	freeProgram(program);

	cout << "Wordlang file compiled successfully." << endl << "Run:\n\033[32mmake run\033[0m" << endl;

	return EXIT_SUCCESS;
}