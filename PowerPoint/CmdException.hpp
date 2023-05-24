#ifndef __COMMAND__EXCEPTION__HPP__
#define __COMMAND__EXCEPTION__HPP__

#include <exception>
#include <string>

namespace PowerPoint{
    class CmdException : public std::exception{
	public:
		explicit CmdException(const std::string& ErrorMessage);
		const char* what() const noexcept;
	private:
		std::string m_ErrorMessage;
	};
}

#include "CmdException.impl.cpp"

#endif // __COMMAND__EXCEPTION__HPP__