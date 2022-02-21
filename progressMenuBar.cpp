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
        std::cout << newLine_11 << CYAN << "\t\t\t\t\t\t\tℙ𝕣𝕠𝕔𝕖𝕤𝕤𝕚𝕟𝕘 " << totalProcesesCount << " 𝕗𝕦𝕟𝕔𝕥𝕚𝕠𝕟𝕤...\n\n\n\n" << RESET << std::endl;

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
                        std::cout << YELLOW << percent << "%" << RESET << CYAN << " [𝔽𝕦𝕟𝕔𝕥𝕚𝕠𝕟𝕤 " << RESET << YELLOW << i + 1 << RESET << CYAN << " 𝕠𝕗 " << RESET << B_GREEN << totalProcesesCount << RESET << CYAN << "]" << RESET;
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
    std::string start = "\033[32m    🆂 🆃 🅰 🆁 🆃 \u001b[0m\n";
    std::string speed = "\u001b[36m🆂 🅿 🅴 🅴 🅳  ▬ ▭ ▭ ▭ \u001b[0m\n";
    std::string difficulty = "\u001b[36m🆂 🅴 🅻 🅴 🅲 🆃  🅳 🅸 🅵 🅵 🅸 🅲 🆄 🅻 🆃 🆈  ▬ ▭ ▭ \u001b[0m\n";
    std::string settings = "\u001b[36m🆂 🅴 🆃 🆃 🅸 🅽 🅶 🆂 \u001b[0m\n";
    std::string exit = "\u001b[36m🅴 🆇 🅸 🆃 \u001b[0m\n";
	printMenu(start, speed, difficulty, settings, exit);	
	cbreak();

    bool game = true;
        while(game){
                const int key_prs = keypress();
                switch (key_prs) {
                        case keyUp:
                                if(line_num == 5){
                                        settings = "\033[32m    🆂 🅴 🆃 🆃 🅸 🅽 🅶 🆂 \u001b[0m\n";
                                        exit = "\u001b[36m🅴 🆇 🅸 🆃 \u001b[0m\n";
                                        line_num = 4;
					                    printMenu(start, speed, difficulty, settings, exit);
                                }
                                else if(line_num == 4){
                                        if(hard_lvl == 1){
                                            difficulty = "\033[32m    🆂 🅴 🅻 🅴 🅲 🆃  🅳 🅸 🅵 🅵 🅸 🅲 🆄 🅻 🆃 🆈  ▬ ▭ ▭ \u001b[0m\n";
                                        }
                                        else if(hard_lvl == 2){ 
                                            difficulty = "\033[32m    🆂 🅴 🅻 🅴 🅲 🆃  🅳 🅸 🅵 🅵 🅸 🅲 🆄 🅻 🆃 🆈  ▬ ▬ ▭ \u001b[0m\n";
                                        }
                                        else if(hard_lvl == 3){ 
                                            difficulty = "\033[32m    🆂 🅴 🅻 🅴 🅲 🆃  🅳 🅸 🅵 🅵 🅸 🅲 🆄 🅻 🆃 🆈  ▬ ▬ ▬ \u001b[0m\n";
                                        }
                                        settings = "\u001b[36m🆂 🅴 🆃 🆃 🅸 🅽 🅶 🆂 \u001b[0m\n";
                                        line_num = 3;
					                    printMenu(start, speed, difficulty, settings, exit);
                                }
                                else if(line_num == 3){
                                        if(gameSpeed == 500){
                                            speed = "\033[32m    🆂 🅿 🅴 🅴 🅳  ▬ ▭ ▭ ▭ \u001b[0m\n";
                                        }
                                        else if(gameSpeed == 350){ 
                                            speed = "\033[32m    🆂 🅿 🅴 🅴 🅳  ▬ ▬ ▭ ▭ \u001b[0m\n";
                                        }
                                        else if(gameSpeed == 200){ 
                                            speed = "\033[32m    🆂 🅿 🅴 🅴 🅳  ▬ ▬ ▬ ▭ \u001b[0m\n";
                                        }
                                        else if(gameSpeed == 100){ 
                                            speed = "\033[32m    🆂 🅿 🅴 🅴 🅳  ▬ ▬ ▬ ▬ \u001b[0m\n";
                                        }
                                        if(hard_lvl == 1){
                                            difficulty = "\u001b[36m🆂 🅴 🅻 🅴 🅲 🆃  🅳 🅸 🅵 🅵 🅸 🅲 🆄 🅻 🆃 🆈  ▬ ▭ ▭ \u001b[0m\n";
                                        }
                                        else if(hard_lvl == 2){ 
                                            difficulty = "\u001b[36m🆂 🅴 🅻 🅴 🅲 🆃  🅳 🅸 🅵 🅵 🅸 🅲 🆄 🅻 🆃 🆈  ▬ ▬ ▭ \u001b[0m\n";
                                        }
                                        else if(hard_lvl == 3){ 
                                            difficulty = "\u001b[36m🆂 🅴 🅻 🅴 🅲 🆃  🅳 🅸 🅵 🅵 🅸 🅲 🆄 🅻 🆃 🆈  ▬ ▬ ▬ \u001b[0m\n";
                                        }
                                        line_num = 2;
					                    printMenu(start, speed, difficulty, settings, exit);
                                }
                                else{   
                                        if(gameSpeed == 500){
                                            speed = "\u001b[36m🆂 🅿 🅴 🅴 🅳  ▬ ▭ ▭ ▭ \u001b[0m\n";
                                        }
                                        else if(gameSpeed == 350){ 
                                            speed = "\u001b[36m🆂 🅿 🅴 🅴 🅳  ▬ ▬ ▭ ▭ \u001b[0m\n";
                                        }
                                        else if(gameSpeed == 200){ 
                                            speed = "\u001b[36m🆂 🅿 🅴 🅴 🅳  ▬ ▬ ▬ ▭ \u001b[0m\n";
                                        }
                                        else if(gameSpeed == 100){ 
                                            speed = "\u001b[36m🆂 🅿 🅴 🅴 🅳  ▬ ▬ ▬ ▬ \u001b[0m\n";
                                        }
                                        start = "\033[32m    🆂 🆃 🅰 🆁 🆃 \u001b[0m\n"; 
                                        line_num = 1; 
					                    printMenu(start, speed, difficulty, settings, exit);
                                }
			            break;
                        case keyDown:
                                if(line_num == 1){
                                        if(gameSpeed == 500){
                                            speed = "\033[32m    🆂 🅿 🅴 🅴 🅳  ▬ ▭ ▭ ▭ \u001b[0m\n";
                                        }
                                        else if(gameSpeed == 350){ 
                                            speed = "\033[32m    🆂 🅿 🅴 🅴 🅳  ▬ ▬ ▭ ▭ \u001b[0m\n";
                                        }
                                        else if(gameSpeed == 200){ 
                                            speed = "\033[32m    🆂 🅿 🅴 🅴 🅳  ▬ ▬ ▬ ▭ \u001b[0m\n";
                                        }
                                        else if(gameSpeed == 100){ 
                                            speed = "\033[32m    🆂 🅿 🅴 🅴 🅳  ▬ ▬ ▬ ▬ \u001b[0m\n";
                                        }
                                        start = "\u001b[36m🆂 🆃 🅰 🆁 🆃 \u001b[0m\n";
                                        line_num = 2;
					                    printMenu(start, speed, difficulty, settings, exit);
                                }
                                else if(line_num == 2){ 
                                        if(hard_lvl == 1){
                                            difficulty = "\033[32m    🆂 🅴 🅻 🅴 🅲 🆃  🅳 🅸 🅵 🅵 🅸 🅲 🆄 🅻 🆃 🆈  ▬ ▭ ▭ \u001b[0m\n";
                                        }
                                        else if(hard_lvl == 2){ 
                                            difficulty = "\033[32m    🆂 🅴 🅻 🅴 🅲 🆃  🅳 🅸 🅵 🅵 🅸 🅲 🆄 🅻 🆃 🆈  ▬ ▬ ▭ \u001b[0m\n";
                                        }
                                        else if(hard_lvl == 3){ 
                                            difficulty = "\033[32m    🆂 🅴 🅻 🅴 🅲 🆃  🅳 🅸 🅵 🅵 🅸 🅲 🆄 🅻 🆃 🆈  ▬ ▬ ▬ \u001b[0m\n";
                                        }
                                        if(gameSpeed == 500){
                                            speed = "\u001b[36m🆂 🅿 🅴 🅴 🅳  ▬ ▭ ▭ ▭ \u001b[0m\n";
                                        }
                                        else if(gameSpeed == 350){ 
                                            speed = "\u001b[36m🆂 🅿 🅴 🅴 🅳  ▬ ▬ ▭ ▭ \u001b[0m\n";
                                        }
                                        else if(gameSpeed == 200){ 
                                            speed = "\u001b[36m🆂 🅿 🅴 🅴 🅳  ▬ ▬ ▬ ▭ \u001b[0m\n";
                                        }
                                        else if(gameSpeed == 100){ 
                                            speed = "\u001b[36m🆂 🅿 🅴 🅴 🅳  ▬ ▬ ▬ ▬ \u001b[0m\n";
                                        }
                                        line_num = 3;
					                    printMenu(start, speed, difficulty, settings, exit);
                                }
                                else if(line_num == 3){
                                        settings = "\033[32m    🆂 🅴 🆃 🆃 🅸 🅽 🅶 🆂 \u001b[0m\n";
                                        if(hard_lvl == 1){
                                            difficulty = "\u001b[36m🆂 🅴 🅻 🅴 🅲 🆃  🅳 🅸 🅵 🅵 🅸 🅲 🆄 🅻 🆃 🆈  ▬ ▭ ▭ \u001b[0m\n";
                                        }
                                        else if(hard_lvl == 2){ 
                                            difficulty = "\u001b[36m🆂 🅴 🅻 🅴 🅲 🆃  🅳 🅸 🅵 🅵 🅸 🅲 🆄 🅻 🆃 🆈  ▬ ▬ ▭ \u001b[0m\n";
                                        }
                                        else if(hard_lvl == 3){ 
                                            difficulty = "\u001b[36m🆂 🅴 🅻 🅴 🅲 🆃  🅳 🅸 🅵 🅵 🅸 🅲 🆄 🅻 🆃 🆈  ▬ ▬ ▬ \u001b[0m\n";
                                        }
                                        line_num = 4;
					                    printMenu(start, speed, difficulty, settings, exit);
                                }
                                else{
                                        exit = "\033[32m    🅴 🆇 🅸 🆃 \u001b[0m\n";
                                        settings = "\u001b[36m🆂 🅴 🆃 🆃 🅸 🅽 🅶 🆂 \u001b[0m\n";
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
                                        std::cout << backSpace_5 << B_GREEN << "𝕆𝕟𝕔𝕖 𝕪𝕠𝕦 𝕤𝕥𝕒𝕣𝕥, 𝕪𝕠𝕦 𝕨𝕚𝕝𝕝 𝕟𝕖𝕧𝕖𝕣 𝕤𝕥𝕠𝕡 𝕡𝕝𝕒𝕪𝕚𝕟𝕘.\n\n" << 
backSpace_5 << "𝕁𝕦𝕤𝕥 𝕠𝕟𝕖 𝕠𝕓𝕛𝕖𝕔𝕥𝕚𝕧𝕖: 𝔽𝕚𝕝𝕝 𝕥𝕙𝕖 𝕓𝕠𝕒𝕣𝕕.\n\n" << backSpace_5 
<< "𝕍𝕖𝕣𝕪 𝕖𝕒𝕤𝕪 𝕘𝕒𝕞 𝕖𝕡𝕝𝕒𝕪 𝕞 𝕖𝕔𝕙𝕒𝕟𝕚𝕔𝕤 𝕨𝕚𝕥𝕙 𝕙𝕦𝕟𝕕𝕣𝕖𝕕𝕤 𝕠𝕗 𝕦𝕟𝕚𝕢𝕦𝕖 𝕝𝕖𝕧𝕖𝕝𝕤.\n\n" << backSpace_5 
<< "ℙ𝕝𝕒𝕪 𝕨𝕚𝕥𝕙 𝕥𝕙𝕖 𝕗𝕠𝕝𝕝𝕠𝕨𝕚𝕟𝕘 𝕜𝕖𝕪𝕤, 𝕒𝕧𝕠𝕚𝕕 𝕠𝕓𝕤𝕥𝕒𝕔𝕝𝕖𝕤, 𝕔𝕠𝕧𝕖𝕣 𝕒𝕝𝕝 𝕠𝕗 𝕥𝕙𝕖 𝕓𝕠𝕒𝕣𝕕 𝕥𝕠 𝕨 𝕚𝕟.\n\n" << backSpace_5  <<  ">(𝘳𝘪𝘨𝘩𝘵)\t\t" << "^(𝘶𝘱)\t\t" << "<(𝘭𝘦𝘧𝘵)\t\t" << "𝘷(𝘥𝘰𝘸𝘯)" << RESET << std::endl;
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
                                                difficulty = "\033[32m    🆂 🅴 🅻 🅴 🅲 🆃  🅳 🅸 🅵 🅵 🅸 🅲 🆄 🅻 🆃 🆈  ▬ ▬ ▭  \u001b[0m\n";
					                            printMenu(start, speed, difficulty, settings, exit);
                                            break;
                                            case 2:
                                                hard_lvl = 3;
                                                difficulty = "\033[32m    🆂 🅴 🅻 🅴 🅲 🆃  🅳 🅸 🅵 🅵 🅸 🅲 🆄 🅻 🆃 🆈  ▬ ▬ ▬  \u001b[0m\n";
					                            printMenu(start, speed, difficulty, settings, exit);
                                            break;
                                        } 
                                }
                                else if(line_num == 2){
                                        switch (gameSpeed){
                                            case 500:
                                                gameSpeed = 350;
                                                speed = "\033[32m    🆂 🅿 🅴 🅴 🅳  ▬ ▬ ▭ ▭ \u001b[0m\n";
					                            printMenu(start, speed, difficulty, settings, exit);
                                            break;
                                            case 350:
                                                gameSpeed = 200;
                                                speed = "\033[32m    🆂 🅿 🅴 🅴 🅳  ▬ ▬ ▬ ▭ \u001b[0m\n";
					                            printMenu(start, speed, difficulty, settings, exit);
                                            break;
                                            case 200:
                                                gameSpeed = 100;
                                                speed = "\033[32m    🆂 🅿 🅴 🅴 🅳  ▬ ▬ ▬ ▬ \u001b[0m\n";
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
                                                difficulty = "\033[32m    🆂 🅴 🅻 🅴 🅲 🆃  🅳 🅸 🅵 🅵 🅸 🅲 🆄 🅻 🆃 🆈  ▬ ▬ ▭  \u001b[0m\n";
					                            printMenu(start, speed, difficulty, settings, exit);
                                            break;
                                            case 2:
                                                hard_lvl = 1;
                                                difficulty = "\033[32m    🆂 🅴 🅻 🅴 🅲 🆃  🅳 🅸 🅵 🅵 🅸 🅲 🆄 🅻 🆃 🆈  ▬ ▭ ▭  \u001b[0m\n";
					                            printMenu(start, speed, difficulty, settings, exit);
                                            break;
                                        } 
                                }
                                else if(line_num == 2){
                                        switch (gameSpeed){
                                            case 100:
                                                gameSpeed = 200;
                                                speed = "\033[32m    🆂 🅿 🅴 🅴 🅳  ▬ ▬ ▬ ▭ \u001b[0m\n"; 
					                            printMenu(start, speed, difficulty, settings, exit);
                                            break;
                                            case 200:
                                                gameSpeed = 350;
                                                speed = "\033[32m    🆂 🅿 🅴 🅴 🅳  ▬ ▬ ▭ ▭ \u001b[0m\n"; 
					                            printMenu(start, speed, difficulty, settings, exit);
                                            break;
                                            case 350:
                                                gameSpeed = 500;
                                                speed = "\033[32m    🆂 🅿 🅴 🅴 🅳  ▬ ▭ ▭ ▭ \u001b[0m\n";
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
