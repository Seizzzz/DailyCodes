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
    if (n == 2) //��С������ ֻ��������ʱ
    {
        table[0][0] = 0;
        copy(2);
        return;
    }

    if (n % 2) //�����е���������ת��Ϊż������
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
            table[i + mid][j + mid] = table[i][j]; //�����ϽǸ��Ƶ����½�
            table[i][j + mid] = table[i][j] + mid; //�����ϽǼ�mid���Ƶ����½�
            table[i + mid][j] = table[i][j + mid]; //�����ϽǼ�mid���Ƶ����Ͻ�
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
            if (table[i][j] >= mid) //�������Ͽ鲻С��mid���� ����ʱ+n/2���¸���ʱ�ᳬ����Χ �����Ҫ���⴦��
            {
                table[i][j] = mid + i; //vital
                table[i + mid][j] = (mid + mid + i) % n;
            }
            else table[i + mid][j] = table[i][j] + mid;
        }
    }

    for (int i = 0; i < mid; ++i)
    {
        for (int j = 1; j < mid; ++j) //���Ҳ�����
        {
            int k = mid + (i + j) % mid; //����
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
