#include <iostream>
using namespace std;

int main()
{
	/*��λ����ת��� 
	int n;  //��λ��n 
	scanf("%d", &n);
	printf("%03d%d%d\n", n%10, (n/10)%10, n/100);  //����λ �ڶ�λ ��һλ   ~%03d(d~ʮ���� 3~��λ 0~����0)
	*/
	
	/*����һλ������λ����ĩβΪ�����λ�� 
	int m, n;
	scanf("%03d", &n);
	m = (n%10) * 100 + ((n/10)%10) * 10 + n/100;
	printf("%03d", m);
	*/
	
	/*�������� ֱ����� 
	int m, n;
	scanf("%d%d", &m, &n);
	printf("%d %d", n, m);
	*/
	
	/*�������� ��������
	int m,n,t;
	scanf("%d%d", &m, &n);
	t=m;
	m=n;
	n=t;
	printf("%d %d", m, n);
	*/
	
	/*�������� ˫���� 
	int m,n;
	scanf("%d%d", &m, &n);
	m=m+n;
	n=m-n;
	m=m-n;
	printf("%d %d", m, n);
	*/
	
	/**/����ͬ�� 
	int a,b,m,n;
	scanf("%d%d", &a, &b);   //a���������� b����  m����  n����
	//m+n=a 2m+4n=b
	n=(b-2*a)/2;
	m=a-n;
	if(b%2==1||m<0||n<0||m+n>a||m+n<a)  //������Ϊ����  ��������С��0  ��֤ 
		printf("No answer");
	else
		printf("%d %d", m, n);
	/**/
	
	/*����������  failed  ע��淶  �����ţ� 
	int a,b,c,t;
	scanf("%d%d%d",&a,&b,&c);
	if(a>b) {t=a; a=b; b=t;}	//ab��С��������    //??????    //!!!!ע�⻨����? 
	if(a>c)	t=a; a=c; c=t;	//bc
	if(b>c)  t=b; b=c; c=t;
	printf("%d %d %d", a, b, c);
	*/
	
	/*���������� 
	int a,b,c,t;
	scanf("%d%d%d",&a,&b,&c);
	if(a>b) {t=a; a=b; b=t;}
	if(a>c) {t=a; a=c; c=t;}
	if(b>c) {t=b; b=c; c=t;}
	printf("%d %d %d", a, b, c);
	*/
	
	

	
	
	
	
	
	
	
	
	
	
	return 0;
}
