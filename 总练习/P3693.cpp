#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;

int T;
LL tmp;
vector<vector<LL>> sum;

int main()
{
    ios ::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--)
    {
        LL n, m, q;
        cin >> n >> m >> q;

        sum.assign(n + 1, vector<LL>(m + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> tmp;
                sum[i][j] = sum[i][j - 1] + tmp + sum[i - 1][j] - sum[i - 1][j - 1];
            }
        }

        int u, v, x, y;
        LL ret = 0;
        while (q--)
        {
            cin >> u >> v >> x >> y;
            ret ^= sum[x][y] - sum[x][v - 1] - sum[u - 1][y] + sum[u - 1][v - 1];
        }

        cout << ret << "\n";
        sum.clear();
    }

    return 0;
}