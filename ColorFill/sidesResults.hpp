#ifndef SIDESRESULTS_HPP
#define SIDESRESULTS_HPP

#include "source.hpp"

 void updatePreviousValue();

 void rightSides(char matrix1[][matrixSize], int& x1, int& y1, bool isBreaked = false);
 void upSides(char matrix1[][matrixSize], int& x1, int& y1, bool isBreaked = false);
 void leftSides(char matrix1[][matrixSize], int& x1, int& y1, bool isBreaked = false);
 void downSides(char matrix1[][matrixSize], int& x1, int& y1, bool isBreaked = false);

#endif // SIDESRESULTS_HPP
