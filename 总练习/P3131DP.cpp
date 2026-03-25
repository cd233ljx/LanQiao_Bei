#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 5e4 + 10;
LL dp[N][7];
int n;
LL ret = 0;


int main()
{
    ios ::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        for (int j = 0; j <= 6;j++)
        {
            if(dp[i-1][j])
            {
                dp[i][(j + x) % 7] = dp[i - 1][j] + 1;
            }
        }
        dp[i][x % 7] = max(dp[i][x % 7], (LL)1);
    }

    for (int i = 1; i <= n;i++)
    {
        ret = max(ret, dp[i][0]);
    }

    cout << ret;

    return 0;
}
