#ifndef __LOGGER__CPP__
#define __LOGGER__CPP__

#include "Logger.hpp"

Logger::Logger(const std::string& path){
	m_file.open(path, std::ios::app);
}

void Logger::Log(const std::string& msg){
	std::lock_guard<std::mutex> lock(m_mutex);
	m_file << msg << std::endl;
}

#endif // __LOGGER__CPP__
