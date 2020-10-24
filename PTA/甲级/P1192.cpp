#include <bits/stdc++.h>
using namespace std;

int kind[100005],n,k;

int main()
{
	cin >> n >> k;
	
	for(int i=0;i<=n;i++) kind[i]=0;
	kind[0]=1;
	kind[1]=1;
	
	for(int i=2;i<=n;i++)
	{
		for(int step=1;step<=k && i-step>=0;step++)
		{
			kind[i]+=kind[i-step];
		}
		kind[i]%=100003;
	}
	
	cout << kind[n] << endl;

	return 0;
}

