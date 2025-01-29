#ifndef __ROMAN__CONTAINER__IMPL__CPP__
#define __ROMAN__CONTAINER__IMPL__CPP__

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

#include "romanLimitsTranslator.hpp"
#include "utilities.hpp"

namespace TuringMachine{
	
	bool RomanContainer::checkLimit(const std::string& value){
		//std::cout << __func__ << std::endl;
		RomanLimitsTranslator& romanTranslator = RomanLimitsTranslator::getInstance();
		if(m_data.empty()){
			return true;
		}
		return 	m_data.size() <= romanTranslator.translateValue(value);
	}

	size_t RomanContainer::getSize() const{
		return m_data.size();
	}

	std::string RomanContainer::getValue() const noexcept{
		if(m_data.empty()){
			return NULL;
		}
		return m_data[0];
	}

	void RomanContainer::cPrint() const noexcept{
		for(const auto& symbol : m_data){
			std::cout << symbol << "|";
		}
	}

	bool RomanContainer::checkValue(const std::string& value){
		//std::cout << __func__ << std::endl;
		RomanLimitsTranslator& romanTranslator = RomanLimitsTranslator::getInstance();
		romanTranslator.translateValue(value);
		return true;
	}

	void RomanContainer::addSymbol(const std::string& symbol){
		if(!checkValue(symbol)){
			throw std::invalid_argument("Invalid argument: " + symbol);
		}
		m_data.push_back(symbol);
	}

	void RomanContainer::removeSymbol(const size_t count){
		if(count > m_data.size()){
			throw std::invalid_argument("Invalid count to remove: " + std::to_string(count));
		}
		for(size_t i = 0; i < count; ++i){
			m_data.pop_back();
		}
	}

}

#endif // __ROMAN__CONTAINER__IMPL__CPP__
