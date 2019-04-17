#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

int main()
{
	/*1-15输入输出实验
	int a,b,c,d;                            //?????输入字符？ 
	scanf("%d%d%d%d",&a,&b,&c,&d);
	printf("%d %d %d %d\n",a,b,c,d);              
	printf("%%d\\n");    //一般字符用\转义  %用%转义 
	*/
	
	/*1.5.3 习题1-1  平均数 
	int a,b,c;
	double v;
	scanf("%d%d%d",&a,&b,&c);
	v=((a+b+c)/3.0);   //注意3.0 必要时可加(double) 
	printf("%.3f",v);
	*/
	
	/*习题1-2   温度 
	double f,c;
	scanf("%f",&f);
	c=5.0*(f-32)/9.0;
	printf("%.3f",c); 
	*/
	
	/*1-3  连续和 
	int n;
	scanf("%d",&n);
	printf("%d",((1+n)*n)/2);
	*/
	
	/*1-4 正弦余弦 
	int n;   //角度制 
	const double pi=acos(-1.0);   //acos arccos 反余弦 
	scanf("%d", &n);
	printf("%.3f %.3f",sin(pi*n/180),cos(pi*n/180));
	*/
	
	/*1-5 打折 
	int n;
	double s;
	scanf("%d",&n);
	if(95*n>300) {s=0.85*(95.0*n);}
	else {s=95.0*n;}
	printf("%lf",s);
	*/
	
	/*1-6 三角形 
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(a+b>c && a-b<c)  //三角形 
		{
			if(pow(a,2)+pow(b,2) == pow(c,2) || pow(a,2)+pow(c,2) == pow(b,2) || pow(b,2)+pow(c,2) == pow(a,2))  //勾股 
					{printf("yes");}
			else printf("no");
		}
	else printf("not a triangle");
	*/
	
	/*1-7 年份 
	int n;
	scanf("%d",&n);
	if(n%400==0) {printf("yes");}
	else if(n%4==0 && n%100!=0) {printf("yes");}
	else printf("no");
	*/

    /*问题4 
	int a=1, b=2, c=3;
	if(a<b||b<c&&a<c) printf("q");  // 真或真且真 对照          为真   输出q 
	if(a<b||b<c&&a>c) printf("w");  // 如果||优先  则为真&&假   为假  不输出w 
									// 如果&&优先  则为真||假   为真   输出w 
									// 运行后输出qw  故&&的优先级高于|| 
	*/
	
	return 0;
}


