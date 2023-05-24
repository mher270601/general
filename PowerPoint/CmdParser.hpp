#ifndef __COMMAND__PARSER__HPP__
#define __COMMAND__PARSER__HPP__

#include <iostream>
#include <string>
#include <unordered_map>

#include "Token.hpp"
#include "ICmdParser.hpp"
#include "CmdTokenizer.hpp"

namespace PowerPoint{
	
	class CmdParser : public ICmdParser{
	public:
		// Meyer's Singleton
		static CmdParser& GetInstance();
		CmdParser(const CmdParser&) = delete;
		CmdParser& operator=(const CmdParser&) = delete;
		void Parse(std::stringstream& expr) override;
	private:
		CmdParser();
		Token getToken(std::stringstream& expr) const;
		EActionType getAction(std::stringstream& expr) const;
	private:
		const std::unordered_map<std::string, EActionType> m_actionsTranslater;
		Tokenizer& m_tokenizer = Tokenizer::GetInstance();
		//CmdTokenizer tokenizer;
	};

}

#include "CmdParser.impl.cpp"

#endif // __COMMAND__PARSER__HPP__
