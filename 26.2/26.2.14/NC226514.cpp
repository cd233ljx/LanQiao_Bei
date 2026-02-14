#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e3 + 10;
int n, V;
int dp[N][N];
int v[N], w[N];

int main()
{
    cin >> n >> V;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i] >> w[i];
    }

    // 问题1：
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= V; j++)
        {
            // 不选i
            dp[i][j] = dp[i - 1][j];

            // 选（如果能）
            if (j - v[i] >= 0)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
            }
        }
    }

    cout << dp[n][V] << endl;

    // 问题2：
    memset(dp, -0x3f3f, sizeof dp);
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= V; j++)
        {
            // 不选i
            dp[i][j] = dp[i - 1][j];

            // 选（如果能）
            if (j - v[i] >= 0)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
            }
        }
    }

    if (dp[n][V] < 0)
        cout << 0;
    else
        cout << dp[n][V];

    return 0;
}