#include <exception>
#include <iostream>
#include <memory>
#include <string>
#include <stdlib.h>

#include "Bookstore.hpp"
#include "fileManager.hpp"
#include "ETypes.hpp"
#include "getFilePath.hpp"
#include "input.hpp"
#include "utility.hpp"
#include "menuBar.hpp"
#include "name.hpp"
#include "menuBar.hpp"

int main(const int argc, char** argv){
	cbreak();
	progressBar();
	BSName();
	Menu menu;
	menu.print();	
	while(menu.getState()){
		printMenu(menu);
	}
	normal();
	return 0;
}
