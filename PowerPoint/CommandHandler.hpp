#ifndef __COMMAND__HANDLER__
#define __COMMAND__HANDLER__

#include <string>

#include "IHandler.hpp"
#include "ICommand.hpp"
#include "CmdParser.hpp"

namespace PowerPoint{
	
	class CommandHandler : public IHandler<ICommand_SPtr>{
	public:
		//void Handle(ICommand_SPtr) = 0;
		void Handle(ICommand_SPtr) override;
		void InputDetected(const std::string&);
	private:
		CmdParser& parser = CmdParser::GetInstance();
	};

}

#include "CommandHandler.impl.cpp"

#endif // __COMMAND__HANDLER__
