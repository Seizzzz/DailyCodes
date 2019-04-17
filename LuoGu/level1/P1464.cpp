#include <stdio.h>

long long save[200][200][200]={0,0,0};

long long w(long long a,long long b,long long c)
{
	if(a<=0 || b<=0 || c<=0) return 1;
	else if(save[a][b][c]) 
		return save[a][b][c];
	else if(a>20 || b>20 || c>20)
		save[a][b][c]=w(20,20,20);
	else if(a<b && b<c) 
		save[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
	else save[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);

	return save[a][b][c];
}

int main()
{
	long long a=0,b=0,c=0;
	scanf("%lld %lld %lld",&a,&b,&c);
	
	while(a!=-1 || b!=-1 || c!=-1)
	{
		printf("w(%lld, %lld, %lld) = %lld\n",a,b,c,w(a,b,c));
		scanf("%lld %lld %lld",&a,&b,&c);
	}

	return 0;
}

