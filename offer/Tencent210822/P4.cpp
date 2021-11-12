#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include <algorithm>
using namespace std;

vector<string> dic;
int n, k;

string findmax(string now, int idx)
{
	if (idx >= n) return now;

	if(now.size() + 1 <= k)
	{
		string choice1 = findmax(now, idx + 1);
		string choice2 = findmax(now + dic[idx], idx + 1);

		if (choice1.size() < choice2.size()) return choice2;
		if (choice1 < choice2) return choice2;
		return choice1;
	}

	return now;
}

int main()
{
	cin >> n >> k;
	string str; cin >> str;
	dic.resize(n);
	for (int i = 0; i < n; ++i) dic[i] = str[i];

	cout << findmax("", 0) << endl;
}