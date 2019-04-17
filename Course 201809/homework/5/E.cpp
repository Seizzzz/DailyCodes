#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	
	long long fz=1,fm=3;
	
	for(int i=3;i<=n;i+=2)
	{
		long long fm2=i+2;
		long long fz2=i;
		long long fm1=fm2*fm;
		long long fz1=fz2*fm+fz*fm2;
		fz=fz1;
		fm=fm1;
		//
		long long a=fm>fz? fm:fz;
		long long b=fz<fm? fz:fm;
		long long extra=a%b;
		while (extra!=0)
		{
			a=b;
			b=extra;
			extra=a%b;
		}
		
		fz/=b;
		fm/=b;
	}
	
	printf("%lld/%lld\n",fz,fm);

	return 0;
}
