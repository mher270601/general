#include <iostream>
#include <thread>

#include "source.hpp"
#include "fillMatrix.hpp"
//#include "sidesResults.hpp"
#include "callSides.hpp"

extern short xmax1, xmax2, ymax1,  ymax2, xmin1, xmin2,  ymin1, ymin2;
short *previousSide = &xmax1;

void updatePreviousValue(){
    if(xmax2 != -1){
        xmax1 = xmax2;
        std::cout << "\nPrevious = xmax2 = " << xmax2 << std::endl;
        previousSide = &xmax2;
        std::this_thread::sleep_for(std::chrono::milliseconds(6000));
    }
    else if(xmin2 != -1){
        xmin1 = xmin2;
        std::cout << "\nPrevious = xmin2 = " << xmin2 << std::endl;
        previousSide = &xmin2;
        std::this_thread::sleep_for(std::chrono::milliseconds(6000));
    }
    else if(ymax2 != -1){
        ymax1 = ymax2;
        std::cout << "\nPrevious = ymax2 = " << ymax2 << std::endl;
        previousSide = &ymax2;
        std::this_thread::sleep_for(std::chrono::milliseconds(6000));
    }
    else if(ymin2 != -1){
        ymin1 = ymin2;
        std::cout << "\nPrevious = ymin2 = " << xmax2 << std::endl;
        previousSide = &ymin2;
        std::this_thread::sleep_for(std::chrono::milliseconds(6000));
    }
    *previousSide = -1;
}

void rightSides(char matrix1[][matrixSize], int& x1, int& y1, bool isBreaked = false){
    if(isBreaked){
        if(ymax1 != -1){
            ymax2 = matrixSize-1;
        }
        else{
            ymax1 = matrixSize-1;
        }
    }
    if(ymax1 != -1){
        previousSide = &ymax2;
        //previousSide = &ymax1;
        ymax2 = x1;
        xmax1 = -1, xmax2 = -1, xmin1 = -1, xmin2 = -1, ymin1 = -1, ymin2 = -1;
    }
    else if(ymin1 != -1){
        //previousSide = &ymin1;
        ymax1 = x1;
        xmax1 = -1, xmax2 = -1, xmin1 = -1, xmin2 = -1, ymax2 = -1, ymin2 = -1;
    }
    else if(xmax1 != -1){
        //previousSide = &xmax1;
        ymax1 = x1;
        xmax2 = -1, xmin1 = -1, xmin2 = -1, ymax2 = -1, ymin1 = -1, ymin2 = -1;
        //std::cout << "Previous is equal xmax1" << std::endl;
        //std::this_thread::sleep_for(std::chrono::milliseconds(4000));
    }
    else if(xmin1 != -1){
        //previousSide = &xmin1;
        ymax1 = x1;
        xmax1 = -1, xmax2 = -1, xmin2 = -1, ymax2 = -1, ymin1 = -1, ymin2 = -1;
        //std::cout << "Previous is equal xmin1" << std::endl;
        //std::this_thread::sleep_for(std::chrono::milliseconds(4000));
    }
    else if(ymax2 == -1){
        previousSide = &ymax1;
    }
    
        std::cout << "Previous is equal " << *previousSide << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(4000));
    std::cout << "\nRIGHT Side is catched   " << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    charge(matrix1, x1, y1);
}
void upSides(char matrix1[][matrixSize], int& x1, int& y1, bool isBreaked = false){
    if(isBreaked){
        if(xmin1 != -1){
            xmin2 = 0;
        }
        else{
            xmin1 = 0;
        }
    }
    if(xmin1 != -1){
        previousSide = &xmin1;
        xmin2 = y1;
        xmax1 = -1, xmax2 = -1, ymax1 = -1, ymax2 = -1, ymin1 = -1, ymin2 = -1;
    }
    else if(xmax1 != -1){
        previousSide = &xmax1;
        xmin1 = y1;
        xmax2 = -1, xmin2 = -1, ymax1 = -1, ymax2 = -1, ymin1 = -1, ymin2 = -1;
    }
    else if(ymin1 != -1){
        previousSide = &ymin1;
        xmin1 = y1;
        xmax1 = -1, xmax2 = -1, xmin2 = -1, ymax1 = -1, ymax2 = -1, ymin2 = -1;
    }
    else if(ymax1 != -1){
        previousSide = &ymax1;
        xmin1 = y1;
        xmax1 = -1, xmax2 = -1, xmin2 = -1, ymax2 = -1, ymin1 = -1, ymin2 = -1;
    }
        std::cout << "Previous is equal " << *previousSide << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(4000));
    std::cout << "\nUP Side is catched   " << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    charge(matrix1, x1, y1);
}
void leftSides(char matrix1[][matrixSize], int& x1, int& y1, bool isBreaked = false){
    if(isBreaked){
        if(ymin1 != -1){
            ymin2 = 0;
        }
        else{
            ymin1 = 0;
        }
    }
    if(ymin1 != -1){
        previousSide = &ymin1;
        ymin2 = x1;
        xmax1 = -1, xmax2 = -1, xmin1 = -1, xmin2 = -1, ymax1 = -1, ymax2 = -1;
    }
    else if(ymax1 != -1){
        previousSide = &ymax1;
        ymin1 = x1;
        xmax1 = -1, xmax2 = -1, xmin1 = -1, xmin2 = -1, ymax2 = -1, ymin2 = -1;
    }
    else if(xmin1 != -1){
        previousSide = &xmin1;
        ymin1 = x1;
        xmax1 = -1, xmax2 = -1, xmin2 = -1, ymax1 = -1, ymax2 = -1, ymin2 = -1;
    }
    else if(xmax1 != -1){
        previousSide = &xmax1;
        ymin1 = x1;
        xmax2 = -1, xmin1 = -1, xmin2 = -1, ymax1 = -1, ymax2 = -1, ymin2 = -1;
    }
        std::cout << "Previous is equal " << *previousSide << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(4000));
    std::cout << "\nLEFT Side is catched   " << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    charge(matrix1, x1, y1);
}
void downSides(char matrix1[][matrixSize], int& x1, int& y1, bool isBreaked = false){
    if(isBreaked){
        if(xmax1 != -1){
            xmax2 = matrixSize-1;
        }
        else{
            xmax1 = matrixSize-1;
        }
    }
    if(xmax1 != -1){
        previousSide = &xmax1;
        xmax2 = y1;
        xmin1 = -1, xmin2 = -1, ymax1 = -1, ymax2 = -1, ymin1 = -1, ymin2 = -1;
    }
    else if(xmin1 != -1){
        previousSide = &xmin1;
        xmax1 = y1;
        xmax2 = -1, xmin2 = -1, ymax1 = -1, ymax2 = -1, ymin1 = -1, ymin2 = -1;
    }
    else if(ymin1 != -1){
        previousSide = &ymin1;
        xmax1 = y1;
        xmax2 = -1, xmin1 = -1, xmin2 = -1, ymax1 = -1, ymax2 = -1, ymin2 = -1;
    }
    else if(ymax1 != -1){
        previousSide = &ymax1;
        xmax1 = y1;
        xmax2 = -1, xmin1 = -1, xmin2 = -1, ymax2 = -1, ymin1 = -1, ymin2 = -1;
    }
        std::cout << "Previous is equal " << *previousSide << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(4000));
    std::cout << "\nDOWN Side is catched   " << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    charge(matrix1, x1, y1);
}

