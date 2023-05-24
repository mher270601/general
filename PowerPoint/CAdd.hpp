#ifndef __CADD__HPP__
#define __HANDLE__HPP__

#include "ICommand.hpp"

namespace PowerPoint{
	class CmdAdd : public ICommand{
	public:
		void Execute() = 0;
	private:
	};
}

#endif // __HANDLE__HPP__
