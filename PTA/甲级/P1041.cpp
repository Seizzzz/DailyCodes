#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	
	int n; cin >> n;
	vector<int> ans;
	map<int, bool> mymap;

	for (int i = 0; i < n; ++i)
	{
		int num; cin >> num;
		auto ptr = mymap.find(num);
		if (ptr == mymap.end())
		{
			mymap.insert(pair<int, bool>(num, true));
			ans.push_back(num);
		}
		else ptr->second = false;
	}

	for (auto i = ans.begin(); i != ans.end(); ++i)
	{
		if ((mymap.find(*i))->second == true)
		{
			cout << *i << endl;
			return 0;
		}
	}
	cout << "None" << endl;

	return 0;
}