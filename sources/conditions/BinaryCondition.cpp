#include "../../headers/conditions/BinaryCondition.hpp"

BinaryCondition::BinaryCondition(Expression* l, Expression* r, ComparisonOperator o) : left(l), right(r), op(o) {}

BinaryCondition::~BinaryCondition() {
	delete left;
	delete right;
}

bool BinaryCondition::evaluate() {

	Terminal left_term = left->evaluate(), right_term = right->evaluate();

	Type left_type = left_term.getType(), right_type = right_term.getType();

	if (left_type != right_type)
		return false;
	
	void *left_val = left_term.getValue(), *right_val = right_term.getValue();

	switch (op) {
		case ComparisonOperator::GreaterThanOrEqual: {
			switch (left_type) {
				case Type::integer:
					return *(int*)left_val >= *(int*)right_val;
				case Type::character:
					return *(char*)left_val >= *(char*)right_val;
				case Type::word:
				case Type::sentence:
					return *(string*)left_val >= *(string*)right_val;
				default:
					break;
			}
			break;
		}
		case ComparisonOperator::GreaterThan: {
			switch (left_type) {
				case Type::integer:
					return *(int*)left_val > *(int*)right_val;
				case Type::character:
					return *(char*)left_val > *(char*)right_val;
				case Type::word:
				case Type::sentence:
					return *(string*)left_val > *(string*)right_val;
				default:
					break;
			}
			break;
		}
		case ComparisonOperator::LessThan: {
			switch (left_type) {
				case Type::integer:
					return *(int*)left_val < *(int*)right_val;
				case Type::character:
					return *(char*)left_val < *(char*)right_val;
				case Type::word:
				case Type::sentence:
					return *(string*)left_val < *(string*)right_val;
				default:
					break;
			}
			break;
		}
		case ComparisonOperator::LessThanOrEqual: {
			switch (left_type) {
				case Type::integer:
					return *(int*)left_val <= *(int*)right_val;
				case Type::character:
					return *(char*)left_val <= *(char*)right_val;
				case Type::word:
				case Type::sentence:
					return *(string*)left_val <= *(string*)right_val;
				default:
					break;
			}
			break;
		}
		case ComparisonOperator::Equal: {
			switch (left_type) {
				case Type::integer:
					return *(int*)left_val == *(int*)right_val;
				case Type::character:
					return *(char*)left_val == *(char*)right_val;
				case Type::word:
				case Type::sentence: 
					return *(string*)left_val == *(string*)right_val;
				default:
					break;
			}
			break;
		}
		case ComparisonOperator::NotEqual: {
			switch (left_type) {
				case Type::integer:
					return *(int*)left_val != *(int*)right_val;
				case Type::character:
					return *(char*)left_val != *(char*)right_val;
				case Type::word:
				case Type::sentence:
					return *(string*)left_val != *(string*)right_val;
				default:
					break;
			}
			break;
		}
		default:
			break;
	}
	return false;
}

void BinaryCondition::print(int level, ofstream& out) {
	printLevels(level, out);
	out << "new BinaryCondition(" << endl;
	left->print(level + 1, out);
	out << ", " << endl;
	right->print(level + 1, out);
	out << ", " << endl;
	printLevels(level + 1, out);
	switch (op) {
		case ComparisonOperator::GreaterThanOrEqual:
			out << "ComparisonOperator::GreaterThanOrEqual";
			break;
		case ComparisonOperator::GreaterThan:
			out << "ComparisonOperator::GreaterThan";
			break;
		case ComparisonOperator::LessThan:
			out << "ComparisonOperator::LessThan";
			break;
		case ComparisonOperator::LessThanOrEqual:
			out << "ComparisonOperator::LessThanOrEqual";
			break;
		case ComparisonOperator::Equal:
			out << "ComparisonOperator::Equal";
			break;
		case ComparisonOperator::NotEqual:
			out << "ComparisonOperator::NotEqual";
			break;
		case ComparisonOperator::Not:
			out << "ComparisonOperator::Not";
			break;
		case ComparisonOperator::Val:
			out << "ComparisonOperator::Val";
			break;
		default:
			break;
	}
	out << endl;
	printLevels(level, out);
	out << ")";
}
