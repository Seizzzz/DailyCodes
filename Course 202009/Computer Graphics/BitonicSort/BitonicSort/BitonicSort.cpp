#include <iostream>
using namespace std;

void output(int a[], int N)
{
    for (int i = 0; i < N; i++)
        cout << a[i] << " ";
    cout << endl;
}

void bitonicSwap(int& a, int& b, bool& desc)
{
    if (desc == (a > b)) swap(a, b);
}

void bitonicMerge(int a[], int lb, int cnt, bool& desc)
{
    if (cnt < 2) return;
	
    int k = cnt / 2;
    for (int i = lb; i < lb + k; ++i)
    {
        cout << "check " << i << " " << i + k << endl;
        bitonicSwap(a[i], a[i + k], desc);
    }
	
    bitonicMerge(a, lb, k, desc);
    bitonicMerge(a, lb + k, k, desc);
}

void bitonicSort(int a[], int lb, int cnt, bool desc)
{
    if (cnt < 2) return;

    int k = cnt / 2;
    bitonicSort(a, lb, k, true);
    bitonicSort(a, lb + k, k, false);

    bitonicMerge(a, lb, cnt, desc);
}

int main()
{
    int a[] = { 25, 5, 31, 7, 36, 1, 18, 14 };
    int N = sizeof(a) / sizeof(a[0]);
    int up = 1;   // means sort in ascending order 
    bitonicSort(a, 0, N, true);

    output(a, N);

	
	return 0;
}