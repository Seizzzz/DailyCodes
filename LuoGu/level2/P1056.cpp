#include <bits/stdc++.h>
using namespace std;

struct node
{
	int pair;
	int xv;
};

struct node hang[1005],lie[1005];// k l

bool cmp(struct node a,struct node b)
{
	return a.pair>b.pair;
}

bool cmp1(struct node a,struct node b)
{
	return a.xv<b.xv;
}

int m,n,k,l,d;

int main()
{
	cin >> m >> n >> k >> l >> d;
	
	for(int i=0;i<1005;i++)
	{
		hang[i].pair=0;
		hang[i].xv=i;
		lie[i].pair=0;
		lie[i].xv=i;
	}
	
	int buf1,buf2,buf3,buf4;
	while(d--)
	{
		cin >> buf1 >> buf2 >> buf3 >> buf4;
		if(buf1==buf3)
		{
			if(buf2<buf4) lie[buf2].pair++;
			else lie[buf4].pair++;
		}
		else //buf2==buf4
		{
			if(buf1<buf3) hang[buf1].pair++;
			else hang[buf3].pair++;
		}
	}
	
	sort(hang+1,hang+m+1,cmp);
	sort(lie+1,lie+n+1,cmp);
	
	sort(hang+1,hang+k+1,cmp1);
	sort(lie+1,lie+l+1,cmp1);
	
	for(int i=1;i<=k;i++)
	{
		if(i==k) cout << hang[i].xv << endl;
		else cout << hang[i].xv << " ";
	}
	
	for(int i=1;i<=l;i++)
	{
		if(i==l) cout << lie[i].xv << endl;
		else cout << lie[i].xv << " ";
	}
	

	return 0;
}

