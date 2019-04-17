#include <iostream>
#include <cstdio>
using namespace std;

/*
10
20 40 32 67 40 20 89 300 400 15
*/

void myquicksort(int* num,int len)
{
	if(len<=0) return;
	
	int left=0,right=len-1;
	int mid=num[left];
	
	while(left<right)
	{
		while(num[right]>mid) right--;
		while(num[left]<=mid && left<right) left++;
		swap(num[left],num[right]);
	}
	
	if(num[left]<mid) swap(num[left],num[0]);
	
	myquicksort(num,left);
	myquicksort(num+left+1,len-right-1);
}

int main()
{
	int n;
	cin >> n;
	
	int num[n];
	for(int i=0;i<n;i++) cin >> num[i];
	
	myquicksort(num,n); 
	
	int ans[n],at=1;
	ans[0]=num[0];
	for(int i=0;i<n-1;i++)
	{
		if(num[i]!=num[i+1])
		{
			ans[at]=num[i+1];
			at++; 
		}
	}
	
	cout << at << endl;
	for(int i=0;i<at;i++) cout << ans[i] << " ";
	cout << endl;

	return 0;
}

