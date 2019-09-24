#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	vector<int> digit;
	
	while(n--)
	{
		int tmp; 
		cin >> tmp;
		digit.push_back(tmp);
	}
	
	vector<int> ans = digit;

	for(vector<int>::iterator ptr = digit.begin();ptr < digit.end();++ptr)
	{
		int num = *ptr;
		while(num != 1)
		{
			if(num & 1) num = (num*3 + 1) >> 1;
			else num = num >> 1;
			vector<int>::iterator fptr = find(ans.begin(),ans.end(),num);
			if(fptr != ans.end()) ans.erase(fptr);
		}
	}
	
	sort(ans.begin(),ans.end());
	
	for(vector<int>::iterator ptr = ans.end() - 1;ptr >= ans.begin();--ptr)
	{
		if(ptr == ans.end() - 1) cout << *ptr;
		else cout << " " << *ptr;
	}
	
	cout << endl;

	return 0;
}

