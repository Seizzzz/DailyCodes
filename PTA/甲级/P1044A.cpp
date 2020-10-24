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
	
	int left = 1, right = 0;
	int err = 0x7fffffff;
	int val = 0;
	while (right <= n)
	{
		if (val < m)
		{
			val += chain[++right];
			if (right > n) break;
		}
		else if (val >= m)
		{
			val -= chain[left++];
		}

		int nowerr = val - m;
		if (nowerr <= err && nowerr >= 0)
		{
			if (nowerr < err)
			{
				ans.clear();
				err = nowerr;
			}
			node tmp; tmp.from = left; tmp.to = right;
			ans.push_back(tmp);
		}
	}

	for (auto i : ans)
	{
		cout << i.from << "-" << i.to << endl;
	}

	return 0;
}