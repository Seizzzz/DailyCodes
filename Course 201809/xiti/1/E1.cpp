#include <stdio.h>
#include <math.h>

int main()
{
	long long int n,T,s;
	scanf("%d",&T);
	for(;T>0;T--)
	{
	scanf("%d",&n);
	s=n%10;
	
	
	if(s==0) printf("0\n");
	//
	else if(s==1) printf("1\n");
	//
	else if(s==2) {
		if((n-1)%4==0) printf("2\n");
		else if((n-2)%4==0) printf("4\n");
		if((n+1)%4==0) printf("8\n");
		if(n%4==0) printf("6\n");
		}
	else if(s==3){
		if((n-1)%4==0) printf("3\n");
		else if((n-2)%4==0) printf("9\n");
		if((n+1)%4==0) printf("7\n");
		if(n%4==0) printf("1\n");
		}
	else if(s==4){
		if((n-1)%2==0) printf("4\n");
		if(n%2==0) printf("6\n");
		}
	else if(s==5) printf("5\n");
	else if(s==6) printf("6\n");
	else if(s==7){
		if((n-1)%4==0) printf("7\n");
		else if((n-2)%4==0) printf("9\n");
		if((n+1)%4==0) printf("3\n");
		if(n%4==0) printf("1\n");
		}
	else if(n==8){
		if((n-1)%4==0) printf("8\n");
		else if((n-2)%4==0) printf("4\n");
		if((n+1)%4==0) printf("2\n");
		if(n%4==0) printf("6\n");
		}
	else if(s==9){
		if((n-1)%2==0) printf("9\n");
		if(n%2==0) printf("1\n");
		}
		
	//
	
	
	}
	return 0;
}
