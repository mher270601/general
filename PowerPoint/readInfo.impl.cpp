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

#include "readFromFile.hpp"
#include "PowerPoint.hpp"
#include "utility.hpp"

void Administrator::ParseLine(std::stringstream& line) {
	
}

void Administrator::GetData(){
	m_file.open(m_FPath, std::ios::app);
	std::string line;
	std::string action;
	do{
		std::cout << "Input action: ";
		std::cin >> action;
		line += action;
		line += " ";
		std::transform(action.begin(), action.end(), action.begin(), ::toupper);
		if(!strcmp(action.c_str(), "CREATE")){
			std::string object;
			std::cout << "Input object type: ";
			std::cin >> object;
			std::transform(object.begin(), object.end(), object.begin(), ::toupper);
			line += object;
			line += " ";
			if(!strcmp(object.c_str(), "SLIDE")){
				std::string slideName;
				std::cout << "Input Slide name: ";
				std::cin >> slideName;

				line += slideName;
				line += " ";
			}
			else if(!strcmp(object.c_str(), "GROUP")){
				std::string groupName;
				std::cout << "Input Group name: ";
				std::cin >> groupName;
				
				line += groupName;
				line += " ";
			}
			else if(!strcmp(object.c_str(), "TRIANGLE")){
				std::string color;
				std::cout << "(Triangle): Input color";
				std::cin >> color;
				
				line += color;
				line += " ";
			}
			else if(!strcmp(object.c_str(), "TRIANGLE")){
				std::string color;
				std::cout << "(Triangle): Input color";
				std::cin >> color;
				
				line += color;
				line += " ";
			}
		}
		else if(!strcmp(action.c_str(), "PRESENT")){
			std::string _slideName;
			std::cout << "Input slide name: " << std::endl;
			std::cin >> _slideName;
			
			line += _slideName;
			line += " ";
		}
		else{
			std::cerr << "ERROR: Invalid type of action" << std::endl;
			throw std::runtime_error("ERROR: Invalid type of action");
		}
		m_file << line << std::endl;
	}while(line != "end");
	m_file.close();
}

Administrator::Administrator() : m_FPath("data.txt"){
	GetData();
	ReadParseData();
}

static Administrator& GetInstance(){
	static Administrator instance;
	return instance;
}


void Administrator::ReadParseData(){
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	m_file.open(m_FPath, std::ios::in);
	do{
		std::stringstream currLine(getLine(m_file));
		ParseLine(currLine);
	}while(!m_file.eof());
	//return "123";
}

#endif // __READ__INFO__IMPL__CPP__
