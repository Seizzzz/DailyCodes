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
			++cmptimes;//�Ƚ�
			int i = l, j = r, mid = R[l + (rand() % (r - l + 1))];
			while (i < j) { 
				++cmptimes;//�Ƚ�
				while (i < j && R[j] >= mid) {
					cmptimes += 2;//�Ƚ�
					--j;
				}
				if (i < j) {
					++cmptimes;//�Ƚ�
					R[i++] = R[j]; ++mvtimes; //��Ų
				}
				while (i < j && R[i] < mid) {
					cmptimes += 2;//�Ƚ�
					++i;
				}
				if (i < j) {
					++cmptimes;//�Ƚ�
					R[j--] = R[i]; ++mvtimes; //��Ų
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