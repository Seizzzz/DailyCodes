#include <iostream>
#include <vector>
using namespace std;

const int numCity = 5;

int map[numCity][numCity];
void init() {
    for (int i = 0; i < numCity; ++i)
    {
        for (int j = 0; j < numCity; ++j) map[i][j] = 0;
    }
}
void readin()
{
    map[0][1] = 10;
    map[0][2] = 13;
    map[1][2] = 10;
    map[1][3] = 17;
    map[2][3] = 10;
    map[2][4] = 21;
    map[3][4] = 10;
}

int sv_money = 2147483647;
vector<int> sv_path;

void dfs(int from, int to, int money, vector<int>& path)
{
    if (from == to)
    {
        if (money < sv_money)
        {
            sv_money = money;
            sv_path = path;
        }
        return;
    }
    for (int nxt = 0; nxt < numCity; ++nxt)
    {
        bool ved = false;
        for (auto v : path)
        {
            if (v == nxt) ved = true;
        }
        if (nxt == from || map[from][nxt] == 0) ved = true;
        if (ved) continue;

        path.push_back(nxt);
        money += map[from][nxt];
        dfs(nxt, to, money, path);
        money -= map[from][nxt];
        path.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);

    init();
    readin();

    char from, to;
    cin >> from >> to;
    int intfrom = from - 'A', intto = to - 'A';

    vector<int> p;
    dfs(intfrom, intto, 0, p);

    cout << from;
    for (auto i : sv_path)
    {
        cout << ',' << (char)('A' + i);
    }
    cout << endl;
    cout << sv_money << endl;


}