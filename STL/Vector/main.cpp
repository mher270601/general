#include <iostream>

#include "vector.hpp"
// attock polymorphism, is a, has a, dynamic typing
int main(){
	Containers::Vector<int> myVec;
	myVec.Push_back(7);
	myVec.Push_back(9);
	myVec.Push_back(3);
	myVec.Push_back(7);
	myVec.Push_back(1);
	for(const auto& item : myVec){
		std::cout << item << std::endl;
	}
	return 0;
}
