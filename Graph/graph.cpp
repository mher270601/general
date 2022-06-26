#include <iostream>
#include <fstream>
#include <cassert>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <vector>

#include "graph.hpp"

int main(){
	
	std::string fileName = "graph.txt";
	std::ifstream file;
	file.open(fileName);
	Graph<unsigned int> myGraph(fileName);
	myGraph.Render();
	return 0;
}
