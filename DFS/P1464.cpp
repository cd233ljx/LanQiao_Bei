#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL w[25][25][25];

LL dfs(LL a, LL b, LL c)
{
    if (a <= 0 || b <= 0 || c <= 0)
    {
        return 1;
    }

    if (a > 20 || b > 20 || c > 20)
    {
        return dfs(20, 20, 20);
    }

    if (w[a][b][c] != -1)
    {
        return w[a][b][c];
    }

    if (a < b && b < c)
    {
        w[a][b][c] = 
        dfs(a, b, c - 1) 
        + dfs(a, b - 1, c - 1) 
        - dfs(a, b - 1, c);
    }
    else
    {
        w[a][b][c] = 
        dfs(a - 1, b, c) 
        + dfs(a - 1, b - 1, c)
        + dfs(a - 1, b, c - 1) 
        - dfs(a - 1, b - 1, c - 1);
    }
    return w[a][b][c];
}

int main()
{
    memset(w, -1, sizeof(w));
    while (1)
    {
        LL a, b, c;
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)
            return 0;
        printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, dfs(a, b, c));
    }

    return 0;
}