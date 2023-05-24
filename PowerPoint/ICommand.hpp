#ifndef __ICOMMAND__HPP__ 
#define __ICOMMAND__HPP__ 

#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <memory>

#include "IHandle.hpp"

namespace PowerPoint{

	class ICommand{
	public:
		virtual void Execute(std::istringstream&) = 0;
		virtual ~ICommand() = default;
	//private: 
		//std::unordered_map<std::string, > 
	};
	using ICommand_SPtr = std::shared_ptr<ICommand>;
}
#endif // __ICOMMAND__HPP__ 
