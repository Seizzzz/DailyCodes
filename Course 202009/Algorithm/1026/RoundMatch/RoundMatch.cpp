#include <iostream>
#include "exhasut.h"
#include "merge.h"
#include "rotate.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
	
    int n;
    cin >> n;

    //ExhaustMethod sol(n);
    //sol.output();

    //MergeMethod sol(n);
    //sol.output();

    RotateMethod sol(n);
    sol.output();
}