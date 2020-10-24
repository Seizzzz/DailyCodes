#include <bits/stdc++.h>
#define maxn 505
using namespace std;

int a[maxn],b[maxn],ans[maxn];
int alen,blen;

void add(int* a,int& alen,int* b,int& blen,int* ans)
{
	bool delta=false;
	int i=alen,j=blen,point=max(alen,blen)-1;
	
	while(point>=0)
	{
		ans[point]=a[--i]+b[--j];
		if(delta)
		{
			ans[point]++;
			delta=false;
		}
		if(ans[point]>9 && point!=0)
		{
			ans[point]=ans[point]-10;
			delta=true;
		}
		point--;
	}
	
	return;
}

void read(int* a,int& len)
{
	int i=0;
	char c='\0';
	while(c!='\n')
	{
		cin.get(c);
		a[i++]=c-'0';
	}
	len=i-1;
	return;
}

void put(int* a)
{
	int anslen=max(alen,blen);
	for(int i=0;i<anslen;i++) cout << a[i];
	cout << endl;
	return;
}

int main()
{
	std::ios::sync_with_stdio(false);
	
	read(a,alen);
	read(b,blen);
	
	add(a,alen,b,blen,ans);
	
	put(ans);
	return 0;
}

