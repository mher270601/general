#include <cassert>
#include <cstdlib>
#include <cstring>
#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <utility>
#include <vector>

#include "getFilePath.hpp"
#include "graph.hpp"
#include "parser.hpp"

//enum EFInput{
//	Console,
//	Default
//};

template <typename T>
void Print(std::stringstream expr, const Graph<T>& graph){
	std::cout << expr.str() << std::endl;
	for(const auto& elem : graph){
		std::cout << elem << " ";
	}
	std::cout << std::endl;
}

int main(const int argc, char** argv){
	
	try{
		std::string filePath = getFilePath(argc, argv);
		std::ifstream file;
		file.open(filePath);
		Graph<unsigned int> myGraph(Check_Parse_File<unsigned int>(filePath));
		myGraph.Render();
		Print(std::stringstream("__ ANSWER __  առավելագույն երկարությունը"), myGraph);
	}catch(const std::exception& Err){
		std::cerr << Err.what() << std::endl;
		return 0;
	}
	return 0;
}
