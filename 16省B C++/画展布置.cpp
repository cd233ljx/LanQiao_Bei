#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 1e5 + 10;
LL a[N];

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    LL l = LLONG_MAX;
    for (int i = 1; i + m -1 <= n; i++)
    {
        l = min(l, a[i + m - 1] * a[i + m - 1] - a[i] * a[i]);
    }

    cout << l;
    return 0;
}