#ifndef __PROCESS__MANAGER__IMPL__CPP__
#define __PROCESS__MANAGER__IMPL__CPP__

#include <iostream>
#include <string>
#include <exception>

//#include "romanLimitsTranslator.hpp"
#include "turingGenerator.hpp"

namespace TuringMachine{

	Manager& Manager::getInstance(const std::string& expr){
		static Manager instance(expr);
		return instance;
	}

	Manager::Manager(const std::string& expr){
		this->expr = expr;
	}

	void Manager::Execute(){
		//std::cout << __func__ << std::endl;
		RomanLimitsTranslator& romanLimitsTranslator = RomanLimitsTranslator::getInstance();
		TuringGenerator& turingGenerator = TuringGenerator::getInstance(expr);
		turingGenerator.generateTuringCode();
	}

} // namespace TuringMachine

#endif // __PROCESS__MANAGER__IMPL__CPP__
