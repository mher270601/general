#include <cassert>
#include <functional>
#include <iostream>
#include <thread>

template <typename T, typename TContainer , typename C >
void Priority_Queue::PriorityQueue<T, TContainer, C>::CopyInit(TContainer& arr){
	std::cout << __func__ << std::endl;
	for(int i = 0; i < m_arr.size(); ++i){
		m_arr.push_back(arr[i]);
	}
}
template <typename T, typename TContainer , typename C >
void Priority_Queue::PriorityQueue<T, TContainer, C>::Build(TContainer& arr){
	//m_arr.size() = arrSize;
	CopyInit();
	std::cout << __func__ << std::endl;
	for(int i = m_arr.size() >> 1; i >= 0; --i){
		Heapify(i);
	}
}
template <typename T, typename TContainer , typename C >
void Priority_Queue::PriorityQueue<T, TContainer, C>::Heapify(PQ_Size Indx){
		// Recursive version
	std::cout << __func__ << " " << Indx << std::endl;
	const PQ_Size l = left(Indx);
	const PQ_Size r = right(Indx);
	PQ_Size PQueue = Indx;

	if(l < m_arr.size() && cmp(m_arr[l], m_arr[PQueue])){
		PQueue = l;
	}
	if(r < m_arr.size() && cmp(m_arr[r], m_arr[PQueue])){
		PQueue = r;
	}
	if(PQueue != Indx){
		std::swap(m_arr[Indx], m_arr[PQueue]);
		Heapify(PQueue);
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
}
template <typename T, typename TContainer , typename C >
void Priority_Queue::PriorityQueue<T, TContainer, C>::Push(const T& value){
	//T* newBlock = new T[++m_arr.size()];
	//for(PQ_Size i = 0; i < m_arr.size(); ++i){
	//	newBlock[i] = m_arr[i];
	//}
	//newBlock[m_arr.size()-1] = value;
	//delete[] m_arr;
	//m_arr = newBlock;
	std::cout << __func__ << " For " << value << std::endl;
	//C cmp = C{};

	m_arr.push_back(value);
	PQ_Size lastIndx = m_arr.size() - 1;
	if(/* cmp(1, m_arr.size()) && */ cmp(m_arr[lastIndx], m_arr[(lastIndx - 1) >> 1])){
		for(int i = (lastIndx - 1) >> 1; i > 0; i = (i - 1 ) >> 1){
			Heapify(i);
		}
	}
}
template <typename T, typename TContainer , typename C >
void Priority_Queue::PriorityQueue<T, TContainer, C>::Pop(){
	std::cout << __func__ << std::endl;
	if(m_arr.size() > 0){
		m_arr.pop_back();
	}
}
template <typename T, typename TContainer , typename C >
T Priority_Queue::PriorityQueue<T, TContainer, C>::Top(){
	std::cout << __func__ << std::endl;
	return m_arr[0];
}
template <typename T, typename TContainer , typename C >
bool Priority_Queue::PriorityQueue<T, TContainer, C>::Empty(){
	std::cout << __func__ << std::endl;
	return m_arr.size() == 0;
}
template <typename T, typename TContainer , typename C >
PQ_Size Priority_Queue::PriorityQueue<T, TContainer, C>::Size(){
	std::cout << __func__ << std::endl;
	return m_arr.size();
}
template <typename T, typename TContainer , typename C >
Priority_Queue::PriorityQueue<T, TContainer, C>::PriorityQueue(/* T arr[], PQ_Size arrSize */){
	//ReAlloc(1);
	//CopyInit(m_arr);
	std::cout << __func__ << std::endl;
}
template <typename T, typename TContainer , typename C >
Priority_Queue::PriorityQueue<T, TContainer, C>::~PriorityQueue(){
	//m_arr.clear();
	std::cout << __func__ << std::endl;
	TContainer{}.swap(m_arr);
	//m_arr.size() = 0;
}
template <typename T, typename TContainer, typename C >
Priority_Queue::PriorityQueue<T, TContainer, C>::PriorityQueue(TContainer& arr){
	std::cout << __func__ << std::endl;
	Build(arr);
}
template <typename T, typename TContainer, typename C >
void Priority_Queue::PriorityQueue<T, TContainer, C>::PrintContainer(){
	for(const auto elem : m_arr){
		std::cout << elem << " ";
	}
	std::cout << std::endl;
}
//template <typename T>
//void Priority_Queue::PriorityQueue<T>::Push(const T& value){
//	
//}
