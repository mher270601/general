#ifndef __CADD__IMPL__CPP__
#define __CADD__IMPL__CPP__

#include <memory>

#include "ICommand.hpp"

namespace PowerPoint{
	namespace Cmd{
		CmdAdd::CmdAdd(){

		}

		void CmdAdd::Execute(){

		}

		ICommand_SPtr CmdAdd::Clone() const {
			return std::make_shared<CmdAdd>(*this);
		}
	} // namespace Cmd
} // namespace PowerPoint

#endif // __CADD__IMPL__CPP__
