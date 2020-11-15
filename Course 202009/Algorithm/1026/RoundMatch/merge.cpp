#include "merge.h"

void MergeMethod::output()
{
    int n = (num % 2) ? num + 1 : num;
	for (int i = 0; i < num; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
            if (table[i][j] == num) cout << "- ";
            else cout << table[i][j] + 1 << " ";
		}
		cout << endl;
	}
}

void MergeMethod::divide(int n)
{
    if (n == 2) //最小子问题 只有两个人时
    {
        table[0][0] = 0;
        copy(2);
        return;
    }

    if (n % 2) //将所有的奇数问题转换为偶数问题
    {
        divide(n + 1); 
        return;
    }
    else
    {
        divide(n / 2);
        if ((n / 2) % 2) generate(n); 
        else copy(n);
    }
}

void MergeMethod::copy(int n)
{
    int mid = n / 2;
    
    for (int i = 0; i < mid; ++i)
    {
        for (int j = 0; j < mid; ++j)
        {
            table[i + mid][j + mid] = table[i][j]; //将左上角复制到右下角
            table[i][j + mid] = table[i][j] + mid; //将左上角加mid后复制到左下角
            table[i + mid][j] = table[i][j + mid]; //将左上角加mid后复制到右上角
        }
    }
}

void MergeMethod::generate(int n)
{
    int mid = n / 2;

    for (int i = 0; i < mid; ++i)
    {
        for (int j = 0; j <= mid; ++j)
        {
            if (table[i][j] >= mid) //对于左上块不小于mid的数 若此时+n/2向下复制时会超出范围 因而需要额外处理
            {
                table[i][j] = mid + i; //vital
                table[i + mid][j] = (mid + mid + i) % n;
            }
            else table[i + mid][j] = table[i][j] + mid;
        }
    }

    for (int i = 0; i < mid; ++i)
    {
        for (int j = 1; j < mid; ++j) //对右侧进行填补
        {
            int k = mid + (i + j) % mid; //对手
            table[i][j + mid] = k;
            table[k][j + mid] = i;
        }
    }
}

MergeMethod::MergeMethod(int n): num(n)
{
    table = new int* [n + 1];
    for (int i = 0; i < n + 1; ++i) table[i] = new int[n + 1];

    divide(n);
}

MergeMethod::~MergeMethod()
{
    for (int i = 0; i < num + 1; ++i) delete[] table[i];
    delete[] table;
}
