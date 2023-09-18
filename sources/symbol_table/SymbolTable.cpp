#include "../../headers/symbol_table/SymbolTable.hpp"

SymbolTable symbolTable;

SymbolTable::~SymbolTable() {

	for (auto it = table.begin(); it != table.end(); ++it) {
		free(it->second.value);
	}
}

void SymbolTable::addSymbol(const string& name, Type type) {
	if (table.find(name) != table.end()) {
		throw runtime_error("Symbol " + name + " already exists");
	}

	Symbol symbol;
	symbol.type = type;

	switch (type) {
		case Type::integer:
			symbol.value = new int(0);
			break;
		case Type::character:
			symbol.value = new char('\0');
			break;
		case Type::word:
			symbol.value = new string("");
			break;
		case Type::sentence:
			symbol.value = new string("\n");
			break;
		case Type::identifier:
		default:
			break;
	}

	table[name] = symbol;
}

void* SymbolTable::getSymbolValue(const string& name) {
	if (table.find(name) == table.end()) {
		throw runtime_error("Symbol " + name + " not found");
	}
	return table[name].value;
}

void SymbolTable::setSymbolValue(const string& name, void* value, Type type) {
	Symbol symbol;
	if (this->getSymbolType(name) != type) {
		throw runtime_error("Symbol type mismatch");
	}

	free(this->getSymbolValue(name));

	switch (type) {
		case Type::integer:
			symbol.value = new int(*(int*)value);
			break;
		case Type::character:
			symbol.value = new char(*(char*)value);
			break;
		case Type::word:
		case Type::sentence:
			symbol.value = new string(*(string*)value);
			break;
		case Type::identifier:
		default:
			break;
	}
	symbol.type = type;
	table[name] = symbol;
}

Type SymbolTable::getSymbolType(const string& name) {
	if (table.find(name) == table.end()) {
		throw runtime_error("Symbol " + name + " not found");
	}
	return table[name].type;
}

void SymbolTable::removeSymbol(const string& name) {
	if (table.find(name) == table.end()) {
		throw runtime_error("Symbol " + name + " not found");
	}
	free(table[name].value);
	table.erase(name);
}

void printDepth(int level, ofstream& out) {
	for (int i = 0; i <= level; i++) {
		out << "\t";
	}
}