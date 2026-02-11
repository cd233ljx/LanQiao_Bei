#include<iostream>
using namespace std;

typedef long long LL;
int n;
LL dp[60];
int main()
{
    cin >> n;

    // dp[1] = 1, dp[2] = 2, dp[3] = 4;
    // for (int i = 4; i <= n;i++)
    // {
    //     dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    // }

    // 空间优化版
    switch (n){
        case 1 :
            cout << 1;
            return 0;
        case 2 :
            cout << 2;
            return 0;
        case 3 :
            cout << 4;
            return 0;
        default:
            break;
    }

    LL x = 1, y = 2, z = 4;
    LL ret;
    for (int i = 4; i <= n; i++)
    {
        ret = x + y + z;
        x = y;
        y = z;
        z = ret;
    }

 // cout << dp[n];
    cout << ret;
 
    return 0;
}
