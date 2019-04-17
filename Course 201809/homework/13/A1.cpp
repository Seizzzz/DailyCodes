#include <stdio.h>

int search(int* a,int n,int size)
{
	for(int i=0;i<size;i++)
	{
		if(a[i]==n) return i;
	}
	return -1;
}

int main()
{
	int n;
	scanf("%d",&n);
	
	int a[n+2];
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	
	int m;
	scanf("%d",&m);
	while(m--)
	{
		int temp;
		scanf("%d",&temp);
		
		int pos=search(a,temp,n);
		if(pos==-1) printf("NULL\n");
		else if(pos==0) printf("%d\n",a[pos+1]);
		else if(pos==n-1) printf("%d\n",a[pos-1]);
		else printf("%d %d\n",a[pos-1],a[pos+1]);
	}

	return 0;
}

