#pragma once

#ifndef WORD_LANG_H
#define WORD_LANG_H

#include "term/Term.hpp"
#include "controls/If.hpp"
#include "controls/Loop.hpp"
#include "controls/While.hpp"
#include "controls/IfElse.hpp"
#include "statements/Input.hpp"
#include "statements/Output.hpp"
#include "statements/Assign.hpp"
#include "symbol_table/SymbolTable.hpp"
#include "conditions/UnaryCondition.hpp"
#include "conditions/BinaryCondition.hpp"
#include "statements/ControlStatement.hpp"
#include "expressions/UnaryExpression.hpp"
#include "expressions/BinaryExpression.hpp"
#include "statements/VariablesDeclaration.hpp"



void freeProgram(list<Statement*> *prog) {
	if (prog == nullptr)
		return;
	for (auto it = prog->begin(); it != prog->end(); ++it) {
		delete *it;
	}
	delete prog;
}

void executeProgram(list<Statement*> *prog) {
	
	if (prog == nullptr)
		return;
	for (auto it = prog->begin(); it != prog->end(); ++it) {
		try {
			(*it)->execute();
		} catch (const runtime_error& e) {
			cout << e.what() << endl;
			freeProgram(prog);
			exit(EXIT_FAILURE);
		}
	}
}

void yyerror(const string message) {
	cout << message << endl;
	exit(EXIT_FAILURE);
}


void build(list<Statement*> *prog) {

	ofstream result("sources/result/result.cpp");
	if (!result.is_open()) {
		cout << "Error opening file" << endl;
		exit(EXIT_FAILURE);
	}
	result << "#include \"../../headers/wordlang.hpp\"" << endl;
	result << endl << endl << endl;
	result << "int main(int argc, char *argv[]) {" << endl << endl;
	result << "\tlist<Statement*> *program = new list<Statement*>({" << endl;
	if (prog != nullptr) {
		for (auto it = prog->begin(); it != prog->end(); ++it) {
			(*it)->print(1, result);
			result << "," << endl;
		}
	}
	result << "\t});" << endl;
	result << "\texecuteProgram(program);" << endl;
	result << "\tfreeProgram(program);" << endl;
	result << "\treturn EXIT_SUCCESS;" << endl;
	result << "}" << endl;
}


#endif // WORD_LANG_H