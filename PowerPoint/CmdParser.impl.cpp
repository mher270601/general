#ifndef __COMMAND__PARSER__IMPL__CPP__
#define __COMMAND__PARSER__IMPL__CPP__

#include <algorithm>
#include <exception>
#include <iostream>
#include <memory>

#include "Token.hpp"
#include "ICommand.hpp"
//#include "CAdd.hpp"
#include "cmd_add.hpp"

namespace PowerPoint{

	CmdParser& CmdParser::GetInstance(){
		// Meyer's Singleton
		static CmdParser Instance;
		return Instance;
	}

	//ECommandType CmdParser::getActionType(std::stringstream& expr) const{
	//	std::string action;
	//	expr >> action;
	//	std::transform(action.begin(), action.end(), action.begin(), ::toupper); // Transform input to uppercase
	//	if()
	//}

	ICommand_SPtr CmdParser::getAction(std::stringstream& expr) const{
		ICommand_SPtr currentCmd = nullptr;
		std::string action;
		expr >> action;
		//std::transform(action.begin(), action.end(), action.begin(), ::tolower); // Transform input to lowercase
		if(m_actionsTranslater.count(action)){
			//throw std::logic_error("ERROR: Invalid action\n");
			currentCmd = m_actionsTranslater.at(action)->Clone();
		}
		
		return currentCmd;
		//return m_actionsTranslater.at(action);
	}

	Token CmdParser::getToken(std::stringstream& expr) const{
		Token currToken;
		currToken.m_tokenType = ETokenType::Invalid;
		//currToken.m_actionType = getAction(expr); //TODO
		
		return currToken;
	}

	void CmdParser::Parse(std::stringstream& expr){
		m_tokenizer.Lexemmer(expr);
		// EToken = 
	}

	CmdParser::CmdParser() { // Default Ctor
		
		ICommand_SPtr CAddCmd = std::make_shared<Cmd::CAddCmd>();
		
		//m_actionsTranslater.emplace("SET", EActionType::Set);
		//m_actionsTranslater.emplace("RESET", EActionType::Reset);
		//m_actionsTranslater.emplace("CREATE", EActionType::Create);
		//m_actionsTranslater.emplace("PRESENT", EActionType::Present);
		m_actionsTranslater.emplace("ADD", CAddCmd);
		//m_actionsTranslater.emplace("REMOVE", EActionType::Remove);

	}
}

#endif // __COMMAND__PARSER__IMPL__CPP__
