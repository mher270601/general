#ifndef PRIORITY_QUEUE_HPP
#define PRIORITY_QUEUE_HPP

#include <vector>
#include <functional>

namespace Priority_Queue{
	using size = size_t;
	template <typename T, typename TContainer = std::vector<T>, typename C = std::less<T>>
	class PriorityQueue{
		public:
			PriorityQueue();
			PriorityQueue(TContainer& arr);
			~PriorityQueue();
			T Top();
			bool Empty();
			size Size();
			void Push(const T& value);
			void Pop();
			void PrintContainer();
		private:
			C cmp;
			size m_size = 0;
			//size m_capacity = 0;
			TContainer m_arr;
			void CopyInit(TContainer& arr);
			void Build(TContainer& arr);
			void Heapify(size Indx);
			//void ReAlloc(size newCapacity);
	}; // PQ Class
} // PQ Namespace

namespace {
	using PQ_Size = Priority_Queue::size;
	inline PQ_Size parent(PQ_Size Indx){
		return (Indx >> 1);
	}
	inline PQ_Size left(PQ_Size Indx){
		return (Indx << 1) + 1;
	}
	inline PQ_Size right(PQ_Size Indx){
		return ((Indx << 1) + 2);
	}
}  // Anonymous namespace for parent, left, right

#include "priority_queue.impl.hpp"

#endif // PRIORITY_QUEUE_HPP
