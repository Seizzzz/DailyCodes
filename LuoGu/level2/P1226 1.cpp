#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll b,p,k;

ll quick(ll a,ll b,ll c)
{
	int ans=1;
	a=a%c;
	while(b!=0)
	{
		if(b&1) ans=(ans*a)%c;
		b>>=1;
		a=(a*a)%c;
	}
	return ans;
}

int main()
{
	cin >> b >> p >> k;
	cout << b << "^" << p << " " << "mod" << " " << k << "=";
	
	if(p==0)
	{
		cout << 1%k << endl;
		return 0;
	}
	else cout << quick(b,p,k) << endl;
	return 0;
}

