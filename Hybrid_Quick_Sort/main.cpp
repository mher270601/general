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
	return 0;
}
