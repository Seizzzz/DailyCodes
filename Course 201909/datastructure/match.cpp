#include <bits/stdc++.h>
using namespace std;

bool match(string s)
{
	stack<char> stk;
	for(int i = 0; i < s.length(); ++i)
	{
		switch(s[i])
		{
			//Ϊ������ʱ
			case '(':
			case '[':
			case '{':{
				stk.push(s[i]);
				break;
			}
			//Ϊ������ʱ 
			case ')':{  
				if(stk.top() == '(') stk.pop();
				else return false;
				break;
			}
			case ']':{
				if(stk.top() == '[') stk.pop();
				else return false;
				break;
			}
			case '}':{
				if(stk.top() == '{') stk.pop();
				else return false;
				break;
			}
			default: continue; //�����ַ� 
		}
	}
	if(stk.empty()) return true; //��û��δƥ������������� 
	return false;
}

int main()
{
	std::ios::sync_with_stdio(false);
	
	string tmp;
	cin >> tmp;
	cout << match(tmp);

	return 0;
}

