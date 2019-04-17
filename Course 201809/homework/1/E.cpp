#include <stdio.h>

int main()
{
	char a;
	short b;
	int c;
	long d;
	long long e;
	float f;
	double g;
	scanf("%c%hd%d%ld%lld%f%lf",&a,&b,&c,&d,&e,&f,&g);
	printf("The ¡®char¡¯ variable is %c, it takes %lf byte.",a,sizeof(a));
}
