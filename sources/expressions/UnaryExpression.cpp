#include "../../headers/expressions/UnaryExpression.hpp"

UnaryExpression::UnaryExpression(Term* t) : Term(t) {}

UnaryExpression::~UnaryExpression() {
	delete Term;
}

Term UnaryExpression::evaluate() {
	return *Term;
}

void UnaryExpression::print(int level, ofstream& out) {
	printDepth(level, out);
	out << "new UnaryExpression(" << endl;
	Term->print(level + 1, out);
	printDepth(level, out);
	out << ")";
}