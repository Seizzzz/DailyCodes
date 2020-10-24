#include <iostream>
#include "exhasut.h"
#include "merge.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
	
    int n;
    cin >> n;

    MergeMethod sol(n);
    sol.output();

    //ExhaustMethod sol(n);
    //sol.output();

}