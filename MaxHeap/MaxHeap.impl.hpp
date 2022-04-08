template <typename T>
void Heap::MaxHeap<T>::Print(T* arr, size arrSize){
	std::cout << "Final condition = ";
	for(size i = 0; i < arrSize; ++i){
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
template <typename T>
Heap::MaxHeap<T>::MaxHeap(T arr[], size arrSize){
	Copy(arr, arrSize);
	//std::cout << "Unsorted" << std::endl;
	//Print();
	Build(arrSize); // 38
	//std::cout << "Sorted" << std::endl;
	//Print();
}
template <typename T>
void Heap::MaxHeap<T>::Copy(T arr[], size arrSize){
	m_size = arrSize;
	m_arr = new T[m_size];
	for(size i = 0; i < m_size; ++i){
		m_arr[i] = arr[i];
	}
}
template <typename T>
void Heap::MaxHeap<T>::Build(size arrSize){
	m_size = arrSize;
	for(int i = m_size >> 1; i >= 0; --i){
		Heapify(i);
	}
}
template <typename T>
void Heap::MaxHeap<T>::Heapify(size Indx){
		// Recursive version
		
	const size l = left(Indx+1)-1;
	const size r = right(Indx+1)-1;
	size max = Indx;

	if((l < m_size) && (m_arr[l] > m_arr[max])){
		max = l;
	}
	if((r < m_size) && (m_arr[r] > m_arr[max])){
		max = r;
	}
	if(max != Indx){
		std::swap(m_arr[Indx], m_arr[max]);
		Heapify(max);
	}

		// Iterative version
	
	//for(int i = m_size << 1; i >= 0; --i){
	//	const size l = left(Indx+1)-1;
	//	const size r = right(Indx+1)-1;
	//	size max = Indx;

	//	if((l < m_size) && (m_arr[l] > m_arr[max])){
	//		max = l;
	//	}
	//	if((r < m_size) && (m_arr[r] > m_arr[max])){
	//		max = r;
	//	}
	//	if(max != Indx){
	//		std::swap(m_arr[Indx], m_arr[max]);
	//		Heapify(max);
	//	}
	//}
}
template <typename T>
void Heap::MaxHeap<T>::Insert(T value)
{
	T* newArr = new T[++m_size];
	for(size i = 0; i < m_size-1; ++i){
		newArr[i] = m_arr[i];
	}
	newArr[m_size-1] = value;
	delete[] m_arr;
	m_arr = newArr;
	size lastIndx = m_size - 1;
	if(m_arr[lastIndx] > m_arr[m_size >> 1]){
		for(int i = (m_size - 1) >> 1; i >= 0; i >> 1){
			Heapify(i);
		}
	}	
}
template <typename T>
T Heap::MaxHeap<T>::Extract(){
	std::swap(m_arr[0], m_arr[--m_size]);
	m_size > 1 ? : Heapify(0);
	return m_arr[m_size];
}
template <typename T>
void HeapSort(T* arr, size arrSize){
	Heap::MaxHeap<T> ob(arr, arrSize);
	ob.Sort(arr, arrSize);
	ob.Print(arr, arrSize);
}
template <typename T>
void Heap::MaxHeap<T>::Sort(T* arr, size arrSize){
	for(size i = 0; i < arrSize; ++i){
		std::swap(m_arr[0], m_arr[--m_size]);
		arr[arrSize-i-1] = m_arr[m_size];
		Heapify(0);
	}
}
template <typename T>
size Heap::MaxHeap<T>::Size(){
	return m_size;
}
