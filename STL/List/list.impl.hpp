#include <cassert>

// ITERATOR
template <typename T>
List<T>::Iterator::Iterator(typename List<T>::Node* _node) : m_node{_node}
{}

template <typename T>
List<T>::Iterator::Iterator(const Iterator& iter) : m_node{iter.m_node}
{}

template <typename T>
typename List<T>::Iterator& List<T>::Iterator::operator=(const Iterator &iter){
	m_node = iter.m_node;
	return m_node;
}

template <typename T>
T& List<T>::Iterator::operator*(){
	return m_node->value;
}

template <typename T>
const T& List<T>::Iterator::operator*() const {
	assert(m_node);
	return m_node->value;
}

template <typename T>
typename List<T>::Iterator& List<T>::Iterator::operator++(){
	m_node = m_node->next;
	return *this;
}

template <typename T>
typename List<T>::Iterator& List<T>::Iterator::operator--(){
	m_node = m_node->prev;
	return *this;
}

template <typename T>
bool List<T>::Iterator::operator==(const Iterator& iter) const {
	return m_node == iter.m_node;
}

template <typename T>
bool List<T>::Iterator::operator!=(const Iterator& iter) const {
	return m_node != iter.m_node;
}

template <typename T>
typename List<T>::Iterator List<T>::begin(){
	return Iterator{m_head};
}

template <typename T>
typename List<T>::Iterator List<T>::end(){
	return Iterator{m_dummy};
}

template <typename T>
void List<T>::Push_back(const T& val){
	Node* cur = new Node(val);
	if(Empty()){
		assert(m_head == m_dummy && m_tail == m_dummy);
		++m_size;
		m_head = m_tail = cur;
		m_tail->next = m_dummy;
		return;
	}
	assert(m_head != m_dummy && m_tail != m_dummy);
	++m_size;
	m_tail->next = cur;
	cur->prev = m_tail;
	m_tail = m_tail->next;
	m_tail->next = m_dummy;
}

template <typename T>
void List<T>::Push_front(const T& val){
	Node* cur = new Node(val);
	if(Empty()){
		assert(m_head == m_dummy && m_tail == m_dummy);
		++m_size;
		m_head = m_tail = cur;
		m_tail = m_dummy;
		return;
	}
	assert(m_head != m_dummy && m_tail != m_dummy);
	++m_size;
	m_head->prev = cur;
	cur->next = m_head;
	m_head = cur;
	m_head->prev = m_dummy;
}

template <typename T>
void List<T>::Pop_back(){
	if(Empty()){
		return;
	}
	m_tail->prev->next = m_dummy;
	m_tail = m_tail->prev;
	--m_size;
}

template <typename T>
bool List<T>::Empty() const noexcept {
	return Size() == 0; 
}

template <typename T>
size_t List<T>::Size() const noexcept {
	return m_size;
}

template <typename T>
const T& List<T>::First() const noexcept {
	return m_head->value;
}

template <typename T>
const T& List<T>::Back() const noexcept {
	return m_tail->value;
}

template <typename T>
void List<T>::Clear(){
	while(m_head){
		Node* cur = m_head;
		m_head = m_head->next;
		delete cur;
	}
	m_tail = nullptr;
	m_size = 0;
}

// COPY AND MOVE SEMANTICS
template <typename T>
List<T>::List(const List& rhs){
	Node* cur = rhs.m_head;
	if(cur){
		Push_back(cur->value);
		cur = cur->next;
	}
	assert(m_tail);
	while(cur){
		m_tail->next = new Node(cur->value);
		m_tail->next->prev = m_tail;
		m_tail = m_tail->next;
		cur = cur->next;
	}
}

template <typename T>
List<T>& List<T>::operator=(List rhs){
	using std::swap;
	//copy and swap idiom
	swap(*this, rhs);
	return *this;
}

template <typename T>
List<T>::List(List&& rhs) noexcept {
	m_head = rhs.m_head;
	m_tail = rhs.m_tail;
	rhs.m_head = rhs.m_tail = nullptr;
}

template <typename T>
List<T>& List<T>::operator=(List&& rhs) noexcept {
	List cur = std::move(rhs);
	swap(*this, cur);
	return *this;
}

template <typename T>
List<T>::~List(){
	Clear();
}
