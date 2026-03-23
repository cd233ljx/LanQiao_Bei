#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v;

void dfs(int i, int b)
{
    if (i > m)
    {
        for (int a : v)
        {
            cout << a << " ";
        }
        puts("");

        return;
    }

    for (int j = b; j <= n; j++)
    {
        v.push_back(j);
        dfs(i + 1, j + 1);
        v.pop_back();
    }
}

int main()
{

    cin >> n >> m;

    dfs(1, 1);

    return 0;
}