#include<iostream>
using namespace std;

const int N = 1e5 + 10, MOD = 1e5 + 3;

int n, k;
int dp[N];

int main()
{
    cin >> n >> k;

    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k && i - j >= 0; j++)
        {
            dp[i] = (dp[i] + dp[i - j]) % MOD;
        }
    }

    cout << dp[n];
    return 0;
}
