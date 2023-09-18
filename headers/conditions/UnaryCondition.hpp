#pragma once

#ifndef UNARY_CONDITION_H
#define UNARY_CONDITION_H

#include "Condition.hpp"

class UnaryCondition : public Condition {

	Condition* condition;
	Expression* expression;
	ComparisonOperator op;

public:
	UnaryCondition(Condition* c);
	UnaryCondition(Expression* e);
	~UnaryCondition();
	bool evaluate() override;
	void print(int level, ofstream& out) override;
};

#endif // UNARY_CONDITION_H