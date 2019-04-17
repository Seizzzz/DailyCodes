#include <iostream>
#include <cstdio>
using namespace std;

/*
10
6 1 2 7 9 3 4 5 10 8
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
	
	for(int i=0;i<n;i++) cout << num[i] << " ";
	cout << endl;

	return 0;
}

