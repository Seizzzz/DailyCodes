#include <bits/stdc++.h>
using namespace std;

/*
5
1234
1233
2312
1312
2312
*/

struct president
{
	int score[105];
	int len;
	int xv;
}human[22];

bool cmp(president a,president b)
{
	if(a.len==b.len)
	{
		int i=0;
		while(i<a.len)
		{
			if(a.score[i]!=b.score[i]) return a.score[i] > b.score[i];
			i++;
		}
	}
	return a.len>b.len;
}

int main()
{
	int n;
	cin >> n;
	
	getchar();
	
	char buf='\0';
	for(int i=0;i<n;i++)
	{
		int cnt=0;
		human[i].xv=i+1;
		while((buf=getchar())!='\n')
		{
			human[i].score[cnt]=buf-'0';
			cnt++;
			human[i].len=cnt;
		}
	}
	
	sort(human,human+n,cmp);
	
	cout << human[0].xv << endl;
	for(int i=0;i<human[0].len;i++) cout << human[0].score[i];
	cout << endl;
	
	return 0;
}

