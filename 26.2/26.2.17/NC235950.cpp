#include<iostream>
using namespace std;

const int N = 110;
int n, m;
int dp[N][N];
int x[N], w[N], v[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        cin >> x[i] >> w[i] >> v[i];

    for (int i = 1; i <= n;i++)
        for (int j = m; j >= 0;j--)
            for (int k = 0; k <= x[i] && j - k * w[i] >= 0;k++)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k * w[i]] + k * v[i]);

    cout << dp[n][m];
    return 0;
}

//空间优化方式同 01-背包