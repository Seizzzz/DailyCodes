#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int chain[100005];

struct node
{
	int from;
	int to;
};
vector<node> ans;

bool deal(int amount)
{
	for (int i = 1; i <= n; ++i)
	{
		int val = 0;
		for (int j = i; j <= n; ++j)
		{
			val += chain[j];
			if (val == amount)
			{
				node k; k.from = i; k.to = j;
				ans.push_back(k);
			}
			else if (val > amount) break;
		}
	}
	if (ans.empty()) return false;
	return true;
}

bool cmp(node a, node b)
{
	if (a.from == b.from) return a.to < b.to;
	return a.from < b.from;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;

	for (int i = 1; i <= n; ++i) cin >> chain[i];

	while (!deal(m++)) ans.clear();
	sort(ans.begin(), ans.end(), cmp);

	for (auto i : ans)
	{
		cout << i.from << "-" << i.to << endl;
	}

	return 0;
}