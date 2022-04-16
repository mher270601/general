#include <iostream>
#include <functional>
#include "priority_queue.hpp"

int main(){
	Priority_Queue::PriorityQueue<int, std::vector<int>, std::less<int>> ob;
	std::cout << "4, 6, 8, 2, 7, 9, 17" << std::endl;
	ob.Push(4);
	ob.Push(6);
	ob.Push(8);
	ob.Push(2);
	ob.Push(7);
	ob.Push(9);
	ob.Push(17);
	std::cout << "Container -- ";
	ob.PrintContainer();
	std::cout << "Top = " << ob.Top() << std::endl;
	return 0;
}
