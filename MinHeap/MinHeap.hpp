#ifndef MAXHEAP_HPP
#define MAXHEAP_HPP

#include <algorithm>
#include <cassert>
#include <iostream>

using size = size_t;
namespace Heap{
	template <typename T>
	class MinHeap{
		public:
			MinHeap(T* arr, size arrSize);
			size Size();
			//void Swap(T& a, T& b);
			void Print(T* arr, size arrSize);
			void Insert(T value);
			T Extract();
			void Sort(T* arr, size arrSize);
		private:
			size m_size = 0;
			T* m_arr = nullptr;
			void Copy(T* arr, size arrSize);
			void Build(size arrSize);
			void Heapify(size arrSize);
	};
}

namespace {
	inline size parent(size Indx){
		return (Indx >> 1);
	}
	inline size left(size Indx){
		return (Indx << 1);
	}
	inline size right(size Indx){
		return ((Indx << 1) + 1);
	}
}
#include "MinHeap.impl.hpp"
//template <typename T>
//void Heap::MinHeap<T>::Swap(T& x, T& y){
//	std::cout << "X = " << x << " Y = " << y << std::endl;
//	x ^= y;
//	y ^= x;
//	x ^= y;
//	std::cout << "X = " << x << " Y = " << y << std::endl;
//}
#endif // MAXHEAP_HPP
