#ifndef __INPUT__CMD__IMPL__CPP__
#define __INPUT__CMD__IMPL__CPP__

#include <iostream>
#include <cassert>
#include <exception>
#include <string>
#include <memory>

#include "CmdException.hpp"

namespace PowerPoint{
	
	/////////////////////////////////////

	std::shared_ptr<CmdInput>& CmdInput::GetInstance(){
		// Meyer's Singleton
		static std::shared_ptr<CmdInput> Instance(new CmdInput);
		return Instance;
	}

	std::string CmdInput::GetCommand() const{
		std::string CurrentCommand = "";
		//do{
		std::cout << "Input command: ";
		std::cin >> CurrentCommand;
		std::stringstream SExpr(CurrentCommand);
		if(CmdVerified(SExpr)){
			return CurrentCommand;
		}
		throw CmdException("Invalid Command ! (if you want to finish, write 'finish' or 'end')");
		assert(false && "Must not reach here");
		//}while(CurrentCommand != "end" || CurrentCommand != "finish");
		
	}
	bool CmdInput::CmdVerified(std::stringstream& expr) const noexcept{
		//TODO
		m_cmdParser.Parse(expr);
		
		return true;	
	}

}

#endif // __INPUT__CMD__IMPL__CPP__
