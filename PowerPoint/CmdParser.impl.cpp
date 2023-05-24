#ifndef __COMMAND__PARSER__IMPL__CPP__
#define __COMMAND__PARSER__IMPL__CPP__

#include <algorithm>
#include <exception>
#include <iostream>

#include "Token.hpp"

namespace PowerPoint{

	CmdParser& CmdParser::GetInstance(){
		// Meyer's Singleton
		static CmdParser Instance;
		return Instance;
	}

	EActionType CmdParser::getAction(std::stringstream& expr) const{
		std::string action;
		expr >> action;
		std::transform(action.begin(), action.end(), action.begin(), ::tolower); // Transform input to lowercase
		if(m_actionsTranslater.find(action) == m_actionsTranslater.end()){
			throw std::logic_error("ERROR: Invalid action\n");
		}

		return m_actionsTranslater.at(action);
	}

	Token CmdParser::getToken(std::stringstream& expr) const{
		Token currToken;
		currToken.m_tokenType = ETokenType::Invalid;
		currToken.m_actionType = getAction(expr);
		
		return currToken;
	}

	void CmdParser::Parse(std::stringstream& expr){
		m_tokenizer.Lexemmer(expr);
		// EToken = 
	}

	CmdParser::CmdParser() : // Default Ctor
		m_actionsTranslater{
			{"set", EActionType::Set},
			{"reset", EActionType::Reset},
			{"create", EActionType::Create},
			{"present", EActionType::Present},
			{"add", EActionType::Add},
			{"remove", EActionType::Remove}
		}
	{
	}
}

#endif // __COMMAND__PARSER__IMPL__CPP__
