#ifndef __ROMAN__LIMITS__TRANSLATOR__IMPL__CPP__
#define __ROMAN__LIMITS__TRANSLATOR__IMPL__CPP__

#include <iostream>
#include <map>
#include <string>
#include <stdexcept>

namespace TuringMachine{

	RomanLimitsTranslator& RomanLimitsTranslator::getInstance(){
		static RomanLimitsTranslator instance;
		return instance;
	}

	bool RomanLimitsTranslator::checkValue(const std::string& value){
		return m_romanLimits.find(value) != m_romanLimits.end();
	}

	size_t RomanLimitsTranslator::translateValue(const std::string& romanValue){
		//std::cout << __func__ << std::endl;
		if(!checkValue(romanValue)){
			throw std::invalid_argument("Invalid roman value: " + romanValue);
		}
		return m_romanLimits[romanValue];
	}

	RomanLimitsTranslator::RomanLimitsTranslator(){
		m_romanLimits.emplace("I", 4);
		m_romanLimits.emplace("V", 1);
		m_romanLimits.emplace("X", 4);
		m_romanLimits.emplace("L", 1);
		m_romanLimits.emplace("C", 4);
		m_romanLimits.emplace("D", 1);
		m_romanLimits.emplace("M", 3);
	}

} // namespace TuringMachine

#endif // __ROMAN__LIMITS__TRANSLATOR__IMPL__CPP__
