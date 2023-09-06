#ifndef __READ__INFO__IMPL__CPP__
#define __READ__INFO__IMPL__CPP__

#include <algorithm>
#include <cstring>
#include <memory>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <string>

#include "readFromFile.hpp"
#include "PowerPoint.hpp"
#include "utility.hpp"
#include "IInput.hpp"
#include "InputCmd.hpp"
#include "CmdParser.hpp"

namespace PowerPoint{

	void FileManager::ParseLine(std::stringstream& line) {
		std::string currCommand;
		line >> currCommand;
		//std::transform(currCommand.begin(), currCommand.end(), currCommand.begin(), ::toupper);
		CmdParser& cmdParser = CmdParser::GetInstance();
		cmdParser.Parse(line);
	}
	
	void FileManager::GetData(){
		SPtrCmdInput cmdPtr = CmdInput::GetInstance();
		m_file.open(m_FPath, std::ios::app);
		//std::vector<std::string> commands;
		std::string current_CmdLineInput;
		
		while(true){
			current_CmdLineInput = cmdPtr->GetCommand();
			std::transform(current_CmdLineInput.begin(), current_CmdLineInput.end(), current_CmdLineInput.begin(), ::toupper);
			if(current_CmdLineInput == "END"){
				break;
			}

			//commands.push_back(current_command);
			m_file << current_CmdLineInput << std::endl;

		}

		//std::string action;
	
		//while(true){
		//	std::cout << "Input command: ";
		//	std::cin >> current_command;
		//	std::transform(current_command.begin(), current_command.end(), current_command.begin(), ::toupper);
		//	if(current_command != "END"){
		//		commands.push_back(current_command);
		//		m_file << current_command << std::endl;
		//	}
		//	else{
		//		break;
		//	}
		//}
		m_file.close();
		//const std::string currCmd = m_cmdInput->GetCommand();
		//std::string currentCmd;
		//do{
		//	currentCmd = m_cmdInput->GetCommand();
		//	// ...
		//}while(currentCmd != "end" || currCmd != "finish");
		
		// m_file.open(m_FPath, std::ios::app);
		// std::string line;
		// std::string action;
		// do{
		// 	std::cout << "Input action: ";
		// 	std::cin >> action;
		// 	line += action;
		// 	line += " ";
		// 	std::transform(action.begin(), action.end(), action.begin(), ::toupper);
		// 	if(!strcmp(action.c_str(), "CREATE")){
		// 		std::string object;
		// 		std::cout << "Input object type: ";
		// 		std::cin >> object;
		// 		std::transform(object.begin(), object.end(), object.begin(), ::toupper);
		// 		line += object;
		// 		line += " ";
		// 		if(!strcmp(object.c_str(), "SLIDE")){
		// 			std::string slideName;
		// 			std::cout << "Input slide name: ";
		// 			std::cin >> slideName;
	
		// 			line += slideName;
		// 			line += " ";
		// 		}
		// 		else if(!strcmp(object.c_str(), "GROUP")){
		// 			std::string groupName;
		// 			std::cout << "Input group name: ";
		// 			std::cin >> groupName;
					
		// 			line += groupName;
		// 			line += " ";
		// 		}
		// 		else if(!strcmp(object.c_str(), "TRIANGLE")){
	
		// 			std::string _color;
		// 			std::cout << "Input color: (RED, BLUE, GREEN, BLACK, WHITE, YELLOW, PINK, GREY)";
		// 			std::cin >> _color;
					
		// 			line += _color;
		// 			line += " ";
					
		// 			std::string _backgroundColor;
		// 			std::cout << "Input background color: (RED, BLUE, GREEN, BLACK, WHITE, YELLOW, PINK, GREY)";
		// 			std::cin >> _backgroundColor;
					
		// 			line += _backgroundColor;
		// 			line += " ";
					
		// 			int _size;
		// 			std::cout << "Input text size: ";
		// 			std::cin >> _size;
		// 			if(_size < 0 || _size > 96){
		// 				throw std::runtime_error("Range of text size 0 - 96");
		// 			}
	
		// 			line += std::to_string(_size);
		// 			line += " ";
		// 		}
		// 	}
		// 	else if(!strcmp(action.c_str(), "PRESENT")){
		// 		std::string _slideName;
		// 		std::cout << "Input slide name: " << std::endl;
		// 		std::cin >> _slideName;
				
		// 		line += _slideName;
		// 		line += " ";
		// 	}
		// 	else if(!strcmp(action.c_str(), "FINISH") || !strcmp(action.c_str(), "Q") || !strcmp(action.c_str(), "EXIT") || !strcmp(action.c_str(), "QUIT")){}
		// 	else{
		// 		//std::cerr << "ERROR: Invalid type of action" << std::endl;
		// 		throw std::runtime_error("ERROR: Invalid type of action");
		// 	}
		// 	m_file << line << std::endl;
		// }while(line != "end");
		// m_file.close();
	}
	
	FileManager::FileManager() : m_FPath("data.txt"){
		try{
			GetData();
			ParseData();
		}catch(const std::exception& err){
			std::cerr << err.what() << std::endl;
		}
	}
	
	static FileManager& GetInstance(){
		static FileManager instance;
		return instance;
	}
	
	
	void FileManager::ParseData(){
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		m_file.open(m_FPath, std::ios::in);
		do{
			std::stringstream currLine(getLine(m_file));
			ParseLine(currLine);
		}while(!m_file.eof());
		//return "123";
	}

} // namespace PowerPoint

#endif // __READ__INFO__IMPL__CPP__
