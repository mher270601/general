#ifndef __CADD__HPP__
#define __CADD__HPP__

#include <sstream>

#include "ICommand.hpp"

namespace PowerPoint{
	namespace Cmd{
		class CmdAdd : public ICommand{
		public:
			CmdAdd();
			void Execute(std::stringstream& expr) override;
			ICommand_SPtr Clone() const override;
		private:
		};
	} // namespace Cmd
} // namespace PowerPoint

#include "CAdd.impl.cpp"

#endif // __CADD__HPP__
