#include <iostream>
#include <string>
using namespace std;

string convert(int x)
{
	string s;
	if (x == 0)
	{
		s.append("00");
		return s;
	}

	while (x)
	{
		char c = ((x % 13) > 9 ? (x % 13) + 'A' - 10 : (x % 13) + '0');
		s.insert(s.begin(),c);
		x /= 13;
	}

	if (s.length() == 1)
	{
		s.insert(s.begin(), '0');
	}

	return s;
}

int main()
{
	std::ios::sync_with_stdio(false);
	
	cout << "#";
	for (int i = 0; i < 3; ++i)
	{
		int x;
		cin >> x;
		cout << convert(x);
	}
	cout << endl;

	return 0;
}