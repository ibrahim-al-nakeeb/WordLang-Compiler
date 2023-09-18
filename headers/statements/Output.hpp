#pragma once

#ifndef OUTPUT_STATEMENT_H
#define OUTPUT_STATEMENT_H

#include "Statement.hpp"

class Output : public Statement {

	Expression* expression;
	Condition*	condition;

public:
	Output(Condition* c);
	Output(Expression* e);
	~Output();
	
	void execute() override;
	void print(int level, ofstream& out) override;
};


#endif // OUTPUT_STATEMENT_H