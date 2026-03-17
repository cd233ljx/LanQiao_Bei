#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> t;

void dfs(int i)
{
    if(i > n)
    {
        for(int a : t)
        {
            cout << a << " ";
        }
        puts("");
        return;
    }
    for (int x = 1; x <= k;x++)
    {
        t.push_back(x);
        dfs(i + 1);
        t.pop_back();
    }
}


int main()
{
    cin >> n >> k;
    dfs(1);

    return 0;
}