#ifndef __FILE__MANAGER__HPP__
#define __FILE__MANAGER__HPP__

#include <iostream>
#include <string>
#include <fstream>
#include <mutex>

namespace Snowball{

	class FileManager{
	public:
		static FileManager& getInstance();
	    	FileManager(const FileManager&) = delete;
	    	FileManager& operator=(const FileManager&) = delete;
		void logMessage(const std::string& message);
		virtual ~FileManager();
	private:
		void clearFile(const std::string& filename);
    		FileManager();
	private:
		std::string m_fName;
	    	std::ofstream m_logFile;
	    	std::mutex m_mutex;
	};

}

#include "FileManager.impl.cpp"

#endif // __FILE__MANAGER__HPP__
