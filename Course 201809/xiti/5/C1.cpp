#include <stdio.h>
#include <math.h>

int main()
{
	int n1,n2;
	scanf("%d%d",&n1,&n2);
	
	int len1=0,len2=0;
	
	for(;n1/(int)pow(10,len1);len1++);
	for(;n2/(int)pow(10,len2);len2++);
	
	int rn1=0,rn2=0;
	
	for(int i=len1-1;i>=0;i--) rn1+= ((n1/(int)pow(10,i))%10)*(int)pow(10,len1-i-1);
	for(int i=len2-1;i>=0;i--) rn2+= ((n2/(int)pow(10,i))%10)*(int)pow(10,len2-i-1);
	
	int sum=rn1+rn2;
	
	int len3=0;
	for(;sum/(int)pow(10,len3);len3++);
	
	int rn3=0;
	for(int i=len3-1;i>=0;i--) rn3+= ((sum/(int)pow(10,i))%10)*(int)pow(10,len3-i-1);
	
	printf("%d\n",rn3);

	return 0;
}

