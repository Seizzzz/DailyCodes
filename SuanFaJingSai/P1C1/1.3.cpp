#include <iostream>
using namespace std;

int main()
{
	/*三位数反转简版 
	int n;  //三位数n 
	scanf("%d", &n);
	printf("%03d%d%d\n", n%10, (n/10)%10, n/100);  //第三位 第二位 第一位   ~%03d(d~十进制 3~三位 0~补充0)
	*/
	
	/*对于一位数、两位数、末尾为零的三位数 
	int m, n;
	scanf("%03d", &n);
	m = (n%10) * 100 + ((n/10)%10) * 10 + n/100;
	printf("%03d", m);
	*/
	
	/*交换变量 直接输出 
	int m, n;
	scanf("%d%d", &m, &n);
	printf("%d %d", n, m);
	*/
	
	/*交换变量 三变量法
	int m,n,t;
	scanf("%d%d", &m, &n);
	t=m;
	m=n;
	n=t;
	printf("%d %d", m, n);
	*/
	
	/*交换变量 双变量 
	int m,n;
	scanf("%d%d", &m, &n);
	m=m+n;
	n=m-n;
	m=m-n;
	printf("%d %d", m, n);
	*/
	
	/**/鸡兔同笼 
	int a,b,m,n;
	scanf("%d%d", &a, &b);   //a鸡兔总数量 b腿数  m鸡数  n兔数
	//m+n=a 2m+4n=b
	n=(b-2*a)/2;
	m=a-n;
	if(b%2==1||m<0||n<0||m+n>a||m+n<a)  //腿数不为奇数  鸡兔数不小于0  验证 
		printf("No answer");
	else
		printf("%d %d", m, n);
	/**/
	
	/*三整数排序  failed  注意规范  花括号！ 
	int a,b,c,t;
	scanf("%d%d%d",&a,&b,&c);
	if(a>b) {t=a; a=b; b=t;}	//ab从小到大排列    //??????    //!!!!注意花括号? 
	if(a>c)	t=a; a=c; c=t;	//bc
	if(b>c)  t=b; b=c; c=t;
	printf("%d %d %d", a, b, c);
	*/
	
	/*三整数排序 
	int a,b,c,t;
	scanf("%d%d%d",&a,&b,&c);
	if(a>b) {t=a; a=b; b=t;}
	if(a>c) {t=a; a=c; c=t;}
	if(b>c) {t=b; b=c; c=t;}
	printf("%d %d %d", a, b, c);
	*/
	
	

	
	
	
	
	
	
	
	
	
	
	return 0;
}
