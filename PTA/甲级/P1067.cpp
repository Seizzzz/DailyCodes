#include <bits/stdc++.h>
using namespace std;

int xishu[105];

int main()
{
	int n;
	cin >> n;
	
	for(int i=0;i<=n;i++) cin >> xishu[i];
	
	int buf=n+1;
	while((buf--)>=0)
	{	
		if(buf==0)
		{
			if(xishu[n-buf]>0) cout << "+" << xishu[n-buf];
			else if(xishu[n-buf]<0) cout << xishu[n-buf];
			
			break;
		}
		
		if(xishu[n-buf]>0)
		{
			
			if(xishu[n-buf]==1)
			{
				if(buf==n) cout << "x^" << buf;
				else if(buf==1) cout << "+x";
				else cout << "+" << "x^" << buf;
			}
			else
			{
				if(buf==n) cout << xishu[n-buf] << "x^" << buf;
				else if(buf==1) cout << "+" << xishu[n-buf] << "x";
				else cout << "+" << xishu[n-buf] << "x^" << buf;
			}
		}
		else if(xishu[n-buf]<0)
		{
			if(xishu[n-buf]==-1)
			{
				if(buf==1) cout << "-x";
				else cout << "-" << "x^" << buf;
			}
			else
			{
				if(buf==1) cout << xishu[n-buf] << "x";
				else cout << xishu[n-buf] << "x^" << buf;
			}
		}
	}
	
	cout << endl;

	return 0;
}

