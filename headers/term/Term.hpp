#pragma once

#ifndef Term_H
#define Term_H

#include "../symbol_table/SymbolTable.hpp"

using namespace std;

class Term {

	void* value;
	Type type;

public:
	Term();
	Term(const Term& t);
	Term(void* value, Type type);
	virtual ~Term();

	void* getValue() const;
	Type getType() const;
	void print(int level, ofstream& out);
};

#endif // Term_H
