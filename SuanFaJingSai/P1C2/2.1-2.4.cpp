#include <iostream>
#include <cmath>
#include <time.h>
//#define INF 1e6
using namespace std;

int main()
{
	/*���� 
	int n;
	scanf("%d",&n);	// for(���� ��ʼ��;ѭ������;��������)  {ѭ����}  
	for (int i=1; i<=n; i++) printf("%d\n", i);	//i��������ѭ������� �������ⲿ��� 
	*/
	
	/*���� 
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

	/*7744���
	for(int a=1; a<=9; a++)
	{
		for(int b=0; b<=9; b++)
		{
			int n = 1100*a+11*b;
			int m=floor(sqrt(n)+0.5);	//floor(n+0.5)��������  //�˲�Ϊ��ֹ����żȻ�����ޱ�Ҫ?
			if(pow(m,2)==n) {printf("%d",n);}
			//int m=sqrt(n); if(pow(m,2)==n) {printf("%d", n);}
		}
	}
	*/
	
	/*7744��� ���ƽ���� ���� 
	for(int n=1;;n++) 
	{
		int m=pow(n,2);
		if(m<1000)	continue;  //����ѭ���Ŀ�ʼ 
		if(m>9999)	break;	   //�ж�ѭ������ 
		if(m/100%10==m/1000 && m/10%10==m%10)
		{
			printf("%d",m);
		}
	}
	*/
	
	//for(;;) ��ѭ��
	
	/*question 3n+1
	int n1, count=0;
	scanf("%d",&n1);
	long long n=n1;
	while(n>1)
	{
		if(n%2==1)    //��������� ���Ϊ3n+1 
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
	
	/*2-6���Ƽ��� 
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
	
	/*2-8 failed test �׳˺�
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
	
	/*first �׳˺� 
	int n,s;
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++)
	{
		int sum=1;            //��ʼ��ÿ�εĺ��� 
		for(int j=1;j<=i;j++)
		{
			sum*=j;           //ÿ�εĽ׳�ֵ 
		}
		s+=sum;
	}
	
	printf("%d %d",s,s%1000000);
	*/
	
	/*refine �׳˺�
	int n,s,sum=1;           //if(n>25) n=25;  //����Ч��  //25!ĩβ��6��0  23333 
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++)
	{
		sum*=i;
		s+=sum;
	} 
	printf("%d",s%1000000);
	*/
	
	/*2-6 first recite ����ͳ�� 
	int x,n,line=0;
	while (scanf("%d",&n)==1 && n)    //��ȡ�������ݸ���  ��һ���һ�����Ҳ�Ϊ��
	{
		int MAX=-INF,MIN=INF,s=0; 
		for(int i=1;i<=n;i++)     //���������ζ�ȡ 
		{
			scanf("%d",&x);
			if(x>MAX) MAX=x;
			if(x<MIN) MIN=x;
			s+=x;               //��� ���ʱȡƽ�� 
		}
		if(line) printf("\n");
		line+=1;    //���м�ո� 
		printf("%d %d %lf", MIN, MAX, (double)s/n);
	}
	*/
	
	/*refine ����ͳ�� 
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
	
	/*2-5��������ͳ��(δ֪����) 
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
