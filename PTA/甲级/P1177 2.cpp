#include <bits/stdc++.h>
using namespace std;

int a[100005];

void myquicksort(int left,int right)
{
	int i=left,j=right;
	int mid=a[(left+right)/2];
	
	while(i<j)
	{
		while(a[i]<mid) i++;
		while(a[j]>mid) j--;
		if(i<=j)
		{
			swap(a[i],a[j]);
			i++;
			j--;
		}
	}
	
	if(left<j) myquicksort(left,j);
	if(right>i) myquicksort(i,right);
	
	return;
}

int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++) cin >> a[i];
	
	myquicksort(0,n);
	
	for(int i=1;i<n;i++) cout << a[i] << " ";
	cout << a[n] << endl;
	
	return 0;
}

