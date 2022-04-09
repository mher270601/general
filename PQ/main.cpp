#include <iostream>
#include "priority_queue.hpp"

int main(){
	Priority_Queue::PriorityQueue<int, std::vector<int>, std::less<int>> ob;
	ob.Push(4);
	ob.Push(5);
	ob.Push(8);
	ob.Push(2);
	ob.Push(1);

	return 0;
}
