#include <bits/stdc++.h>
#define maxn 20
using namespace std;

char a[maxn];
bool vis[maxn];
char temp[maxn];
int len;

void cal(int have,int need)
{
	if(have==need)
	{
		for(int i=0;i<need;i++) cout << temp[i];
		cout << endl;
	}
	else
	{
		for(int i=0;i<len;i++)
		{
			if(vis[i])
			{
				temp[have]=a[i];
				vis[i]=false;
				cal(have+1,need);
				vis[i]=true; //只释放使用过的!!!
			}
		}
		return;
	}
}

int main()
{
	cin >> a;
	memset(vis,true,maxn);
	len=strlen(a);
	
	cal(0,len);
	
	
	return 0;
}

