#include <cstdlib> // abort()
#include <iostream>
#include <stdlib.h> // system()
#include <string> // std::string(_view)
#include <thread> // sleep()

#include "input.hpp"
#include "source.hpp"
#include "gameName.hpp"

std::string_view newLine_11 = "\n\n\n\n\n\n\n\n\n\n\n";
std::string_view backSpace_8 = "\t\t\t\t\t\t\t\t";

void progressBar()
{	
	int displayNext = 1, percent = 0;
    const int totalProcesesCount = 13, totalPercent = 100;

        system("clear");
        std::cout << newLine_11 << CYAN << "\t\t\t\t\t\t\tâğ£ğ ğğğ¤ğ¤ğğğ " << totalProcesesCount << " ğğ¦ğğğ¥ğğ ğğ¤...\n\n\n\n" << RESET << std::endl;

        // loop through the process count
        for (size_t i = 0; i < totalProcesesCount ; ++i)
        {
                std::this_thread::sleep_for(std::chrono::milliseconds(220));

                // Individual image processing operations

                // Formatted progress indicator
                percent = (totalPercent * (i + 1)) / totalProcesesCount ;
                if (percent >= displayNext)
                {
                        std::cout << "\r\t\t\t\t\t" << CYAN << "[" << RESET << BACK_B_GREEN << GREEN << std::string(percent / 5, (char)61u) << RESET << YELLOW << std::string(100 / 5 - percent / 5, ' ') << RESET << CYAN << "]" << RESET;
                        std::cout << YELLOW << percent << "%" << RESET << CYAN << " [ğ½ğ¦ğğğ¥ğğ ğğ¤ " << RESET << YELLOW << i + 1 << RESET << CYAN << " ğ ğ " << RESET << B_GREEN << totalProcesesCount << RESET << CYAN << "]" << RESET;
                        std::cout.flush();
                        displayNext++;//displayNext += step;
                }
        }
        system("clear");	
}

void printMenu(std::string start, std::string speed, std::string difficulty, std::string settings, std::string exit)
{
	system("clear");
    game_name();	
	std::cout << "\n\n" << backSpace_8 << start << std::endl;
    std::cout << backSpace_8 << speed << std::endl;
    std::cout << backSpace_8 << difficulty << std::endl;
    std::cout << backSpace_8 << settings << std::endl;
    std::cout << backSpace_8 << exit << std::endl;
}

bool menuBar(char matrix1[][matrixSize])
{	
    size_t line_num = 1;
    extern size_t gameSpeed;
    extern int hard_lvl;
    std::string start = "\033[32m    ğ ğ ğ° ğ ğ \u001b[0m\n";
    std::string speed = "\u001b[36mğ ğ¿ ğ´ ğ´ ğ³  â¬ â­ â­ â­ \u001b[0m\n";
    std::string difficulty = "\u001b[36mğ ğ´ ğ» ğ´ ğ² ğ  ğ³ ğ¸ ğµ ğµ ğ¸ ğ² ğ ğ» ğ ğ  â¬ â­ â­ \u001b[0m\n";
    std::string settings = "\u001b[36mğ ğ´ ğ ğ ğ¸ ğ½ ğ¶ ğ \u001b[0m\n";
    std::string exit = "\u001b[36mğ´ ğ ğ¸ ğ \u001b[0m\n";
	printMenu(start, speed, difficulty, settings, exit);	
	cbreak();

    bool game = true;
        while(game){
                const int key_prs = keypress();
                switch (key_prs) {
                        case keyUp:
                                if(line_num == 5){
                                        settings = "\033[32m    ğ ğ´ ğ ğ ğ¸ ğ½ ğ¶ ğ \u001b[0m\n";
                                        exit = "\u001b[36mğ´ ğ ğ¸ ğ \u001b[0m\n";
                                        line_num = 4;
					                    printMenu(start, speed, difficulty, settings, exit);
                                }
                                else if(line_num == 4){
                                        if(hard_lvl == 1){
                                            difficulty = "\033[32m    ğ ğ´ ğ» ğ´ ğ² ğ  ğ³ ğ¸ ğµ ğµ ğ¸ ğ² ğ ğ» ğ ğ  â¬ â­ â­ \u001b[0m\n";
                                        }
                                        else if(hard_lvl == 2){ 
                                            difficulty = "\033[32m    ğ ğ´ ğ» ğ´ ğ² ğ  ğ³ ğ¸ ğµ ğµ ğ¸ ğ² ğ ğ» ğ ğ  â¬ â¬ â­ \u001b[0m\n";
                                        }
                                        else if(hard_lvl == 3){ 
                                            difficulty = "\033[32m    ğ ğ´ ğ» ğ´ ğ² ğ  ğ³ ğ¸ ğµ ğµ ğ¸ ğ² ğ ğ» ğ ğ  â¬ â¬ â¬ \u001b[0m\n";
                                        }
                                        settings = "\u001b[36mğ ğ´ ğ ğ ğ¸ ğ½ ğ¶ ğ \u001b[0m\n";
                                        line_num = 3;
					                    printMenu(start, speed, difficulty, settings, exit);
                                }
                                else if(line_num == 3){
                                        if(gameSpeed == 500){
                                            speed = "\033[32m    ğ ğ¿ ğ´ ğ´ ğ³  â¬ â­ â­ â­ \u001b[0m\n";
                                        }
                                        else if(gameSpeed == 350){ 
                                            speed = "\033[32m    ğ ğ¿ ğ´ ğ´ ğ³  â¬ â¬ â­ â­ \u001b[0m\n";
                                        }
                                        else if(gameSpeed == 200){ 
                                            speed = "\033[32m    ğ ğ¿ ğ´ ğ´ ğ³  â¬ â¬ â¬ â­ \u001b[0m\n";
                                        }
                                        else if(gameSpeed == 100){ 
                                            speed = "\033[32m    ğ ğ¿ ğ´ ğ´ ğ³  â¬ â¬ â¬ â¬ \u001b[0m\n";
                                        }
                                        if(hard_lvl == 1){
                                            difficulty = "\u001b[36mğ ğ´ ğ» ğ´ ğ² ğ  ğ³ ğ¸ ğµ ğµ ğ¸ ğ² ğ ğ» ğ ğ  â¬ â­ â­ \u001b[0m\n";
                                        }
                                        else if(hard_lvl == 2){ 
                                            difficulty = "\u001b[36mğ ğ´ ğ» ğ´ ğ² ğ  ğ³ ğ¸ ğµ ğµ ğ¸ ğ² ğ ğ» ğ ğ  â¬ â¬ â­ \u001b[0m\n";
                                        }
                                        else if(hard_lvl == 3){ 
                                            difficulty = "\u001b[36mğ ğ´ ğ» ğ´ ğ² ğ  ğ³ ğ¸ ğµ ğµ ğ¸ ğ² ğ ğ» ğ ğ  â¬ â¬ â¬ \u001b[0m\n";
                                        }
                                        line_num = 2;
					                    printMenu(start, speed, difficulty, settings, exit);
                                }
                                else{   
                                        if(gameSpeed == 500){
                                            speed = "\u001b[36mğ ğ¿ ğ´ ğ´ ğ³  â¬ â­ â­ â­ \u001b[0m\n";
                                        }
                                        else if(gameSpeed == 350){ 
                                            speed = "\u001b[36mğ ğ¿ ğ´ ğ´ ğ³  â¬ â¬ â­ â­ \u001b[0m\n";
                                        }
                                        else if(gameSpeed == 200){ 
                                            speed = "\u001b[36mğ ğ¿ ğ´ ğ´ ğ³  â¬ â¬ â¬ â­ \u001b[0m\n";
                                        }
                                        else if(gameSpeed == 100){ 
                                            speed = "\u001b[36mğ ğ¿ ğ´ ğ´ ğ³  â¬ â¬ â¬ â¬ \u001b[0m\n";
                                        }
                                        start = "\033[32m    ğ ğ ğ° ğ ğ \u001b[0m\n"; 
                                        line_num = 1; 
					                    printMenu(start, speed, difficulty, settings, exit);
                                }
			            break;
                        case keyDown:
                                if(line_num == 1){
                                        if(gameSpeed == 500){
                                            speed = "\033[32m    ğ ğ¿ ğ´ ğ´ ğ³  â¬ â­ â­ â­ \u001b[0m\n";
                                        }
                                        else if(gameSpeed == 350){ 
                                            speed = "\033[32m    ğ ğ¿ ğ´ ğ´ ğ³  â¬ â¬ â­ â­ \u001b[0m\n";
                                        }
                                        else if(gameSpeed == 200){ 
                                            speed = "\033[32m    ğ ğ¿ ğ´ ğ´ ğ³  â¬ â¬ â¬ â­ \u001b[0m\n";
                                        }
                                        else if(gameSpeed == 100){ 
                                            speed = "\033[32m    ğ ğ¿ ğ´ ğ´ ğ³  â¬ â¬ â¬ â¬ \u001b[0m\n";
                                        }
                                        start = "\u001b[36mğ ğ ğ° ğ ğ \u001b[0m\n";
                                        line_num = 2;
					                    printMenu(start, speed, difficulty, settings, exit);
                                }
                                else if(line_num == 2){ 
                                        if(hard_lvl == 1){
                                            difficulty = "\033[32m    ğ ğ´ ğ» ğ´ ğ² ğ  ğ³ ğ¸ ğµ ğµ ğ¸ ğ² ğ ğ» ğ ğ  â¬ â­ â­ \u001b[0m\n";
                                        }
                                        else if(hard_lvl == 2){ 
                                            difficulty = "\033[32m    ğ ğ´ ğ» ğ´ ğ² ğ  ğ³ ğ¸ ğµ ğµ ğ¸ ğ² ğ ğ» ğ ğ  â¬ â¬ â­ \u001b[0m\n";
                                        }
                                        else if(hard_lvl == 3){ 
                                            difficulty = "\033[32m    ğ ğ´ ğ» ğ´ ğ² ğ  ğ³ ğ¸ ğµ ğµ ğ¸ ğ² ğ ğ» ğ ğ  â¬ â¬ â¬ \u001b[0m\n";
                                        }
                                        if(gameSpeed == 500){
                                            speed = "\u001b[36mğ ğ¿ ğ´ ğ´ ğ³  â¬ â­ â­ â­ \u001b[0m\n";
                                        }
                                        else if(gameSpeed == 350){ 
                                            speed = "\u001b[36mğ ğ¿ ğ´ ğ´ ğ³  â¬ â¬ â­ â­ \u001b[0m\n";
                                        }
                                        else if(gameSpeed == 200){ 
                                            speed = "\u001b[36mğ ğ¿ ğ´ ğ´ ğ³  â¬ â¬ â¬ â­ \u001b[0m\n";
                                        }
                                        else if(gameSpeed == 100){ 
                                            speed = "\u001b[36mğ ğ¿ ğ´ ğ´ ğ³  â¬ â¬ â¬ â¬ \u001b[0m\n";
                                        }
                                        line_num = 3;
					                    printMenu(start, speed, difficulty, settings, exit);
                                }
                                else if(line_num == 3){
                                        settings = "\033[32m    ğ ğ´ ğ ğ ğ¸ ğ½ ğ¶ ğ \u001b[0m\n";
                                        if(hard_lvl == 1){
                                            difficulty = "\u001b[36mğ ğ´ ğ» ğ´ ğ² ğ  ğ³ ğ¸ ğµ ğµ ğ¸ ğ² ğ ğ» ğ ğ  â¬ â­ â­ \u001b[0m\n";
                                        }
                                        else if(hard_lvl == 2){ 
                                            difficulty = "\u001b[36mğ ğ´ ğ» ğ´ ğ² ğ  ğ³ ğ¸ ğµ ğµ ğ¸ ğ² ğ ğ» ğ ğ  â¬ â¬ â­ \u001b[0m\n";
                                        }
                                        else if(hard_lvl == 3){ 
                                            difficulty = "\u001b[36mğ ğ´ ğ» ğ´ ğ² ğ  ğ³ ğ¸ ğµ ğµ ğ¸ ğ² ğ ğ» ğ ğ  â¬ â¬ â¬ \u001b[0m\n";
                                        }
                                        line_num = 4;
					                    printMenu(start, speed, difficulty, settings, exit);
                                }
                                else{
                                        exit = "\033[32m    ğ´ ğ ğ¸ ğ \u001b[0m\n";
                                        settings = "\u001b[36mğ ğ´ ğ ğ ğ¸ ğ½ ğ¶ ğ \u001b[0m\n";
                                        line_num = 5;
					                    printMenu(start, speed, difficulty, settings, exit);
                                }
                        break;
                        case keyEnter:
                                if(line_num == 1){
                                        system("clear");
                                        randomBlock(matrix1, hard_lvl);
                                        print_m(matrix1);
                                        game = false;
                                }
				                else if(line_num == 4){
                                        system("clear");
                                        game_name();
                                        std::string_view backSpace_5 = "\t\t\t\t\t";
                                        std::cout << backSpace_5 << B_GREEN << "ğğğğ ğªğ ğ¦ ğ¤ğ¥ğğ£ğ¥, ğªğ ğ¦ ğ¨ğğğ ğğğ§ğğ£ ğ¤ğ¥ğ ğ¡ ğ¡ğğğªğğğ.\n\n" << 
backSpace_5 << "ğğ¦ğ¤ğ¥ ğ ğğ ğ ğğğğğ¥ğğ§ğ: ğ½ğğğ ğ¥ğğ ğğ ğğ£ğ.\n\n" << backSpace_5 
<< "ğğğ£ğª ğğğ¤ğª ğğğ ğğ¡ğğğª ğ ğğğğğğğğ¤ ğ¨ğğ¥ğ ğğ¦ğğğ£ğğğ¤ ğ ğ ğ¦ğğğ¢ğ¦ğ ğğğ§ğğğ¤.\n\n" << backSpace_5 
<< "âğğğª ğ¨ğğ¥ğ ğ¥ğğ ğğ ğğğ ğ¨ğğğ ğğğªğ¤, ğğ§ğ ğğ ğ ğğ¤ğ¥ğğğğğ¤, ğğ ğ§ğğ£ ğğğ ğ ğ ğ¥ğğ ğğ ğğ£ğ ğ¥ğ  ğ¨ ğğ.\n\n" << backSpace_5  <<  ">(ğ³ğªğ¨ğ©ğµ)\t\t" << "^(ğ¶ğ±)\t\t" << "<(ğ­ğ¦ğ§ğµ)\t\t" << "ğ·(ğ¥ğ°ğ¸ğ¯)" << RESET << std::endl;
                                        line_num = 100;
                                }
                                else if(line_num == 5){
                                        game = false;
                                        system("clear");
					                    //std::exit(0);
					                    return false;
                                }
                        break;
                        case keyRight:
                                if(line_num == 3){
                                        switch (hard_lvl){
                                            case 1:
                                                hard_lvl = 2;
                                                difficulty = "\033[32m    ğ ğ´ ğ» ğ´ ğ² ğ  ğ³ ğ¸ ğµ ğµ ğ¸ ğ² ğ ğ» ğ ğ  â¬ â¬ â­  \u001b[0m\n";
					                            printMenu(start, speed, difficulty, settings, exit);
                                            break;
                                            case 2:
                                                hard_lvl = 3;
                                                difficulty = "\033[32m    ğ ğ´ ğ» ğ´ ğ² ğ  ğ³ ğ¸ ğµ ğµ ğ¸ ğ² ğ ğ» ğ ğ  â¬ â¬ â¬  \u001b[0m\n";
					                            printMenu(start, speed, difficulty, settings, exit);
                                            break;
                                        } 
                                }
                                else if(line_num == 2){
                                        switch (gameSpeed){
                                            case 500:
                                                gameSpeed = 350;
                                                speed = "\033[32m    ğ ğ¿ ğ´ ğ´ ğ³  â¬ â¬ â­ â­ \u001b[0m\n";
					                            printMenu(start, speed, difficulty, settings, exit);
                                            break;
                                            case 350:
                                                gameSpeed = 200;
                                                speed = "\033[32m    ğ ğ¿ ğ´ ğ´ ğ³  â¬ â¬ â¬ â­ \u001b[0m\n";
					                            printMenu(start, speed, difficulty, settings, exit);
                                            break;
                                            case 200:
                                                gameSpeed = 100;
                                                speed = "\033[32m    ğ ğ¿ ğ´ ğ´ ğ³  â¬ â¬ â¬ â¬ \u001b[0m\n";
					                            printMenu(start, speed, difficulty, settings, exit);
                                            break;
                                        }
                                }
                        break;
                        case keyLeft:
                                if(line_num == 3){
                                        switch (hard_lvl){
                                            case 3:
                                                hard_lvl = 2;
                                                difficulty = "\033[32m    ğ ğ´ ğ» ğ´ ğ² ğ  ğ³ ğ¸ ğµ ğµ ğ¸ ğ² ğ ğ» ğ ğ  â¬ â¬ â­  \u001b[0m\n";
					                            printMenu(start, speed, difficulty, settings, exit);
                                            break;
                                            case 2:
                                                hard_lvl = 1;
                                                difficulty = "\033[32m    ğ ğ´ ğ» ğ´ ğ² ğ  ğ³ ğ¸ ğµ ğµ ğ¸ ğ² ğ ğ» ğ ğ  â¬ â­ â­  \u001b[0m\n";
					                            printMenu(start, speed, difficulty, settings, exit);
                                            break;
                                        } 
                                }
                                else if(line_num == 2){
                                        switch (gameSpeed){
                                            case 100:
                                                gameSpeed = 200;
                                                speed = "\033[32m    ğ ğ¿ ğ´ ğ´ ğ³  â¬ â¬ â¬ â­ \u001b[0m\n"; 
					                            printMenu(start, speed, difficulty, settings, exit);
                                            break;
                                            case 200:
                                                gameSpeed = 350;
                                                speed = "\033[32m    ğ ğ¿ ğ´ ğ´ ğ³  â¬ â¬ â­ â­ \u001b[0m\n"; 
					                            printMenu(start, speed, difficulty, settings, exit);
                                            break;
                                            case 350:
                                                gameSpeed = 500;
                                                speed = "\033[32m    ğ ğ¿ ğ´ ğ´ ğ³  â¬ â­ â­ â­ \u001b[0m\n";
					                            printMenu(start, speed, difficulty, settings, exit);
                                            break;
                                        }
                                }
                        break;
                        case keyEsq:
                                system("clear");
                                game_name();
                                if(line_num == 100){
                                    line_num = 4;
                                }
					            printMenu(start, speed, difficulty, settings, exit);
                        break;
                }
        }
        normal();
	return true;

}
