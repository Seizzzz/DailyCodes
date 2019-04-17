#include <stdio.h>

int main()
{
	int count=0;
	float sum;
	scanf("%f",&sum);
	float s=2,distance=0;
	while(distance<(float)sum)
	{
	distance +=s;
	s=0.98*s;
	count++;
	//\printf("%f\n",distance);
	}
	printf("%d",count);
	return 0;
}
