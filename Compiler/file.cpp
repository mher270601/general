#ifndef __GET_FILE_PATH_AND_CHEK_OPEN__
#define __GET_FILE_PATH_AND_CHEK_OPEN__

#include <exception>
#include <fstream>
#include <string>

#include "fileType.hpp"

std::string getFilePath(const int& argc, char** argv, InputType& inputType){
	constexpr auto DEFAULT_FILE_PATH = "file.txt";
	switch(argc){
		case 1:
			inputType = File;
			return DEFAULT_FILE_PATH;
		break;
		case 3:
			if(!std::strcmp(argv[1], "-f")){
				inputType = Console;
				return argv[2];
			}else{

				throw std::invalid_argument("Invalid format of file path");
			}
		break;
		default:
			throw std::invalid_argument("Invalid count of arguments");
		break;
	}
	assert(false && "Must not reach here");
}

void openCheckFile(std::ifstream& file, std::string filePath){
	file.open(filePath);
	if(!file){
		throw std::invalid_argument("ERROR: Can't open the file");
	}
}

#endif // __GET_FILE_PATH_AND_CHEK_OPEN__
