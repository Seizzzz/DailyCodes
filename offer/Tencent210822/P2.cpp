#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int T;
	cin >> T;

	while(T--)
	{
		int n; cin >> n;
		vector<int> magic(n);
		for (int i = 0; i < n; ++i) cin >> magic[i];
		sort(magic.begin(), magic.end(), [](int a, int b)
		{
			return a > b;
		});

		int total = 0;
		for (int i = 0; i < n; ++i)
		{
			int val = magic[i];
			total += val;
			total %= 1000000007;
			for (int j = i + 1; j < n; ++j) magic[j] += val;
		}
		cout << total << endl;
	}
}