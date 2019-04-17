#include <stdio.h>

int main()
{
	int a[11]={0,10,2,8,22,16,4,10,6,14,20};
	int temp[11]={0};
	
	int t=0,right=0;
	
	while(right!=9)
	{
		for(int i=1;i<=10;i++) temp[i]=0;
		
		right=0;
		
		printf("%d: ",t);
		for(int j=1;j<=10;j++) printf("%d ",a[j]);
		printf("\n");
		
		for(int i=1;i<=10;i++)
		{
			if(a[i]%2==0)
			{
			
				if(i==10) temp[1]+= a[i]/2;
				else temp[i+1]= a[i]/2;
			
				a[i]=a[i]/2;
			}
			else temp[i]++;
		}
		
		for(int i=1;i<=10;i++)
		{
			a[i]+=temp[i];
		}
		
		
		for(int m=1;m<=9;m++)
		{
			if(a[m]==a[m+1]) right++;
			else break;
		}
		
		t++;
	}

	return 0;
}

