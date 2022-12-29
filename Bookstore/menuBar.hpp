#ifndef __MENU__BAR__HPP__
#define __MENU__BAR__HPP__

#include <iostream>
#include <stdlib.h>
#include <thread>

#include "input.hpp"
#include "utility.hpp"
#include "menu.hpp"
#include "name.hpp"

void progressBar()
{	
	std::string_view newLine_11 = "\n\n\n\n\n\n\n\n\n\n\n";
	int displayNext = 1, percent = 0;
    	const int totalProcesesCount = 13, totalPercent = 100;

        system("clear");
        std::cout << newLine_11 << CYAN << "\t\t\t\t\t\t\tLOADING " << totalProcesesCount << " SECTIONS...\n\n\n\n" << RESET << std::endl;

        // loop through the process count
        for (size_t i = 0; i < totalProcesesCount ; ++i)
        {
                std::this_thread::sleep_for(std::chrono::milliseconds(220));

                // Individual image processing operations

                // Formatted progress indicator
                percent = (totalPercent * (i + 1)) / totalProcesesCount;
                if (percent >= displayNext)
                {
                        std::cout << "\r\t\t\t\t\t" << CYAN << "[" << RESET << BACK_B_GREEN << GREEN << std::string(percent / 5, (char)61u) << RESET << YELLOW << std::string(100 / 5 - percent / 5, ' ') << RESET << CYAN << "]" << RESET;
			
                        std::cout << YELLOW << percent << "%" << RESET << CYAN << " [LOADED " << RESET << YELLOW << i + 1 << RESET << CYAN << " of " << RESET << B_GREEN << totalProcesesCount << RESET << CYAN << "]" << RESET;
                        std::cout.flush();
                        displayNext++;                }
        }
        system("clear");	
} // progressBar

void printMenu(Menu& menu){
	const int key_prs = keypress();
	switch(key_prs){
	case keyUp:
		system("clear");
		BSName();
		menu.Top();
	break;
	case keyDown:
		system("clear");
		BSName();
		menu.Down();
	break;
	case keyEnter:
		system("clear");
		BSName();
		menu.Enter();
	break;
	case quit:
		menu.finish();
	break;
	}
} // printMenu
#endif // __MENU__BAR__HPP__
