#ifndef __GRAPH__HPP__
#define __GRAPH__HPP__

#include <iostream>
#include <vector>
#include <utility>
#include <cassert>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <fstream>
// PRECONDITION: The initial vertices of the graph pairs must be sorted
template<typename T>
class Graph{
	public:
		class Iterator{
			public:
				// Member types
				using value_type = T;
				using pointer = T*;
				using const_pointer = const T*;
				using reference = T&;
				using const_reference = const T&;
				using iterator = std::bidirectional_iterator_tag;
				
				// Copyable and Assignable
				Iterator(const Iterator&);
				Iterator& operator=(const Iterator&);

				//T& operator*();
				const T& operator*() const;
				Iterator& operator++();
				Iterator& operator--();

				bool operator!=(const Iterator&) const;
				bool operator==(const Iterator&) const;
				~Iterator() =default;
				Iterator(const Graph<T>* graph, int indx);
			private:
				const Graph<T>* m_graph;
				int m_indx{-1};
				// hidden friend idiom
				friend Iterator operator++(Graph<T>::Iterator& it, int){
					Iterator curIt = it;
					++it;
					return curIt;
				}

		}; // class Iterator
		
		Iterator begin() const;
		Iterator end() const;

		Graph(const std::vector<std::pair<T, T>> PairsVector) : m_graphVec(PairsVector){};
		const T& operator[](int indx) const;
		
		// RULE OF FIVE
		~Graph() =default;
		// value semantics
		Graph(const Graph&); // copy-init
		Graph& operator=(Graph&); // copy-assign

		// move semantics
		Graph(Graph&&) noexcept; // move init
		Graph& operator=(const Graph&&) noexcept; // move assign

		//~Graph() =default;
		size_t MaxPath() const noexcept;
		void Render() noexcept;
	private:
		using valueType = T;
		using vecType = std::vector<std::pair<valueType, valueType>>;
		using repType = std::vector<std::pair<std::pair<valueType, valueType>, valueType>>; // make structure-binding
	
		vecType m_graphVec;
		vecType m_unRepeated;
		vecType m_repeated;
	
		std::string m_filePath;
		std::ifstream m_file;
		std::vector<std::vector<valueType>> roads;
		repType m_repeats; 
		size_t maximumPath{0};
	private: // HELPERS
		void CheckSimplicity();
		void Reverse(std::vector<std::vector<valueType>>& _roads);
		void BuildRoads(repType longPath);
		void RenderStrings(repType& longPaths);
		size_t CurrentCount(valueType numb, size_t count = 0);
		void FilterRepeats();
		void FilterRoads();
		void SepRepeaters();
};  // class Graph

#include "graph.impl.hpp"

#endif // __GRAPH__HPP__
