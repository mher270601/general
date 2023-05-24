#ifndef __INPUT__CMD__HPP__
#define __INPUT__CMD__HPP__

#include <exception>
#include <string>
#include <memory>

#include "IInput.hpp"
#include "CmdParser.hpp"

namespace PowerPoint{
 
	

	class CmdInput : ICmdInput{
	public:
		CmdInput(const CmdInput& rhs) = delete;	
		CmdInput& operator=(const CmdInput& rhs) = delete;
	public:
		// Interface
		static std::shared_ptr<CmdInput>& GetInstance();
		std::string GetCommand() const override;
	private: // Helpers
		bool CmdVerified(std::stringstream& expr) const noexcept override;
		CmdInput() = default;
	private:
		CmdParser& m_cmdParser = CmdParser::GetInstance();
	};
}

#include "InputCmd.impl.cpp"

#endif // __INPUT__CMD__HPP__
