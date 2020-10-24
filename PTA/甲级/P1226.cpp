#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll b,p,k;
int divnum=10;


ll cal(ll num,ll step) //µü´ú¹ýÉî 
{
	if(step==p) return num;
	if(num>=divnum) num=num-k*(num/k);
	
	return cal(num*b,step+1);
}

int main()
{
	cin >> b >> p >> k;
	
	if(p==0)
	{
		cout << b << "^" << p << " " << "mod" << " " << k << "=";
		cout << 1%k << endl;
		return 0;
	}
	
	for(;k/divnum;divnum*=10);
	//initialized
	cout << b << "^" << p << " " << "mod" << " " << k << "=";
	cout << cal(b,1)%k << endl;
	
	return 0;
}

