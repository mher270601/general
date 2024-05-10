#ifndef __CADD__HPP__
#define __CADD__HPP__

#include "ICommand.hpp"

namespace PowerPoint{
	namespace Cmd{
		class CmdAdd : public ICommand{
		public:
			CmdAdd();
			void Execute() override;
			ICommand_SPtr Clone() const;
		private:
		};
	}
}

#endif // __CADD__HPP__
