#include "../../headers/statements/Input.hpp"

Input::Input(string v, Expression* e) : variable(v), prompt(e) {}

Input::~Input() {
	delete prompt;
}

void Input::execute() {
	
	Term term = prompt->evaluate();
	string input, regexPattern;
	Type variableType = symbolTable.getSymbolType(variable);

	switch (variableType) {
		case Type::integer:
			regexPattern = "-?[0-9]+";
			break;
		case Type::character:
			regexPattern = "[^']?";
			break;
		case Type::word:
			regexPattern = "[^\" ]*";
			break;
		case Type::sentence:
			regexPattern = "[^\\^]*";
			break;
		case Type::identifier:
		default:
			break;
	}

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

	getline(cin, input);

	while (!regex_match(input, regex(regexPattern))) {
		cout << "Invalid input. Try again: ";
		getline(cin, input);
	}
	void* value;
	switch (variableType) {
		case Type::integer: {
			value = new int(stoi(input));
			symbolTable.setSymbolValue(variable, value, Type::integer);
			break;
		}
		case Type::character: {
			value = new char(input[0]);
			symbolTable.setSymbolValue(variable, value, Type::character);
			break;
		}
		case Type::word: {
			value = new string(input);
			symbolTable.setSymbolValue(variable, value, Type::word);
			break;
		}
		case Type::sentence: {
			value = new string(input);
			symbolTable.setSymbolValue(variable, value, Type::sentence);
			break;
		}
		case Type::identifier:
		default:
			break;
	}
	free(value);

}

void Input::print(int level, ofstream& out) {
	printDepth(level, out);
	out << "new Input(" << endl;
	printDepth(level + 1, out);
	out << "\"" << variable << "\"," << endl;
	prompt->print(level + 1, out);
	out << endl;
	printDepth(level, out);
	out << ")";
}