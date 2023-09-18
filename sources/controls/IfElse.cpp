#include "../../headers/controls/IfElse.hpp"

IfElse::IfElse(Condition *c, list<Statement*> *bs, list<Statement*> *sbs) : Control(bs), condition(c), secondBlockStatement(sbs) {}

IfElse::~IfElse() {
	delete condition;
	for (auto& statement : *secondBlockStatement)
		delete statement;
}

void IfElse::execute() {
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
	else {
		list<string> blockDefines;
		for (auto& statement : *secondBlockStatement) {
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


void IfElse::print(int level, ofstream& out) {
	printDepth(level, out);
	out << "new IfElse(" << endl;
	condition->print(level + 1, out);
	out << "," << endl;
	printDepth(level + 1, out);
	out << "new list<Statement*>({" << endl;
	for (auto& statement : *blockStatement) {
		statement->print(level + 2, out);
		out << "," << endl;
	}
	printDepth(level + 1, out);
	out << "})";
	out << "," << endl;
	printDepth(level + 1, out);
	out << "new list<Statement*>({" << endl;
	for (auto& statement : *secondBlockStatement) {
		statement->print(level + 2, out);
		out << "," << endl;
	}
	printDepth(level + 1, out);
	out << "})" << endl;
	printDepth(level, out);
	out << ")" << endl;
}