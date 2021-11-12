#include <iostream>
#include <vector>
using namespace std;

bool isInVisible(int& i, int& j, const vector<int>& shape)
{
    const int& hi = shape[i];
    const int& hj = shape[j];
    for (int k = i + 1; k <= j - 1; ++k)
    {
        if (shape[k] > hi && shape[k] > hj) return true;
    }
    return false;
}

bool check(vector<int>& vec, const vector<int>& shape)
{
	for(int i=0; i<vec.size(); ++i)
	{
        if (vec[i] == -1) continue;
		for(int j=i+1; j<vec.size(); ++j)
		{
            if (vec[j] == -1) continue;
			if(!isInVisible(vec[i], vec[j], shape))
			{
                if (vec[i] < vec[j]) vec[i] = -1;
                else vec[j] = -1;
                return false;
			}
		}
	}
    return true;
}

int main()
{
    int T; cin >> T;

    while (T--)
    {
        int N, M;
        cin >> N >> M;
        vector<int> shape(N + 1);
        for (int i = 1; i <= N; ++i) cin >> shape[i];

        vector<int> vec;
        for (int l = 1; l <= M - 1; ++l)
        {
            if (isInVisible(l, M, shape)) vec.push_back(l);
        }
        for (int r = M + 1; r <= N; ++r)
        {
            if (isInVisible(M, r, shape)) vec.push_back(r);
        }
        
        while (!check(vec, shape));
    	
        int total = 0;
        for(auto& it: vec)
        {
            if (it != -1) ++total;
        }
        cout << total << endl;
    	
    }
}