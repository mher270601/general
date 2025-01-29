#ifndef __CCREATE__HPP__
#define __CCREATE__HPP__

#include <sstream>

#include "ICommand.hpp"

namespace PowerPoint{
	namespace Cmd{
		class CmdCreate : public ICommand{
		public:
			CmdCreate();
			void Execute(std::stringstream& expr) override;
			ICommand_SPtr Clone() const override;
		private:
		};
	} // namespace Cmd
} // namespace PowerPoint

#include "CCreate.impl.cpp"

#endif // __CCREATE__HPP__
