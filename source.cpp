#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <thread>

#include "source.hpp"
#include "callSides.hpp"
#include "input.hpp"

void print_m(char [][matrixSize]);
void blockMovementDown(char [][matrixSize], size_t, size_t);
void blockMovementUp(char [][matrixSize], size_t, size_t);

int start_X = matrixSize-1, start_Y = matrixSize/2;

int hard_lvl = 1;

//void blockMovementDown(char matrix1[][matrixSize], size_t blockX, size_t blockY){
//    for(int i = 0; i < matrixSize-2; ++i){
//        matrix1[i][blockY] = '-';
//        matrix1[i][blockY-1] = '-';
//        matrix1[i+2][blockY] = '*';
//        matrix1[i+2][blockY-1] = '*';
//        system("clear");
//        print_m(matrix1);
//        std::this_thread::sleep_for(std::chrono::milliseconds(350));
//    }
//    blockMovementUp(matrix1, blockX, blockY);
//}
void blockMovementUp(char matrix1[][matrixSize], size_t blockX, size_t blockY){
    bool game = true;
    while(game){
        for(size_t i = matrixSize-1; i >= 2; --i){
            matrix1[i][blockY] = '-';
            matrix1[i][blockY-1] = '-';
            matrix1[i-2][blockY] = '*';
            matrix1[i-2][blockY-1] = '*';
            system("clear");
            print_m(matrix1);
            std::this_thread::sleep_for(std::chrono::milliseconds(350));
        }
        for(size_t i = 0; i < matrixSize-2; ++i){
            matrix1[i][blockY] = '-';
            matrix1[i][blockY-1] = '-';
            matrix1[i+2][blockY] = '*';
            matrix1[i+2][blockY-1] = '*';
            system("clear");
            print_m(matrix1);
            std::this_thread::sleep_for(std::chrono::milliseconds(350));
        }
    }
    //blockMovementDown(matrix1, blockX, blockY);
}
void randomBlock(char matrix1[][matrixSize], int hard_lvl)
{
    static int hard_lvl2 = hard_lvl;
    size_t blockX, blockY;
    const size_t easy = 1, normal = 2, hard = 3;
    switch (hard_lvl2){
        case easy:
            do{
                blockX = rand() % (matrixSize-1) + 1;
                blockY = rand() % (matrixSize-1) + 1;
            }while((blockX == start_X && blockY == start_Y) || (blockX == start_X && blockY == start_Y + 1));
            
            matrix1[blockX][blockY] = '*';
            matrix1[blockX-1][blockY] = '*';
            matrix1[blockX-1][blockY-1] = '*';
            matrix1[blockX][blockY-1] = '*';
        break;
        case normal: case hard:
            
            for(size_t i = 0; i < 3; ++i){
                do{
                    blockX = rand() % (matrixSize-1) + 1;
                    blockY = rand() % (matrixSize-1) + 1;
                }while((blockX == start_X && blockY == start_Y) || (blockX == start_X && blockY == start_Y + 1));
                matrix1[blockX][blockY] = '*';
                matrix1[blockX-1][blockY] = '*';
                matrix1[blockX-1][blockY-1] = '*';
                matrix1[blockX][blockY-1] = '*';
            } 
            
            if(hard_lvl2 == hard){
                //std::thread th(blockMovementUp, matrix1, blockX, blockY);
                //th.join();
                blockMovementUp(matrix1, blockX, blockY); 
            } 
        break;
    }
     
	//cbreak();
    //bool game = true;
	//while(game){
	//	const int key_prs = keypress();
	//	switch (key_prs) {
	//		case keyUp:
	//			go_up(matrix1, matrixSize-1, 6);
	//		break;
	//		case keyDown:
	//			go_down(matrix1, matrixSize-1, 6);
	//		break;
	//		case keyRight:
	//			go_right(matrix1, matrixSize-1, 6);
	//		break;
	//		case keyLeft: 
	//			go_left(matrix1, matrixSize-1, 6);
	//		break;
	//		case quit:
	//			game = false;
	//		break;	
	//	}
	//}
	//normal();
}

void matrixInit(char matrix1[][matrixSize])
{
	for (size_t i = 0; i < matrixSize; ++i)
    {
        for (size_t j = 0; j < matrixSize; ++j)
        {
            matrix1[i][j] = '-';
        }
    }
    start_X = matrixSize-1;
    start_Y = matrixSize/2;
    //randomBlock(matrix1, hard_lvl);
    matrix1[start_X][start_Y] = '#';
}

void print_m(char matrix1[][matrixSize]){
        std::string_view tab6 = "\t\t\t\t\t\t", matrixWall = "\u001b[44;1m▒▒\u001b[0m";
        std::string matrixFullWall = "\u001b[44;1m";
        for(short i = 0; i < matrixSize+2; ++i){
            matrixFullWall += "▒▒";
        }
        matrixFullWall += "\u001b[0m\n";
        const char elemCompleted = '#', footStep = '$', elemBlock = '*', three = 3, two = 2, emp = '-';
        std::cout << "\n\n\n\t==============================================================================================================\n\n";
        std::cout << tab6 << matrixFullWall;
        for(int i = 0; i < matrixSize; ++i){
                std::cout << tab6 << matrixWall;
                for(int j = 0; j < matrixSize; ++j){
                        switch(matrix1[i][j])
                        {
                            case elemCompleted:
                                std::cout << BACK_GREEN << GREEN << matrix1[i][j] << matrix1[i][j] << RESET;
                                //std::cout << BACK_GREEN << GREEN << matrix1[i][j] << RESET;
                            break;
                            case footStep: 
                                std::cout << BACK_YELLOW << YELLOW << matrix1[i][j] << matrix1[i][j] << RESET;
                                //std::cout << BACK_YELLOW << YELLOW << matrix1[i][j] << RESET;
                            break;
                            case elemBlock:
                                std::cout << BACK_RED << B_RED << matrix1[i][j] << matrix1[i][j] << RESET;
                                //std::cout << BACK_RED << B_RED << matrix1[i][j] << RESET;
                            break;
                            case 'Y': case 'O': case 'U': case ' ': case 'W': case 'N':
                                std::cout << RESET << BACK_B_GREEN << BLUE  << matrix1[i][j] << matrix1[i][j] << RESET;
                            break;
                            default:
                                //std::cout << BACK_GREEN << B_GREEN  << matrix1[i][j] << matrix1[i][j] << RESET;
                                std::cout << BACK_B_WHITE << WHITE  << matrix1[i][j] << matrix1[i][j] << RESET;
                                //std::cout << BACK_B_WHITE << WHITE  << matrix1[i][j] << RESET;
                            break; 
                        }
                }
                std::cout << matrixWall << std::endl;
        }
        std::cout << tab6 << matrixFullWall;
        std::cout << "\n\t==============================================================================================================\n";
}
