#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 15;
LL s[N], b[N];
int n;
LL mn = 0x3f3f3f3f;

void dfs(int x, LL ss, LL bb, bool chose)
{
    if(x > n)
    {
        if(chose)
            mn = min(abs(ss - bb), mn);

        return;
    }

    dfs(x + 1, ss, bb, chose);

    dfs(x + 1, ss * s[x], bb + b[x], true);
}





int main()
{
    cin >> n;
    for (int i = 1; i <= n;i++)
    {
        cin >> s[i] >> b[i];
    }

    dfs(1, 1, 0, false);

    cout << mn;
    return 0;
}
