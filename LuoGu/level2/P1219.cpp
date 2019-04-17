#include <bits/stdc++.h>
using namespace std;

bool ColOccupy[15];
bool DiaOccupy[30];
bool AidOccupy[30]; 
bool mymap[15][15];
int n,ans=0;
int nowlist[15];

void dfs(int row)
{
	if(row==n+1)
	{
		if(ans<3)
		{
			for(int i=1;i<=n;++i) cout << nowlist[i] << " ";
			cout << endl;
		}
		ans++;
	}
	else
	{
		for(int col=1;col<=n;++col)
		{
			if(!ColOccupy[col] || !DiaOccupy[row+col] || !AidOccupy[row-col+n]) continue;
			else
			{
				nowlist[row]=col;
				ColOccupy[col]=false;
				DiaOccupy[row+col]=false;
				AidOccupy[row-col+n]=false;
				dfs(row+1);
				ColOccupy[col]=true;
				DiaOccupy[row+col]=true;
				AidOccupy[row-col+n]=true;
			}
		}
	}
	
	return;
}

int main()
{
	cin >> n;
	for(int i=0;i<15;i++)
	{
		ColOccupy[i]=true;
		for(int j=0;j<15;j++) mymap[i][j]=true;
	}
	for(int i=0;i<30;i++)
	{
		DiaOccupy[i]=true;
		AidOccupy[i]=true;
	}
	//initialized
	
	dfs(1);
	
	cout << ans << endl;

	return 0;
}

