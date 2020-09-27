#include <vector>
#include <iostream>

using namespace std;

int N, x;
vector<int> U;
vector<int> V;
vector<int> W;

vector<pair<int, int>> nextpath(int st) //返回起点为他的所有道路
{
	vector<pair<int,int>> res;
	for (int i = 0; i < U.size(); ++i)
	{
		if (U[i] == st) res.push_back(pair<int,int>(V[i],i)); //目的地 道路序号
		else if (V[i] == st) res.push_back(pair<int, int>(U[i], i));
	}
	return res;
}

long long pathTotalW[100005];

void dfs(int from, int to, vector<pair<int,int>>& path) //道路序号 权值
{
	if (from == to)
	{
		for (auto i : path) pathTotalW[i.first] += i.second;
	}


	vector<pair<int, int>> next = nextpath(from);
	for (auto nxt : next)
	{
		bool ved = false;
		for (auto visited : path)
		{
			if (U[visited.first] == nxt.first || V[visited.first] == nxt.first) ved = true;
		}
		if (ved) continue;

		path.push_back(pair<int,int>(nxt.second, W[nxt.second]));
		dfs(nxt.first, to, path);
		path.pop_back();
	}
}

long long solve(int n, vector<int>& u, vector<int>& v, vector<int>& w) { //
	// 补全代码
	for (int i = 1; i <= n; ++i)
	{
		for (int j = i+1; j <= n; ++j)
		{
			vector<pair<int, int>> pa;
			dfs(i, j, pa);
		}
	}

	long long max = 0;
	for (int i = 0; i < N; ++i)
	{
		if (pathTotalW[i] > max) max = pathTotalW[i];
	}

	return max;
}


int main() {
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> x;
		U.push_back(x);
	}
	for (int i = 0; i < N - 1; i++) {
		cin >> x;
		V.push_back(x);
	}
	for (int i = 0; i < N - 1; i++) {
		cin >> x;
		W.push_back(x);
	}
	
	cout << solve(N, U, V, W) << endl;
}