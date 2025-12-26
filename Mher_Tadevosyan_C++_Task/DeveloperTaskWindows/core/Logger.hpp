#ifndef __LOGGER__HPP__
#define __LOGGER__HPP__

#include <mutex>
#include <fstream>
#include <memory>
#include <string>

class Logger{
public:
	static Logger& Instance();

	void Log(const std::string& msg);

private:
	Logger();
	std::mutex m_mutex;
	std::ofstream m_file;
};

#endif // __LOGGER__HPP__
