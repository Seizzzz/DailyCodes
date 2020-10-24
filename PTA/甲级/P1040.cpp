#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string s;
int maxlength = 1;

void detect_odd(int pos)
{
	int left = pos - 1, right = pos + 1, len = 1;
	while (left >= 0 && right < s.length())
	{
		if (s[left--] == s[right++]) len = len + 2;
		else break;
	}
	maxlength = max(maxlength, len);
	return;
}

void detect_even(int pos)
{
	if (s[pos] != s[pos + 1]) return;
	int left = pos - 1, right = pos + 2, len = 2;
	while (left >= 0 && right < s.length())
	{
		if (s[left--] == s[right++]) len = len + 2;
		else break;
	}
	maxlength = max(maxlength, len);
	return;
}

int main()
{
	ios::sync_with_stdio(false);

	getline(cin, s);

	for (unsigned i = 0; i < s.length(); ++i)
	{
		detect_odd(i);
		detect_even(i);
	}

	cout << maxlength << endl;

	return 0;
}