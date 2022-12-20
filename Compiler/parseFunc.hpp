#ifndef __PARSE__FUNCTION__HPP__
#define __PARSE__FUNCTION__HPP__

#include <cstdlib>
#include <cstring>
#include <exception>
#include <iostream>
#include <sstream>

#include "errors.cpp"
#include "helpers.hpp"
#include "SymbolTable.hpp"
#include "TokenType.hpp"

std::pair<std::string, size_t> parseFuncName(std::istream& expr, std::vector<std::string>& funcArgs){
	std::string declName;
	expr >> declName;
	if(!checkFunctionality(declName)){
		throw Invalid_function_decl("ERROR: Invalid function declaration");
	}
	std::string name = getFuncName(declName);
	size_t argsCount = getArgsCount(declName, funcArgs);
	return std::make_pair(name, argsCount);
}

std::pair<std::vector<std::string>, std::pair<std::string, size_t>> parseFuncDecl(std::stringstream& expr){
	std::vector<std::string> funcArgs;
	std::pair<std::string, size_t> funcConfig = parseFuncName(expr, funcArgs);
	return std::make_pair(funcArgs, funcConfig);
}

#endif // __PARSE__FUNCTION__HPP__
