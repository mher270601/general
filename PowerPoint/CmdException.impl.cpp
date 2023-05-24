
#include <string>

namespace PowerPoint{
    // Invalid Command -> Throw CmdException
	CmdException::CmdException(const std::string& ErrorMessage) : m_ErrorMessage{ErrorMessage + "\n"}
	{}
	const char* CmdException::what() const noexcept{
		return m_ErrorMessage.c_str();
	}
}