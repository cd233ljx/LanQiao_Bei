#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

const int N = 1e5 + 10;
long long a[N], Dif[N];

int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    FOR(i, 1, n)
    {
        cin >> a[i];
        Dif[i] = a[i] - a[i - 1];
    }

    int l, r;
    long long k;

    FOR(i, 1, m)
    {
        cin >> l >> r >> k;
        Dif[l] += k;
        Dif[r + 1] -= k;
    }

    FOR(i, 1, n)
    {
        a[i] = Dif[i] + a[i - 1];
        cout << a[i] << " ";
    }
    return 0;
}
