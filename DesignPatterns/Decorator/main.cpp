#include <iostream>

#include "decorator.hpp"

int main(){
	IBurger* burger = new ClassicBurger;
	burger->process();

	Ingredient* onion = new Onion(burger);
	onion->process();

	Ingredient* tomat = new Tomat(onion);
	tomat->process();
	std::cout << "Total price = " << tomat->getPrice() << std::endl;
	return 0;
}
