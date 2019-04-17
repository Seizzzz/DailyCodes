#include <stdio.h>

int main()
{
	int n,m;
	int count=0;
	scanf("%d%d",&n,&m);
	

	for(int i=1;i<=n;i++)
	{
		int s=i/m;
		int a=(i/10000),b=(i/1000)%10,c=(i/100)%10,d=(i/10)%10,e=i%10;
		if(a*a+b*b+c*c+d*d+e*e==s)
		{
		
			if(count%5==0)
			{
				printf("\n%d\t",i);
			}
			else
			{
				printf("%d\t",i);
			}
		count++;
		}
		
		
	}
	
	
	
}
