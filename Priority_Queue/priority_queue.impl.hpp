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
	CopyInit(arr);
	std::cout << __func__ << std::endl;
	for(int i = m_arr.size() >> 1; i >= 0; --i){
		Heapify(i);
	}
}
template <typename T, typename TContainer , typename C >
void Priority_Queue::PriorityQueue<T, TContainer, C>::Heapify(PQ_Size Indx){
		// Recursive version
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
	m_arr.push_back(value);

	PQ_Size lastIndx = m_arr.size() - 1;
	if(/* cmp(1, m_arr.size()) && */ cmp(m_arr[lastIndx], m_arr[(m_arr.size() - 2) >> 1])){
		std::cout << m_arr[lastIndx] << " < " << m_arr[(m_arr.size() - 2) >> 1] << std::endl;
		do{
			lastIndx = (lastIndx-1) >> 1;
			Heapify(lastIndx);
		}while(lastIndx != 0 && cmp(m_arr[lastIndx], m_arr[(lastIndx - 1) >> 1]));
	}
	TContainer temp;
	//PQ_Size cur = 0;
	while(m_arr.size() != 0){
		//temp[cur] = m_arr[cur++];
		temp.push_back(m_arr[0]);
		std::swap(m_arr[0], m_arr[m_arr.size()-1]);
		m_arr.pop_back();
		for(int i = m_arr.size() - 1; i >= 0; --i){
			Heapify(i);
		}
	}
	for(const auto& elem : temp){
		m_arr.push_back(elem);
	}
	//m_arr = temp;
	//for(PQ_Size i = 0; i < m_arr.size(); ++i){
	//	
	//}
}
template <typename T, typename TContainer , typename C >
void Priority_Queue::PriorityQueue<T, TContainer, C>::Pop(){
	if(m_arr.size() > 0){
		m_arr.pop_back();
	}
}
template <typename T, typename TContainer , typename C >
T Priority_Queue::PriorityQueue<T, TContainer, C>::Top(){
	return m_arr[m_arr.size()-1];
}
template <typename T, typename TContainer , typename C >
bool Priority_Queue::PriorityQueue<T, TContainer, C>::Empty(){
	return m_arr.size() == 0;
}
template <typename T, typename TContainer , typename C >
PQ_Size Priority_Queue::PriorityQueue<T, TContainer, C>::Size(){
	return m_arr.size();
}
template <typename T, typename TContainer , typename C >
Priority_Queue::PriorityQueue<T, TContainer, C>::PriorityQueue(/* T arr[], PQ_Size arrSize */){
	//ReAlloc(1);
	//CopyInit(m_arr);
}
template <typename T, typename TContainer , typename C >
Priority_Queue::PriorityQueue<T, TContainer, C>::~PriorityQueue(){
	//m_arr.clear();
	TContainer{}.swap(m_arr);
	//m_arr.size() = 0;
}
template <typename T, typename TContainer, typename C >
Priority_Queue::PriorityQueue<T, TContainer, C>::PriorityQueue(TContainer& arr){
	Build(arr);
}
template <typename T, typename TContainer, typename C >
void Priority_Queue::PriorityQueue<T, TContainer, C>::PrintContainer(){
	for(const auto& elem : m_arr){
		std::cout << elem << " ";
	}
	std::cout << std::endl << m_arr.size() << std::endl;
}
//template <typename T>
//void Priority_Queue::PriorityQueue<T>::Push(const T& value){
//	
//}
