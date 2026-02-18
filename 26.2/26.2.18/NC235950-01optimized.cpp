#include <iostream>
using namespace std;

const int N = 110*5;
int n, m,pos;
int dp[N];
int x[N], w[N], v[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        int t = 1;
        while(x - t >= 0)
        {
            pos++;
            w[pos] = t * y;
            v[pos] = t * z;
            x -= t;
            t *= 2;
        }
        if(x)
        {
            pos++;
            w[pos] = x * y;
            v[pos] = x * z;
        }
    }

    for (int i = 1; i <= pos; i++)
        for (int j = m; j >= w[i]; j--)
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);

    cout << dp[m];
    return 0;
}

