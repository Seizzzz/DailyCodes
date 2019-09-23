#include <bits/stdc++.h>
using namespace std;

double xishu[2002],ans[2002];
bool vis[2002];

int main()
{
	std::ios::sync_with_stdio(false);
	for(int i=0;i<2002;++i) vis[i]=false;
	
	int k1,k2,cnt=0;
	int n; double a;
	cin >> k1;
	for(int i=0;i<k1;++i)
	{
		cin >> n >> a;
		xishu[n]=a;
		vis[n]=true;
	}
	
	cin >> k2;
	for(int i=0;i<k2;++i)
	{
		cin >> n >> a;
		for(int j=0;j<2002;++j)
		{
			if(vis[j])
			{
				if(ans[j+n]==0) ++cnt;
				ans[j+n] += xishu[j] * a;
			}
		}
	}
	
	cout << cnt;
	for(int i=2001;i>=0;--i)
	{
		if(ans[i]!=0) cout << " " << i << " " << setprecision(1) << fixed << ans[i];
	}
	
	cout << endl;

	return 0;
}

