#pragma once

#ifndef IF_ELSE_CONTROL_H
#define IF_ELSE_CONTROL_H

#include "Control.hpp"

class IfElse : public Control {

	Condition* condition;
	list<Statement*> *secondBlockStatement;

public:
	IfElse(Condition* c, list<Statement*> *bs, list<Statement*> *sbs);
	~IfElse();

	void execute() override;
	void print(int level, ofstream& out) override;
};

#endif // IF_ELSE_CONTROL_H