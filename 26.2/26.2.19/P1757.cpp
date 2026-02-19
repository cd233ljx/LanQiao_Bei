// #include <bits/stdc++.h>
// using namespace std;

// int m, n, cnt;
// const int N = 1e4 + 10;
// vector<pair<int, int>> g[N];
// int dp[N][N];

// int main()
// {
//     cin >> m >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         int a, b, c;
//         cin >> a >> b >> c;
//         cnt = max(cnt, c);
//         g[c].push_back({a, b});
//     }

//     for (int i = 1; i <= cnt; i++)
//     {
//         for (int j = m; j >= 0; j--)
//         {
//             dp[i][j] = dp[i - 1][j];
//             for (auto &t : g[i]) 
//             {
//                 if (j - t.first >= 0)
//                     dp[i][j] = max(dp[i][j], dp[i - 1][j - t.first] + t.second);
//             }
//         }
//     }

//     cout << dp[cnt][m];

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int m, n, cnt;
const int N = 1e4 + 10;
vector<pair<int, int>> g[N];
int dp[N];

int main()
{
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        cnt = max(cnt, c);
        g[c].push_back({a, b});
    }

    for (int i = 1; i <= cnt; i++)
    {
        for (int j = m; j >= 0; j--)
        {
            for (auto &t : g[i])
            {
                if (j - t.first >= 0)
                    dp[j] = max(dp[j], dp[j - t.first] + t.second);
            }
        }
    }

    cout << dp[m];

    return 0;
}