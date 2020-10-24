#pragma once
#include <iostream>
using namespace std;

template<typename T> class mergeSort
{
public:
	T* R;
	int size;

	T* tmp;
	int num = 0;
	long long mvtimes = 0, cmptimes = 0;

	void merge_rec(int l, int m, int r) {
		int i = l, j = m + 1, n = 0, len = r - l;

		while (i <= m && j <= r) {
			cmptimes += 2; //�Ƚ�
			if (R[i] > R[j]) {
				++cmptimes; //�Ƚ�
				tmp[n++] = R[j++]; ++mvtimes; //��Ų
				num += m - i + 1;
			}
			else {
				tmp[n++] = R[i++]; ++mvtimes; //��Ų
			}
		}

		if (i > m) {
			++cmptimes; //�Ƚ�
			while (j <= r) {
				++cmptimes; //�Ƚ�
				tmp[n++] = R[j++]; ++mvtimes; //��Ų
			}
		}
		else {
			while (i <= m) {
				++cmptimes; //�Ƚ�
				tmp[n++] = R[i++]; ++mvtimes; //��Ų
			}
		}

		for (int k = 0; k <= len; ++k) {
			R[l + k] = tmp[k]; ++mvtimes; //��Ų
		}
	}

	void sort_rec(int l, int r) {
		if (l < r) {
			++cmptimes; //�Ƚ�
			int m = (l + r) / 2;
			sort_rec(l, m);
			sort_rec(m + 1, r);
			merge_rec(l, m, r);
		}
	}

	void sort(int l, int r) {
		int l1, r1, l2, r2;
		for (int step = 1; step < size; step = step * 2) {
			for (l1 = 0; l1 < size - step; l1 = r2) {
				l2 = r1 = l1 + step;
				r2 = r1 + step;

				if (r2 > size) {
					++cmptimes; //�Ƚ�
					r2 = size;
				}
				int next = 0;

				while (l1 < r1 && l2 < r2) {
					cmptimes += 2; //�Ƚ�
					if (R[l1] < R[l2]) {
						++cmptimes; //�Ƚ�
						tmp[next++] = R[l1++]; ++mvtimes; //��Ų
					}
					else {
						tmp[next++] = R[l2++]; ++mvtimes; //��Ų
					}
				}
				while (l1 < r1) {
					++cmptimes; //�Ƚ�
					R[--l2] = R[--r1]; ++mvtimes; //��Ų
				}
				while (next > 0) {
					++cmptimes; //�Ƚ�
					R[--l2] = tmp[--next]; ++mvtimes; //��Ų
				}
			}
		}
	}

	mergeSort(T* r, int n) : R(r), size(n) {
		tmp = new T[size];
		sort_rec(0, size - 1);
	};
	~mergeSort() {
		delete[] tmp;
	}
};