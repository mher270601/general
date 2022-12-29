#ifndef __GET__FILE__PATH__
#define __GET__FILE__PATH__

#include <string>
#include <string.h>

std::string getFilePath(int argc = 1, char** argv = nullptr){
	//EFInput fInput;
	constexpr auto DEFAULT_FILE_PATH = "data.txt";
	switch(argc){
		case 1:
			//fInput = Default;
			return DEFAULT_FILE_PATH;
		break;
		case 3:
			if(!strcmp(argv[1],"-f")){
				return argv[2];
			}
			else{
				throw std::invalid_argument("Invalid format of file path");
				//fInput = Console;
			}
		break;
		default:
			throw std::invalid_argument("Invalid count of arguments");
		break;
	}
	//return FToken;
	assert(false && "Must not reach here");
}

#endif // __GET__FILE__PATH__
