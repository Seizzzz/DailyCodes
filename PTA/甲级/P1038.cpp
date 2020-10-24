#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> num;
bool cmp(string a, string b)
{
	return a + b < b + a;
}

int main()
{
	std::ios::sync_with_stdio(false);

	int n; cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string s; cin >> s;
		num.push_back(s);
	}

	sort(num.begin(), num.end(), cmp);

	int st = 0;
	for (; st < num.size(); ++st)
	{
		if (atoi(num[st].c_str()) != 0) break;
	}
	if (st == num.size())
	{
		cout << 0 << endl;
		return 0;
	}
	int first = atoi(num[st++].c_str());
	if (first != 0) cout << first;
	for (; st < num.size(); ++st) cout << num[st];
	cout << endl;

	return 0;
}