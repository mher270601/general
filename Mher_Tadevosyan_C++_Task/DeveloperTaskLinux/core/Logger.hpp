#ifndef __LOGGER__HPP__
#define __LOGGER__HPP__

#include <mutex>
#include <fstream>
#include <string>

class Logger{
public:
	explicit Logger(const std::string& path);
	void Log(const std::string& msg);

private:
	std::mutex m_mutex;
	std::ofstream m_file;
};

#endif // __LOGGER__HPP__
