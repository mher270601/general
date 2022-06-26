#ifndef __GRAPH__IMPL__HPP__
#define __GRAPH__IMPL__HPP__

#include <algorithm>
#include <exception>
#include <utility>
#include <cstring>
#include <sstream>
#include <stdexcept>
#include <fstream>
#include <string>
#include <limits>
#include <thread>

template <typename T>
inline size_t Graph<T>::MaxPath() const noexcept{
	return maximumPath;
} // MaxPath

template <typename T>
void Graph<T>::CheckSimplicity(){
	vecType tempGraph = m_graphVec;
	while(tempGraph.size() != 1){
		for(size_t i = 0; i < tempGraph.size()-1; ++i){
			if(tempGraph[i].second == tempGraph[tempGraph.size()-1].second){
				throw std::runtime_error("Graph is not simple ! ! !");
			}
		}
		tempGraph.pop_back();	
	}
	std::cout << "Graph is simple" << std::endl;
	std::this_thread::sleep_for (std::chrono::seconds(1));
} // CheckSimplicity

template <typename T>
void Graph<T>::SepRepeaters(){
	// std::sort - O(nlong)
	size_t i{0}, j{0};
	while(i < m_graphVec.size()){ // O(n)
		while(m_graphVec[i].first != m_graphVec[i+1].first){
			if((i > 0 && m_graphVec[i].first != m_graphVec[i-1].first) || i == 0){
				m_unRepeated.push_back(m_graphVec[i]);
			}else{
				m_repeated.push_back(m_graphVec[i]);
			}
			++i;
		}
		m_repeated.push_back(m_graphVec[i]);
		++i;
	}
	m_graphVec.pop_back();
	m_repeated.pop_back();
	std::cout << "__ REPEATED __  ճյուղավորվողներ" << std::endl;
	for(const auto& elem : m_repeated){
		std::cout << elem.first << " " << elem.second << std::endl;
	}
	//m_unRepeated.swap(m_graphVec);
	std::cout << "__ VECTOR __  ընդհանուր" << std::endl;
	for(const auto& elem : m_graphVec){
		std::cout << elem.first << " " << elem.second << std::endl;
	}

	std::cout << "__ UNREPEATED __  չճյուղավորվողներ" << std::endl;
	for(const auto& elem : m_unRepeated){
		std::cout << elem.first << " " << elem.second << std::endl;
	}
	FilterRepeats();
} // SepRepeaters

template <typename T>
size_t Graph<T>::CurrentCount(valueType numb, size_t count){
	for(size_t i = 0; i < m_unRepeated.size(); ++i){
		if(numb == m_unRepeated[i].first){
			++count;
			CurrentCount(m_unRepeated[i].second, count);
		}
	}
	return count;
} // CurrentCount

template <typename T>
void Graph<T>::Reverse(std::vector<std::vector<valueType>>& _roads){
	for(size_t i = 0; i < _roads.size(); ++i){
		std::reverse(_roads[i].begin(), _roads[i].end());
	}	
} // Reverse

template <typename T>
void Graph<T>::FilterRoads(){ // ostream
	size_t count{0};
	//Reverse(roads);
	for(size_t i = 1; i < roads.size(); ++i){
		if(roads[i].size() > roads[0].size()){
			roads[i].swap(roads[0]);

		}
	}
} // FilterRoads

template <typename T>
void Graph<T>::BuildRoads(repType longPath){
	RenderStrings(longPath);
	valueType startPoint = m_graphVec[0].first;
	std::vector<valueType> road;
	size_t i{0};
	while(longPath.size() != 0){
		int curSize = longPath.size()-1;
		road.push_back(longPath[curSize].first.first);
		road.push_back(longPath[longPath.size()-1].first.second);
		for(size_t i = 0; i < m_unRepeated.size() ; ++i){
			if(m_unRepeated[i].first == road[road.size()-1]){
				road.push_back(m_unRepeated[i].second);
			}
		}
		std::reverse(road.begin(), road.end());
		for(int i = m_graphVec.size()-1; i >= 0; --i){
			if(m_graphVec[i].second == road[road.size()-1]){
				road.push_back(m_graphVec[i].first);
			}
		}
		longPath.pop_back();
		roads.push_back(road);
		std::vector<T>{}.swap(road);
	}
	Reverse(roads);
	FilterRoads();
	maximumPath = roads[0].size();

} // BuildRoads

template <typename T>
void Graph<T>::RenderStrings(repType& longPath){
	valueType val = longPath[0].first.first;
	std::string expr = std::to_string(val);
	for(size_t i = 0; i < m_unRepeated.size(); ++i){
		if(m_unRepeated[i].first == longPath[0].first.second){
			valueType m_first = m_unRepeated[i].first;
			valueType m_second = m_unRepeated[i].second;
			expr = expr + " " + std::to_string(m_first) + " " + std::to_string(m_second);
		}
	}
} // RenderStrings

template <typename T>
void Graph<T>::FilterRepeats(){
	repType length; // not long repeats / in the end
	repType longPath; // long repeats
	repType tempLength; // full repeats
	while(m_repeated.size() != 0){
		valueType repNumber = m_repeated[m_repeated.size()-1].first;
		size_t stepCounts{0};
		while(m_repeated[m_repeated.size()-1].first == repNumber){
			++stepCounts;
			size_t curr = CurrentCount(m_repeated[m_repeated.size()-1].second);
			length.push_back(std::make_pair(m_repeated[m_repeated.size()-1], stepCounts + curr));
			tempLength.push_back(std::make_pair(m_repeated[m_repeated.size()-1], stepCounts + curr));
			m_repeated.pop_back();
			stepCounts = 0;
		}
		size_t maxIndx{0};
		for(size_t i = 1; i < length.size(); ++i){
			if(length[i].second > length[maxIndx].second){
				maxIndx = i;
			}
		}
		longPath.push_back(length[maxIndx]);
		length.clear();
	}
	std::cout << "__ Rep length count __  ճյուղավորվողները ըստ իրենց երկարության" << std::endl;
	for(const auto& elem : tempLength){
		std::cout << elem.first.first << " " << elem.first.second << " = " << elem.second << std::endl;
	}
	std::cout << "__ Long length count __ ամենաերկար ճյուղավորվածները" << std::endl;
	for(const auto& elem : longPath){
		std::cout << elem.first.first << " " << elem.first.second << " = " << elem.second << std::endl;
	}
	BuildRoads(longPath);
} // FilterRepeats

template <typename T>
void Graph<T>::Render() noexcept{
	CheckSimplicity();
	std::cout << "__ VECTOR __" << std::endl;
	for(const auto& elem : m_graphVec){
		std::cout << elem.first << " " << elem.second << std::endl;
	}
	SepRepeaters();
} // Render

// ####### GRAPH ITERATOR IMPLEMENTATION #######
template <typename T>
typename Graph<T>::Iterator Graph<T>::begin() const{
	return Graph<T>::Iterator(this, 0);
}

template <typename T>
typename Graph<T>::Iterator Graph<T>::end() const{
	return Graph<T>::Iterator(this, maximumPath);
}

template <typename T>
Graph<T>::Iterator::Iterator(const Graph<T>* graph, int indx) : m_graph{graph},
								m_indx{indx}
{
}

template <typename T>
const T& Graph<T>::Iterator::operator*() const{
	return m_graph->operator[](m_indx);
}

template <typename T>
typename Graph<T>::Iterator& Graph<T>::Iterator::operator++(){
	++m_indx;
	return *this;
}

template <typename T>
typename Graph<T>::Iterator& Graph<T>::Iterator::operator--(){
	--m_indx;
	return *this;
}

template <typename T>
bool Graph<T>::Iterator::operator==(const Iterator& it) const{
	return m_indx == it.m_indx;
}

template <typename T>
bool Graph<T>::Iterator::operator!=(const Iterator& it) const{
	return m_indx != it.m_indx;
}

// ####### GRAPH MOVE AND COPY SEMANTICS #######
template <typename T>
Graph<T>::Graph(const Graph& rhs){
	for(const auto& elem : rhs.m_graphVec){
		m_graphVec.push_back(elem);
	}
	for(const auto& elem : rhs.m_repeated){
		m_repeated.push_back(elem);
	}
	for(const auto& elem : rhs.m_unRepeated){
		m_unRepeated.push_back(elem);
	}
	for(const auto& elem : rhs.roads){
		roads.push_back(elem);
	}
	maximumPath = rhs.MaxPath();
} // copy init

template <typename T>
Graph<T>& Graph<T>::operator=(Graph& rhs){
	// copy and swap idiom
	swap(*this, rhs);
	return *this;
} // copy assign

template <typename T>
Graph<T>::Graph(Graph&& rhs) noexcept{
	m_graphVec = std::move(rhs.m_graphVec);
	m_repeated = std::move(rhs.m_repeated);
	m_graphVec = std::move(rhs.m_unRepeated);
	roads = std::move(rhs.roads);
	maximumPath = std::move(rhs.MaxPath());
} // move init

template <typename T>
Graph<T>& Graph<T>::operator=(const Graph&& rhs) noexcept{
	Graph temp = rhs;
	swap(*this, temp);
	return *this;	
} // move assign

// #######
template <typename T>
const T& Graph<T>::operator[](int indx) const{
	return roads[0][indx];
} // Graph operator[]

#endif // __GRAPH__IMPL__HPP__
