#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 5e4 +10;
LL x[N],y[N];

int main()
{
    int n;
    cin >> n;
    LL ret = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> y[i];
    }
    sort(x + 1, x + n + 1);
    sort(y + 1, y + n + 1);
    for (int i = 1; i <= n; i++)
    {
        ret += abs(x[i] - y[i]);
    }

    cout << ret;
    return 0;
}