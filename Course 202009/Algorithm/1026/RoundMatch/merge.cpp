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

    for (int i = 0; i < mid; ++i) //用于填补右侧
    {
        temp[i] = mid + i;
        temp[mid + i] = temp[i];
    }

    for (int i = 0; i < mid; ++i)
    {
        for (int j = 0; j <= mid; ++j)
        {
            if (table[i][j] >= mid)
            {
                table[i][j] = temp[i]; //vital
                table[i + mid][j] = (temp[i] + mid) % n;
            }
            else table[i + mid][j] = table[i][j] + mid;
        }

        for (int j = 1; j < mid; ++j)
        {
            table[i][j + mid] = temp[i + j];
            table[temp[i + j]][j + mid] = i;
        }
    }
}

MergeMethod::MergeMethod(int n): num(n)
{
    table = new int* [n + 1];
    for (int i = 0; i < n + 1; ++i) table[i] = new int[n + 1];
    temp = new int[n];

    divide(n);
}
