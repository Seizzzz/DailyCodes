#include <iostream>
#include <fstream>
#include <ctime>
#include "insertsort.h"
#include "mergesort.h"
#include "quicksort.h"
using namespace std;

void genRandom(int* num, int n)
{
    srand((unsigned int)time(nullptr));
    for (int i = 0; i < n; ++i)
    {
        num[i] = rand() % 10;
    }
}

void genRandom2File(int n, const char* s)
{
    ofstream _out(s);
    if (!_out) {
        cout << "failed" << endl;
        return;
    }
    srand((unsigned int)time(nullptr));
    _out << n;
    for (int i = 0; i < n; ++i)
    {
        _out << " " << rand() % 1000;
    }
    _out.close();
}

void testQuick(const char* s)
{
    ifstream _in(s);
    if (!_in) return;
    int size;
    _in >> size;
    int* a = new int[size];
    for (int i = 0; i < size; ++i) _in >> a[i];
    time_t st = time(nullptr);
    quickSort<int> sol(a, size);
    time_t ed = time(nullptr);
    cout << "QucikSort(size:" << size << "):" << ed - st << "ms, " << sol.mvtimes << "moves, " << sol.cmptimes << "compares" << endl;
    _in.close();
    delete[] a;
}

void testMerge(const char* s)
{
    ifstream _in(s);
    if (!_in) return;
    int size;
    _in >> size;
    int* a = new int[size];
    for (int i = 0; i < size; ++i) _in >> a[i];
    time_t st = time(nullptr);
    mergeSort<int> sol(a, size);
    time_t ed = time(nullptr);
    cout << "MergeSort(size:" << size << "):" << ed - st << "ms, " << sol.mvtimes << "moves, " << sol.cmptimes << "compares" << endl;
    _in.close();
    delete[] a;
}

void testInsert(const char* s)
{
    ifstream _in(s);
    if (!_in) return;
    int size;
    _in >> size;
    int* a = new int[size];
    for (int i = 0; i < size; ++i) _in >> a[i];
    time_t st = time(nullptr);
    insertSort<int> sol(a, size);
    time_t ed = time(nullptr);
    cout << "insertSort(size:" << size << "):" << ed - st << "ms, " << sol.mvtimes << "moves, " << sol.cmptimes << "compares" << endl;
    _in.close();
    delete[] a;
}

int main()
{
    ios::sync_with_stdio(false);
    
    genRandom2File(10000, "./test/black10000.txt");
    
    return 0;
}