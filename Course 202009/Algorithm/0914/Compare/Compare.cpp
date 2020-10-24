#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int algo1(const int A[], int N)
{
    int ThisSum, MaxSum, i, j, k;
    /* 1*/ MaxSum = 0; /* initialize the maximum sum */
    /* 2*/ for (i = 0; i < N; i++) /* start from A[ i ] */
        /* 3*/ for (j = i; j < N; j++) { /* end at A[ j ] */
            /* 4*/ ThisSum = 0;
            /* 5*/ for (k = i; k <= j; k++)
                /* 6*/ ThisSum += A[k]; /* sum from A[ i ] to A[ j ] */
            /* 7*/ if (ThisSum > MaxSum)
                /* 8*/ MaxSum = ThisSum; /* update max sum */
        } /* end for-j and for-i */
    /* 9*/ return MaxSum;
}

int algo2(const int A[], int N)
{
    int ThisSum, MaxSum, i, j;
    /* 1*/ MaxSum = 0; /* initialize the maximum sum */
    /* 2*/ for (i = 0; i < N; i++) { /* start from A[ i ] */
        /* 3*/ ThisSum = 0;
        /* 4*/ for (j = i; j < N; j++) { /* end at A[ j ] */
            /* 5*/ ThisSum += A[j]; /* sum from A[ i ] to A[ j ] */
            /* 6*/ if (ThisSum > MaxSum)
                /* 7*/ MaxSum = ThisSum; /* update max sum */
        } /* end for-j */
    } /* end for-i */
    /* 8*/ return MaxSum;
}

int algo4(const int A[], int N)
{
    int ThisSum, MaxSum, j;
    /* 1*/ ThisSum = MaxSum = 0;
    /* 2*/ for (j = 0; j < N; j++) {
        /* 3*/ ThisSum += A[j];
        /* 4*/ if (ThisSum > MaxSum)
            /* 5*/ MaxSum = ThisSum;
        /* 6*/ else if (ThisSum < 0)
            /* 7*/ ThisSum = 0;
    } /* end for-j */
    /* 8*/ return MaxSum;
}

void genRandom(int* num, int n)
{
    srand(time(nullptr));
    for (int i = 0; i < n; ++i)
    {
        num[i] = rand() % 10;
    }
}

void test(int* num, int n)
{
    clock_t pt, nt;
    cout << "n = " << n << ":" << endl;

    if (n <= 3000)
    {
        pt = clock();
        algo1(num, n);
        nt = clock();
        cout << "ALGORITHM 1: " << nt - pt << " CLOCKS(" << (nt - pt) / CLOCKS_PER_SEC << " sec)" << endl;
    }

    if (n <= 50000)
    {
        pt = clock();
        algo2(num, n);
        nt = clock();;
        cout << "ALGORITHM 2: " << nt - pt << " CLOCKS(" << (nt - pt) / CLOCKS_PER_SEC << " sec)" << endl;
    }

    pt = clock();
    algo4(num, n);
    nt = clock();
    cout << "ALGORITHM 4: " << nt - pt << " CLOCKS(" << (nt - pt) / CLOCKS_PER_SEC << " sec)" << endl;

    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    
    int* num = new int[10000000];
    genRandom(num, 10000000);

    test(num, 10);
    test(num, 100);
    test(num, 500);
    test(num, 1000);
    test(num, 3000);
    test(num, 5000);
    test(num, 10000);
    test(num, 30000);
    test(num, 50000);
    test(num, 100000);
    test(num, 200000);
    test(num, 300000);
    test(num, 500000);
    test(num, 800000);
    test(num, 1000000);
    test(num, 3000000);
    test(num, 5000000);
    test(num, 8000000);
    test(num, 10000000);

    delete[] num;
}