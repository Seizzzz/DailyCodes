#include "basic.h"

int BasicMethod::sol()
{
	for (int i = 1; i <= number; ++i)
	{
		for (int j = capacity; j >= 0; --j)
		{
			dp[i][j] = dp[i - 1][j];
			if (j >= weight[i]) dp[i][j] = max(dp[i][j], dp[i - 1][j - weight[i]] + value[i]);
		}
	}
	
	return dp[number][capacity];
}

void BasicMethod::printItems()
{
	int nowWeight = capacity;
	vector<int> res;
	
	for (int i = number; i >= 1; --i)
	{
		if (dp[i][nowWeight] > dp[i - 1][nowWeight])
		{
			nowWeight -= weight[i];
			res.push_back(i);
		}
	}
	
	for (int i = res.size() - 1; i >= 0; --i) cout << res[i] << " ";
	cout << endl;
}

BasicMethod::BasicMethod(int num, int cap, int* w, int* v) : number(num), capacity(cap), weight(w), value(v)
{
	dp = new int* [num + 1];
	for (int i = 0; i < num + 1; ++i) dp[i] = new int[cap + 1];

	for (int j = 0; j <= cap; ++j) dp[0][j] = 0;

	cout << sol() << endl;
	printItems();
}

BasicMethod::~BasicMethod()
{
	for (int i = 0; i < number + 1; ++i) delete[] dp[i];
	delete[] dp;
}
