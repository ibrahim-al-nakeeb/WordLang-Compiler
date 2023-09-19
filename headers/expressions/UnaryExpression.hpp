#pragma once

#ifndef UNARY_EXPRESSION_H
#define UNARY_EXPRESSION_H

#include "Expression.hpp"


class UnaryExpression : public Expression {

	Term* term;

public:
	UnaryExpression(Term* l = nullptr);
	~UnaryExpression();
	
	Term evaluate() override;
	void print(int level, ofstream& out) override;
};

#endif // UNARY_EXPRESSION_H