#ifndef __FILE__EXCEPTION__HPP__
#define __FILE__EXCEPTION__HPP__

#include <exception>
#include <string>

class FileOpen_Error : public std::exception{
public:
	explicit FileOpen_Error(const std::string what_arg);
	~FileOpen_Error() = default;
	std::string what();
private:
	std::string m_s_message;
};

#include "fileExcep.cpp"

#endif // __FILE__EXCEPTION__HPP__
