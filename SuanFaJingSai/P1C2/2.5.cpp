#include <iostream>
#include <stdio.h>
#include <cmath>
#define INF 10000
using namespace std;

int main()
{
	
	/*2-1水仙花数 
	int a=1,b=0,c=0;
	while(1<=a<=9 && 0<=b<=10 && 0<=c<=10)
	{
		int n=100*a+10*b+c;
		if (n==pow(a,3)+pow(b,3)+pow(c,3))
		{
			printf("%d\n",n);
		}
		c++;
		if (n>999) {break;}
		if (b>=10) {a++;b=0;}
		if (c>=10) {b++;c=0;}
	}
	*/
	
	/*2-2韩信点兵 
	int a,b,c;   //abc为357的余数 
	scanf("%d%d%d",&a,&b,&c);
	for(int n=10;n<=100;n++)
	{
		if(a==n%3 && b==n%5 && c==n%7) printf("%d\n",n);
	}
	*/
	
	/*2-3倒三角形 
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			printf(" ");
		}
		
		for(int k=n-i+1;k>0;k--)
		{
			printf("# ");
		}
		printf("\n");
	}
	*/
	
	/*2-4子序列的和 
	int n,m;
	int kase=0;
	while(scanf("%d%d",&n,&m)==2 && (n || m))
	{
		double s=0; 
		for(int a=n;a<=m;a++)
		{
			s+=1.0/pow(a,2);   //数过大时下溢 
		}
	printf("Case%d: %.5f\n",++kase,s);
	}
	*/
	
	/* 错误 2-5 分数化小数 
	double a,b;
	int c;
	scanf("%d%d%d",&a,&b,&c);
	printf("%.*f",c,a/b);
	*/
	
	/*2-6*/
	
	/*思考1
	/*任务1 
	int n;
	scanf("%d",&n);
	for(int i=2; i<=n*2;i+=2)
		printf("%d\n",i);
	*/
	/*任务2
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n;i++)
		printf("%d\n",i*2);
	*/
	
	/*
	double i;   //????
	for(i=0;i!=10;i+=0.1)
	{
		printf("%.1f\n",i);
	}
	*/
	
	


	
	
	return 0;
}
