#ifndef __HELPERS__HPP__
#define __HELPERS__HPP__

bool isOperator(char letter){
	return (!isdigit(letter) && !isalpha(letter));
}

void byPassEqual(std::stringstream& expr){
	std::string opEqual;
	expr >> opEqual;
	if(opEqual != "="){
		throw std::runtime_error("ERROR: Do not found = operator");
	}
}

void checkValue(const std::string& expr){
	if(expr.length() > 0){
		for(size_t i = 1; i < expr.length()-1; ++i){
			if(!std::isdigit(expr[i])){
				throw std::runtime_error("ERROR: Invalid value");
			}
		}
	}
}

void checkInden(const std::string& expr){
	if(expr.length() > 0){
		for(size_t i = 1; i < expr.length(); ++i){
			if(isOperator(expr[i]) && expr[i] != '_' && expr[i] != '(' && expr[i] != ')' && expr[i] != ','){
				throw std::runtime_error("ERROR: Invalid declaration");
			}
		}
	}
}

size_t getArgsCount(const std::string& funcDecl, std::vector<std::string>& funcArgs){
	size_t argsCount{0};
	std::string curIndent = "";
	for(size_t i = funcDecl.find('(')+1; i < funcDecl.find(')'); ++i){
		if(funcDecl[i] == ','){
			++argsCount;
			if(std::isalpha(curIndent[0]) || curIndent[0] == '_' || std::isdigit(curIndent[0])){
				checkInden(curIndent);
			} else {
				throw std::runtime_error("ERROR: Invalid arguments declaration");
			}
			funcArgs.push_back(curIndent);
			curIndent = "";
			continue;
		}
		curIndent += funcDecl[i];
		
	}
	if(curIndent != ""){
		++argsCount;
		funcArgs.push_back(curIndent);
	}
	return argsCount;
}

void separateBrackets(std::stringstream& expr){
	std::string tempExpr = "";
	for(size_t i = 0; i < expr.str().length(); ++i){
		if(expr.str()[i] == '(' && !isalpha(expr.str()[i-1]) && expr.str()[i-1] != '_'){
			tempExpr += ' ';
			tempExpr += expr.str()[i];
			tempExpr += ' ';
		}
		else if(expr.str()[i] == ')' && expr.str()[i-1] == ')'){
			tempExpr += ' ';
			tempExpr += expr.str()[i];
		}
		else{
			tempExpr += expr.str()[i];
		}
	}
	expr << tempExpr;
}

bool checkArg(const std::vector<std::string>& args, std::string inden){
	for(const auto& elem : args){
		if(elem == inden){
			return true;
		}
	}
	return false;
}

inline bool checkFunctionality(const std::string& funcDecl){
	return ((isalpha(funcDecl[0]) || funcDecl[0] == '_') && funcDecl.find('(') < funcDecl.find(')'));
}

inline std::string getFuncName(const std::string& funcDecl){
	return funcDecl.substr(0, funcDecl.find('('));
}

#endif // __HELPERS__HPP__
