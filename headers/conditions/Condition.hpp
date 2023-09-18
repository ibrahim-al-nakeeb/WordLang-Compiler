#pragma once

#ifndef CONDITION_H
#define CONDITION_H

#include <stdexcept> 
#include "../expressions/Expression.hpp"

enum class ComparisonOperator {
	GreaterThanOrEqual,		// >=
	GreaterThan,			// >
	LessThan,				// <
	LessThanOrEqual,		// <=
	Equal,					// ==
	NotEqual,				// !=
	Not,					// !
	Val						// value check
};

class Condition {

public:
	virtual ~Condition();
	virtual bool evaluate() = 0;
	virtual void print(int level, ofstream& out) = 0;
};


#endif // CONDITION_H