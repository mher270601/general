namespace Containers{
	template <typename T>
	class Vector{
		public:
			Vector();
			class Iterator{
			public:
				// MEMBER TYPES
				using value_type = T;
				using pointer = T*;
				using reference = T&;

				Iterator() = default;

				// Copy semantics
				Iterator(const Iterator&);
				Iterator& operator=(const Iterator&);

				T& operator*();
				const T& operator*() const;
				Iterator& operator++();
				Iterator& operator--();
				bool operator==(const Iterator&) const;
				bool operator!=(const Iterator&) const;

			private:
				Iterator(typename Containers::Vector<T>*, const size_t);
			private:
				size_t m_indx{0};
				Vector<T>* m_VecPtr{nullptr};
				friend class Vector;
			};
				
			Iterator begin();
			Iterator end();

			// Rule of five
			~Vector();
			// Copy semantics
			Vector(const Vector&); // Copy-init
			Vector& operator=(const Vector&); // Copy-assign
			// Move semantics
			Vector(Vector&&) noexcept; // Move-init
			Vector& operator=(Vector&&) noexcept; // Move-assign
			
			T& operator[](const size_t&);
			const T& operator[](const size_t&) const;

			void Clear() noexcept;
			void ReAlloc(const size_t&);
			void Swap(Vector&);
			void Push_back(const size_t&);
			void Pop_back();

			size_t Size() const noexcept;
			size_t Capacity() const noexcept;
			bool Empty() const noexcept;
		private:
			size_t m_size{0};
			size_t m_capacity{0};
			T* m_data{nullptr};
	};
	#include "vector.impl.hpp"
}
