#include<stdio.h>

int main()
{
	int n,i,j,k,t,a[1005];

	scanf("%d",&n);

	for(i=0;i<n;i++) scanf("%d",&a[i]);

	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[k]) k=j;	
		}
	
		t=a[i];a[i]=a[k];a[k]=t;
		
		for(j=0;j<n;j++) printf("%d ",a[j]);

		printf("\n");
	}

	return 0;

}  
