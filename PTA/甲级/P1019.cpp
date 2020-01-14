#include <bits/stdc++.h>
using namespace std;

bool judge(vector<int> s)
{
	int i = 0,j = s.size() - 1;
	
	while(i<j)
	{
		if(s[i++]==s[j--]);
		else return false;
	}
	return true;
}

vector<int> dec2any(int x,int b)
{
	vector<int> ans;
	if(x == 0) ans.push_back(x);
	while(x)
	{
		ans.push_back(x%b);
		x /= b;
	}
	return ans;
}

int main()
{
	std::ios::sync_with_stdio(false);
	
	int n,b;
	cin >> n >> b;
	
	vector<int> s = dec2any(n,b);
	cout << ((judge(s))? "Yes":"No") << endl;
	cout << s[s.size()-1];
	for(int i=s.size()-2;i>=0;--i) cout << " " << s[i];

	return 0;
}

