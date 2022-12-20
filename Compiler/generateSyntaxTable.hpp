#ifndef __GENERATE__SYNTAX__TABLE__HPP__
#define __GENERATE__SYNTAX__TABLE__HPP__

#include <iostream>
#include <cstring>
#include <cctype>
#include <sstream>
#include <stdexcept>
#include <string>
#include <queue>

#include "evalExpr.hpp"
#include "helpers.hpp"
#include "parseVar.hpp"
#include "parseFunc.hpp"
#include "readFromFile.hpp"
#include "SymbolTable.hpp"
#include "TokenType.hpp"

symType checkType(std::stringstream& expr){
	symType elemType;
	std::string str;
	expr >> str;
	
	if(str == "VAR" || str == "var"){
		elemType = VAR;
	}else if(str == "FUNCTION" || str == "function"){
		elemType = FUNCTION;
	}else{
		throw std::runtime_error("Invalid declaration");
	}
	return elemType;
}

std::string evalArgs(const std::string& expr, const SymbolTable& ob){
	//using getValueOfVar = ob.data[ob.getVarAddress(curArg)];
	//std::cout << __PRETTY_FUNCTION__ << std::endl;
	size_t i{expr.find('(') + 1};
	std::string curFunc = expr.substr(0, expr.find('(') + 1);
	std::string tempExpr = "";
	std::string curArg = "";
	do{
		switch(expr[i]){
			case ',':
				if(curArg[0] == '_' || isalpha(curArg[0])){
					tempExpr += std::to_string(ob.data[ob.getVarAddress(curArg)]);
				}else{
					tempExpr += curArg;
				}
				curFunc += std::to_string(evaluate(tempExpr));
				curFunc += ',';
				tempExpr = curArg = "";
				++i;
				continue;
			break;
			case '+': case '-': case '*': case '/':
				if(curArg[0] == '_' || isalpha(curArg[0])){
					tempExpr += std::to_string(ob.data[ob.getVarAddress(curArg)]);
				}else{
					tempExpr += curArg;
				}
				curArg = "";
				tempExpr += expr[i];
				++i;
			break;
			default:
				curArg += expr[i];
				++i;
			break;
		}
	}while(i != expr.length() - 1);
	if(curArg[0] == '_' || isalpha(curArg[0])){
		tempExpr += std::to_string(ob.data[ob.getVarAddress(curArg)]);
	}else{
		tempExpr += curArg;
	}
	curFunc += std::to_string(evaluate(tempExpr));
	curFunc += ')';
	std::cout << "\t\t//// " << curFunc << std::endl; 
	return curFunc;
}

// Get a word, parse the type and return 
Token Tokenizer(const std::string& expr, const SymbolTable& ob, const bool& isFunction = false, std::vector<std::string> funcArgs = std::vector<std::string>()){
	assert(expr.length() > 0);
	Token cur;
		if(isOperator(expr[0])){
			Token elem;
			switch(expr[0]){
				case '+':
					elem.type = Operator;
					elem.oper = Plus;
					return elem;
				break;
				case '-':
					elem.type = Operator;
					elem.oper = Minus;
					return elem;
				break;
				case '/':
					elem.type = Operator;
					elem.oper = Divide;
					return elem;
				break;
				case '*':
					elem.type = Operator;
					elem.oper = Mult;
					return elem;
				break;
				case '(':
					elem.type = Bracket;
					elem.bracket = opnBracket;
					return elem;
				break;
				case ')':
					elem.type = Bracket;
					elem.bracket = clsBracket;
					return elem;
				break;
			}

		}
		else if(std::isdigit(expr[0])){
			checkValue(expr);
			Token elem2;
			elem2.type = Number;
			elem2.number = std::stoi(expr);
			return elem2;
		}
		else if(std::isalpha(expr[0]) || expr[0] == '_'){
			Token elem;
			elem.type = Indentifier;
			if(isFunction){
				checkArg(funcArgs, expr);
				elem.argName = expr;
				return elem;
			}
			if(checkFunctionality(expr)){
				elem.type = Number;
				elem.number = ob.generateFunc(evalArgs(expr, ob));
				return elem;
			}
			checkInden(expr);
			elem.symbolIndx = ob.getVarAddress(expr);
			return elem;
		}
	return cur;
} // Token Tokenizer

void insertInLastLeaf(Node* root, const Token& elem){
	Node* temp;
	std::queue<Node*>q;
	q.push(root);
	
	while(!q.empty()){
		temp = q.front();
		q.pop();

		if(temp->left == nullptr){
			temp->left = new Node(elem);
			break;
		}
		else{
			q.push(temp->left);
		}
		if(temp->right == nullptr){
			temp->right = new Node(elem);
			break;
		}
		else{
			q.push(temp->right);
		}
	}
} // insertInLastLeaf

Node* CreateTree(std::stringstream& m_str, SymbolTable& ob, const bool& isFunction = false, std::vector<std::string> funcArgs = std::vector<std::string>()){
	std::string expr; // **
	std::getline(m_str, expr);
	
	assert(expr.length() > 0 && expr[expr.length()-1] == ';');
	std::istringstream str(expr);
	std::string word;
	str >> word;
	Token fToken;
	switch(word[word.length()-1]){
		case ';':
			switch(word.length()){
				case 1:
					throw std::runtime_error("Umbigious behavior: An invalid ; character was found");
				break;
				default:
					word.resize(word.length()-1);
				break;
			};
		break;				
	} // by pass ; character
	if(isFunction){
		fToken = Tokenizer(word, ob, true, funcArgs);
	} else{
		fToken = Tokenizer(word, ob);
	}
	Node* tree = new Node(fToken);
	
	while(str){
		bool cur = false;
		str >> word;
		switch(word[word.length()-1]){
			case ';':
				cur = true;
				switch(word.length()){
					case 1:
						return tree;
					break;
					default:
						word.resize(word.length()-1);
					break;
				};
			break;
		} // by pass ; character
		if(word.length()-1 > 0){
			std::string curExpr{word};
			switch(word[0]){
				case '(':
					curExpr = word[0];
					if(checkFunctionality(word)){
						if(isFunction){
							fToken = Tokenizer(word, ob, true, funcArgs);
						}else{
							fToken = Tokenizer(word, ob);
						}
						goto byPass;
					}
					else{
						fToken = Tokenizer(curExpr, ob);
						word.erase(0, 1);
					}
					insertInLastLeaf(tree, fToken);
				break;
			}
			switch(word[word.length()-1]){
				case ')':
					if(!checkFunctionality(word)){	
						curExpr.resize(curExpr.length()-1);
						if(isFunction){
							fToken = Tokenizer(curExpr, ob, true, funcArgs);
						} else{
							fToken = Tokenizer(curExpr, ob);
						}
						insertInLastLeaf(tree, fToken);
						word = word[word.length()-1];
					}
				break;
			}
		}
	byPass:
		if(isFunction){
			fToken = Tokenizer(word, ob, true, funcArgs);
		} else{
			fToken = Tokenizer(word, ob);
		}
		insertInLastLeaf(tree, fToken);
		if(cur) return tree;
	}
	return tree;
} // CreateTree

int getValueOfTree(Node* root, const SymbolTable& ob, const bool& isFunction = false){
	Node* root2 = root;
	Node* temp;
	std::string expr = "";
	std::queue<Node*>q;
	q.push(root2);
	bool curBool = true;
	while(!q.empty()){
		temp = q.front();
		q.pop();
		int curVal{0};
		std::cout << "\t\t\t\t" << expr << std::endl;
		if(temp != nullptr && curBool == true){
			curBool = false;
			switch(temp->data.type){
				case Indentifier:
					curVal = ob.data[temp->data.symbolIndx];
					expr += std::to_string(curVal);
				break;
				case Number:
					expr += std::to_string(temp->data.number);
				break;
				case Bracket:
					switch(temp->data.bracket){
						case opnBracket:
							expr += "(";
						break;
						case clsBracket:
							expr += ")";
						break;
					}
				break;	
				case Operator:
					switch(temp->data.oper){
						case Plus:
							expr += "+";
						break;
						case Minus:
							expr += "-";
						break;
						case Divide:
							expr += "/";
						break;
						case Mult:
							expr += "*";
						break;
					}
				break;
			}
		}
		if(temp->left != nullptr){
			expr += " ";
			switch(temp->left->data.type){
				case Indentifier:
					curVal = ob.data[temp->left->data.symbolIndx];
					expr += std::to_string(curVal);
				break;
				case Number:
					expr += std::to_string(temp->left->data.number);
				break;	
				case Bracket:
					switch(temp->left->data.bracket){
						case opnBracket:
							expr += "(";
						break;
						case clsBracket:
							expr += ")";
						break;
					}
				break;	
				case Operator:
					switch(temp->left->data.oper){
						case Plus:
							expr += "+";
						break;
						case Minus:
							expr += "-";
						break;
						case Divide:
							expr += "/";
						break;
						case Mult:
							expr += "*";
						break;
					}
				break;
			}
			q.push(temp->left);
		}
		else{
			break;
		}
		if(temp->right != nullptr){
			expr += " ";
			switch(temp->right->data.type){
				case Indentifier:
					curVal = ob.data[temp->right->data.symbolIndx];
					expr += std::to_string(curVal);
				break;
				case Number:
					expr += std::to_string(temp->right->data.number);
				break;	
				case Bracket:
					switch(temp->right->data.bracket){
						case opnBracket:
							expr += "(";
						break;
						case clsBracket:
							expr += ")";
						break;
					}
				break;	
				case Operator:
					switch(temp->right->data.oper){
						case Plus:
							expr += "+";
						break;
						case Minus:
							expr += "-";
						break;
						case Divide:
							expr += "/";
						break;
						case Mult:
							expr += "*";
						break;
					}
				break;
			}
			q.push(temp->right);
		}
		else{
			break;
		}
	}
	return evaluate(expr);
} // getValue

void buildLine(std::stringstream& str, SymbolTable& ob){
	symType declType = checkType(str);
	Node* tree;
	std::string declName;
	int val{0};
	separateBrackets(str);
	switch(declType){
		case VAR:
			//declName = parseVarName(str);
			//byPassEqual(str);
			//std::cout << "Write the checkVarName(str) function" << std::endl;
			parseVar(str, declName);
			tree = CreateTree(str, ob);
			val = getValueOfTree(tree, ob);
			ob.InsertVar(declName, val);
			std::cout << declName << " value = " << val << std::endl;
		break;
		case FUNCTION:
			auto decl = parseFuncDecl(str);
			byPassEqual(str);
			tree = CreateTree(str, ob, true, decl.first);
			ob.InsertFunc(decl.second.first, decl.first, decl.second.second, tree); // ** (structure binding)
		break;
	}
}

#endif // __GENERATE__SYNTAX__TABLE__HPP__
