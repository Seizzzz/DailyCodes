#include <bits/stdc++.h>
using namespace std;

int digit[10002];

int main()
{
	std::ios::sync_with_stdio(false);
	
	int t;
	cin >> t;
	for(int i=0;i<t;i++) cin >> digit[i];
	
	int maxsum,maxhere;
	maxsum = maxhere = digit[0];
	
	int left,sv_left;
	
	for(int i=0;i<t;i++)
	{
		if(maxhere <= 0)
		{
			maxhere = digit[i];
			left = i;
		}
		else maxhere += digit[i];
		if(maxhere > maxsum)
		{
			maxsum = maxhere;
			sv_left = left;
		}
	}
	
	cout << maxsum;
	
	int tmp=0,sv_right=sv_left;
	for(;tmp!=maxsum;++sv_right) tmp+=digit[sv_right];
	
	cout << " " << digit[sv_left] << " " << digit[sv_right-1] << endl;

	return 0;
}

