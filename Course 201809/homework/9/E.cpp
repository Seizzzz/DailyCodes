#include <stdio.h>

int a[2000005]; 

/*
15
20
-293 -213 -23 0 1 5 11 23 56 67 87 273 999 2132 10000
-23 -99999 0 999 953 67 56 44 33 87 -293 23 11 273 -213 2132 10000 87654 1 5
*/
int erfen(int a[],int n,int num)
{
	int high=n-1,low=0,mid,flag=1;
	
	while(low<=high)
	{
		mid=(high+low)/2;
	
		if(a[mid]<num) low=mid+1;
		else if(a[mid]>num) high=mid-1;
		else
		{
			flag=0;
			break;
		}
	}

	if(flag==1) return -1;
	else return mid;
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	
	while(m--)
	{
		int search;
		scanf("%d",&search);
		
		printf("%d ",erfen(a,n,search));
	}
	
	printf("\n");

	return 0;
}

