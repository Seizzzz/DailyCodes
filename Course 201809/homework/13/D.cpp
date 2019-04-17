#include <stdio.h>

struct team
{
	char name[23];
	int zong;
	int shi;
	int jifen;
};

int comp(struct team p1,struct team p2)
{
	// 0 ÎÞÐè»»Ðò    1 »»Ðò 
	if(p1.jifen > p2.jifen) return 0;
	else if(p1.jifen < p2.jifen) return 1;
	else //p1.jifen == p2.jifen
	{
		if(p1.zong - p1.shi > p2.zong - p2.shi) return 0;
		else if(p1.zong - p1.shi < p2.zong - p2.shi) return 1;
		else
		{
			if(p1.zong > p2.zong) return 0;
			else if(p1.zong < p2.zong) return 1;
		}
	}
	return 0;
}


int main()
{
	struct team a;
	struct team b;
	struct team c;
	struct team d;
	
	scanf("%s",a.name);
	scanf("%d",&a.zong);
	scanf("%d",&a.shi);
	scanf("%d",&a.jifen);
	scanf("%s",b.name);
	scanf("%d",&b.zong);
	scanf("%d",&b.shi);
	scanf("%d",&b.jifen);
	scanf("%s",c.name);
	scanf("%d",&c.zong);
	scanf("%d",&c.shi);
	scanf("%d",&c.jifen);
	scanf("%s",d.name);
	scanf("%d",&d.zong);
	scanf("%d",&d.shi);
	scanf("%d",&d.jifen);
	
	if(comp(a,b)==0);
	else
	{
		struct team temp=a;
		a=b;
		b=temp;
	}
	if(comp(a,c)==0);
	else
	{
		struct team temp=a;
		a=c;
		c=temp;
	}
	if(comp(a,d)==0);
	else
	{
		struct team temp=a;
		a=d;
		d=temp;
	}
	if(comp(b,c)==0);
	else
	{
		struct team temp=b;
		b=c;
		c=temp;
	}
	if(comp(b,d)==0);
	else
	{
		struct team temp=b;
		b=d;
		d=temp;
	}
	if(comp(c,d)==0);
	else
	{
		struct team temp=c;
		c=d;
		d=temp;
	}
	
	printf("%s\n",a.name);
	printf("%s\n",b.name);
	printf("%s\n",c.name);
	printf("%s\n",d.name);
	
	
	
	
	return 0;
}

