#include <iostream>
using namespace std;

const int N = 5010;
int n;
int a[N];
int dp[N];
int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    
    int ret = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1;
        for (int j = 1; j <= i - 1; j++)
        {
            if (a[j] < a[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ret = max(ret, dp[i]);
    }

    cout << ret;
    return 0;
}