/*
#include <iostream>
#include <vector>
using namespace std;

int cal(int pos, const vector<int>& a)
{
    int score = 0;
    int sz = a.size();
    while(pos < sz)
    {
        score += a[pos];
        pos = pos + a[pos];
    }
    return score;
}

int main()
{
    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;++i) cin >> a[i];

        int mxval = -1;
        for(int st=0;st<n;++st)
        {
            mxval = max(mxval, cal(st, a));
        }
        cout << mxval << endl;
    }
}
 */

/* p4

class Solution {
public:
    map<TreeNode*, TreeNode*> parent;
    map<int, TreeNode*> node;
    void dfs_parent(TreeNode* now, TreeNode* parent)
    {
        node.insert(pair<int, TreeNode*>(now->val, now));
        parent.insert(pair<TreeNode*, TreeNode*>(now, parent));
        if (now->left) dfs_parent(now->left, now);
        if (now->right) dfs_parent(now->right, now);
    }

    TreeNode* solve(TreeNode* root, vector<vector<int> >& b) {
        if (root == nullptr) return nullptr;
        dfs_parent(root, nullptr);

        for (int i = 0; i < b.size(); ++i)
        {
            int treeA = b[i][0];
            int treeB = b[i][1];
        }


        return nullptr;
    }
};
 */

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <vector>
#include <array>
#include <deque>
#include <algorithm>
#include <set>
using namespace std;

struct TreeNode;

map<TreeNode*, TreeNode*> parent;
map<int, TreeNode*> node;

void dfs()
{
    parent.insert(pair<TreeNode*, TreeNode*>(nullptr, nullptr));
}

using intlong = long long;

bool prioriry(const char& now, const char& top)
{
	switch (top)
	{
    case '@':
        //if (now == '@' || now == 'x' || now == '+') 
			return true;
        break;
    case 'x':
        if (now == 'x' || now == '+') 
            return true;
        break;
    case '+':
        if (now == '+') return true;
	}
	
    return false;
}

decltype(auto) bfs(int)
{
    tuple<int, double> tp;
	
    vector<int> a;
    return a.begin();
	
}

int main()
{
    string str; cin >> str;
    stack<char> symbol;
    stack<intlong> digit;
    set<int> st;
    vector<int> vc = { 7,4,2,8,5,1 };
    for (auto& it : vc) st.insert(it);

    vector<int> a;
    a.resize(1, -1);

    auto it = str.begin();
    while (it != str.end())
    {
    	if(isdigit(*it))
    	{
            intlong num = 0;
            do
            {
                num *= 10;
                num += ((*it) - '0');
                ++it;
            } while (it != str.end() && isdigit(*it));

            digit.push(num);
    	}
        else //issymbol
        {
        	if(symbol.empty() || !prioriry(*it, symbol.top()))
        	{
                symbol.push(*it);
        	}
            else
        	{
                intlong right = digit.top(); digit.pop();
                intlong left = digit.top(); digit.pop();
                switch (symbol.top())
                {
                    case '@':
                        digit.push(left | (left + right));
                        break;
                    case 'x':
                        digit.push(left * right);
                        break;
                    case '+':
                        digit.push(left + right);
                        break;
                	default:
                        return -1;
                }
                symbol.pop();
                symbol.push(*it);
        	}
            ++it;
        }
    }

	while(!symbol.empty())
	{
        intlong right = digit.top(); digit.pop();
        intlong left = digit.top(); digit.pop();
        switch (symbol.top())
        {
        case '@':
            digit.push(left | (left + right));
            break;
        case 'x':
            digit.push(left * right);
            break;
        case '+':
            digit.push(left + right);
            break;
        default:
            return -1;
        }
        symbol.pop();
	}

    cout << digit.top() << endl;

    return 0;
}