#include <iostream>
#include <exception>

#include "GameEngine.hpp"

int main(){

	try{
		Snowball::GameEngine& gameEngine = Snowball::GameEngine::getInstance();
		gameEngine.execute();
	}catch(std::exception& err){
		std::cout << err.what() << std::endl;
	}

	return 0;
}
