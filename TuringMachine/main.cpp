#include <iostream>
#include <stdexcept>

#include "processManager.hpp"

int main(int argc, char *argv[]){
	try{
		TuringMachine::Manager& procManager = TuringMachine::Manager::getInstance("MDCCCCLXXXXVIIIII");
		procManager.Execute();
	} catch(std::exception& any){
		std::cout << "Error: " << any.what() << std::endl;
	}
}
