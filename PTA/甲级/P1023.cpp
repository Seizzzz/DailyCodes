#include <bits/stdc++.h>
using namespace std;

int bucket[10];

int main()
{
	std::ios::sync_with_stdio(false);
	
	vector<int> digits;
	char tmp;
	while(cin >> tmp) digits.push_back(tmp-'0');
	for(int i=0;i<digits.size();++i) --bucket[digits[i]];
	
	for(int i=0;i<digits.size();++i) digits[i] <<= 1;
	for(int i=1;i<digits.size();++i)
	{
		if(digits[i]>9) digits[i-1] += (digits[i]/10);
		digits[i] %= 10;
	}
	
	for(int i=1;i<digits.size();++i) ++bucket[digits[i]];
	++bucket[digits[0]%10];
	if(digits[0]>9) ++bucket[digits[0]/10];
	
	bool flag=false;
	for(int i=0;i<10;++i)
	{
		if(bucket[i])
		{
			flag = true;
			break;
		}
	}
	cout << (flag? "No":"Yes") << endl;
	
	for(int i=0;i<digits.size();++i) cout << digits[i];
	cout << endl;

	return 0;
}

