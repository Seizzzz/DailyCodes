#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int n, k; //stu cour

struct stu
{
	string name;
	vector<int> course;
};

int main()
{
	std::ios::sync_with_stdio(false);
	cin >> n >> k;

	map<string, stu> mymap;
	int nowptr = 0;

	for (int i = 0; i < k; ++i)
	{
		int courindex, stunum;
		cin >> courindex >> stunum;
		for (int j = 0; j < stunum; ++j)
		{
			string name;
			cin >> name;
			auto iter = mymap.find(name);
			if (iter != mymap.end())
			{
				iter->second.course.push_back(courindex);
			}
			else
			{
				stu tmp;
				tmp.course.push_back(courindex);
				tmp.name = name;
				mymap.insert(pair<string, stu>(name, tmp));
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		string tosearch;
		cin >> tosearch;
		cout << tosearch << " ";
		auto iter = mymap.find(tosearch);
		if (iter == mymap.end())
		{
			cout << 0 << endl;
			continue;
		}
		sort(iter->second.course.begin(), iter->second.course.end());
		cout << iter->second.course.size() << " ";
		auto k = iter->second.course.begin();
		for (; k != iter->second.course.end() - 1; ++k)
		{
			cout << (*k) << " ";
		}
		cout << (*k) << endl;
	}

	return 0;
}