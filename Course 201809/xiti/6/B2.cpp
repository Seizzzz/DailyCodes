#include<stdio.h>
#define N 10

void adjust(int a[],int n)
{
	int i,b[N],s=1;
	for(i=1;i<N;i++)
	{
	if(a[0]==a[i]) s=s+1;
	}
	if(s==10) return;
	
	else
	{
	for(i=0;i<10;i++)
	{
	if(a[i]%2!=0) a[i]++;
	}

	for(i=0;i<N;i++) b[i]=a[i]/2;
	for(i=0;i<N;i++) a[i]=a[i]/2+b[(i+9)%10];
	printf("%d: ",n);
	for(i=0;i<N;i++)
	printf("%d ",a[i]);
	printf("\n");
	n++;
	adjust(a,n);
	}
}

int main()
{
int a[N]={10,2,8,22,16,4,10,6,14,20};
printf("0: ");
for(int i=0;i<N;i++)
printf("%d ",a[i]);
printf("\n");
adjust(a,1);
}
