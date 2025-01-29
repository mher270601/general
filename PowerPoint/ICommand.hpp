#ifndef __ICOMMAND__HPP__ 
#define __ICOMMAND__HPP__ 

#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <memory>

//#include "IHandle.hpp"

namespace PowerPoint{

	//namespace Cmd{

		class ICommand{
		public:
			virtual void Execute(std::stringstream& expr) = 0;
			virtual std::shared_ptr<ICommand> Clone() const = 0;
			virtual ~ICommand() = default;
		//private: 
			//std::unordered_map<std::string, > 
		};
		using ICommand_SPtr = std::shared_ptr<ICommand>;
		
	//} // namespace Cmd

} // namespace PowerPoint

#endif // __ICOMMAND__HPP__ 
