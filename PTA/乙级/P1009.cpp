#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	
	stack<string> word;
	string tmp;
	
	while(cin >> tmp) word.push(tmp);
	
	cout << word.top();
	word.pop();
	while(!word.empty())
	{
		cout << " " << word.top();
		word.pop();
	}
	
	cout << endl;

	return 0;
}

