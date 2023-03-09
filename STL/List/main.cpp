#include <iostream>

#include "list.hpp"

int main(){
	DataStructure::List<int> myList;
	myList.Push_back(5);
	myList.Push_back(2);
	myList.Push_back(1);
	myList.Push_back(9);
	myList.Push_back(0);
	for(const auto& elem : myList){
		std::cout << elem << std::endl;
	}
	std::cout << "Size = " << myList.Size() << std::endl;
	myList.Pop_back();
	myList.Pop_back();
	for(const auto& elem : myList){
		std::cout << elem << std::endl;
	}
	std::cout << "Size = " << myList.Size() << std::endl;
	return 0;
}
