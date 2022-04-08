#ifndef FILLMATRIX_HPP
#define FILLMATRIX_HPP

#include "source.hpp"
//void go_right(char matrix1[][matrixSize], int& x1, int& y1);
//void go_up(char matrix1[][matrixSize], int& x1, int& y1);
//void go_left(char matrix1[][matrixSize], int& x1, int& y1);
//void go_down(char matrix1[][matrixSize], int& x1, int& y1);
//void rightSides(char matrix1[][matrixSize], int& x1, int& y1);
//short xmax1 = 6, xmax2 = -1, ymax1 = -1, ymax2 = -1, xmin1 = -1, xmin2 = -1, ymin1 = -1, ymin2 = -1;
bool check_matrix(char matrix1[][matrixSize]);
void complete_m(char matrix1[][matrixSize], short i1, short j1);
void charge(char matrix1[][matrixSize], int x1, int y1);

#endif // FILLMATRIX_HPP
