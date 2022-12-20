#include <iostream>
#include <stack>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <sstream>
#include <stdexcept>
#include <fstream>

#include "fileType.hpp"
#include "file.cpp"
#include "generateSyntaxTable.hpp"
#include "readFromFile.hpp"
#include "SymbolTable.hpp"

int main(const int argc, char** argv)
{
	try{
		InputType input;
		std::string filePath = getFilePath(argc, argv, input);
		std::ifstream file;
		openCheckFile(file, filePath);
		SymbolTable ob;
		do{
			std::stringstream current_line(getLine(file));
			if(current_line.str() != ""){
				buildLine(current_line, ob);
			}
		}while(!file.eof());
		std::cout << "File path = " << filePath << std::endl;
	}catch(const std::exception& err){
		std::cerr << err.what() << std::endl;
	}
    	return 0;
}
