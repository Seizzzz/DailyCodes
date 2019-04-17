#include <stdio.h>
#include <math.h>
int main()
{
    long long int m,n ;
    scanf("%lld",&n);
    
    if(n<1||n>10000)
    {
    	printf("%lld out of range\n",n);
    	return 0;
	}
    
    long long n1=n*n;

    
    long long int len0=0;
    for(;n/(long long int)pow(10,len0)!=0;len0++);

    long long int error=0;
    for(long long int i=0;i<=len0-1;i++)
    {
    	if((n1/(long long int)pow(10,i))%10==(n/(long long int)pow(10,i))%10);
    	else
    	{
    		error++;
    		break;
		}
    	
	}
	
	if(error==0) printf("Yes\n");
	else printf("No\n");
    
    return 0;
}
