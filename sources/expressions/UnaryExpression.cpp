#include "../../headers/expressions/UnaryExpression.hpp"

UnaryExpression::UnaryExpression(Term* t) : term(t) {}

UnaryExpression::~UnaryExpression() {
	delete term;
}

Term UnaryExpression::evaluate() {
	return *term;
}

void UnaryExpression::print(int level, ofstream& out) {
	printDepth(level, out);
	out << "new UnaryExpression(" << endl;
	term->print(level + 1, out);
	printDepth(level, out);
	out << ")";
}