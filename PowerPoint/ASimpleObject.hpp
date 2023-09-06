#ifndef __ASIMPLEOBJECT__HPP__
#define __ASIMPLEOBJECT__HPP__

#include <string>

namespace PowerPoint{

	class ASimpleObject{
	public:
		ASimpleObject(const std::string& objectName);
		std::string getName() const noexcept;
		size_t GetId() const noexcept;
		virtual ~ASimpleObject() = 0;
	private:
		const std::string m_name;
		const size_t m_Identifier;
	};


} // namespace PowerPoint

#include "ASimpleObject.impl.cpp"

#endif // __ASIMPLEOBJECT__HPP__
