#include <iostream>
#include <exception>

#include "Line.hpp"

int main(){
	
	try{

	}catch(std::exception& err){
		std::cout << err.what() << std::endl;
	}


	return 0;
}
