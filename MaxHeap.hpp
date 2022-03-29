#ifndef MAXHEAP_HPP
#define MAXHEAP_HPP

#include <cassert>
#include <iostream>

using size = size_t;
namespace Heap{
	template <typename T>
	class MaxHeap{
		public:
			MaxHeap(T* arr, size arrSize);
			size Size();
			void Swap(T a, T b);
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
		return ((Indx << 1)+1);
	}
}

template <typename T>
void Heap::MaxHeap<T>::Swap(T x, T y){
	x ^= y;
	y ^= x;
	x ^= y;
}
template <typename T>
Heap::MaxHeap<T> MaxHeap(T* arr, size arrSize){
	Copy(arr, arrSize);
	Build(arrSize); // 38
}
template <typename T>
void Heap::MaxHeap<T>::Copy(T* arr, size arrSize){
	m_size = arrSize;
	m_arr = new T[m_size];
	for(size i = 0; i < m_size; ++i){
		m_arr[i] = arr[i];
	}
}
template <typename T>
void Heap::MaxHeap<T>::Build(size arrSize){
	m_size = arrSize;
	for(size_t i = m_size >> 1; i > 0; --i){
		Heapify(i);
	}
}
template <typename T>
void Heap::MaxHeap<T>::Heapify(size Indx){
	size l = left(Indx);
	size r = right(Indx);
	size max = Indx;

	if((l < m_size) && (m_arr[l] > m_arr[Indx])){
		max = l;
	}
	if((r < m_size) && (m_arr[r] > m_arr[max])){
		max = r;
	}
	if(max != Indx){
		Swap(m_arr[Indx], m_arr[max]);
		Heapify(max);
	}
}
template <typename T>
size Heap::MaxHeap<T>::Size(){
	return m_size;
}
#endif // MAXHEAP_HPP
