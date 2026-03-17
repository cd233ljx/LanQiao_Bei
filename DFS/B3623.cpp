#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> t;
vector<bool> used;

void dfs(int i)
{
    if (i > n)
    {

        for (int a : t)
        {
            cout << a << " ";
        }
        puts("");

        return;
    }
    for (int x = 1; x <= k; x++)
    {
        if (!used[x])
        {
            used[x] = true;
            t.push_back(x);
            dfs(i + 1);
            t.pop_back();
            used[x] = false;
        }
    }
}

int main()
{
    cin >> k >> n;
    used.assign(k + 1, false);
    dfs(1);

    return 0;
}