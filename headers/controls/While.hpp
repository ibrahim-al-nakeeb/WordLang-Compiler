#pragma once

#ifndef WHILE_CONTROL_H
#define WHILE_CONTROL_H

#include "Control.hpp"

class While  : public Control {

	Condition* condition;
	
public:
	While(Condition* c, list<Statement*> *bs);
	~While();
	
	void execute() override;
	void print(int level, ofstream& out) override;
};


#endif // WHILE_CONTROL_H