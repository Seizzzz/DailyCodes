#include <iostream>
#include "commodity.h"
using namespace std;

int main()
{
    Commodity com;

    retState state;
    do
    {
        cout << "输入猜测价格：" << endl;
        int p; cin >> p;
        state = com.guessPrice(p);
        if (state == higher) cout << "高了" << endl;
        else if (state == lower) cout << "低了" << endl;
    } while (state != hit);

    cout << "猜对了" << endl;
}