#include <stdio.h>

int main()
{
	double s,x;
	scanf("%lf%lf",&s,&x);
	
	double step=7,distance=0;
	
	int detect=0;
	
	while(distance <= s+x)
	{
		if(distance>=s-x && distance<=s+x)
		{
			if(detect)
			{
				printf("y\n");
				return 0;
			}
			else detect=1;
		}
		distance+=step;
		step*=0.98;
	}
	printf("n\n");
	return 0;
}

