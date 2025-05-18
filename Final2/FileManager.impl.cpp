#ifndef __FILE__MANAGER__IMPL__CPP__
#define __FILE__MANAGER__IMPL__CPP__

#include <string>
#include <iostream>
#include <fstream>
#include <mutex>
#include <stdexcept>

namespace Snowball{

	FileManager::FileManager() : m_fName("log.txt"){
		clearFile(m_fName);
    	    	m_logFile.open(m_fName, std::ios::app);
    	    	if(!m_logFile.is_open()) {
			throw std::runtime_error("Failed to open file: " + m_fName);
    	    	}
    	}

    	// Get the Mayer's singleton instance (thread safe)
    	FileManager& FileManager::getInstance() {
    	    	static FileManager instance;
    	    	return instance;
    	}

	FileManager::~FileManager() {
    	    	if(m_logFile.is_open()) {
    	        	m_logFile.close();
    	    	}
    	}

	void FileManager::clearFile(const std::string& filename) {
        	std::ofstream ofs(filename, std::ios::trunc);
        	// file is now cleared
        	ofs.close();
    	}

    	void FileManager::logMessage(const std::string& message) {
    	    	std::lock_guard<std::mutex> lock(m_mutex);
    	    	if(m_logFile.is_open()) {
    	        	m_logFile << message << '\n';
    	    	}
    	}
}

#endif // __FILE__MANAGER__IMPL__CPP__
