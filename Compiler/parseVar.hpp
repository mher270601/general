#ifndef __PARSE__VARIABLE__HPP__
#define __PARSE__VARIABLE__HPP__

#include <cassert>
#include <cstring>
#include <iostream>
#include <sstream>

#include "helpers.hpp"

std::string parseVarName(std::istream& expr){
	std::string name;
	expr >> name;
	if(isalpha(name[0]) || name[0] == '_'){
		checkInden(name);
		return name;
	}
	throw std::invalid_argument("Invalid variable name");
	assert(false && "Must not reach here");
} // parseVarName

void parseVar(std::stringstream& str, std::string& declName){
	declName = parseVarName(str);
	byPassEqual(str);
} // parseVar

#endif // __PARSE__VARIABLE__HPP__
