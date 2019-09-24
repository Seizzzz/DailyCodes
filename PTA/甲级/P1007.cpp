#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	vector<int> num;
	int tmp;
	for(int i=0;i<n;++i)
	{
		cin >> tmp;
		num.push_back(tmp);
	}
	
	vector<int> ans;
	vector<int> sv_ans;
	int maxhere=0,maxsum=0;
	
	for(vector<int>::iterator ptr=num.begin();ptr<num.end();++ptr)
	{
		if(maxhere < 0)
		{
			maxhere = (*ptr);
			ans.clear();
			ans.push_back(*ptr);
		}
		else
		{
			maxhere += (*ptr);
			ans.push_back(*ptr);
		}
		
		if(maxhere > maxsum || (maxsum==0 && maxhere==0))
		{
			maxsum = maxhere;
			sv_ans = ans;
		}
	}
	
	if(sv_ans.empty()) cout << "0 " << num.front() << " " << num.back() << endl;
	else cout << maxsum << " " << sv_ans.front() << " " << sv_ans.back() << endl;

	return 0;
}

