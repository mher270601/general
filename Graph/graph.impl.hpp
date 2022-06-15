#ifndef __GRAPH__IMPL__HPP__
#define __GRAPH__IMPL__HPP__

#include <algorithm>
#include <utility>
#include <cstring>
#include <sstream>
#include <fstream>
#include <string>
#include <limits>
#include <thread>

template <typename T>
inline size_t Graph<T>::maxPath() const noexcept{
	return maximumPath;
}

template <typename T>
void Graph<T>::checkSimplicity(){
	vecType tempGraph = m_graphVec;
	//for(size_t i = tempGraph.size()-1; tempGraph.size() > 0; --i){
	//	for(size_t j = tempGraph.size()-2; j < ){
	//		
	//	}
	//}
	while(tempGraph.size() != 1){
		for(size_t i = 0; i < tempGraph.size()-1; ++i){
			if(tempGraph[i].second == tempGraph[tempGraph.size()-1].second){
				std::cerr << "Graph is not simple !!!" << std::endl;
				std::exit(0);
			}
		}
		tempGraph.pop_back();	
	}
	std::cout << "Graph is simple" << std::endl;
	std::this_thread::sleep_for (std::chrono::seconds(1));
}

template <typename T>
void Graph<T>::SepRepeaters(){
	m_unRepeated = m_graphVec;
	for(size_t i = 0; i < m_graphVec.size()-1; ++i){
		bool cur = false;
		for(size_t j = i+1; j < m_graphVec.size(); ++j){
			if(m_graphVec[i].first == m_graphVec[j].first){
				cur = true;
				std::cout << m_graphVec[i].first << " " << m_graphVec[i].second << " Matched " << std::endl;
				std::cout << m_graphVec[j].first << " " << m_graphVec[j].second << " has repeated" << std::endl;
				//m_repeated.push_back(m_graphVec[i]);
	
				m_repeated.push_back(m_graphVec[j]);
				
				for(size_t k = j; k < m_graphVec.size()-1; ++k){
					m_graphVec[k].swap(m_graphVec[k+1]);
				}
				m_graphVec.pop_back();
				//--j;
			}
			else{
				//for(const auto& elem : m_graphVec){
				//	std::cout << "** ";
				//	std::cout << elem.first << " " << elem.second << "**" << std::endl;
				//}
				//m_unRepeated.push_back(m_graphVec[i]);
				//m_unRepeated.push_back(m_graphVec[j]);
			}	
		}
		if(cur){
			//std::cout << m_graphVec[i].first << " " << m_graphVec[i].second << " Pushed to Vector " << std::endl;
			m_repeated.push_back(m_graphVec[i]);
			for(size_t k = i; k < m_graphVec.size()-1; ++k){
				m_graphVec[k].swap(m_graphVec[k+1]);
			}
			//int h = m_graphVec.size()-1;
			m_graphVec.pop_back();
			//m_graphVec[i].swap(m_graphVec[m_graphVec.size()-1]);
			//m_graphVec.pop_back();
			//m_graphVec[i].swap(m_graphVec[m_graphVec.size()-1]);
			//m_graphVec.pop_back();
		}
	}
	std::cout << "__ REPEATED __  ճյուղավորվողներ" << std::endl;
	for(const auto& elem : m_repeated){
		std::cout << elem.first << " " << elem.second << std::endl;
	}
	m_unRepeated.swap(m_graphVec);
	std::cout << "__ VECTOR __  ընդհանուր" << std::endl;
	for(const auto& elem : m_graphVec){
		std::cout << elem.first << " " << elem.second << std::endl;
	}

	std::cout << "__ UNREPEATED __  չճյուղավորվողներ" << std::endl;
	for(const auto& elem : m_unRepeated){
		std::cout << elem.first << " " << elem.second << std::endl;
	}
	filterRepeats();
}

template <typename T>
size_t Graph<T>::currentCount(valueType numb, size_t count){
	//size_t count{0};
	//std::cout << "COUNT = " << count << std::endl;
	for(size_t i = 0; i < m_unRepeated.size(); ++i){
		if(numb == m_unRepeated[i].first){
			++count;
			currentCount(m_unRepeated[i].second, count);
		}
	}
	return count;
}

template <typename T>
void Graph<T>::m_reverse(std::vector<std::vector<valueType>>& _roads){
	for(size_t i = 0; i < _roads.size(); ++i){
		std::reverse(_roads[i].begin(), _roads[i].end());
		//for(size_t j = 0; j < _roads[i].size(); ++j){
		//	
		//}
	}	
}

template <typename T>
void Graph<T>::Print(){
	size_t count{0};
	m_reverse(roads);
	for(size_t i = 0; i < roads.size()-1; ++i){
		//for(size_t j = 0; j < roads[i]){
			
		//}
		if(roads[i+1].size() > roads[i].size()){
			count = i + 1;
		}
	}
	std::cout << "__ ANSWER __  առավելագույն երկարությունը" << std::endl;
	for(size_t i = 0; i < roads[count].size(); ++i){
		std::cout << roads[count][i] << " ";
	}
	std::cout << "\n" << "Size = " << roads[count].size() - 1 << std::endl;

}

template <typename T>
void Graph<T>::buildRoads(repType longPath){
	renderStrings(longPath);
	//std::cout << "__ ** " << m_graphVec[0].first << " " << m_graphVec[0].second << " ** __" << std::endl;
	valueType startPoint = m_graphVec[0].first;
	while(longPath.size() != 0){
		std::vector<valueType> road;
		road.push_back(longPath[0].first.first);
		road.push_back(longPath[0].first.second);
		size_t bindCounts{longPath[0].second-1};
		size_t binds{longPath[0].second};
		while(bindCounts != 0){
			for(size_t i = 0; i < m_unRepeated.size(); ++i){
				if(m_unRepeated[i].first == road[road.size()-1]){
					road.push_back(m_unRepeated[i].second);
					//break;
				}
			}
			--bindCounts;
			std::reverse(road.begin(), road.end());
		}
		//for(size_t i = 0; i < road.size(); ++i){
		//	std::cout << ""
		//}
		//std::cout << "SKSUMA LCNEL" << std::endl;
		valueType cur; 
		if(cur == startPoint){
			++cur;
		}
		//for(const auto& elem : road){
		//	std::cout << elem << std::endl;
		//}
		//std::cout << "STUGUM ENQ VOR KBRNI " << road[road.size()-1] << "-I HET" << std::endl; 
		//bool m_queue = true;
		while(cur != startPoint && road[road.size()-1] != startPoint){
			//std::cout << "MTAVVVV" << std::endl;
			for(size_t i = 0; i < m_graphVec.size(); ++i){
				if(m_graphVec[i].second == road[road.size()-1]){
					//std::cout << m_graphVec[i].first << " " << m_graphVec[i].second << " is matched with " << road[road.size()-1] << std::endl;
					road.push_back(m_graphVec[i].first);
					cur = m_graphVec[i].first;
					break;
				}
				else{
					//std::cout << m_graphVec[i].first << " " << m_graphVec[i].second << " CHBRNEC " << road[road.size()-1] << std::endl;
				}
			}
			//break;
		}
		//m_queue = false;
		//cur = std::numeric_limits<valueType>::max();
		//std::cout << "LCNELUC HETO" << std::endl;
		//for(const auto& elem : road){
		//	std::cout << elem << std::endl;
		//}
		//cur = std::numeric_limits<valueType>::max();
		roads.push_back(road);
		for(size_t i = 0; i < longPath.size()-1; ++i){
			longPath[i].swap(longPath[i+1]);
		}
		longPath.pop_back();
		//for(size_t k = 0; k < longPath.size(); ++k){
		//	std::cout << longPath[k].first.first << " " << longPath[k].first.second << " : " << longPath[k].second << std::endl;
		//}
	}
	std::cout << "__ ROADS __  ամենաերկար ճյուղավորվողների երկարությունները" << std::endl;
	for(size_t i = 0; i < roads.size(); ++i){
		for(size_t j = 0; j < roads[i].size(); ++j){
			std::cout << roads[i][j] << " ";
		}
		std::cout << std::endl;
	}
	Print();

}

template <typename T>
void Graph<T>::renderStrings(repType& longPath){
	valueType val = longPath[0].first.first;
	std::string expr = std::to_string(val);
	//std::cout << "MHER JAN " << expr << std::endl;
	for(size_t i = 0; i < m_unRepeated.size(); ++i){
		if(m_unRepeated[i].first == longPath[0].first.second){
			valueType m_first = m_unRepeated[i].first;
			valueType m_second = m_unRepeated[i].second;
			expr = expr + " " + std::to_string(m_first) + " " + std::to_string(m_second);
		}
	}
	//buildRoads();
}

template <typename T>
void Graph<T>::filterRepeats(){
	repType length; // not long repeats / in the end
	repType longPath; // long repeats
	repType tempLength; // full repeats
	while(m_repeated.size() != 0){
		valueType repNumber = m_repeated[m_repeated.size()-1].first;
		std::vector<valueType> curSize;
		size_t stepCounts{0};
		while(m_repeated[m_repeated.size()-1].first == repNumber){
			//std::cout << "WHILED" << std::endl;
			++stepCounts;
			size_t curr = currentCount(m_repeated[m_repeated.size()-1].second);
			//std::cout << "cur = " << curr << ", stepCounts = " << stepCounts << std::endl;
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
		//std::cout << "AXPERSSS INDX = " << maxIndx << std::endl;
		//std::cout << "### " << length[maxIndx].first.first << " " << length[maxIndx].first.second << " : " << length[maxIndx].second << " ###" << std::endl;
		longPath.push_back(length[maxIndx]);
		//length.shrink_to_fit();
		length.clear();
		//std::cout << "SIZEE = " << length.size() << std::endl;
		//for(const auto& elem : length){
		//	std::cout << elem.first.first << " " << elem.first.second << " : " << elem.second << std::endl;
		//}
		//size_t curTemp{0};
		//for(size_t i = 0; i < length.size()-1; ++i){
		//	if(length[i].second < length[i+1].second){
		//		curTemp = i + 1;
		//	}
		//}
		//std::cout << "CUR TEMP = " << curTemp << std::endl;
		//std::cout << length[curTemp].first.first << " " << length[curTemp].first.second << " : " << length[curTemp].second << std::endl;

		//std::cout << "______ " << std::endl;
		//size_t lngIndx{0};
		//for(size_t i = 0; i < length.size()-1; ++i){
		//	if(length[i+1].first.second > length[i].first.second){
		//		lngIndx = i+1;
		//	}	
		//}
		//longPath.push_back(length[lngIndx]);
	}
	std::cout << "__ Rep length count __  ճյուղավորվողները ըստ իրենց երկարության" << std::endl;
	for(const auto& elem : tempLength){
		std::cout << elem.first.first << " " << elem.first.second << " = " << elem.second << std::endl;
	}
	std::cout << "__ Long length count __ ամենաերկար ճյուղավորվածները" << std::endl;
	for(const auto& elem : longPath){
		std::cout << elem.first.first << " " << elem.first.second << " = " << elem.second << std::endl;
	}
	//renderStrings(longPath);
	buildRoads(longPath);
}

template <typename T>
void Graph<T>::checkFile(){
	m_file.open(m_filePath);
	if(!m_file){
		std::cerr << "Can't open the file" << std::endl;
		std::exit(0);
	}
}

template <typename T>
std::pair<T, T> Graph<T>::ReadFile(){
	valueType temp1{0};
	valueType temp2{0};
	std::string lineExpr;
	std::getline(m_file, lineExpr);
	std::istringstream lStream(lineExpr);
	std::string cur = "0";
	
	lStream >> cur;
	int curVal1 = std::stoi(cur);
	temp1 = curVal1;
	
	lStream >> cur;
	int curVal2 = std::stoi(cur);
	temp2 = curVal2;
	
	return std::make_pair(temp1, temp2);
}

template <typename T>
void Graph<T>::Render() noexcept{
	std::string curExpr;
	checkFile();
	while(!m_file.eof()){
		std::pair<valueType, valueType> curPair = ReadFile();
		if(!m_file.eof()){
			m_graphVec.push_back(curPair);
		}
		//std::cout << "Readed ! ! !" << std::endl;
	}
	checkSimplicity();
	std::cout << "__ VECTOR __" << std::endl;
	for(const auto& elem : m_graphVec){
		std::cout << elem.first << " " << elem.second << std::endl;
	}
	//std::cout << "Vector has successfuly created" << std::endl;
	SepRepeaters();
}

template <typename T>
Graph<T>::~Graph(){}

#endif // __GRAPH__IMPL__HPP__
