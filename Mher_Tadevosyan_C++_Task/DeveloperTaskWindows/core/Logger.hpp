#ifndef __LOGGER__HPP__
#define __LOGGER__HPP__

#include <mutex>
#include <fstream>
#include <string>

class Logger{
public:
	static Logger& Instance();
	void LogApp(const std::string& msg);
	void LogEvent(const std::string& msg);
	void LogCamera(const std::string& msg);
	void LogMicrophone(const std::string& msg);
	void LogFileOpen(const std::string& msg);

private:
	Logger();
	void LogToFile(const std::string& filePath, const std::string& msg);
	std::mutex m_mutex;
};

#endif // __LOGGER__HPP__
