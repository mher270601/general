#ifndef __CADD__IMPL__CPP__
#define __CADD__IMPL__CPP__

#include <memory>
#include <sstream>

#include "ICommand.hpp"
#include "pwpt_DocStorage.hpp"

namespace PowerPoint{
	namespace Cmd{
		CmdAdd::CmdAdd(){

		}

		void CmdAdd::Execute(std::stringstream& expr){
			DocumentStorage& docStorage = DocumentStorage::GetInstance();
		}

		ICommand_SPtr CmdAdd::Clone() const {
			return std::make_shared<CmdAdd>(*this);
		}
	} // namespace Cmd
} // namespace PowerPoint

#endif // __CADD__IMPL__CPP__
