#ifndef __LOGGER__CPP__
#define __LOGGER__CPP__

#include "Logger.hpp"

Logger::Logger(){
	m_file.open("C:\\log-app.txt", std::ios::app);
}

Logger& Logger::Instance(){
	static Logger instance;
	return instance;
}

void Logger::Log(const std::string& msg){
	std::lock_guard<std::mutex> lock(m_mutex);
	m_file << msg << std::endl;
}

#endif // __LOGGER__CPP__
