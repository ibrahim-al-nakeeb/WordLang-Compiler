#pragma once

#ifndef CONTROL_STATEMENT_H
#define CONTROL_STATEMENT_H

#include "Statement.hpp"
#include "../controls/Control.hpp"

class ControlStatement : public Statement{
	Control *control;
public:
	ControlStatement(Control *c);
	~ControlStatement();
	void execute() override;
	void print(int level, ofstream& out) override;
};


#endif // CONTROL_STATEMENT_H