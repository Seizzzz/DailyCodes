#include <bits/stdc++.h>
using namespace std;

int n,x,y;
int infolist[10005][4]; //a,b,g,k

int main()
{
	cin >> n;
	for(int i=0;i<n;i++)
		for(int k=0;k<4;k++) cin >> infolist[i][k];
	cin >> x >> y;
	
	int cnt=-1;
	for(int i=0;i<n;i++)
	{
		if(infolist[i][0]<=x && infolist[i][0]+infolist[i][2]>=x)
		{
			if(infolist[i][1]<=y && infolist[i][1]+infolist[i][3]>=y)
			{
				cnt=i+1;
			}
		}
	}
	
	cout << cnt << endl;

	return 0;
}

