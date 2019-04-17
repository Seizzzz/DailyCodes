#include <bits/stdc++.h>
using namespace std;

//q的所属主件编号就是输入的编号位置... 

struct main
{
	int add;
	int main_price;
	int main_importance;
	int item1_price;
	int item1_importance;
	int item2_price;
	int item2_importance;
}item[60];

int money,total,totalmain=0;
int dp[60][3200];

void init()
{
	cin >> money >> total;
	int v,p,q;
	int trans[60]; //万恶的题意 标记的位置竟然还包括附件在内 佛了 
	 
	for(int i=1;i<=total;i++)
	{
		cin >> v >> p >> q;
		if(q)
		{
			if(item[trans[q]].add) //已有一个附件 输入item2内
			{
				item[trans[q]].item2_price=v/10;
				item[trans[q]].item2_importance=p;
			}
			else //输入item1 
			{
				item[trans[q]].item1_price=v/10;
				item[trans[q]].item1_importance=p;
			}
			item[trans[q]].add++;
		}
		else //输入主件 
		{
			item[++totalmain].main_price=v/10;
			item[totalmain].main_importance=p;
			trans[i]=totalmain;
		}
	}
	return;
}

int main()
{
	std::ios::sync_with_stdio(false);
	init();
	
	
	int equalmoney=money/10;
	for(int i=1;i<=totalmain;i++)
	{
		int delta1=item[i].main_price*item[i].main_importance; //只有主件 
		int delta2=delta1+item[i].item1_price*item[i].item1_importance; //主件和附件1 
		int delta3=delta1+item[i].item2_price*item[i].item2_importance; //主件和附件2
		int delta4=delta2+delta3-delta1; //主件、附件1和附件2 
		
		for(int j=equalmoney;j;j--)
		{
			dp[i][j]=dp[i-1][j]; //初始 
			if(j>=item[i].main_price)
				dp[i][j]=max(dp[i][j],dp[i-1][j-item[i].main_price]+delta1); //选不选主件 
			if(j>=item[i].main_price+item[i].item1_price)
				dp[i][j]=max(dp[i][j],dp[i-1][j-item[i].main_price-item[i].item1_price]+delta2); //主件和附件1
			if(j>=item[i].main_price+item[i].item2_price)
				dp[i][j]=max(dp[i][j],dp[i-1][j-item[i].main_price-item[i].item2_price]+delta3); //主件和附件2
			if(j>=item[i].main_price+item[i].item1_price+item[i].item2_price)
				dp[i][j]=max(dp[i][j],dp[i-1][j-item[i].main_price-item[i].item1_price-item[i].item2_price]+delta4);
		}
		//cout << dp[i][equalmoney] << endl;
	}
	
	cout << 10*dp[totalmain][equalmoney] << endl;

	return 0;
}

