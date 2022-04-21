#include <array>
#include <iostream>

#include "quickSort.hpp"

int main(){
	std::array<int, 7> al = {7, 15, 3, 1, 6, 5, 0};
	Hybryd_QSort::QuickSort<std::array<int, 7>>(al, 0, 7);
	std::cout << "array:" << std::endl;
	for(size_t i = 0; i < 7; ++i){
		std::cout << al[i] << std::endl;
	}
	//std::cout << " -- -- -- " << std::endl;
	//int X[5] = {7, 3, 8, 2, 4};
	//Hybryd_QSort::QuickSort<int>(X, 0, 5);
	//for(size_t i = 0; i < 5; ++i){
	//	std::cout << X[i] << std::endl;
	//}
	return 0;
}
