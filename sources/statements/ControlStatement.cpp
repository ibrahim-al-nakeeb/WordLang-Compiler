#include "../../headers/statements/ControlStatement.hpp"

ControlStatement::ControlStatement(Control *c) : control(c) {}

ControlStatement::~ControlStatement() {
	delete control;
}

void ControlStatement::execute() {
	control->execute();
}

void ControlStatement::print(int level, ofstream& out) {
	printDepth(level, out);
	out << "new ControlStatement(" << endl;
	control->print(level + 1, out);
	printDepth(level, out);
	out << ")";
}
