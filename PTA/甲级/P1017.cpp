#include <bits/stdc++.h>
using namespace std;

struct person
{
	int arrive,process;
}customer[10002];
int n,k;
int mymap[2][102];
int nowtime = 28800;
double sum = 0;
int finish = 0;

bool cmp(person p1,person p2)
{
	return p1.arrive < p2.arrive;
}

void deal_due()
{
	for(int i=0;i<k;++i)
	{
		if(mymap[1][i] == 0) continue;
		if(mymap[1][i] <= nowtime)
		{
			++finish;
			sum += (nowtime - customer[mymap[0][i]].arrive - customer[mymap[0][i]].process);
			mymap[1][i] = 0;
		}
	}
	return;
}

int find_empty()
{
	for(int i=0;i<k;++i)
	{
		if(mymap[1][i] <= nowtime) return i;
	}
	return -1;
}

int main()
{
	scanf("%d%d",&n,&k);
	
	for(int i=0;i<n;++i)
	{
		int h,m,s;
		scanf("%d:%d:%d",&h,&m,&s);
		int t = h*3600+m*60+s;
		customer[i].arrive = t;
		scanf("%d",&m);
		customer[i].process = m*60;
	}
	
	sort(customer,customer+n,cmp);
	
	int nowat = 0;
	while(nowtime <= 61200)
	{
		deal_due();
		int empty_pos;
		while((empty_pos = find_empty()) != -1)
		{
			if(customer[nowat].arrive < nowtime)
			{
				mymap[0][empty_pos] = nowat;
				mymap[1][empty_pos] = nowtime + customer[nowat++].process;
			}
			else break;
		}
		++nowtime;
	}
	
	for(;nowat<n;++nowat)
	{
		if(customer[nowat].arrive <= 61200) sum += (61200 - customer[nowat].arrive);
	}
	
	printf("%.1lf",(sum/60)/finish);

	return 0;
}

