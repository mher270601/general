#ifndef __FILE__MANAGER__HPP__
#define __FILE__MANAGER__HPP__

#include <iostream>
#include <string>
#include <fstream>

namespace TuringMachine{

	class FileManager{
	public:
		FileManager& operator=(const FileManager& rhs) = delete;
		FileManager(const FileManager& rhs) = delete;
		static FileManager& getInstance();
		void writeToFile(const std::string expr, const size_t fileNumber);
		~FileManager();
	private:
		FileManager();
		std::ofstream m_outputFile1;
		std::ofstream m_outputFile2;
	};
	
} // namespace TuringMachine

#include "fileManager.impl.cpp"

#endif // __FILE__MANAGER__HPP__
