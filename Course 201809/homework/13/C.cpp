#include <stdio.h>
#include <stdlib.h>

int search(int* a,int size,int num)
{
	int up=size,low=0,mid=size/2;
	if(a[low]==num) return low;
	if(a[up]==num) return up;
	while(a[mid] != num)
	{
		if(up==low || low+1==up) return -1;
		mid=(up+low)/2;
		if(a[mid]<num) low=mid;
		else up=mid;
	}
	return mid;
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	
	int* a=(int*)malloc(sizeof(int) * n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	
	while(m--)
	{
		int num;
		scanf("%d",&num);
		
		printf("%d ",search(a,n,num));
	}
	
	printf("\n");

	return 0;
}

