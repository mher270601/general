#ifndef __ROMAN__LIMITS__TRANSLATOR__HPP__
#define __ROMAN__LIMITS__TRANSLATOR__HPP__

#include <string>
#include <map>

namespace TuringMachine{

	class RomanLimitsTranslator{
	public:
		RomanLimitsTranslator& operator=(const RomanLimitsTranslator& rhs) = delete;
		RomanLimitsTranslator(const RomanLimitsTranslator& rhs) = delete;
		static RomanLimitsTranslator& getInstance();
		size_t translateValue(const std::string& romanValue);
	private:
		bool checkValue(const std::string& value);
		RomanLimitsTranslator();
		std::map<std::string, size_t> m_romanLimits;
	};

} // namespace TuringMachine

#include "romanLimitsTranslator.impl.cpp"

#endif // __ROMAN__LIMITS__TRANSLATOR__HPP__
