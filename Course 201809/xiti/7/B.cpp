#include <stdio.h>
#include <ctype.h>

int main()
{
	char temp;
	int cnt[130]={0};
	while((temp=getchar())!='\n')
	{
		if((temp>='a' && temp<='z')||(temp>='A' && temp<='Z')) cnt[temp]++;
	}
	
	for(int i='A';i<='z';i++)
	{
		if(cnt[i]!=0) printf("The character %c has presented %d times.\n",i,cnt[i]);
	}

	return 0;
}

