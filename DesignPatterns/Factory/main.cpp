#include <iostream>

#include "factory.hpp"

int main(){

	IWorkShop* creator = new iPhoneWorkShop();

	IProduction* iphone = creator->create();

	creator = new SamsungWorkShop();

	IProduction* samsung = creator->create();

	iphone->release();
	samsung->release();

	return 0;
}
