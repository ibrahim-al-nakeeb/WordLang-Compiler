#pragma once

#ifndef IF_CONTROL_H
#define IF_CONTROL_H

#include "Control.hpp"

class If : public Control {

	Condition* condition;
	
public:
	If(Condition* c, list<Statement*> *bs);
	~If();
	
	void execute() override;
	void print(int level, ofstream& out) override;
};

#endif // IF_CONTROL_H