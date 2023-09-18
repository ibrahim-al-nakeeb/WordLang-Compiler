#include "../../headers/expressions/BinaryExpression.hpp"

BinaryExpression::BinaryExpression(Expression* l, Action a, Expression* r) : left(l), action(a), right(r){}

BinaryExpression::~BinaryExpression() {
	delete left;
	delete right;
}

Term BinaryExpression::evaluate() {
	switch (this->action) {
		case Action::plus: 
			return this->plusAction();
		case Action::minus: 
			return this->minusAction();
		case Action::concat: 
			return this->concatAction();
		case Action::index: 
			return this->indexAction();
		default:
			break;
	}
}


Term BinaryExpression::plusAction() {
	Term left_term = this->left->evaluate(), right_t = this->right->evaluate();

	if (left_term.getType() != Type::integer || right_t.getType() != Type::integer) 
		throw runtime_error("Invalid operands to + operator");
	
	int *result = new int(*(int*)left_term.getValue() + *(int*)right_t.getValue());
	return Term(result, Type::integer);
}
