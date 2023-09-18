#include "../../headers/controls/While.hpp"


While::While(Condition* c, list<Statement*> *bs) : Control(bs), condition(c) {}

While::~While() {
	delete condition;
}

void While::execute() {
	while (condition->evaluate()) {
		list<string> blockDefines;
		for (auto& statement : *blockStatement) {
			if (dynamic_cast<VariablesDeclaration*>(statement) != nullptr) {
				VariablesDeclaration* defineStatement = static_cast<VariablesDeclaration*>(statement);
				const auto& varsList = defineStatement->getVariables();
				for (const auto& var : varsList) {
					blockDefines.push_back(var);
				}
			}
			statement->execute();
		}
		for (auto& define : blockDefines) {
			symbolTable.removeSymbol(define);
		}
	}
}

void While::print(int level, ofstream& out) {
	printDepth(level ,out);
	out << "new While(" << endl;
	condition->print(level + 1, out);
	out << "," << endl;
	printDepth(level + 1, out);
	out << "new list<Statement*>({" << endl;
	for (auto& statement : *blockStatement) {
		statement->print(level + 2, out);
		out << "," << endl;
	}
	printDepth(level + 1, out);
	out << "})" << endl;
	printDepth(level, out);
	out << ")" << endl;
}