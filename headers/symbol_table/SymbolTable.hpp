#pragma once

#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <string>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <unordered_map>


enum class Type {
	integer,
	character,
	word,
	sentence,
	identifier
};

using namespace std;


class SymbolTable {
public:
	~SymbolTable();

	void addSymbol(const string& name, Type type);
	void* getSymbolValue(const string& name);
	void setSymbolValue(const string& name, void* value, Type type);
	Type getSymbolType(const string& name);
	void removeSymbol(const string& name);


private:

	struct Symbol {
		Type	type;
		void*	value;
	};

	unordered_map<string, Symbol> table;
};

extern SymbolTable symbolTable;

void printDepth(int level, ofstream& out);

#endif // SYMBOL_TABLE_H
