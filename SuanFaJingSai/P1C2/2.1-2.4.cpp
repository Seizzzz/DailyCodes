#include <iostream>
#include <cmath>
#include <time.h>
//#define INF 1e6
using namespace std;

int main()
{
	/*正序 
	int n;
	scanf("%d",&n);	// for(声明 初始化;循环条件;调整方法)  {循环体}  
	for (int i=1; i<=n; i++) printf("%d\n", i);	//i仅定义在循环语句中 不可在外部输出 
	*/
	
	/*倒序 
	int n;
	scanf("%d",&n);
	for (int i=n; i>0; i--) printf("%d\n",i);
	*/
	
	/*7744 first 7744
	for(int i=1001; i<=9999; i++)
	{
		int n=i;
			if (n/100%10 == n/1000  &&  n/10%10 == n%10)
			{
				int m=sqrt(n);
				if(pow(m,2)==n) {printf("%d",n);}
			}
	}
	*/

	/*7744标答
	for(int a=1; a<=9; a++)
	{
		for(int b=0; b<=9; b++)
		{
			int n = 1100*a+11*b;
			int m=floor(sqrt(n)+0.5);	//floor(n+0.5)四舍五入  //此步为防止极其偶然的误差，无必要?
			if(pow(m,2)==n) {printf("%d",n);}
			//int m=sqrt(n); if(pow(m,2)==n) {printf("%d", n);}
		}
	}
	*/
	
	/*7744另解 穷举平方数 后验 
	for(int n=1;;n++) 
	{
		int m=pow(n,2);
		if(m<1000)	continue;  //跳到循环的开始 
		if(m>9999)	break;	   //判定循环结束 
		if(m/100%10==m/1000 && m/10%10==m%10)
		{
			printf("%d",m);
		}
	}
	*/
	
	//for(;;) 死循环
	
	/*question 3n+1
	int n1, count=0;
	scanf("%d",&n1);
	long long n=n1;
	while(n>1)
	{
		if(n%2==1)    //如果是奇数 则变为3n+1 
		{
			n=3*n+1;
			printf("%d\n",n);
		}
		else
		{
			n /= 2; printf("%d\n",n);
		}
		count ++;
	}
	printf("after %d steps, done!",count,n);
	*/
	
	/*2-6近似计算 
	double s=1; 
	for(int i=1;;i++)
	{
		double p=1.0/(i*2+1);
		if(i%2==0)
		{
			s+=p;
		}
		else
		{
			s-=p;
		}
	if(p<pow(10,-8)) break;
	}
	printf("%.9f",s*4);
	*/
	
	/*2-8 failed test 阶乘和
	int n,m,s=0,k;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		printf("i=%d ",i);  //**
		for(int j=i,m=1;j>=1;j--)
		{
			m*=j;
			printf("m=%d j=%d\n",m,j);
		}
	}
	*/
	
	/*first 阶乘和 
	int n,s;
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++)
	{
		int sum=1;            //初始化每次的和数 
		for(int j=1;j<=i;j++)
		{
			sum*=j;           //每次的阶乘值 
		}
		s+=sum;
	}
	
	printf("%d %d",s,s%1000000);
	*/
	
	/*refine 阶乘和
	int n,s,sum=1;           //if(n>25) n=25;  //提升效率  //25!末尾有6个0  23333 
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++)
	{
		sum*=i;
		s+=sum;
	} 
	printf("%d",s%1000000);
	*/
	
	/*2-6 first recite 数据统计 
	int x,n,line=0;
	while (scanf("%d",&n)==1 && n)    //读取该组数据个数  第一项仅一个数且不为零
	{
		int MAX=-INF,MIN=INF,s=0; 
		for(int i=1;i<=n;i++)     //组数据依次读取 
		{
			scanf("%d",&x);
			if(x>MAX) MAX=x;
			if(x<MIN) MIN=x;
			s+=x;               //求和 输出时取平均 
		}
		if(line) printf("\n");
		line+=1;    //两行间空格 
		printf("%d %d %lf", MIN, MAX, (double)s/n);
	}
	*/
	
	/*refine 数据统计 
	int n, CASE=1;
	while(scanf("%d",&n)==1 && n)
	{
		int s=0,x,MAX=-INF,MIN=INF;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if(x>MAX) MAX=x;
			if(x<MIN) MIN=x;
			s+=x;
			
		}
		printf("Case%d: Min:%d Max:%d Average:%lf\n", CASE++,MIN, MAX, (double)s/n);
	}
	*/
	
	/*2-5单组数据统计(未知个数) 
	int x,MIN=INF, MAX=-INF,s=0,n=0;
	while(scanf("%d",&x)==1 && x)
	{
		if(x>MAX) MAX=x;
		if(x<MIN) MIN=x;
		s+=x;
		n++;
	}
	printf("Min:%d Max:%d Average:%lf",MIN ,MAX, (double)s/n);
	*/
	
	
	
	
	
	return 0; 
}
