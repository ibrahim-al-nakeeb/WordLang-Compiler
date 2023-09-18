#include "../../headers/term/Term.hpp"

Term::Term()  {
	this->type = Type::integer;
	this->value = new int(0);
}

Term::Term(const Term& t) {

	this->type = t.type;
	switch (type) {
		case Type::integer:
			this->value = new int(*(int*)t.value);
			break;
		case Type::character:
			this->value = new char(*(char*)t.value);
			break;
		case Type::word:
		case Type::sentence:
		case Type::identifier:
			this->value = new string(*(string*)t.value);
			break;
	}
}
Term::Term(void* value, Type type) {
	
	this->type = type;

	switch (type) {
		case Type::integer:
			this->value = new int(*(int*)value);
			break;
		case Type::character:
			this->value = new char(*(char*)value);
			break;
		case Type::word:
		case Type::sentence:
		case Type::identifier:
			this->value = new string(*(string*)value);
			break;
	}
	free(value);
}

Term::~Term() {
	free(value);
}

void* Term::getValue() const {
	if (this->type == Type::identifier) 
		return symbolTable.getSymbolValue(*(string*)this->value);
	return value;
}

Type Term::getType() const {
	if (this->type == Type::identifier) {
		return symbolTable.getSymbolType(*(string*)this->value);
	}
	return type;
}


void Term::print(int level, ofstream& out) {
	printDepth(level, out);
	out << "new Term(";
	switch (type) {
		case Type::integer:
			out << "new int(" << *(int*)value << "), Type::integer";
			break;
		case Type::character: {
			if (*(char*)value != '\0')
				out << "new char(\'" << *(char*)value << "\'), Type::character";
			else
				out << "new char('\\0'), Type::character";
			break;
		}
			
		case Type::word:
			out << "new string(\"" << *(string*)value << "\"), Type::word";
			break;
		case Type::identifier:
			out << "new string(\"" << *(string*)value << "\"), Type::identifier";
			break;

		case Type::sentence: {
			string s = *(string*)value;
			size_t pos = 0;
			while ((pos = s.find('\n', pos)) != string::npos) {
				s.replace(pos, 1, "\\n");
				pos += 2;
			}

			out << "new string(\"" << s << "\"), Type::sentence";
			break;
		}
			
	}
	out << ")" << endl;
}