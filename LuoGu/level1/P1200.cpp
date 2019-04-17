#include <stdio.h>
#include <string.h>

int main()
{
	char a[10],b[10];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(a));
	gets(a);
	gets(b);
	
	int num1=1,num2=1;
	
	for(int i=0;a[i]!=0;i++)
	{
		num1*=(a[i]-'A'+1);	
	}
	num1%=47;
	
	for(int i=0;b[i]!=0;i++)
	{
		num2*=(b[i]-'A'+1);
	}
	num2%=47;

	
	if(num1==num2) printf("GO\n");
	else printf("STAY\n");
	
	return 0;
}
