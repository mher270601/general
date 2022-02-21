#ifndef CALLSIDES_HPP
#define CALLSIDES_HPP

#include <string>
#include "source.hpp"

//bool checkMatrixFilled(char matrix1[][matrixSize]);
bool checkMatrixCont(char matrix1[][matrixSize], int& x1, int& y1, int low, int high, std::string_view side);
void suicide(char matrix1[][matrixSize], int &x1, int &y1);
void go_right(char matrix1[][matrixSize], int& x1, int& y1);
void go_up(char matrix1[][matrixSize], int& x1, int& y1);
void go_left(char matrix1[][matrixSize], int& x1, int& y1);
void go_down(char matrix1[][matrixSize], int& x1, int& y1);

#endif // CALLSIDES_HPP
