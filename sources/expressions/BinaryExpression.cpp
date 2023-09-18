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

