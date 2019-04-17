#include <stdio.h>
#include <stdlib.h> 

int cmp(const void *a,const void *b)
{
	return(*(int*)a - *(int*)b);
}

int main()
{
	int a[1005];
	
	int n;
	scanf("%d",&n);
	
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	//for(int i=0;i<n;i++) b[i]=a[i];
	
	//qsort(a,n,sizeof(a[0]),cmp);
	
	for(int i=2;i<=n;i++)
	{
		qsort(a,i,sizeof(a[0]),cmp);
		for(int j=0;j<n;j++) printf("%d ",a[j]);
		
		printf("\n");
	}
	
	/*
	int b[1005];
	
	for(int geshu=2;geshu<=n;geshu++)
	{
		int k=1;
		for(int i=1;i<=geshu;i++)
		{
			int min=32768;
			if(a[i]<min)
		}
	}
	*/
	
	/*
	int k=1;
	for(int i=2;i<=n-1;i++)
	{
		if(k==1)
		{
			if(a[2]>a[1])
			{
				int t=a[1];
				a[1]=a[2];
				a[2]=t;
				k++;
			}
		}
		else
		{
			int j=1
			for(;j<=i-1;j++)
			{
				if(a[j]<a[i]);
				else break;
			}
			
			a[j]=
		}
		
	}
	
	/*for(int i=1;i<=n;i++) b[i]=a[i];
	
	for(int i=2;i<=n-1;i++)
	{
		if(b[i]>)
	}*/

	return 0;
}

