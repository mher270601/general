#ifndef __GET__FILE__PATH__
#define __GET__FILE__PATH__

std::string getFilePath(int argc, char** argv){
	//EFInput fInput;
	constexpr auto DEFAULT_FILE_PATH = "graph.txt";
	switch(argc){
		case 1:
			//fInput = Default;
			return DEFAULT_FILE_PATH;
		break;
		case 3:
			if(!std::strcmp(argv[1],"-f")){
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
