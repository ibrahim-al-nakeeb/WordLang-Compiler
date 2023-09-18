#include "../../headers/controls/If.hpp"

If::If(Condition* c, list<Statement*> *bs) : Control(bs), condition(c) {}

If::~If() {
	delete condition;
}

void If::execute() {
	if (condition->evaluate()) {
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

void If::print(int level, ofstream& out) {
	printDepth(level, out);
	out << "new If(" << endl;
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

