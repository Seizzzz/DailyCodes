#pragma once
#include <cstdlib>

template<typename T> class quickSort
{
public:
	T* R;
	int size;
	long long mvtimes = 0, cmptimes = 0;

	void sort_rec(int l, int r) {
		if (l < r) { 
			++cmptimes;//比较
			int i = l, j = r, mid = R[l + (rand() % (r - l + 1))];
			while (i < j) { 
				++cmptimes;//比较
				while (i < j && R[j] >= mid) {
					cmptimes += 2;//比较
					--j;
				}
				if (i < j) {
					++cmptimes;//比较
					R[i++] = R[j]; ++mvtimes; //腾挪
				}
				while (i < j && R[i] < mid) {
					cmptimes += 2;//比较
					++i;
				}
				if (i < j) {
					++cmptimes;//比较
					R[j--] = R[i]; ++mvtimes; //腾挪
				}
			}
			R[i] = mid;
			sort_rec(l, i - 1);
			sort_rec(i + 1, r);
		}
	}

	quickSort(T* r, int n) : R(r), size(n) {
		sort_rec(0, size - 1);
	};
};