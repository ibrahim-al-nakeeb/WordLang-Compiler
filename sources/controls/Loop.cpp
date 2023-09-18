#include "../../headers/controls/Loop.hpp"

Loop::Loop(Expression* e, list<Statement*> *bs) : Control(bs), expression(e) {}

Loop::~Loop() {
	delete expression;
}

void Loop::execute() {

	Term term = expression->evaluate();
	
	if (term.getType() != Type::integer) {
		throw runtime_error("Loop condition must be integer");
	}
	int rounds = *(int*)term.getValue();

	for (int i = 0; i < rounds; i++) {
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

void Loop::print(int level, ofstream& out) {
	printDepth(level, out);
	out << "new Loop(" << endl;
	expression->print(level + 1, out);
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