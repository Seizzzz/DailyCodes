#include <bits/stdc++.h>
using namespace std;

//q������������ž�������ı��λ��... 

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
	int trans[60]; //�������� ��ǵ�λ�þ�Ȼ�������������� ���� 
	 
	for(int i=1;i<=total;i++)
	{
		cin >> v >> p >> q;
		if(q)
		{
			if(item[trans[q]].add) //����һ������ ����item2��
			{
				item[trans[q]].item2_price=v/10;
				item[trans[q]].item2_importance=p;
			}
			else //����item1 
			{
				item[trans[q]].item1_price=v/10;
				item[trans[q]].item1_importance=p;
			}
			item[trans[q]].add++;
		}
		else //�������� 
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
		int delta1=item[i].main_price*item[i].main_importance; //ֻ������ 
		int delta2=delta1+item[i].item1_price*item[i].item1_importance; //�����͸���1 
		int delta3=delta1+item[i].item2_price*item[i].item2_importance; //�����͸���2
		int delta4=delta2+delta3-delta1; //����������1�͸���2 
		
		for(int j=equalmoney;j;j--)
		{
			dp[i][j]=dp[i-1][j]; //��ʼ 
			if(j>=item[i].main_price)
				dp[i][j]=max(dp[i][j],dp[i-1][j-item[i].main_price]+delta1); //ѡ��ѡ���� 
			if(j>=item[i].main_price+item[i].item1_price)
				dp[i][j]=max(dp[i][j],dp[i-1][j-item[i].main_price-item[i].item1_price]+delta2); //�����͸���1
			if(j>=item[i].main_price+item[i].item2_price)
				dp[i][j]=max(dp[i][j],dp[i-1][j-item[i].main_price-item[i].item2_price]+delta3); //�����͸���2
			if(j>=item[i].main_price+item[i].item1_price+item[i].item2_price)
				dp[i][j]=max(dp[i][j],dp[i-1][j-item[i].main_price-item[i].item1_price-item[i].item2_price]+delta4);
		}
		//cout << dp[i][equalmoney] << endl;
	}
	
	cout << 10*dp[totalmain][equalmoney] << endl;

	return 0;
}

