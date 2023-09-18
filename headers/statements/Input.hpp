#pragma once

#ifndef INPUT_STATEMENT_H
#define INPUT_STATEMENT_H

#include <regex>
#include "Statement.hpp"


class Input : public Statement {

	string variable;
	Expression* prompt;


public:
	Input(string v, Expression* e);
	~Input();
	
	void execute() override;
	void print(int level, ofstream& out) override;
};

#endif // INPUT_STATEMENT_H