#pragma once

#ifndef LOOP_CONTROL_H
#define LOOP_CONTROL_H

#include "Control.hpp"

class Loop : public Control {
	
	Expression* expression;

public:

	Loop(Expression* e, list<Statement*> *bs);
	~Loop();
	
	void execute() override;
	void print(int level, ofstream& out) override;
};

#endif // LOOP_CONTROL_H