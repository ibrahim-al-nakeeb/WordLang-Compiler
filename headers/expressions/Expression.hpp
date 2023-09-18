#pragma once

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <vector>
#include <stdexcept>
#include "../term/Term.hpp"

enum class Action {
	plus,
	minus,
	concat,
	index
};

class Expression {

public:
	virtual ~Expression();
	virtual Term evaluate() = 0;
	virtual void print(int level, ofstream& out) = 0;

};


#endif // EXPRESSION_H