#include <iostream>
#include <thread>

#include "callSides.hpp"
#include "input.hpp"
#include "progressMenuBar.hpp"
#include "sidesResults.hpp"
#include "source.hpp"

short xmax1 = 6, xmax2 = -1, ymax1 = -1,  ymax2 = -1, xmin1 = -1, xmin2 = -1,  ymin1 = -1, ymin2 = -1;
//void charge(char [][matrixSize], int, int);
//bool singleSide = false; 

void checkBigSide(char matrix1[][matrixSize], size_t& zero, size_t& two){
    for(int i = 0; i < matrixSize; ++i){
        for(int j = 0; j < matrixSize; ++j){
            switch(matrix1[i][j]){
                case '-':
                    ++zero;
                break;
                case 2:
                    ++two;
                break;
            }
        }
    }
}

void autoFill(char matrix1[][matrixSize]){
    for(short i = 0; i < matrixSize; ++i){
        for(short j = 0; j < matrixSize; ++j){
            matrix1[i][j] = '#';
        }
    }
}
    
bool singleSide(char matrix1[][matrixSize]){
    for(short i = 0; i < matrixSize; i += matrixSize - 1){
        for(short j = 0; j < matrixSize; ++j){
            if(matrix1[i][j] != '#' || matrix1[j][i] != '#'){
                return true;
            }
        }
    }
    return false;
}

bool check_matrix(char matrix1[][matrixSize], size_t zero){
    static size_t allSize = matrixSize*matrixSize;
    allSize -= zero;
    //bool single_side = singleSide(matrix1); 
    if(!singleSide(matrix1)){
        autoFill(matrix1);
    }
    else if(allSize != 0){
        return false;
	    //for(short i = 0; i < matrixSize; ++i){
	    //	for(short j = 0; j < matrixSize; ++j){
	    //		if(matrix1[i][j] != '#'){
	    //			return false;
	    //		}
	    //	}
	    //}
    }
    int mid = matrixSize/2, start = mid/2;
    matrix1[mid][start++] = 'Y'; 
    matrix1[mid][start++] = 'O'; 
    matrix1[mid][start++] = 'U'; 
    matrix1[mid][start++] = ' '; 
    matrix1[mid][start++] = 'W'; 
    matrix1[mid][start++] = 'O'; 
    matrix1[mid][start] = 'N'; 
    //std::cout << "\n\n\n\n\n\n\t\t\t\t\t\t\t\033[32m🅈🄾🅄 🅆🄾🄽 🅃🄷🄴 🄶🄰🄼🄴 \u001b[0m" << std::endl;
	//std::cout << "\nY⃣   O⃣   U⃣    W⃣   O⃣   N⃣    T⃣   H⃣   E⃣    G⃣   A⃣   M⃣   E⃣";
    //std::this_thread::sleep_for(std::chrono::milliseconds(1350));
	return true;
}
void checkLittleSide(char matrix1[][matrixSize], size_t& zero, size_t& two){
    for(int i = 0; i < matrixSize; ++i){
        for(int j = 0; j < matrixSize; ++j){
            switch(matrix1[i][j]){
                case '-':
                    ++zero;
                break;
                case 2:
                    ++two;
                break;
            }
        }
    }
}
// Complete matrix with recursion
void complete_m(char matrix1[][matrixSize], short i1, short j1){
    switch (matrix1[i1][j1]){
        case '*':
            matrix1[i1][j1] = 3;
        break;
        case '-':
            matrix1[i1][j1] = 2;
        break;
    }
	if(i1-1 >= 0 && (matrix1[i1-1][j1] == '-' || matrix1[i1-1][j1] == '*')){
		complete_m(matrix1, i1-1, j1);
	}
	if(i1+1 < matrixSize && (matrix1[i1+1][j1] == '-' || matrix1[i1+1][j1] == '*')){
		complete_m(matrix1, i1+1, j1);	
	}
	if(j1-1 >= 0&& (matrix1[i1][j1-1] == '-' || matrix1[i1][j1-1] == '*')){
		complete_m(matrix1, i1, j1-1);	
	}
	if(j1+1 < matrixSize && (matrix1[i1][j1+1] == '-' || matrix1[i1][j1+1] == '*')){
		complete_m(matrix1, i1, j1+1);	
	}

}

void charge(char matrix1[][matrixSize], int x1, int y1) 
{
    std::cout << "Xmax1 = " << xmax1 << " Xmax2 = " << xmax2 << " Xmin1 = " << xmin1 << " Xmin2 = " << xmin2 << " Ymax1 = " << ymax1 << " Ymax2 = " << ymax2 << " Ymin1 = " << ymin1 << " Ymin2 = " << ymin2 << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(10000));
    if(xmax1 != -1 && xmax2 != -1){
    	std::cout << "xmax1 = " << xmax1 << " xmax2 = " << xmax2 << std::endl;
		for(short j = 0; j < matrixSize; ++j){
			if(matrix1[0][j] == '-' || matrix1[0][j] == '*'){
				complete_m(matrix1, 0, j);
			}
			if(matrix1[j][0] == '-' || matrix1[j][0] == '*'){
				complete_m(matrix1, j, 0);
			}
			if(matrix1[j][matrixSize-1] == '-' || matrix1[j][matrixSize-1] == '*'){
				complete_m(matrix1, j, matrixSize-1);
			}
		}
		if(xmax1 < xmax2){
			for(short i = 0; i < xmax1; ++i){
				if(matrix1[matrixSize-1][i] == '-' || matrix1[matrixSize-1][i] == '*'){
					complete_m(matrix1, matrixSize-1, i);
				}
			}
			for(short i = xmax2 + 1; i < matrixSize; ++i){
				if(matrix1[matrixSize-1][i] == '-' || matrix1[matrixSize-1][i] == '*'){
					complete_m(matrix1, matrixSize-1, i);
				}				
			}
		}
		else{
			for(short i = 0; i < xmax2; ++i){
				if(matrix1[matrixSize-1][i] == '-' || matrix1[matrixSize-1][i] == '*'){
					complete_m(matrix1, matrixSize-1, i);
				}
			}
			for(short i = xmax1 + 1; i < matrixSize; ++i){
				if(matrix1[matrixSize-1][i] == '-' || matrix1[matrixSize-1][i] == '*'){
					complete_m(matrix1, matrixSize-1, i);
				}				
			}
		}
	}
	else if (xmax1 != -1 && ymax1 != -1)
        {
		std::cout << "xmax1 = " << xmax1 << " ymax1 = " << ymax1 << std::endl;
		for(short j = 0; j < matrixSize; ++j){
			if(matrix1[0][j] == '-' || matrix1[0][j] == '*'){
				complete_m(matrix1, 0, j);
			}
			if(matrix1[j][0] == '-' || matrix1[j][0] == '*'){
				complete_m(matrix1, j, 0);
			}
		}
		for(short i = 0; i < xmax1; ++i){
			if(matrix1[matrixSize-1][i] == '-' || matrix1[matrixSize-1][i] == '*'){
				complete_m(matrix1, matrixSize-1, i);
			}
		}
		for(short i = 0; i < ymax1; ++i){
			if(matrix1[i][matrixSize-1] == '-' || matrix1[i][matrixSize-1] == '*'){
				complete_m(matrix1, i, matrixSize-1);
			}				
		}
            }
	    else if(xmax1 != -1 && ymin1 != -1){
	    	std::cout << "xmax1 = " << xmax1 << " ymin1 = " << ymin1 << std::endl;
		    for(short j = 0; j < matrixSize; ++j){
		    	if(matrix1[0][j] == '-' || matrix1[0][j] == '*'){
		    		complete_m(matrix1, 0, j);
		    	}
		    	if(matrix1[j][matrixSize-1] == '-' || matrix1[j][matrixSize-1] == '*'){
		    		complete_m(matrix1, j, matrixSize-1);
		    	}
		    }
            for(int i = 0; i < ymin1; ++i){ 
		    	if(matrix1[i][0] == '-' || matrix1[i][0] == '*'){
		    		complete_m(matrix1, i, 0);
		    	}
            }
            for(int i = xmax1; i < matrixSize; ++i){ 
		    	if(matrix1[matrixSize-1][i] == '-' || matrix1[matrixSize-1][i] == '*'){
		    		complete_m(matrix1, matrixSize-1, i);
		    	}
            }
	    }
	   
	    else if(xmax1 != -1 && xmin1 != -1){
	    	std::cout << "xmax1 = " << xmax1 << " xmin1 = " << xmin1 << std::endl;
		for(short i = 0; i < xmin1; ++i){
			if(matrix1[0][i] == '-' || matrix1[0][i] == '*'){
				complete_m(matrix1, 0, i);
			}
		}
		for(short i = 0; i < xmax1; ++i){
			if(matrix1[matrixSize-1][i] == '-' || matrix1[matrixSize-1][i] == '*'){
				complete_m(matrix1, matrixSize-1, i);
			}
		}
	    }
	    //############################
            else if (ymax1 != -1 && ymax2 != -1)
            {
		    std::cout << "ymax1 = " << ymax1 << " ymax2 = " << ymax2 << std::endl;
		    for(short i = 0; i < matrixSize; ++i){
		    	if(matrix1[0][i] == '-' || matrix1[0][i] == '*'){
				    complete_m(matrix1, 0, i);
			    }
			    if(matrix1[i][0] == '-' || matrix1[i][0] == '*'){
				    complete_m(matrix1, i, 0);
			    }
			    if(matrix1[matrixSize-1][i] == '-' || matrix1[matrixSize-1][i] == '*'){
				    complete_m(matrix1, matrixSize-1, i);
			    }
		    }
		    if(ymax1 < ymax2){
		    	for(short i = 0; i < ymax1; ++i){
				    if(matrix1[i][matrixSize-1] == '-' || matrix1[i][matrixSize-1] == '*'){
					    complete_m(matrix1, i, matrixSize-1);
				    }
			    }
		    	for(short i = ymax2+1; i < matrixSize; ++i){
				    if(matrix1[i][matrixSize-1] == '-' || matrix1[i][matrixSize-1] == '*'){
					    complete_m(matrix1, i, matrixSize-1);
				    }
			    }
		    }
		    else{
		    	for(short i = 0; i < ymax2; ++i){
				    if(matrix1[i][matrixSize-1] == '-' || matrix1[i][matrixSize-1] == '*'){
					    complete_m(matrix1, i, matrixSize-1);
				    }
			    }
		    	for(short i = ymax1+1; i < matrixSize; ++i){
				    if(matrix1[i][matrixSize-1] == '-' || matrix1[i][matrixSize-1] == '*'){
					    complete_m(matrix1, i, matrixSize-1);
				    }
			    }
		    }
	    }
	    else if(ymax1 != -1 && xmin1 != -1){
	    	std::cout << "ymax1 = " << ymax1 << " xmin1 = " << xmin1 << std::endl;
		    for(short i = 0; i < matrixSize; ++i){
		    	if(matrix1[i][0] == '-' || matrix1[i][0] == '*'){
		    		complete_m(matrix1, i, 0);
		    	}
		    	if(matrix1[matrixSize-1][i] == '-' || matrix1[matrixSize-1][i] == '*'){
		    		complete_m(matrix1, matrixSize-1, i);
		    	}
		    }
		    for(short i = 0; i < xmin1; ++i){
		    	if(matrix1[0][i] == '-' || matrix1[0][i] == '*'){
		    		complete_m(matrix1, 0, i);
		    	}
		    }
		    for(short i = ymax1+1; i < matrixSize; ++i){
		    	if(matrix1[i][matrixSize-1] == '-' || matrix1[i][matrixSize-1] == '*'){
		    		complete_m(matrix1, i, matrixSize-1);
		    	}
		    }
	    }
	    else if(ymax1 != -1 && ymin1 != -1){
	    	std::cout << "ymax1 = " << ymax1 << " ymin1 = " << ymin1 << std::endl;
		    for(short i = 0; i < matrixSize; ++i){
		    	if(matrix1[0][i] == '-' || matrix1[0][i] == '*'){
		    		complete_m(matrix1, 0, i);
		    	}
		    }
	    }
	    //############################
	    else if (xmin1 != -1 && xmin2 != -1)
        {
		    std::cout << "xmin1 = " << xmin1 << " xmin2 = " << xmin2 << std::endl;
		    for(short i = 0; i < matrixSize; ++i){
		    	if(matrix1[i][0] == '-' || matrix1[i][0] == '*'){
			    	complete_m(matrix1, i, 0);
			    }
			    if(matrix1[matrixSize-1][i] == '-' || matrix1[matrixSize-1][i] == '*'){
			    	complete_m(matrix1, matrixSize-1, i);
			    }
			    if(matrix1[i][matrixSize-1] == '-' || matrix1[i][matrixSize-1] == '*'){
			    	complete_m(matrix1, i, matrixSize-1);
			    }
		    }
		    if(xmin1 < xmin2){
		    	for(short i = 0; i < xmin1; ++i){
			    	if(matrix1[0][i] == '-' || matrix1[0][i] == '*'){
			    		complete_m(matrix1, 0, i);
			    	}
			    }
			    for(short i = xmin2+1; i < matrixSize; ++i){
			    	if(matrix1[0][i] == '-' || matrix1[0][i] == '*'){
			    		complete_m(matrix1, 0, i);
			    	}
			    }
		    }
		    else{
 		    	for(short i = 0; i < xmin2; ++i){
				if(matrix1[0][i] == '-' || matrix1[0][i] == '*'){
					complete_m(matrix1, 0, i);
				}
			}
			    for(short i = xmin1+1; i < matrixSize; ++i){
			    	if(matrix1[0][i] == '-' || matrix1[0][i] == '*'){
			    		complete_m(matrix1, 0, i);
			    	}
			    }  	
		    }
        }
	    else if(xmin1 != -1 && ymin1 != -1){
	    	std::cout << "xmin1 = " << xmin1 << " ymin1 = " << ymin1 << std::endl;
		    for(short i = 1; i < matrixSize; ++i){
		    	if(matrix1[matrixSize-1][i] != '#'){
		    		complete_m(matrix1, matrixSize-1, i);
		    	}
		    	//if(matrix1[matrixSize-1][i] == '-' || matrix1[matrixSize-1][i] == '*'){
		    	//	complete_m(matrix1, matrixSize-1, i);
		    	//}
		    	if(matrix1[i][matrixSize-1] != '#'){
                    //std::cout << "I = " << i << "matrixSize-1 = " << matrixSize-1 << std::endl;
	                //std::this_thread::sleep_for(std::chrono::milliseconds(2350));
		    		complete_m(matrix1, i, matrixSize-1);
		    	}
		    	//if(matrix1[i][matrixSize-1] == '-' || matrix1[i][matrixSize-1] == '*'){
                //    //std::cout << "I = " << i << "matrixSize-1 = " << matrixSize-1 << std::endl;
	            //    //std::this_thread::sleep_for(std::chrono::milliseconds(2350));
		    	//	complete_m(matrix1, i, matrixSize-1);
		    	//}
		    }
		    for(short i = xmin1+1; i < matrixSize; ++i){
		    	if(matrix1[0][i] == '-' || matrix1[0][i] == '*'){
		    		complete_m(matrix1, 0, i);
		    	}
		    }
		    for(short i = ymin1+1; i < matrixSize; ++i){
		    	if(matrix1[i][0] == '-' || matrix1[i][0] == '*'){
		    		complete_m(matrix1, i, 0);
		    	}
		    }
	    }
	    //############################
	    else if (ymin1 != -1 && ymin2 != -1)
        {
		    std::cout << "ymin1 = " << ymin1 << " ymin2 = " << ymin2 << std::endl;
		    for(short i = 0; i < matrixSize; ++i){
		        if(matrix1[0][i] == '-' || matrix1[0][i] == '*'){
			    	complete_m(matrix1, 0, i);
			    }
			    if(matrix1[i][matrixSize-1] == '-' || matrix1[i][matrixSize-1] == '*'){
			    	complete_m(matrix1, i, matrixSize-1);
			    }
			    if(matrix1[matrixSize-1][i] == '-' || matrix1[matrixSize-1][i] == '*'){
			    	complete_m(matrix1, matrixSize-1, i);
			    }
		    }
		    if(ymin1 < ymin2){
		    	for(short i = 0; i < ymin1; ++i){
				    if(matrix1[i][0] == '-' || matrix1[i][0] == '*'){
				    	complete_m(matrix1, i, 0);
				    }
			    }
			    for(short i = ymin2+1; i < matrixSize; ++i){
			    	if(matrix1[i][0] == '-' || matrix1[i][0] == '*'){
			    		complete_m(matrix1, i, 0);
			    	}
			    }
		    }
		    else{
		    	for(short i = 0; i < ymin2; ++i){
				    if(matrix1[i][0] == '-' || matrix1[i][0] == '*'){
				    	complete_m(matrix1, i, 0);
				    }
			    }
			    for(short i = ymin1+1; i < matrixSize; ++i){
			    	if(matrix1[i][0] == '-' || matrix1[i][0] == '*'){
			    		complete_m(matrix1, i, 0);
			    	}
			    }
		    }
        }
    
	if(xmax1 != -1 && xmin1 != -1){
	  	/* static */ size_t zero = 0, two = 0;
        checkBigSide(matrix1, zero, two);
		//for(int i = 0; i < matrixSize; ++i){
		//	for(int j = 0; j < matrixSize; ++j){
		//		if(matrix1[i][j] == 2) ++two;
		//		else if(matrix1[i][j] == '-') ++zero;
		//	}
		//}
		if(two >= zero){
            check_matrix(matrix1, zero);
			for(short i = 0; i < matrixSize; ++i){
				for(short j = 0; j < matrixSize; ++j){
					if(matrix1[i][j] == 2){
						matrix1[i][j] = '-'; 
					}
					else if (matrix1[i][j] == '-' || matrix1[i][j] == '$' || matrix1[i][j] == '*'){
						matrix1[i][j] = '#';
					}
                    else if (matrix1[i][j] == 3){
                        matrix1[i][j] = '*';
                    }
				}
			}
		}
        else if(two == 0){
    		complete_m(matrix1, x1, y1-1);
    		complete_m(matrix1, x1-1, y1-1);
    		complete_m(matrix1, x1+1, y1-1);
        }
		else if(zero > two){
            check_matrix(matrix1, two);
			for(short i = 0; i < matrixSize; ++i){
				for(short j = 0; j < matrixSize; ++j){
					if(matrix1[i][j] == 2 || matrix1[i][j] == '$' || matrix1[i][j] == 3){
						matrix1[i][j] = '#'; 
					}
				}
			}
		}
	}
	else if(ymax1 != -1 && ymin1 != -1){
	  	/* static */ size_t zero = 0, two = 0;
        checkBigSide(matrix1, zero, two);
		//for(int i = 0; i < matrixSize; ++i){
		//	for(int j = 0; j < matrixSize; ++j){
		//		if(matrix1[i][j] == 2) ++two;
		//		else if(matrix1[i][j] == '-') ++zero;
		//	}
		//}
		if(two >= zero){
            check_matrix(matrix1, zero);
			for(short i = 0; i < matrixSize; ++i){
				for(short j = 0; j < matrixSize; ++j){
					if(matrix1[i][j] == 2){
						matrix1[i][j] = '-'; 
					}
					else if (matrix1[i][j] == '-' || matrix1[i][j] == '$' || matrix1[i][j] == '*'){
						matrix1[i][j] = '#';
					} 
                    else if (matrix1[i][j] == 3){
                        matrix1[i][j] = '*';
                    }
				}
			}
		}
        else if(two == 0){
    		complete_m(matrix1, x1+1, y1);
    		complete_m(matrix1, x1+1, y1+1);
    		complete_m(matrix1, x1+1, y1-1);
        }
		else if(zero > two){
            check_matrix(matrix1, two);
			for(short i = 0; i < matrixSize; ++i){
				for(short j = 0; j < matrixSize; ++j){
					if(matrix1[i][j] == 2 || matrix1[i][j] == '$' || matrix1[i][j] == 3){
						matrix1[i][j] = '#'; 
					}
				}
			}
		}
	}
	else{
        //completePath(matrix1);
        //for(short i = 0; i < matrixSize; ++i){
        //    if(matrix1[i][matrixSize-1] != '-' || matrix1[i][matrixSize-1] != 2 || matrix1[i][matrixSize-1] != '*' || matrix1[i][matrixSize-1] != 3 || matrix1[i][matrixSize-1] != '$' || matrix1[i][matrixSize-1] != '#'){
        //        matrix1[i][matrixSize-1] = '-';
        //    }
        //}
        size_t zero = 0, two = 0;
        checkLittleSide(matrix1, zero, two);
        check_matrix(matrix1, zero);
        //switch(zero){
        //    case 0:
        //        for(){
        //        
        //        }
        //    break;
        //}
		for(short i = 0; i < matrixSize; ++i){
			for(short j = 0; j < matrixSize; ++j){
                switch(matrix1[i][j]){
                    case 2:
                        matrix1[i][j] = '-';
                    break;
                    case '-': case '$': case '*':
                        matrix1[i][j] = '#';
                    break;
                    case 3:
                        matrix1[i][j] = '*';
                    break;
                }
                //switch(matrix1[i][j]){
                //    case 2:
                //        if(zero < two){
                //            matrix1[i][j] = '-';
                //        }else{
                //            matrix1[i][j] = '#';
                //        }
                //    break;
                //    case '-': case '$': case '*':
                //        if(zero < two){
                //            matrix1[i][j] = '#';
                //        }else{
                //            matrix1[i][j] = '-';
                //        }
                //    break;
                //    case 3:
                //        matrix1[i][j] = '*';
                //    break;
                //}
				//if(matrix1[i][j] == 2){
				//	matrix1[i][j] = '-'; 
				//}
				//else if (matrix1[i][j] == '-' || matrix1[i][j] == '$' || matrix1[i][j] == '*'){
				//	matrix1[i][j] = '#';
				//}        
                //else if (matrix1[i][j] == 3){
                //    matrix1[i][j] = '*';
                //}
			}
		}
	}
    //std::cout << "xmax1 = " << xmax1 << "\n xmax2 = " << xmax2 << "\n xmin1 = " << xmin1 << "\n xmin2 = " << xmin2 << "\n ymax1 = " << ymax1 << "\n ymax2 = " << ymax2 << "\n ymin1 = " << ymin1 << "\n ymin2 = " << ymin2 << std::endl;
	//std::this_thread::sleep_for(std::chrono::milliseconds(7350));
    //std::cout << "Matrix[1][matrixSize-1] = " << matrix1[1][matrixSize-1];
	//std::this_thread::sleep_for(std::chrono::milliseconds(2350));
    updatePreviousValue();
    system("clear");
  	bool game = true/*, filled = check_matrix(matrix1)*/;
  	if(check_matrix(matrix1, 0)){
        matrixInit(matrix1);
        menuBar(matrix1);
		game = false;
	}
    
    print_m(matrix1/*, true*/);
	cbreak();

	while(game){
		const int key_prs = keypress();
		switch (key_prs) {
			case keyUp:
				go_up(matrix1, x1, y1);
                std::cout << "Go UP" << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                game = false;
			break;
			case keyDown:
				go_down(matrix1, x1, y1);
                std::cout << "Go DOWN" << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                game = false;
			break;
			case keyRight:
				go_right(matrix1, x1, y1);
                std::cout << "Go Right" << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                game = false;
			break;
			case keyLeft: 
				go_left(matrix1, x1, y1);
                std::cout << "Go Left" << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                game = false;
			break;
			case quit:
				game = false;
			break;	
		}
	}
	normal();
}
