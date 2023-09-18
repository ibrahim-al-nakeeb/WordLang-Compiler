#pragma once

#ifndef ASSIGN_STATEMENT_H
#define ASSIGN_STATEMENT_H

#include "Statement.hpp"


class Assign : public Statement {

	string variable;
	Expression* expression;

public:
	Assign(string v, Expression* e);
	~Assign();
	
	void execute() override;
	void print(int level, ofstream& out) override;
};



#endif // ASSIGN_STATEMENT_H