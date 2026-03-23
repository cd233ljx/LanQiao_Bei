#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 5e4 + 10;
LL sum[N];
int n;
LL ret = 0;

int main()
{
    ios ::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        sum[i] += sum[i-1] + t;
    }

    for (int d = n; d > 0; d--)
    {
        for (int i = 0; i + d <= n; i++)
        {
            LL dif = sum[i + d] - sum[i];
            if (dif % 7 == 0)
            {
                ret = d;
                cout << ret;
                return 0;
            }
        }
    }

    cout << 0;

    return 0;
}