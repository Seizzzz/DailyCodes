#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

int main()
{
	/*1-15�������ʵ��
	int a,b,c,d;                            //?????�����ַ��� 
	scanf("%d%d%d%d",&a,&b,&c,&d);
	printf("%d %d %d %d\n",a,b,c,d);              
	printf("%%d\\n");    //һ���ַ���\ת��  %��%ת�� 
	*/
	
	/*1.5.3 ϰ��1-1  ƽ���� 
	int a,b,c;
	double v;
	scanf("%d%d%d",&a,&b,&c);
	v=((a+b+c)/3.0);   //ע��3.0 ��Ҫʱ�ɼ�(double) 
	printf("%.3f",v);
	*/
	
	/*ϰ��1-2   �¶� 
	double f,c;
	scanf("%f",&f);
	c=5.0*(f-32)/9.0;
	printf("%.3f",c); 
	*/
	
	/*1-3  ������ 
	int n;
	scanf("%d",&n);
	printf("%d",((1+n)*n)/2);
	*/
	
	/*1-4 �������� 
	int n;   //�Ƕ��� 
	const double pi=acos(-1.0);   //acos arccos ������ 
	scanf("%d", &n);
	printf("%.3f %.3f",sin(pi*n/180),cos(pi*n/180));
	*/
	
	/*1-5 ���� 
	int n;
	double s;
	scanf("%d",&n);
	if(95*n>300) {s=0.85*(95.0*n);}
	else {s=95.0*n;}
	printf("%lf",s);
	*/
	
	/*1-6 ������ 
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(a+b>c && a-b<c)  //������ 
		{
			if(pow(a,2)+pow(b,2) == pow(c,2) || pow(a,2)+pow(c,2) == pow(b,2) || pow(b,2)+pow(c,2) == pow(a,2))  //���� 
					{printf("yes");}
			else printf("no");
		}
	else printf("not a triangle");
	*/
	
	/*1-7 ��� 
	int n;
	scanf("%d",&n);
	if(n%400==0) {printf("yes");}
	else if(n%4==0 && n%100!=0) {printf("yes");}
	else printf("no");
	*/

    /*����4 
	int a=1, b=2, c=3;
	if(a<b||b<c&&a<c) printf("q");  // ��������� ����          Ϊ��   ���q 
	if(a<b||b<c&&a>c) printf("w");  // ���||����  ��Ϊ��&&��   Ϊ��  �����w 
									// ���&&����  ��Ϊ��||��   Ϊ��   ���w 
									// ���к����qw  ��&&�����ȼ�����|| 
	*/
	
	return 0;
}


