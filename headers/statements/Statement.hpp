#pragma once

#ifndef STATEMENT_H
#define STATEMENT_H


#include "../conditions/Condition.hpp"
#include "../symbol_table/SymbolTable.hpp"

class Statement {

public:
	virtual ~Statement();
	virtual void execute() = 0;
	virtual void print(int level, ofstream& out) = 0;
};

#endif // STATEMENT_H