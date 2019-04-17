#include <stdio.h>
#include <math.h>

int num(int n,int i)
{
	return (n/(int)pow(10,i))%10;
}

int main()
{
	long long n;
	scanf("%lld",&n);
	
	int len=0;
	for(;n/(int)pow(10,len)!=0;len++);
	
	int fa=0;
	
	for(int i=1;i-1<=len-i;i++)
	{
		if(num(n,i-1)==num(n,len-i));
		else
		{
			fa++;
			break;
		}
		//printf("%d %d\n",num(n,i-1),num(n,len-i));
	}
	if(fa==0) printf("Yes\n");
	else printf("No\n");
	
	return 0;
} 
