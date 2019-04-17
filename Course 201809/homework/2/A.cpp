#include<stdio.h>

int main()
{
    int min,max;
    scanf("%d%d",&min,&max);
    
    if(min==max)
    {
        printf("The two numbers are equal.");
    }
	else if(min>max)
    {
        min=max+min;
        max=min-max;
        min=min-max;
        printf("The larger number is %d, the smaller number is %d.",max,min);
    }
    else
    {
    	printf("The larger number is %d, the smaller number is %d.",max,min);
	}
    
    return 0;
}
