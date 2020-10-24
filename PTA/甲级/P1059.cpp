#include <bits/stdc++.h>
#define maxn 1005
using namespace std;

int cnt[maxn],ans=0;
int myans[105],point=0;

/*
10
20 40 32 67 40 20 89 300 400 15
*/

int main()
{
	int n;
	cin >> n;
	
	for(int i=0;i<maxn;i++) cnt[i]=0;
	
	int buf;
	for(int i=0;i<n;i++)
	{
		cin >> buf;
		cnt[buf]++;
	}
	
	for(int i=0;i<maxn;i++)
	{
		if(cnt[i])
		{
			ans++;
			myans[point]=i;
			point++;
		}
	}
	
	cout << ans << endl;
	for(int i=0;i<ans;i++) cout << myans[i] << " ";
	cout << endl;

	return 0;
}

