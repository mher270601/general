#ifndef __CMD__ADD__IMPL__CPP__
#define __CMD__ADD__IMPL__CPP__

#include <iostream>
#include <memory>

#include "ICommand.hpp"

namespace PowerPoint{

	namespace Cmd{
		
		CAddCmd::CAddCmd(){ // Ctor
			
		}

		void CAddCmd::Execute(std::istringstream& expr){

		}

		std::shared_ptr<ICommand> CAddCmd::Clone() const{
			return std::make_shared<CAddCmd>(*this);
		}

	} // namespace Cmd

} // namespace PowerPoint

#endif // __CMD__ADD__IMPL__CPP__
