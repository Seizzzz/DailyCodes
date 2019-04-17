#include <bits/stdc++.h>
using namespace std;

int n,num[200005];

inline int merge(int left,int right)
{
	if(left==right) return num[left];
	int mid=(left+right)>>1;
	
	int maxleft=INT_MIN,sumleft=0;
	for(int i=mid;i>=left;i--) //left~mid ×î´óÖµ 
	{
		sumleft+=num[i];
		maxleft=max(maxleft,sumleft);
	}
	
	int maxright=INT_MIN,sumright=0;
	for(int i=mid+1;i<=right;i++)
	{
		sumright+=num[i];
		maxright=max(maxright,sumright);
	}
	
	return max(maxleft+maxright,max(merge(left,mid),merge(mid+1,right)));
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin >> n;
	
	for(int i=1;i<=n;i++) cin >> num[i];
	
	cout << merge(1,n) << endl;

	return 0;
}

