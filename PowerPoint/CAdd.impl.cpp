#ifndef __CADD__IMPL__CPP__
#define __CADD__IMPL__CPP__

#include <memory>

#include "ICommand.hpp"

namespace PowerPoint{
	
	CmdAdd::CmdAdd(){

	}

	void CmdAdd::Execute(){

	}

	ICommand_SPtr CmdAdd::Clone() const {
		return std::make_shared<CmdAdd>(); //TODO
	}

} // namespace PowerPoint

#endif // __CADD__IMPL__CPP__
