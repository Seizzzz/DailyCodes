#include <stdio.h>
#include <math.h>

long long int stairs(int i)
{
	long long int s=1;
	for(;i>0;i--) s*=i;
	return s;
}

float calc(float x,int cnt)
{
	float c=pow(x,cnt)/(float)stairs(cnt);
	//printf("%f %f %f\n",pow(x,cnt),(float)stairs(cnt),c);
	return c;
}


int main()
{
	int cnt=0; 
	float x,sum=0;
	scanf("%f",&x);
	while(fabs(calc(x,cnt)>1e-8))
	{
		sum+=calc(x,cnt);
		cnt++;
	}
	printf("%.4f\n",sum);
	
	
	return 0;
}
