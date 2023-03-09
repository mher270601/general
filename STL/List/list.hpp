#include <cassert>

namespace DataStructure{
	template <typename T>
	class List{
		public:
			List() =default;
			
			class Iterator{
				public:
					// Member types
					
					using value_type = T;
					using pointer = T*;
					using reference = T&;

					Iterator(const Iterator&); // Copy init.
					Iterator& operator=(const Iterator&); // Copy assigne

					T& operator*();
					const T& operator*() const;
					Iterator& operator++();
					Iterator& operator--();

					bool operator==(const Iterator&) const;
					bool operator!=(const Iterator&) const;
				private:
					Iterator(typename List<T>::Node*);
				private:
					typename List<T>::Node* m_node{nullptr};
					friend class List;
			}; // class Iterator

			// rule of five
			~List();
			List(const List&);
			List& operator=(List); // copy-assign

			List(List&&) noexcept; // move-init
			List& operator=(List&&) noexcept; // move-assign
			
			void Clear();

			Iterator begin();
			Iterator end();

			void Push_back(const T&);
			void Push_front(const T&);
			void Pop_back();
			const T& First() const noexcept;
			const T& Back() const noexcept;
			bool Empty() const noexcept;
			size_t Size() const noexcept;
		private:
			struct Node{
				Node* next{nullptr};
				Node* prev{nullptr};
				T value;
				Node(const T& v) : value{v}
				{};
				Node() =default;
			};
			Node* m_dummy = new Node;
			Node* m_head = m_dummy;
			Node* m_tail = m_dummy;
			size_t m_size{0};
	}; // class List
	#include "list.impl.hpp"
} // DataStructue
