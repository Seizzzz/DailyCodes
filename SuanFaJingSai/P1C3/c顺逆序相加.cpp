#include <stdio.h>
#include <math.h>

int main()
{
	int sum=0;
	char temp;
	
	/*
	int isnuming=-1;
	while((temp=getchar())!='\n')
	{
		if(temp==' ') isnuming=-1;
		else
		{
			isnuming++;
			sum+= (temp-'0')*(int)pow(10,isnuming);
		}
	}
	*/ //�������
	
	/*
	int tempnum=0;
	while((temp=getchar())!='\n')
	{
		if(temp==' ')
		{
			sum+=tempnum;
			tempnum=0;
		}
		else
		{
			tempnum*=10;
			tempnum+=temp-'0';
		}
	}
	sum+=tempnum;
	*/ //˳����� 
	
	printf("%d",sum);

	return 0;
}

