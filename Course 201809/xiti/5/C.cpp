#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
	int a[30],b[30];
	int n1,n2; 
	scanf("%d%d",&n1,&n2);
	
	for(int i=0;n1!=0;i++)
	{
		a[i]=n1%10;
		n1/=10;
	}
	for(int i=0;n2!=0;i++)
	{
		b[i]=n2%10;
		n2/=10;
	}

	int flag1=0,flag2=0,sum=0;
	for(;a[flag1]=0;flag1++);
	for(;a[flag1]=0;flag1++);
	
	int sum1=0,sum2=0;
	for(int i=strlen(a)-1;i>=flag1;i++)
	{
		int k=1;
		sum1+=a[i]*k;
		k*=10;
	}
	for(int i=strlen(b)-1;i>=flag2;i++)
	{
		int k=1;
		sum2+=b[i]*k;
		k*=10;
	}
	sum=sum1+sum2;
	int c[30];
	for(int i=0;sum!=0;i++)
	{
		c[i]=sum%10;
		sum/=10;
	}
	int flag3=0;
	for(;c[flag3]=0;flag3++);
	for(int i=flag3;i<strlen(c);i++) printf("%d",c[i]);

	return 0;
}

