#include "../../headers/statements/Assign.hpp"

Assign::Assign(string v, Expression* e) : variable(v), expression(e) {}

Assign::~Assign() {
	delete expression;
}


void Assign::execute() {
	
	Type symbolType = symbolTable.getSymbolType(variable);
	Term term = expression->evaluate();
	if (symbolType != term.getType())
		throw runtime_error("Symbol type mismatch");
	symbolTable.setSymbolValue(variable, term.getValue(), term.getType());

}

void Assign::print(int level, ofstream& out) {
	printDepth(level, out);
	out << "new Assign(" << endl;
	printDepth(level + 1, out);
	out << "\"" << variable << "\"," << endl;
	expression->print(level + 1, out);
	out << endl;
	printDepth(level, out);
	out << ")";
}
