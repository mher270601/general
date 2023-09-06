#ifndef __CMD__ADD__HPP__
#define __CMD__ADD__HPP__

#include <iostream>
#include <sstream>
#include <string>
#include <memory>

#include "ICommand.hpp"

namespace PowerPoint{

	namespace Cmd{
	
		class CAddCmd : public ICommand{
		public:
			CAddCmd();
			void Execute(std::istringstream& expr) override;
			ICommand_SPtr Clone() const override; 
		private:

		};
		
	} // namespace Cmd

} // namespace PowerPoint

#include "cmd_add.impl.cpp"

#endif // __CMD__ADD__HPP__
