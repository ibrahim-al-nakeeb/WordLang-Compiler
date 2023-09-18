#include "../../headers/controls/Control.hpp"

Control::Control(list<Statement*> *bs) : blockStatement(bs) {}

Control::~Control() {
	for (auto& statement : *blockStatement) {
		delete statement;
	}
	delete blockStatement;
}
