#ifndef __UTILITY__HPP__
#define __UTILITY__HPP__

#include <algorithm>
#include <string>

#include "ETypes.hpp"

constexpr int keyUp = 65, keyDown = 66, keyRight = 67, keyLeft = 68, keyEnter = 0x0A, keyEsq = 27; 

const char quit = 'q';

std::string_view backSpace_8 = "\t\t\t\t\t\t\t\t";

inline std::string_view B_GREEN = "\u001b[32;1m";
inline std::string_view CYAN = "\u001b[36m";
inline std::string_view YELLOW = "\u001b[33m";
inline std::string_view BACK_YELLOW = "\u001b[43m";
inline std::string_view B_RED = "\u001b[31;1m";
inline std::string_view BACK_RED = "\u001b[41m";
inline std::string_view RESET = "\u001b[0m";
inline std::string_view GREEN = "\u001b[32m";
inline std::string_view BACK_B_GREEN = "\u001b[42;1m";
inline std::string_view BACK_GREEN = "\u001b[42m";
inline std::string_view WHITE = "\u001b[37m";
inline std::string_view BACK_B_WHITE = "\u001b[47;1m";
inline std::string_view BACK_BLUE = "\u001b[44;1m";
inline std::string_view BLUE = "\u001b[34m"; // 47
inline std::string_view MAGENTA = "\u001b[35m";


std::string getCategory(const ECategory& expr){
	if(expr == ECategory::BUSINESS){
		return "BUSINESS";
	}
	else if(expr == ECategory::FANTASTIC){
		return "FANTASTIC";
	}
	else if(expr == ECategory::STUDYING){
		return "STUDYING";
	}
	else if(expr == ECategory::DETECTIVE){
		return "DETECTIVE";
	}
	else if(expr == ECategory::HISTORY){
		return "HISTORY";
	}
	else if(expr == ECategory::ROMANTIC){
		return "ROMANTIC";
	}
	else if(expr == ECategory::HUMOR){
		return "HUMOR";
	}
	else if(expr == ECategory::SPORT){
		return "SPORT";
	}
	else if(expr == ECategory::MOTIVATION){
		return "MOTIVATION";
	}
	else if(expr == ECategory::CHILDRENS){
		return "CHILDRENS";
	}
	else if(expr == ECategory::MILITANTS){
		return "MILITANTS";
	}
	assert(false && "Must not reach here");	
}

ECategory checkCategory(std::string expr){
	std::transform(expr.begin(), expr.end(), expr.begin(), ::toupper);
	ECategory category;
	if(expr == "BUSINESS"){
		return ECategory::BUSINESS;
	}
	else if(expr == "FANTASTIC"){
		return ECategory::FANTASTIC;
	}
	else if(expr == "STUDYING"){
		return ECategory::STUDYING;
	}
	else if(expr == "DETECTIVE"){
		return ECategory::DETECTIVE;
	}
	else if(expr == "HISTORY"){
		return ECategory::HISTORY;
	}
	else if(expr == "ROMANTIC"){
		return ECategory::ROMANTIC;
	}
	else if(expr == "HUMOR"){
		return ECategory::HUMOR;
	}
	else if(expr == "SPORT"){
		return ECategory::SPORT;
	}
	else if(expr == "MOTIVATION"){
		return ECategory::MOTIVATION;
	}
	else if(expr == "CHILDRENS"){
		return ECategory::CHILDRENS;
	}
	else if(expr == "MILITANTS"){
		return ECategory::MILITANTS;
	}
	assert(false && "Must not reach here");	
}

#endif // __UTILITY__HPP__
