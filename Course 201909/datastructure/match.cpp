#include <bits/stdc++.h>
using namespace std;

bool match(string s)
{
	stack<char> stk;
	for(int i = 0; i < s.length(); ++i)
	{
		switch(s[i])
		{
			//为左括号时
			case '(':
			case '[':
			case '{':{
				stk.push(s[i]);
				break;
			}
			//为右括号时 
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
			default: continue; //其他字符 
		}
	}
	if(stk.empty()) return true; //若没有未匹配完的左括号了 
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

