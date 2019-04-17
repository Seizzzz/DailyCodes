#include <stdio.h>
#include <math.h>

int main()
{
	int a,b,c,cnt=0,s=0;
	scanf("%d%d%d",&a,&b,&c);
	
	
	for(int i=a;i<=b;i++)
	{
		s=0;
		
		for(int j=1;j<=i/2;j++)
		{
			if(i%j==0) s+=j;
		}
		
		if(abs(i-s)<=c)
		{
			cnt++;
			if(cnt%5!=0) printf("%d\t",i);
			else printf("%d\n",i);
		}
	}
	
	if(cnt==0) printf("There is no proper number in the interval.");
	printf("\n");
	
	return 0;
}
