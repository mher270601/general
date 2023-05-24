#ifndef __IINPUT__HPP__
#define __IINPUT__HPP__

#include <string>

namespace PowerPoint{
	class ICmdInput{
	public:
		virtual std::string GetCommand() const = 0;
		virtual bool CmdVerified(std::stringstream& expr) const noexcept = 0;
		virtual ~ICmdInput() = default;
	private:
	};
}

#endif // __IINPUT__HPP__
