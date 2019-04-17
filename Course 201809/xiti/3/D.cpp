#include <stdio.h>

int main()
{
	int n1,n2,n3,n4,f;
	
	scanf("%1d%1d%1d%1d%1d",&n1,&n2,&n3,&n4,&f);

	if(f==1) //jia
	{
		n1+=7;
		n1=n1%10;
		n2+=7;
		n2=n2%10;
		n3+=7;
		n3=n3%10;
		n4+=7;
		n4=n4%10;
		
		int tran;
		tran=n1; n1=n3; n3=tran;
		tran=n2; n2=n4; n4=tran;
		
		printf("After encrypting the number is %d%d%d%d\n",n1,n2,n3,n4);
	}
	
	
	
	if(f==0) //jie
	{
		int tran;
		tran=n2; n2=n4; n4=tran;
		tran=n1; n1=n3; n3=tran;
		
		n1=(n1+3>9)? n1+3-10:n1+3;
		n2=(n2+3>9)? n2+3-10:n2+3;
		n3=(n3+3>9)? n3+3-10:n3+3;
		n4=(n4+3>9)? n4+3-10:n4+3;
		
		printf("After decrypting the number is %d%d%d%d\n",n1,n2,n3,n4);		
	}
	
	
	return 0;
}
