#include <cassert>
#include <functional>

template <typename T, typename TContainer = std::vector<T>, typename C = std::less<T>>
Priority_Queue::PriorityQueue<T>::PriorityQueue(/* T arr[], PQ_Size arrSize */){
	//ReAlloc(1);
	//CopyInit(arr, arrSize);
	
	Build(arrSize);
}
template <typename T, typename TContainer = std::vector<T>, typename C = std::less<T>>
Priority_Queue::PriorityQueue<T>::~PriorityQueue(){
	m_arr.clear();
	//m_arr.size() = 0;
}
template <typename T, typename TContainer = std::vector<T>, typename C = std::less<T>>
void Priority_Queue::PriorityQueue<T>::CopyInit(const TContainer& arr){
	for(int i = 0; i < m_arr.size(); ++i){
		m_arr[i] = arr[i];
	}
}
template <typename T, typename TContainer = std::vector<T>, typename C = std::less<T>>
void Priority_Queue::PriorityQueue<T>::Build(/* PQ_Size arrSize */){
	//m_arr.size() = arrSize;
	for(int i = m_arr.size() >> 1; i >= 0; --i){
		Heapify(i);
	}
}
template <typename T, typename TContainer = std::vector<T>, typename C = std::less<T>>
void Priority_Queue::PriorityQueue<T>::Heapify(PQ_Size Indx){
		// Recursive version
	const PQ_Size l = left(Indx+1)-1;
	const PQ_Size r = right(Indx+1)-1;
	PQ_Size PQueue = Indx;

	if((l < m_arr.size()) && (m_arr[l] < m_arr[PQueue])){
		PQueue = l;
	}
	if((r < m_arr.size()) && (m_arr[r] < m_arr[PQueue])){
		PQueue = r;
	}
	if(PQueue != Indx){
		std::swap(m_arr[Indx], m_arr[PQueue]);
		Heapify(PQueue);
	}
}
template <typename T, typename TContainer = std::vector<T>, typename C = std::less<T>>
void Priority_Queue::PriorityQueue<T>::Push(const T& value){
	//T* newBlock = new T[++m_arr.size()];
	//for(PQ_Size i = 0; i < m_arr.size(); ++i){
	//	newBlock[i] = m_arr[i];
	//}
	//newBlock[m_arr.size()-1] = value;
	//delete[] m_arr;
	//m_arr = newBlock;
	C cmp = C{};

	m_arr.push_back(value);
	PQ_Size lastIndx = m_arr.size() - 1;
	if(cmp(1, m_arr.size()) && cmp(m_arr[lastIndx], m_arr[m_arr.size() >> 1])){
		for(int i = (m_arr.size() - 1) >> 1; i >= 0; i >> 1){
			Heapify(i);
		}
	}
}
template <typename T, typename TContainer = std::vector<T>, typename C = std::less<T>>
void Priority_Queue::PriorityQueue<T>::Pop(){
	if(m_arr.size() > 0){
		m_arr.pop_back();
	}
}
template <typename T, typename TContainer = std::vector<T>, typename C = std::less<T>>
T Priority_Queue::PriorityQueue<T>::Top(){
	return m_arr[0];
}
template <typename T, typename TContainer = std::vector<T>, typename C = std::less<T>>
bool Priority_Queue::PriorityQueue<T>::Empty(){
	return m_arr.size() == 0;
}
template <typename T, typename TContainer = std::vector<T>, typename C = std::less<T>>
PQ_Size Priority_Queue::PriorityQueue<T>::Size(){
	return m_arr.size();
}
//template <typename T>
//void Priority_Queue::PriorityQueue<T>::Push(const T& value){
//	
//}
