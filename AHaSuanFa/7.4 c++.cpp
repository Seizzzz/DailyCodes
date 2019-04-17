#include <bits/stdc++.h>
#define maxn 10
using namespace std;

/*
9
0 1
2 3
4 1
3 5
1 5
7 6
8 6
0 5
1 3
*/

int human[maxn];

int origin(int i)
{
	if(human[i]==i) return i;
	else return origin(human[i]);
}

void merge(int i,int j)
{
	int bossi=origin(i),bossj=origin(j);
	human[bossj]=bossi;
	return;
}

int main()
{
	for(int i=0;i<maxn;i++) human[i]=i;
	//initialized
	
	int kase;
	cin >> kase;
	while(kase--)
	{
		int buf1,buf2;
		cin >> buf1 >> buf2;
		merge(buf1,buf2);
	} 
	
	int ans=0;
	for(int i=0;i<maxn;i++)
	{
		if(human[i]==i) ans++;
	}

	cout << ans << endl;
	return 0;
}

