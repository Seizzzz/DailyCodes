#include <bits/stdc++.h>
using namespace std;

int numlist[500005],sorted[500005];
long long ans=0;

inline void mergesort(int st,int ed)
{
	if(st>=ed) return;
	int mid=(st+ed)/2;
	
	mergesort(st,mid);
	mergesort(mid+1,ed);
	
	int left=st,right=mid+1,now=st;
	while(left<=mid && right<=ed)
	{
		if(numlist[left]<=numlist[right]) sorted[now++]=numlist[left++];
		else //exchange 
		{
			sorted[now++]=numlist[right++];
			ans+=(long long)mid-(long long)left+1; //vital!
		}
	}
	
	//copy the other
	while(left<=mid) sorted[now++]=numlist[left++];
	while(right<=ed) sorted[now++]=numlist[right++];
	
	for(int i=st;i<=ed;i++) numlist[i]=sorted[i]; //update 
	return;
}

int main()
{
	std::ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	for(int i=0;i<n;++i) cin >> numlist[i];
	
	mergesort(0,n-1);
	
	cout << ans << endl;
	return 0;
}

