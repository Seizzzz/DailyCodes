#include <bits/stdc++.h>
using namespace std;

float val[1005];
int ans = 0;

int main()
{
	std::ios::sync_with_stdio(false);
	
	int k,n;
	float a;
	for(int line = 0;line < 2;line++)
	{
		cin >> k;
		for(int i = 0; i < k; i++)
		{
			cin >> n >> a;
			val[n]+=a;
		}
	}
	
	for(int i = 0;i<1005;i++) if(val[i]) ans++;
	cout << ans;
	
	for(int i=1004;i>=0;i--)
	{
		if(val[i]) cout << " " << i << " " << setprecision(1) << fixed << val[i];
	}
	cout << endl;

	return 0;
}

