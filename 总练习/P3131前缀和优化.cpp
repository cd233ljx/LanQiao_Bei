#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 5e4 + 10;
LL sum[N];
int n;
LL ret = 0;
int fir[7], last[7];

int main()
{
    ios ::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> sum[i];
        sum[i] = (sum[i] + sum[i - 1]) % 7;
    }

    //同余定理
    for (int i = n; i >= 1;i--)
    {
        fir[sum[i]] = i;// 各个余数最早出现的位置
    }

    fir[0] = 0;

    for (int i = 1; i <= n; i++)
        last[sum[i]] = i;

    int mx = 0;
    for (int i = 0; i <= 6;i++)
    {
        mx = max(last[i] - fir[i], mx);
    }

    cout << mx;

    return 0;
}
