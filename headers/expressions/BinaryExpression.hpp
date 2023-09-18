#pragma once

#ifndef BINARY_EXPRESSION_H
#define BINARY_EXPRESSION_H

#include <sstream>
#include "Expression.hpp"


class BinaryExpression : public Expression {

	Expression *left, *right;
	Action action;

public:
	BinaryExpression(Expression* l, Action a, Expression* r);
	~BinaryExpression();
	
	Term evaluate() override;

	Term plusAction();
	Term minusAction();
	Term concatAction();
	Term indexAction();

	void print(int level, ofstream& out) override;

};

#endif // BINARY_EXPRESSION_H