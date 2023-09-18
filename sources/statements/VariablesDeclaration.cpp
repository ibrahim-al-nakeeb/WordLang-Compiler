#include "../../headers/statements/VariablesDeclaration.hpp"

VariablesDeclaration::VariablesDeclaration(Type t, list<string> vl) : type(t), variablesList(vl) {}

VariablesDeclaration::~VariablesDeclaration() {}

void VariablesDeclaration::execute() {
	for (auto it = variablesList.begin(); it != variablesList.end(); it++) {
		symbolTable.addSymbol(*it, type);
	}
}

list<string> VariablesDeclaration::getVariables() {
	return variablesList;
}


void VariablesDeclaration::print(int level, ofstream& out) {

	printDepth(level, out);
	out << "new VariablesDeclaration(" << endl;
	printDepth(level + 1, out);
	out << "Type::" ;
	switch (this->type) {
		case Type::integer:
			out << "integer";
			break;
		case Type::character:
			out << "character";
			break;
		case Type::word:
			out << "word";
			break;
		case Type::sentence:
			out << "sentence";
			break;
		case Type::identifier:
		default:
			break;
	}
	out << endl;
	printDepth(level + 1, out);
	out << ", {" << endl;
	for (auto& var : variablesList) {
		printDepth(level + 2, out);
		out << "\"" << var << "\"," << endl;
	}
	printDepth(level + 1, out);
	out << "}" << endl;
	printDepth(level, out);
	out << ")";
}