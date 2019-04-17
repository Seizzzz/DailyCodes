#include <stdio.h>

int judgeTriangle(int a,int b,int c)
{
	if(a+b>c && c-b<a)
	{
		if(a*a+b*b==c*c) return 1;
		else if (a==b && b==c && a==c) return 3;
		else if (a==b || b==c || a==c) return 2;
		else return 0;
	}
	else return -1;
}

int main()
{
	int a,b,c,tran;
	
	scanf("%d%d%d",&a,&b,&c);
	if(a>b)
	{
		tran=a;a=b;b=tran;}
	if(a>c)
	{
		tran=a;a=c;c=tran;}
	if(b>c)
	{
		tran=b;b=c;c=tran;}
	
	if(judgeTriangle(a,b,c)==-1) printf("It is not a triangle.\n");
	else if(judgeTriangle(a,b,c)==0) printf("It is a scalenous triangle.\n");
	else if(judgeTriangle(a,b,c)==1) printf("It is a right-angled triangle.\n");
	else if(judgeTriangle(a,b,c)==2) printf("It is an isosceles triangle.\n");
	else if(judgeTriangle(a,b,c)==3) printf("It is a equilateral triangle.\n");
	
	return 0;
}
