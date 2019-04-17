#include <stdio.h>

/*
((a+b)*(c+d))
((a+b)*)c+d))
()a+b(*(c+d))
)(a+b)*(c+d)(

((())(()))
*/



int main()
{
	int zuo=0,you=0;
	int judge=0;
	
	char temp;
	while((temp=getchar())!='\n')
	{
		if(temp=='(') judge++;
		if(temp==')') judge--;
		
		if(judge<0)
		{
			printf("parentheses do not match!\n");
			return 0;
		}
	}
	
	if(zuo==you) printf("parentheses match!\n");
	return 0;
}

