#include <iostream>
using namespace std;

const int N = 1e5 + 10;
long long a[N], sum[N];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        sum[i] = a[i] + sum[i - 1];
    }

    int l, r;

    for (int j = 0; j < m; j++)
    {
        scanf("%d %d", &l, &r);
        printf("%lld\n", sum[r] - sum[l - 1]);
    }

    return 0;
}