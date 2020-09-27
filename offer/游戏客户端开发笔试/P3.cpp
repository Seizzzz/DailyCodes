#include <iostream>
#include <vector>
using namespace std;

vector<int> in;

int findpart(vector<int> v)
{
    for (int i = 0; i < v.size() - 1; ++i)
    {
        if (v[i] > v.back())
        {
            for (int j = i; j < v.size() - 1; ++j)
            {
                if (v[j] > v.back());
                else return -1;
            }
            return i;
        }
    }
    return 0;
}

void dfs(vector<int> v)
{
    if (v.size() <= 2) return;

    int p = findpart(v);
    if (p != -1);
    else
    {
        cout << "NO" << endl;
        exit(0);
    }

    vector<int> left;
    for (int i = 0; i < p; ++i) left.push_back(v[i]);
    dfs(left);

    vector<int> right;
    for (int i = p; i < v.size() - 1; ++i) right.push_back(v[i]);
    dfs(right);
}

int main()
{
    ios::sync_with_stdio(false);

    int cnt;
    cin >> cnt;
    while (cnt--)
    {
        int x; cin >> x;
        in.push_back(x);
    }

    dfs(in);
    cout << "YES" << endl;
}