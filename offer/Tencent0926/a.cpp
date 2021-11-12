#include <iostream>
#include <vector>
using namespace std;

vector<int> a;
vector<int> mem;

int dfs(int nowat, int val)
{
    if (nowat >= a.size()) return 0;
    if (mem[nowat] != -1) return mem[nowat];
    int score = dfs(nowat + a[nowat], val + a[nowat]);
    mem[nowat] = score + a[nowat];
    return mem[nowat];
}

int main()
{
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--)
    {
        int n; cin >> n;
        a.resize(n);
        mem.resize(n);
        for (int i = 0; i < n; ++i) mem[i] = -1;
        for (int i = 0; i < n; ++i) cin >> a[i];

        int mxval = -1;
        for (int st = 0; st < n; ++st)
        {
            mxval = max(mxval, dfs(st, 0));
        }
        cout << mxval << endl;
    }
}