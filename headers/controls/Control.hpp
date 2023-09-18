#pragma once

#ifndef CONTROL_H
#define CONTROL_H

#include <list>
#include "../conditions/Condition.hpp"
#include "../expressions/Expression.hpp"
#include "../statements/VariablesDeclaration.hpp"

class Statement;							//
class VariablesDefinitionStatement;			// Forward declaration

class Control {

protected:
	list<Statement*> *blockStatement;

public:
	Control(list<Statement*> *bs);
	virtual ~Control();
	virtual void execute() = 0;
	virtual void print(int level, ofstream& out) = 0;
	
};

#endif // CONTROL_H


