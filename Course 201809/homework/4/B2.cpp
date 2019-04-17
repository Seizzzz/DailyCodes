#include <stdio.h>
#include <math.h>

int main()
{
	int n1,n2,n,i;
	scanf("%d",&n);
	for (n1=2;n1<=n/2;n1++)
    {
        for (i=2;i<=sqrt(n1);i++)
        {
		if (n1%i==0) break;
		}
        
		if (i==(int)sqrt(n1)+1)
        {
        for (i=2,n2=n-n1;i<=sqrt(n2);i++)
        {
        if (n2%i==0) break;
    	}
    	
        if (i==(int)sqrt(n2)+1)
        printf("%d and %d\n",n1,n2);
        
		
		}
	
    }
    printf("\n");
	return 0;
}
