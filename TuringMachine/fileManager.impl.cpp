#ifndef __FILE__MANAGER__IMPL__CPP__
#define __FILE__MANAGER__IMPL__CPP__

#include <iostream>
#include <string>
#include <fstream>

namespace TuringMachine{

	FileManager& FileManager::getInstance(){
		static FileManager instance;
		return instance;
	}

	FileManager::FileManager(){
		try{
			if(std::filesystem::remove("turingCode.txt")){
				return;
			}
		} catch(const std::filesystem::filesystem_error& err){
			return;
		}
		m_outputFile1.open("turingCode.txt");
		m_outputFile2.open("optimizedTuringCode.txt");
	}

	FileManager::~FileManager(){
		m_outputFile1.close();
		m_outputFile2.close();
	}

	void FileManager::writeToFile(const std::string expr, const size_t fileNumber){
		if(fileNumber == 1 && m_outputFile1.is_open()){ // Simple version` without optimization
			m_outputFile1 << expr << std::endl;
		} else if(fileNumber == 2 && m_outputFile2.is_open()){ // With optimization
			m_outputFile1 << expr << std::endl;
			m_outputFile2 << expr << std::endl;
		}
	}

} // namespace TuringMachine

#endif // __FILE__MANAGER__IMPL__CPP__
