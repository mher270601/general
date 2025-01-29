#ifndef __CCREATE__IMPL__CPP__
#define __CCREATE__IMPL__CPP__

#include <memory>
#include <sstream>

#include "ICommand.hpp"
#include "pwpt_DocStorage.hpp"

namespace PowerPoint{
	namespace Cmd{
		CmdCreate::CmdCreate(){

		}

		void CmdCreate::Execute(std::stringstream& expr){
			DocumentStorage& docStorage = DocumentStorage::GetInstance();

		}

		ICommand_SPtr CmdCreate::Clone() const {
			return std::make_shared<CmdCreate>(*this);
		}
	} // namespace Cmd
} // namespace PowerPoint

#endif // __CCREATE__IMPL__CPP__
