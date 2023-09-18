#include "../../headers/statements/Output.hpp"

Output::Output(Expression* e) : expression(e), condition(nullptr) {}
Output::Output(Condition* c) : expression(nullptr), condition(c) {}

Output::~Output() {
	delete expression;
	delete condition;
}


void Output::execute() {
	
	if (expression != nullptr) {
		Term term = expression->evaluate();
		switch (term.getType()) {
			case Type::integer:
				cout << *(int*)term.getValue();
				break;
			case Type::character:
				cout << *(char*)term.getValue();
				break;
			case Type::word:
			case Type::sentence:
				cout << *(string*)term.getValue();
				break;
			case Type::identifier:
			default:
				break;
		}
	} else {
		cout << (condition->evaluate() ? "true" : "false");
	}
	
	
	cout << endl;

}

void Output::print(int level, ofstream& out) {
	printDepth(level, out);
	out << "new Output(" << endl;
	if (expression != nullptr) {
		expression->print(level + 1, out);
		out << endl;
	} else {
		condition->print(level + 1, out);
	}
	printDepth(level, out);
	out << ")";
}