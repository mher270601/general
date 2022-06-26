#include <cstring>
#include <fstream>
#include <string>
#include <utility>
#include <vector>

template <typename T>
auto Check_Parse_File(std::string filePath){
	using valueType = T;
	using vecType = std::vector<std::pair<valueType, valueType>>;
	
	std::ifstream file;
	file.open(filePath);
	if(!file){
		throw std::runtime_error("Unable to open file");
	}
	vecType PairsVector;
	while(!file.eof()){
		std::string lineExpr;
		std::getline(file, lineExpr);
		std::istringstream lStream(lineExpr);
		std::string cur1{"0"};
		std::string cur2{"0"};
		
		lStream >> cur1;
		
		lStream >> cur2;
		PairsVector.push_back(std::make_pair(std::stoi(cur1), std::stoi(cur2)));
	}
	return PairsVector;
}
