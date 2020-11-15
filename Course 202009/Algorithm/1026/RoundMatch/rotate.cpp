#include "rotate.h"

void RotateMethod::rotate()
{
    int rightup = wheel[0][1];
    int leftdown = wheel[pair - 1][0];

    for (int i = pair - 1; i > 0; --i)
    {
        wheel[i][0] = wheel[i - 1][0];
    }

    for (int i = 0; i < pair - 1; ++i)
    {
        wheel[i][1] = wheel[i + 1][1];
    }

    wheel[pair - 1][1] = leftdown;
    wheel[1][0] = rightup;

}

void RotateMethod::record(int day)
{
    for (int i = 0; i < pair; ++i)
    {
        table[wheel[i][0]][day] = wheel[i][1];
        table[wheel[i][1]][day] = wheel[i][0];
    }
}

void RotateMethod::output()
{
    for (int i = 1; i <= num; ++i)
    {
        cout << i << " ";
        for (int j = (num % 2) ? 0 : 1; j < num; ++j)
        {
            if (table[i][j] == 0) cout << "- ";
            else cout << table[i][j] << " ";
        }
        cout << endl;
    }
}

RotateMethod::RotateMethod(int n): num(n)
{
    if (n % 2) pair = n / 2 + 1;
    else pair = n / 2;
	
    table = new int*[n + 1];
    for (int i = 0; i < n + 1; ++i) table[i] = new int[n + 1];
	
    wheel = new int*[pair];
    for (int i = 0; i < pair; ++i) wheel[i] = new int[2];

	//
    int cnt = 1;
    for (int i = 0; i < pair; ++i) wheel[i][0] = cnt++;
    for (int i = pair - 1; i > 0; --i) wheel[i][1] = cnt++;
    if (n % 2) wheel[0][1] = 0;
    else wheel[0][1] = n;

    for (int i = 0; i < n; ++i)
    {
        rotate();
        record(i);
    }
}

RotateMethod::~RotateMethod()
{
    for (int i = 0; i < num + 1; ++i) delete[] table[i];
    delete[] table;

    for (int i = 0; i < pair; ++i) delete[] wheel[i];
    delete[] wheel;
}
