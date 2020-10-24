#pragma once
#include <iostream>
using namespace std;

template<typename T> class insertSort
{
public:
    T* R;
    int size;
	long long mvtimes = 0, cmptimes = 0;

    void sort() {
		for (int i = 1; i < size; ++i)
		{
			T last = R[i];
			int j = i - 1;
			while ((j >= 0) && (R[j] > last)) {
				cmptimes += 2;//±È½Ï
				R[j + 1] = R[j]; ++mvtimes; //ÌÚÅ²
				--j;
			}
			R[j + 1] = last; ++mvtimes; //ÌÚÅ²
		}
    }
	insertSort(T* r, int n) : R(r), size(n) { sort(); };
};