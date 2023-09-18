#include "../../headers/conditions/UnaryCondition.hpp"

UnaryCondition::UnaryCondition(Condition* c) : condition(c), op(ComparisonOperator::Not) {}

UnaryCondition::UnaryCondition(Expression* e) : expression(e), op(ComparisonOperator::Val) {}

UnaryCondition::~UnaryCondition() {
	if (op == ComparisonOperator::Not)
		delete condition;
	else
		delete expression;
}

bool UnaryCondition::evaluate() {

	if (op == ComparisonOperator::Val) {
		Term term = expression->evaluate();
		Type left_type = term.getType();
		void* val = term.getValue();
		switch (left_type) {
			case Type::integer:
				return *(int*)val != 0;
			case Type::character:
				return *(char*)val != '\0';
			case Type::word:
				return *(string*)val != "";
			case Type::sentence:
				return *(string*)val != "\n";
			
			default:
				return false;
		}
	}
	return !condition->evaluate();
}

void UnaryCondition::print(int level, ofstream& out) {

	printDepth(level, out);
	out << "new UnaryCondition(" << endl;
	if (op == ComparisonOperator::Not)
		condition->print(level + 1, out);
	else
		expression->print(level + 1, out);
	out << endl;
	printDepth(level, out);
	out << ")";
}