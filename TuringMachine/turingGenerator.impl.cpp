#ifndef __TURING__GENERATOR__IMPL__CPP__
#define __TURING__GENERATOR__IMPL__CPP__

#include <iostream>
#include <string>
#include <cassert>
#include <stdexcept>

#include "utilities.hpp"
#include "romanLimitsTranslator.hpp"
#include "romanContainer.hpp"
#include "fileManager.hpp"

namespace TuringMachine{

	TuringGenerator& TuringGenerator::getInstance(const std::string& expr){
		static TuringGenerator instance(expr);
		return instance;
	}

	TuringGenerator::TuringGenerator(const std::string& expr){
		m_dataContainer.resize(7);
		this->expr = expr;
	}

	void TuringGenerator::generateTuringCode(){
		RomanLimitsTranslator& romanLimit = RomanLimitsTranslator::getInstance();
		FileManager& fileManager = FileManager::getInstance();
		std::string currExpr = ""; // final expression
		std::string currState = "s"; // starting state
		std::string prevState = ""; // remember previous value
		size_t fileNumber = 2;
		for(auto it = expr.rbegin(); it != expr.rend(); ++it){
			std::string symbol = std::string() + *it;
			if(prevState.compare(symbol) == 0){
				fileNumber = 1;
			}
			currExpr = "((" + currState + "," + symbol + "_),(r,_," + symbol + "))\n((r,_," + symbol + "),(s,->,->))";
			//std::cout << currExpr << std::endl;
			fileManager.writeToFile(currExpr, fileNumber);
			fileNumber = 2;
			prevState = symbol;
			size_t indx = getRomanValueIndex(*it);
			if(romanLimit.translateValue(symbol) >= m_dataContainer[indx].getSize() + 1){
				m_dataContainer[indx].addSymbol(symbol);
			} else {
				m_dataContainer[indx].removeSymbol(romanLimit.translateValue(symbol));
				if(indx >= 6){
					throw std::out_of_range("Count of M's should be <= 3");
				}
				std::string newSymbol = std::string() + getNextRomanValue(*it);
				m_dataContainer[indx + 1].addSymbol(getNextRomanValue(*it));
			}
		}
		std::cout << "\tFINAL ANSWER" << std::endl;
		std::cout << "|";
		for(auto it = m_dataContainer.rbegin(); it != m_dataContainer.rend(); ++it){
			it->cPrint(); 
		}
		std::cout << std::endl;

	}

} // namespace TuringMachine

#endif // __TURING__GENERATOR__IMPL__CPP__
