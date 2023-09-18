#pragma once

#ifndef BINARY_CONDITION_H
#define BINARY_CONDITION_H

#include "Condition.hpp"

class BinaryCondition : public Condition {

	Expression *left, *right;
	ComparisonOperator op;

public:
	BinaryCondition(Expression* l, Expression* r, ComparisonOperator o);
	~BinaryCondition();
	bool evaluate() override;
	void print(int level, ofstream& out) override;
};

#endif // BINARY_CONDITION_H