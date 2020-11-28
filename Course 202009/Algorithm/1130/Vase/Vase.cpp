#include <iostream>
#include <vector>
using namespace std;

int** beauty; //beauty[i][j] 第i朵花放在第j个花瓶的美学值
int** dp;
int F, V;

void cal()
{
	for (int i = 1; i <= F; ++i)
	{
		for (int j = 1; j <= V; ++j)
		{
			//不放、放
			dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - 1] + beauty[i][j]);
		}
	}
}

void trace()
{
	vector<int> ret(F + 1);

	for (int i = 1; i <= F; ++i)
	{
		for (int j = 1; j <= V; ++j)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}

	int j = V, i = F;
	while(i)
	{
		if(dp[i][j] == dp[i - 1][j - 1] + beauty[i][j])
		{
			ret[i] = j;
			--i; --j;
			continue;
		}
		--j;
	}

	cout << dp[F][V] << endl;
	for (int i = 1; i <= F; ++i) cout << ret[i] << " ";
	cout << endl;
}

int main()
{
	cin >> F >> V;

	beauty = new int* [F + 1];
	for (int i = 0; i <= F; ++i) beauty[i] = new int[V + 1];
	dp = new int* [F + 1];
	for (int i = 0; i <= F; ++i) dp[i] = new int[V + 1];

	for (int i = 1; i <= F; ++i)
		for (int j = 1; j <= V; ++j) cin >> beauty[i][j];

	for (int i = 0; i <= F; ++i) dp[i][0] = 0;
	for (int j = 0; j <= V; ++j) dp[0][j] = 0;

	//
	cal();
	trace();
	//
	
	for (int i = 0; i < F; ++i) delete[] beauty[i];
	delete[] beauty;
	for (int i = 0; i < F; ++i) delete[] dp[i];
	delete[] dp;
	
}