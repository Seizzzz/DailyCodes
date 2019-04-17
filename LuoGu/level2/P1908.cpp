#include <bits/stdc++.h>
using namespace std;

int numlist[500005],sorted[500005];
int ans=0;

void mergesort(int st,int ed)
{
	if(st==ed) return;
	int mid=(st+ed)/2;
	
	mergesort(st,mid);
	mergesort(mid+1,ed);
	
	int left=st,right=mid+1,point=st;
	while(left<=mid && right<=ed)
	{
		if(numlist[left]<=numlist[right])
		{
			sorted[point]=numlist[left];
			point++;
			left++;
		}
		else //exchange 
		{
			sorted[point]=numlist[right];
			point++;
			right++;
			ans+=mid-left+1; //attention!
		}
	}
	
	while(left<=mid)
	{
		sorted[point]=numlist[left];
		point++;
		left++;
	}
	while(right<=ed)
	{
		sorted[point]=numlist[right];
		point++;
		right++;
	}
	
	for(int i=st;i<=ed;i++) numlist[i]=sorted[i]; //update 
	
	return;
}

int main()
{
	int n;
	scanf("%d",&n);
	
	for(int i=0;i<n;++i) scanf("%d",&numlist[i]);
	
	mergesort(0,n-1);
	
	cout << ans << endl;

	return 0;
}

