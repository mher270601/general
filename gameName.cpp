#include <iostream>
#include "source.hpp"

void game_name(){
    //std::cout << "\n\n\n\n\n\n\n\n\n\n" << std::endl;
	//std::string_view B_RED = "\u001b[31;1m";
	//std::string_view RESET = "\u001b[0m";
   std::cout << B_RED << "\n\n\n        CCCCCCCCCCCCC                 lllllll                                           FFFFFFFFFFFFFFFFFFFFFF  iiii  lllllll lllllll  " << std::endl;
   std::cout << "     CCC::::::::::::C                 l:::::l                                           F::::::::::::::::::::F i::::i l:::::l l:::::l  " << std::endl;
   std::cout << "   CC:::::::::::::::C                 l:::::l                                           F::::::::::::::::::::F  iiii  l:::::l l:::::l  " << std::endl;
   std::cout << "  C:::::CCCCCCCC::::C                 l:::::l                                           FF::::::FFFFFFFFF::::F        l:::::l l:::::l  " << std::endl;
   std::cout << " C:::::C       CCCCCC   ooooooooooo    l::::l    ooooooooooo   rrrrr   rrrrrrrrr          F:::::F       FFFFFFiiiiiii  l::::l  l::::l  " << std::endl;
   std::cout << "C:::::C               oo:::::::::::oo  l::::l  oo:::::::::::oo r::::rrr:::::::::r         F:::::F             i:::::i  l::::l  l::::l  " << std::endl;
   std::cout << "C:::::C              o:::::::::::::::o l::::l o:::::::::::::::or:::::::::::::::::r        F::::::FFFFFFFFFF    i::::i  l::::l  l::::l  " << std::endl;
   std::cout << "C:::::C              o:::::ooooo:::::o l::::l o:::::ooooo:::::orr::::::rrrrr::::::r       F:::::::::::::::F    i::::i  l::::l  l::::l  " << std::endl;
   std::cout << "C:::::C              o::::o     o::::o l::::l o::::o     o::::o r:::::r     r:::::r       F:::::::::::::::F    i::::i  l::::l  l::::l  " << std::endl;
   std::cout << "C:::::C              o::::o     o::::o l::::l o::::o     o::::o r:::::r     rrrrrrr       F::::::FFFFFFFFFF    i::::i  l::::l  l::::l  " << std::endl;
   std::cout << "C:::::C              o::::o     o::::o l::::l o::::o     o::::o r:::::r                   F:::::F              i::::i  l::::l  l::::l  " << std::endl;
   std::cout << " C:::::C       CCCCCCo::::o     o::::o l::::l o::::o     o::::o r:::::r                   F:::::F              i::::i  l::::l  l::::l  " << std::endl;
   std::cout << "  C:::::CCCCCCCC::::Co:::::ooooo:::::ol::::::lo:::::ooooo:::::o r:::::r                 FF:::::::FF           i::::::il::::::ll::::::l " << std::endl;
   std::cout << "   CC:::::::::::::::Co:::::::::::::::ol::::::lo:::::::::::::::o r:::::r                 F::::::::FF           i::::::il::::::ll::::::l " << std::endl;
   std::cout << "     CCC::::::::::::C oo:::::::::::oo l::::::l oo:::::::::::oo  r:::::r                 F::::::::FF           i::::::il::::::ll::::::l " << std::endl;
   std::cout << "        CCCCCCCCCCCCC   ooooooooooo   llllllll   ooooooooooo    rrrrrrr                 FFFFFFFFFFF           iiiiiiiillllllllllllllll \n\n\n" << RESET << std::endl;
}

void gameOver(){
    std::cout << B_RED;
    std::cout << "\t_________                                 _______\n";                       
    std::cout << "\t__  ____/______ ________ ___ _____        __  __ \\___   _______ ________\n";
    std::cout << "\t_  / __  _  __ `/__  __ `__ \\_  _ \\       _  / / /__ | / /_  _ \\__  ___/\n";
    std::cout << "\t/ /_/ /  / /_/ / _  / / / / //  __/       / /_/ / __ |/ / /  __/_  /\n";    
    std::cout << "\t\\____/   \\__,_/  /_/ /_/ /_/ \\___/        \\____/  _____/  \\___/ /_/";
    std::cout << RESET << std::endl;
}
