#include <stdio.h>
//hailstone <=1ʱֹͣ ����ż����/2 ������*3+1
 
int cal(int n)
{
	int len=1;
	while(n>1)
	{
		if(n%2) n=3*n+1;
		else n=n/2;
		len++;
	}
	return len;
}

int main()
{
	int n;
	scanf("%d",&n);
	
	printf("%d\n",cal(n));

	return 0;
}

