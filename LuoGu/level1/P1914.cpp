#include <stdio.h>
#include <string.h>

int main()
{
	char a[55];
	
	int n;
	scanf("%d",&n);
	scanf("%s",a);
	
	int k=strlen(a);
	for(int i=0;i<k;i++)
	{
		a[i]= (a[i]+n>'z') ? a[i]+n-26:a[i]+n;
	}
	
	puts(a);
	//printf("\n");
	

	return 0;
}

