//#include <utility>
#include <cassert>

template <typename T>
Containers::Vector<T>::Iterator::Iterator(const Iterator& rhs) : m_indx{rhs.m_indx}{}

template <typename T>
typename Containers::Vector<T>::Iterator& Containers::Vector<T>::Iterator::operator=(const Iterator& rhs){
	m_indx = rhs.m_indx;
	return *this;
}

template <typename T>
Containers::Vector<T>::Iterator::Iterator(Containers::Vector<T>* vector, const size_t indx) : m_indx{indx},
											      m_VecPtr{vector}{}


template <typename T>
inline const T& Containers::Vector<T>::Iterator::operator*() const{
	return m_VecPtr->operator[](m_indx);
}

template <typename T>
typename Containers::Vector<T>::Iterator& Containers::Vector<T>::Iterator::operator++(){
	++m_indx;
	return *this;
}

template <typename T>
typename Containers::Vector<T>::Iterator& Containers::Vector<T>::Iterator::operator--(){
	if(m_indx > 0){
		--m_indx;
	}
	return *this;
}

template <typename T>
bool Containers::Vector<T>::Iterator::operator==(const Iterator& rhs) const{
	return this->m_indx == rhs.m_indx;
}

template <typename T>
bool Containers::Vector<T>::Iterator::operator!=(const Iterator& rhs) const{
	return this->m_indx != rhs.m_indx;
}

template <typename T>
typename Containers::Vector<T>::Iterator Containers::Vector<T>::begin(){
	return Iterator(this, 0);
}

template <typename T>
typename Containers::Vector<T>::Iterator Containers::Vector<T>::end(){
	return Iterator(this, m_size);
}

template <typename T>
Containers::Vector<T>::Vector(){
	ReAlloc(2);
}

template <typename T>
void Containers::Vector<T>::Clear() noexcept{
	delete[] m_data;
	m_data = nullptr;
	m_size = 0;
}

template <typename T>
void Containers::Vector<T>::Swap(Vector& vec){
	m_data ^= vec;
	vec ^= m_data;
	m_data ^= vec;
}

template <typename T>
void Containers::Vector<T>::ReAlloc(const size_t& newCapacity){
	if(m_size > newCapacity){
		m_size = newCapacity;
	}
	T* newBlock = new T[newCapacity];
	for(size_t i = 0; i < m_size; ++i){
		newBlock[i] = m_data[i];
	}
	delete[] m_data;
	m_data = newBlock;
	m_capacity = newCapacity;
}

template <typename T>
T& Containers::Vector<T>::operator[](const size_t& indx){
	if(m_size < indx && indx < 0){
		assert(false && "Index is out of range");
	}
	return m_data[indx];
}

template <typename T>
inline T& Containers::Vector<T>::Iterator::operator*(){
	return m_VecPtr->operator[](m_indx);
}

template <typename T>
const T& Containers::Vector<T>::operator[](const size_t& indx) const{
	if(m_size < indx && indx < 0){
		assert(false && "Index is out of range");
	}
	return m_data[indx];
}

template <typename T>
void Containers::Vector<T>::Push_back(const size_t& value){
	if(m_size == m_capacity){
		ReAlloc(2 * m_capacity);
	}
	m_data[m_size++] = value;
}

template <typename T>
void Containers::Vector<T>::Pop_back(){
	if(m_size > 0){
		T* newBlock = new T[--m_size];
		for(size_t i = 0; i < m_size; ++i){
			newBlock[i] = m_data[i];
		}
		delete[] m_data;
		m_data = newBlock;
		--m_capacity;
	}
	else{
		Clear();
	}
}

template <typename T>
size_t Containers::Vector<T>::Size() const noexcept{
	return m_size;
}

template <typename T>
size_t Containers::Vector<T>::Capacity() const noexcept{
	return m_capacity;
}

template <typename T>
bool Containers::Vector<T>::Empty() const noexcept{
	return m_size == 0;
}

// COPY AND MOVE SEMANTICS
template <typename T> // Copy-init
Containers::Vector<T>::Vector(const Vector& rhs){
	delete[] m_data;
	m_data = nullptr;
	m_data = new T[rhs.Capacity()];
	for(size_t i = 0; i < rhs.Size(); ++i){
		m_data[i] = rhs[i];
	}
	m_size = rhs.Size();
	m_capacity = rhs.Capacity();
}

template <typename T> // Copy-assign
typename Containers::Vector<T>& Containers::Vector<T>::operator=(const Vector& rhs){
	using std::swap;
	swap(*this, rhs);
	return *this;
}

template <typename T> // Move-init
Containers::Vector<T>::Vector(Vector&& rhs) noexcept{
	*this = std::move(rhs);
}

template <typename T> // Move-assign
typename Containers::Vector<T>& Containers::Vector<T>::operator=(Vector&& rhs) noexcept{
	Vector tempOb = std::move(rhs);
	std::swap(*this, tempOb);
	return *this;
}

//template <typename T> // Copy-assign
//Vector& Containers::Vector<T>::operator=(Vector& rhs){
//	// Copy and swap idiom
//	swap(*this, rhs);
//	return *this;
//}
//
//template <typename T>
//Containers::Vector<T>::Vector(const Vector&& rhs) noexcept{
//	m_data = std::move(rhs.m_data);
//	m_size = std::move(rhs.size);
//	m_capacity = std::move(rhs.m_capacity);
//}

template <typename T>
Containers::Vector<T>::~Vector(){
	Clear();	
}
