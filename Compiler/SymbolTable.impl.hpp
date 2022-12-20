#ifndef __SYMBOL__TABLE__IMPL__HPP__
#define __SYMBOL__TABLE__IMPL__HPP__

#include <cassert>
#include <cstdlib>
#include <cstring>
#include <stdexcept>
#include <vector>

#include "evalExpr.hpp"
#include "helpers.hpp"

SymbolTable::SymbolTable(){}

void SymbolTable::InsertVar(const std::string& expr, const int& value){
	Symbol ob(expr, data.size());
	symVec.push_back(ob);
	data.push_back(value);
	assert(symVec.size() == data.size());
}

void SymbolTable::InsertFunc(const std::string& funcName, std::vector<std::string> argsNames, const size_t& argsCount, Node* tree){
	funcTable.push_back(std::make_pair(funcName, argsCount));
	fTree.push_back(tree);
	fArgs.push_back(argsNames);
	assert(funcTable.size() == fTree.size());
}

bool SymbolTable::checkFunc(const std::string& funcName, const size_t& argc) const{
	for(const auto& elem : funcTable){
		if(elem.first == funcName && elem.second == argc){
			return true;
		}	
	}
	return false;
}

std::string SymbolTable::getCorrespExpr(const std::string& argName, const argsPairType& argsPair) const{
	std::string expr = "";
	for(size_t i = 0; i < argsPair.size(); ++i){
		if(argName == argsPair[i].first){
			expr = argsPair[i].second;
		}
	}
	return expr;
}

int SymbolTable::getValueOfFunc(Node* root, const argsPairType& argsPair) const{
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
		//std::cout << "\t\t\t\t" << expr << std::endl;
		if(temp != nullptr && curBool == true){
			curBool = false;
			switch(temp->data.type){
				case Indentifier:
					expr += getCorrespExpr(temp->data.argName, argsPair);
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
					expr += getCorrespExpr(temp->left->data.argName, argsPair);
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
					expr += getCorrespExpr(temp->right->data.argName, argsPair);
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
} // getValueOfFunc

bool SymbolTable::checkFuncSurv(const std::string& fName) const noexcept{
	size_t i{0};
	for(i; i < funcTable.size(); ++i){
		if(fName == funcTable[i].first){
			return true;
		}
	}
	return false;
}

size_t SymbolTable::getFuncAddress(const std::string& m_funcName) const{
	size_t i{0};
	for(i; i < funcTable.size(); ++i){
		if(funcTable[i].first == m_funcName) break;
	}
	return i;
}

int SymbolTable::generateFunc(const std::string& funcDecl) const{
	std::string fName = getFuncName(funcDecl);
	std::vector<std::string> funcArgs;
	size_t argsCount = getArgsCount(funcDecl, funcArgs);
	if(!checkFunc(fName, argsCount)){
		throw std::runtime_error("ERROR: Corresponding arguments don't found");
	}
	size_t funcAddress = getFuncAddress(fName);
	argsPairType argvPair;
	for(size_t i = 0; i < funcArgs.size(); ++i){
		funcArgs[i] = std::to_string(evaluate(funcArgs[i])); // **
		argvPair.push_back(std::make_pair(fArgs[funcAddress][i], funcArgs[i]));
	}

	//if(!checkArg(funcDecl)){
	//	std::cerr << "ERROR: Invalid arguments" << std::endl;
	//	std::exit(0);
	//}
	return getValueOfFunc(fTree[funcAddress], argvPair);
}

inline int SymbolTable::Size() const noexcept{
	return data.size();
}

int SymbolTable::getVarAddress(const std::string& exprName) const{
	for(size_t i = 0; i < data.size(); ++i){
		if(symVec[i].name == exprName){
			return i;
		}
	}
	throw std::runtime_error("ERROR: Undefined variable");
	assert(false && "Must not reach here");
}

#endif // __SYMBOL__TABLE__IMPL__HPP__
