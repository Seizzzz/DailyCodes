#include <stdio.h>

int pai(int n)
{
	int hang=1;
	for(;hang*(hang+1)/2<n;hang++);
	return hang;
}

int main()
{
	int n;
	scanf("%d",&n);
	
	int atpai=pai(n);
	int cha=atpai*(atpai+1)/2 - n;
	
	if(atpai%2) printf("%d/%d\n",cha+1,atpai-cha);
	else printf("%d/%d\n",atpai-cha,cha+1);

	return 0;
}

