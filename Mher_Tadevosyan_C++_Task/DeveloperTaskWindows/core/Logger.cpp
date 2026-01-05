#ifndef __LOGGER__CPP__
#define __LOGGER__CPP__

#include "Logger.hpp"
#include <filesystem>

Logger::Logger(){
}

Logger& Logger::Instance(){
	static Logger instance;
	return instance;
}

void Logger::LogToFile(const std::string& filePath, const std::string& msg){
	std::lock_guard<std::mutex> lock(m_mutex);
	std::ofstream file(filePath, std::ios::app);
	if(file.is_open()){
		file << msg << std::endl;
	}
}

void Logger::LogApp(const std::string& msg){
	LogToFile("C:\\log-app.txt", msg);
}

void Logger::LogEvent(const std::string& msg){
	LogToFile("C:\\log-events.txt", msg);
}

void Logger::LogCamera(const std::string& msg){
	LogToFile("C:\\log-camera.txt", msg);
}

void Logger::LogMicrophone(const std::string& msg){
	LogToFile("C:\\log-microphone.txt", msg);
}

void Logger::LogFileOpen(const std::string& msg){
	LogToFile("C:\\log-open-log-file.txt", msg);
}

#endif // __LOGGER__CPP__
