#include <stdio.h>
#include <math.h>

int main()
{
	int n;
	scanf("%d",&n);
	for(int n1=2;n1<=n/2;n1++)
	{
		for(int i=2;i<=sqrt(n1);i++)
		{
			if(n1%i==0) {
				n1=0;
				break;
			}
		}
		
		int n2=n-n1;
		for(int j=2;j<=sqrt(n2);j++)
		{
			if(n2%j==0) {
				n2=0;
				break;
			}
		}
		printf("*");
		if(n1!=0 && n2!=0)
		printf("%d %d\n",n1,n2);
		
	}
	return 0;
}
