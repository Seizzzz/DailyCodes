#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	while(n)
	{
		create:{};
		if(n--);
		else break;
		string s;
		cin >> s;
		
		int len = s.length();
		int left;
		for(left = 0;left<s.length();++left)
		{
			if(s[left] == 'P') break;
			else if(s[left] == 'A');
			else
			{
				cout << "NO" << endl;
				goto create;
			}
		}
		
		int right;
		for(right = s.length() - 1;right >= 0;right--)
		{
			if(s[right] == 'T') break;
			else if(s[right] == 'A');
			else
			{
				cout << "NO" << endl;
				goto create;
			}
		}
		
		if(left < right);
		else
		{
			cout << "NO" << endl;
			goto create;
		}
		
		s = s.substr(left+1,right-left-1);
		if(s.length() == 0)
		{
			cout << "NO" << endl;
			goto create;
		}
		else
		{
			for(int i=0;i<s.length();++i)
			{
				if(s[i]=='A');
				else
				{
					cout << "NO" << endl;
					goto create;
				}
			}
			
			if(left * (right-left-1) == len-right-1) cout << "YES" << endl;
			else
			{
				cout << "NO" << endl;
				goto create;
			}
		}
	}
	

	return 0;
}

