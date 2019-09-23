#include <bits/stdc++.h>
using namespace std;
#define to 16

stack<char> stk;
char cvt[99];


int main()
{
	std::ios::sync_with_stdio(false);
	
	for(int i=0;i<10;i++) cvt[i]='0'+i;
	for(int i=10;i<34;i++) cvt[i]='A'+i-10;
	
	int ori;
	cin >> ori;
	
	while(ori)
	{
		stk.push(cvt[ori%to]);
		ori/=to;
	}
	
	while(!stk.empty())
	{
		cout << stk.top();
		stk.pop();
	}
	
	return 0;
}

