#ifndef __IINPUT__HPP__
#define __IINPUT__HPP__

#include <string>
#include <memory>

namespace PowerPoint{
	class ICmdInput{
	public:
		virtual std::string GetCommand() const = 0;
		//virtual bool CmdVerified(std::stringstream& expr) const noexcept = 0;
		virtual ~ICmdInput() = default;
	private:
	};

	using ICmdInput_SPtr = std::shared_ptr<ICmdInput>;
}

#endif // __IINPUT__HPP__
