#include <algorithm>
namespace Hybryd_QSort{
	template<typename T = int>
	int Partition(T& A, int p, int r){
		if(r-p <= 5){
			auto pivotIndx = rand() % (r-2) + p;
			std::swap(A[pivotIndx], A[r-1]);
		}
		auto pivot = A[r-1];
		int i = p;
		for(size_t j = p; j < r-1; ++j){ 
			if(A[j] <= pivot){
				std::swap(A[i++], A[j]);
			}
		}
		std::swap(A[i], A[r-1]);
		return i;
	}
	template<typename T = int>
	void QuickSort(T& A, int p, int r){
		if(p < r-1){
			int q = Partition<T>(A, p, r);
			QuickSort(A, p, q);
			QuickSort(A, q+1, r);
		}
	}
}
