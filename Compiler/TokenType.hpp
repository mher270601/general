#ifndef __TOKEN__TYPE__HPP__
#define __TOKEN__TYPE__HPP__

#include <string>
	
enum TokenTypes{
	Indentifier,
	Operator,
	Number,
	Bracket
};
enum OperatorTypes{
	Plus,
	Minus,
	Divide,
	Mult
};
enum BracketTypes{
	opnBracket,
	clsBracket
};

struct Token{
	std::string argName;
	TokenTypes type;
	union{
		OperatorTypes oper;
		BracketTypes bracket;
		int symbolIndx;
		int number;
	};	
}; 

struct Node{
	Token data;
	Node* left{nullptr};
	Node* right{nullptr};
	Node(Token value) : data {value}{}
};

#endif // __TOKEN__TYPE__HPP__
