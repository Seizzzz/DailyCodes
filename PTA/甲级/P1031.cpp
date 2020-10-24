#include <iostream>
using namespace std;

int main()
{
	string s;
	cin >> s;

	int line = (s.length() - 1) / 3;
	int st = 0, ed = s.length() - 1;
	int space = line;
	if (s.length() % 3 == 0) ++space;
	else if (s.length() % 3 == 1) --space;
	for (int i = 0; i < line; ++i)
	{
		cout << s[st++];
		for (int j = 0; j < space; ++j) cout << " ";
		cout << s[ed--];
		cout << endl;
	}
	for (; st <= ed; ++st) cout << s[st];
	

	return 0;
}