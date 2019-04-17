#include <stdio.h>

int main()
{
	int a[11]={0,10,2,8,22,16,4,10,6,14,20};
	
	int t=0;
	
	int right=0;
	while(right!=9)
	{
		right=0;
		
		printf("%d: ",t);
		for(int j=1;j<=10;j++) printf("%d ",a[j]);
		printf("\n");
		
		for(int i=1;i<=10;i++)
		{
			if(a[i]%2==0)
			{
			
				if(i==10) a[1]=a[1]+a[i]/2;
				else a[i+1]=a[i+1]+(a[i]/2);
			
				a[i]=a[i]/2;
			}
			else a[i]++;
		}
		for(int m=1;m<=9;m++)
		{
			if(a[m]==a[m+1]) right++;
			else break;
		}
		
		t++;
	}
	
	
	/*
	for(int i=1;;i++)
	{
		printf("%d: ",t);
		
		for(int j=1;j<=10;j++) printf("%d ",a[j]);
		printf("\n");
		
		if(a[i]%2==0)
		{
			
			if(i==10) a[1]=a[1]+a[i]/2;
			else a[i+1]=a[i+1]+(a[i]/2);
			
			a[i]=a[i]/2;
		}
		else a[i]++;
		
		if(i%10==0)
		{
			int right=0;
			for(int m=1;m<=9;m++)
			{
				if(a[m]==a[m+1]) right++;
				else break;
			}
			if(right==9) break;
		}
		
		
		t++;
		
	}
	*/
	
	return 0;
}

