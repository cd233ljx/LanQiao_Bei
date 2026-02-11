#include<iostream>
using namespace std;
const int N = 1010;

int n;
int a[N][N];
int dp[N][N];
int f[N];
int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i;j++){
            cin >> a[i][j];
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= i; j++)
    //     {
    //         dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + a[i][j];
    //     }
    // }

    // 空间优化
     for (int i = 1; i <= n; i++)
    {
        for (int j = i; j >= 1; j--)
        {
            f[j] = max(f[j], f[j - 1]) + a[i][j];
        }
    }

    int ret = 0;
    for (int j = 1; j <= n;j++)
    {
        ret = max(ret, f[j]);
    }

    cout << ret;
}