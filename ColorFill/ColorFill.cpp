/*        xmin1<>xmin2
 *        ____________
 *       |   |    |   |
 *       |   |    |   |
 * ymin1 |__        __| ymax1
 *  ^ v  |            |  ^ v
 * ymin2 |__        __| ymax2
 *       |   |    |   |
 *       |___|____|___|
 *        
 *        xmax1<>xmax2
*/

//#include <mutex>
#include <cstdlib> // abort()
#include <iostream>
#include <stdlib.h> // system()
#include <string> // std::string(_view)
#include <thread> // sleep()

#include "fillMatrix.hpp"
#include "input.hpp" // cbreak(), normal(), keypress()
#include "progressMenuBar.hpp" // Progress bar
#include "sidesResults.hpp" // updatePreviousValue(), rightSides()
#include "source.hpp" // matrixInit(), print_m(), randomBlock(), blockMovement
#include "gameName.hpp" // game_name()
#include "callSides.hpp" // updateMatirx(), check_completed(), checkMatrixCont(), suicide(), go_right()

constexpr size_t intervalDuration = 350;

int main()
{
    srand(time(NULL)); 
	
	// Matrix declaration and initialization 
	char matrix[matrixSize][matrixSize];
    
	matrixInit(matrix);
    
    progressBar();
	
    game_name(); 
	
    extern int start_X, start_Y;
	if(!menuBar(matrix))
	{
		normal();
		return 0;
	}
	// Check the keyboard
	bool game = true;
	
	cbreak();
	
	while(game){
		
		const int key_prs = keypress();
		switch (key_prs) {
			case keyUp:
                {
                //matrixInit(matrix);
                //std::thread th1(go_up, matrix, start_X, start_Y);
                //th1.join();
                //std::cout << "Go UP" << std::endl;
                //std::this_thread::sleep_for(std::chrono::milliseconds(2000));
				go_up(matrix, start_X, start_Y);
                		game = false;
                }
			break;
			case keyRight:
                {
                //matrixInit(matrix);
                //std::thread th2(go_right, matrix, start_X, start_Y);
                //th2.join();
                //std::cout << "Go Right" << std::endl;
                //std::this_thread::sleep_for(std::chrono::milliseconds(2000));
				go_right(matrix, start_X, start_Y);
                game = false;
                }
			break;
			case keyLeft: 
                {
                //matrixInit(matrix);
                //std::thread th3(go_left, matrix, start_X, start_Y);
                //th3.join();
                //std::cout << "Go Left" << std::endl;
                //std::this_thread::sleep_for(std::chrono::milliseconds(2000));
				go_left(matrix, start_X, start_Y);
                game = false;
                }
			break;
			case quit:
				game = false;
			break;
		}
	}
	normal();

    //if(th1.joinable()){
    //   th1.join(); 
    //}
    //else if(th2.joinable()){
    //   th2.join(); 
    //}
    //else if(th3.joinable()){
    //   th3.join(); 
    //}
    
    return 0;
}
	
