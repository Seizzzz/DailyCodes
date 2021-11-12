#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int m;
	cin >> m;

	vector<int> num;
	
	char c; cin >> c;
	int d = 0;
	while(cin >> c)
	{
		if (c == '}')
		{
			num.push_back(d);
			break;
		}
		else if (c == ',')
		{
			num.push_back(d);
			d = 0;
			continue;
		}
		else if (!isdigit(c)) continue;

		string str = string(&c, 1);
		int nowd = atoi(str.c_str());
		d *= 10;
		d += nowd;
	}
	cout << '[';

	vector<vector<int>> table(m);
	for (auto i = 0; i < num.size(); ++i)
	{
		table[num[i] % m].push_back(num[i]);
	}
	
	for (auto i = 0; i < m; ++i)
	{
		cout << '{';

		if(!table[i].empty())
		{
			cout << table[i][0];
			if(table[i].size() > 1)
			{
				for(auto j = 1;j < table[i].size();++j) cout << "," << table[i][j];
			}
		}
		
		if (i == m - 1) cout << '}';
		else cout << "},";
	}

	cout << ']';

	return 0;
}