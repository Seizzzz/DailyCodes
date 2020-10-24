#include <stdio.h>

void swap(long long* a,long long* b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

void ssort(long long* a,int start,int end)
{
	if(start>=end) return;
	
	int mid=a[end];
	int left=start,right=end-1;
	
	while(left<right)
	{
		while(a[left]<mid && left<right) left++;
		while(a[right]>mid && right>left) right--;
		swap(&a[left],&a[right]);
	}
	
	if(a[left]>a[end]) swap(&a[left],&a[end]);
	
	ssort(a,start,left-1);
	ssort(a,left+1,end);
}

int main()
{
	int n;
	scanf("%d",&n);
	
	long long a[n];
	for(int i=0;i<n;i++) scanf("%lld",&a[i]);
	
	ssort(a,0,n-1);
	
	for(int i=0;i<n;i++) printf("%lld ",a[i]);

	return 0;
}

