#include <iostream>

#include "MaxHeap.hpp"

void InputSize(size_t& arrSize){
	do{
		std::cout << "Input size of array between 2-30 (default size = 4): ";
		std::cin >> arrSize;
	}while(arrSize > 30 || arrSize < 2);
}
void InputArr(int* M, size_t arrSize){
	for(size_t i = 0; i < arrSize; ++i){
		std::cout << "Arr[" << i << "] = ";
		std::cin >> M[i];
	}
}
int main(){
	//int x[] = {4, 6, 8, 2, 7};
	size_t arrSize = 4;
	InputSize(arrSize);
	int *M = new int[arrSize];
	InputArr(M, arrSize);
	HeapSort(M, arrSize);
	return 0;
}
