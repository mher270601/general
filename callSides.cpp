#include <iostream>
#include <string>
#include <thread>
#include <utility>

#include "fillMatrix.hpp"
#include "gameName.hpp"
#include "input.hpp"
#include "source.hpp"
#include "sidesResults.hpp"
#include "progressMenuBar.hpp"

//void suicide(char [][matrixSize], int&, int&);
void go_right(char [][matrixSize], int&, int&);
void go_up(char [][matrixSize], int&, int&);
void go_left(char [][matrixSize], int&, int&);
void go_down(char [][matrixSize], int&, int&);

size_t gameSpeed = 500;

//bool checkMatrixFilled(char matrix1[][matrixSize]){
//    for(int i = 0; i < matrixSize; ++i){
//        for(int j = 0; j < matrixSize; ++j){
//            if(matrix1[i][j] == '$'){
//                return true;
//            }
//        }
//    }
//    return false;
//}
void updateMatrix(char matrix1[][matrixSize]){
    // Clear the console screen
    system("clear");
    // Print the matrix
    print_m(matrix1);
    // Keep pause from the next step
    std::this_thread::sleep_for(std::chrono::milliseconds(gameSpeed));
}
bool check_completed(char matrix1[][matrixSize]){
    for(int i = 0; i < matrixSize; ++i){
        for(int j = 0; j < matrixSize; ++j){
            if(matrix1[i][j] == '$'){
                return true;
            }
        }
    }
    return false;
}
bool checkMatrixCont(char matrix1[][matrixSize], int xy, int low, int high, std::string_view side)
{
    //bool checker = checkMatrixFilled(matrix1);
       // bool dynGame = false;
    if(side == "right" || side == "left")
    {    
        for(int i = low; i < high; ++i)
        {
            if(/*checker || */matrix1[xy][i] != '#'/* || matrix1[xy][i] == '$'*/)
            {
                return true;
            }
        }
    }
    else if(side == "up" || side == "down")
    {    
        for(int i = low; i < high; ++i)
        {
            if(/*checker || */matrix1[i][xy] != '#'/* || matrix1[i][xy] == '$'*/)
            {  
                return true;
            }
        }
    }
    return false;
}
void suicide(char matrix1[][matrixSize], int &x1, int &y1)
{
                system("clear");
                x1 = matrixSize-1; y1 = matrixSize/2;
                matrixInit(matrix1);
                randomBlock(matrix1, 1);
                print_m(matrix1);
                gameOver();
                //std::cout << "You lose the game." << std::endl;
                
	bool game = true;
	
	//cbreak();
	
	//if((1 == f && 2 == g) || (9 == t && 7 == m))

	while(game){		
		const int key_prs = keypress();
		switch (key_prs) {
			case keyUp:
				go_up(matrix1, x1, y1);
			break;
			case keyRight:
				go_right(matrix1, x1, y1);
			break;
			case keyLeft: 
				go_left(matrix1, x1, y1);
			break;
			case quit: case keyEsq:
				game = false;
			break;
		}
	}
	//normal();
}
void go_right(char matrix1[][matrixSize], int& x1, int& y1) {
	
    bool game = true, isBreaked = false;
    
	// check that the next element is in the matrix
    int nextIndex = y1 + 1;
    while (nextIndex < matrixSize && game == true)
    {
        bool Continuation = checkMatrixCont(matrix1, x1, nextIndex, matrixSize, "right"); 
        if(matrix1[x1][nextIndex] == '#' && !Continuation && check_completed(matrix1)){
            isBreaked = true;
            game = false; 
        }
        else if(matrix1[x1][nextIndex] == '$' || matrix1[x1][nextIndex] == '*')
        {
            suicide(matrix1, x1, y1);
            return;
        }
        if(!game)
        {
            break;
        }
	
        // equate the next element to 1
        matrix1[x1][nextIndex] == '-' ? matrix1[x1][++y1] = '$' : ++y1;
        ++nextIndex;
        //std::thread th1(updateMatrix, matrix1);
        //th1.join();
        updateMatrix(matrix1);
        // Clear the console screen
        //system("clear");
        // Print the matrix
	    //print_m(matrix1);
	    //std::this_thread::sleep_for(std::chrono::milliseconds(gameSpeed));
        // If another button clicked, leave from here and go to the appropriate function
		const int key_prs = keypress();
		switch (key_prs) {
			case keyUp:
				go_up(matrix1, x1, y1);
			break;
			case keyDown:
				go_down(matrix1, x1, y1);
			break;
			case keyLeft:
				go_left(matrix1, x1, y1);
			break;
			case quit:
				game = false;
			break;
		}
    }
    rightSides(matrix1, x1, y1, isBreaked);
}

void go_up(char matrix1[][matrixSize], int& x1, int& y1) {
    bool game = true, isBreaked = false;
    int previousIndex = x1 - 1;

    while (previousIndex >= 0 && game == true)
    {  
        bool Continuation = checkMatrixCont(matrix1, y1, previousIndex, 0, "up"); 
	    if(matrix1[previousIndex][y1] == '#' && !Continuation && check_completed(matrix1)){ 
            isBreaked = true;
            game = false; 
	    }
        else if(matrix1[previousIndex][y1] == '$' || matrix1[previousIndex][y1] == '*')
        {
            suicide(matrix1, x1, y1);
            return;
        }
        if(!game)
        {
            break;
        }
        matrix1[previousIndex][y1] == '-' ? matrix1[--x1][y1] = '$' : --x1;
        --previousIndex; 
        //std::thread th2(updateMatrix, matrix1);
        //th2.join();
        updateMatrix(matrix1); 
        //system("clear");
	    //print_m(matrix1);
	    //std::this_thread::sleep_for(std::chrono::milliseconds(gameSpeed));
		const int key_prs = keypress();
		switch (key_prs) {
			case keyRight:
				//std::this_thread::sleep_for(std::chrono::milliseconds(150));
				go_right(matrix1, x1, y1);
			break;
			case keyDown:
                //std::this_thread::sleep_for(std::chrono::milliseconds(150));
				go_down(matrix1, x1, y1);
			break;
			case keyLeft:
                //std::this_thread::sleep_for(std::chrono::milliseconds(150));
				go_left(matrix1, x1, y1);
			break;
			case quit:
				game = false;
			break;
		}
	
    }
    upSides(matrix1, x1, y1, isBreaked);
}

void go_left(char matrix1[][matrixSize], int& x1, int& y1) {
    bool game = true, isBreaked = false;
    int previousIndex = y1 - 1;
    while (previousIndex >= 0 && game == true)
    {
        bool Continuation = checkMatrixCont(matrix1, x1, 0, previousIndex, "left"); 
	    if(matrix1[x1][previousIndex] == '#' && !Continuation && check_completed(matrix1)){ 
            isBreaked = true;
            game = false; 
	    }
        else if(matrix1[x1][previousIndex] == '$' || matrix1[x1][previousIndex] == '*')
        {
            suicide(matrix1, x1, y1);
            return;
        }
        if(!game)
        {
            break;
        }
        matrix1[x1][previousIndex] == '-' ? matrix1[x1][--y1] = '$' : --y1;
        --previousIndex;
        //std::thread th3(updateMatrix, matrix1);
        //th3.join();
        updateMatrix(matrix1); 
        //system("clear");
	    //print_m(matrix1);
	    //std::this_thread::sleep_for(std::chrono::milliseconds(gameSpeed));
		const int key_prs = keypress();
		switch (key_prs) {
			case keyUp:
                //std::this_thread::sleep_for(std::chrono::milliseconds(150));
				go_up(matrix1, x1, y1);
			break;
			case keyDown:
                //std::this_thread::sleep_for(std::chrono::milliseconds(150));
				go_down(matrix1, x1, y1);
			break;
			case keyRight:
                //std::this_thread::sleep_for(std::chrono::milliseconds(150));
				go_right(matrix1, x1, y1);
			break;
			case quit:
				game = false;
			break;
		}

    }
    leftSides(matrix1, x1, y1, isBreaked);
}

void go_down(char matrix1[][matrixSize], int& x1, int& y1) {
    bool game = true, isBreaked = false;
    int nextIndex = x1 + 1;
    while (nextIndex < matrixSize && game == true)
    {   
        bool Continuation = checkMatrixCont(matrix1, y1, nextIndex, matrixSize, "down");
	    if(matrix1[nextIndex][y1] == '#' && !Continuation && check_completed(matrix1)){
            isBreaked = true;
            game = false; 
	    }
        else if(matrix1[nextIndex][y1] == '$' || matrix1[nextIndex][y1] == '*')
        {
            suicide(matrix1, x1, y1);
            return;
        }
        if(!game)
        {
            break;
        }
        matrix1[nextIndex][y1] == '-' ? matrix1[++x1][y1] = '$' : ++x1;
        ++nextIndex;
        //std::thread th4(updateMatrix, matrix1);
        //th4.join();
        updateMatrix(matrix1); 
        //system("clear");
	    //print_m(matrix1);
	    //std::this_thread::sleep_for(std::chrono::milliseconds(gameSpeed));
		const int key_prs = keypress();
		switch (key_prs) {
			case keyUp:
                //std::this_thread::sleep_for(std::chrono::milliseconds(150));
				go_up(matrix1, x1, y1);
			break;
			case keyRight:
                //std::this_thread::sleep_for(std::chrono::milliseconds(150));
				go_right(matrix1, x1, y1);
			break;
			case keyLeft:
                //std::this_thread::sleep_for(std::chrono::milliseconds(150));
				go_left(matrix1, x1, y1);
			break;
			case quit:
				game = false;
			break;
		}
	
    }
    downSides(matrix1, x1, y1, isBreaked);
}
