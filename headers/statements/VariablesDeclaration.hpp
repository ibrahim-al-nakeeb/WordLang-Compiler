#pragma once

#ifndef VARIABLES_DECLARATION_STATEMENT_H
#define VARIABLES_DECLARATION_STATEMENT_H


#include <list>
#include "Statement.hpp"

class VariablesDeclaration : public Statement {

	Type type;
	list<string> variablesList;


public:
	VariablesDeclaration(Type t, list<string> vl);
	~VariablesDeclaration();
	
	void execute() override;
	list<string> getVariables();
	void print(int level, ofstream& out) override;
};



#endif // VARIABLES_DECLARATION_STATEMENT_H