#include <bits/stdc++.h>
using namespace std;

const int N = 3e4 + 10;
typedef long long LL;

LL dp[N];
LL v[N], w[N];
int n, m;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> v[i] >> w[i];

    for (int i = 1; i <= m; i++)
        for (int j = n; j >= v[i]; j--)
            dp[j] = max(dp[j], dp[j - v[i]] + v[i] * w[i]);

    cout << dp[n];
    return 0;
}