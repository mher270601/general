#ifndef __HANDLE__HPP__
#define __HANDLE__HPP__

#include <string>

namespace PowerPoint{
	template <typename T>
	class IHandler{
	public:
		virtual void Handle(T/*ICommand_SPtr*/) = 0;
		virtual void InputDetected(const std::string&) = 0;
		virtual ~IHandler() = default;
	};

}

#endif // __HANDLE__HPP__
