#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 +10;
typedef long long LL;

LL n, k;
LL a[N];

bool check(LL x)
{
    for (int i = 1; i <= k;i++)
    {
        LL t = 0;
        for (int j = i; j <= n; j += k)
        {
           if(a[j] + t <x)
               return false;
           t = a[j] + t - x;
        }
    }
    return true;
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n;i++)
        cin >> a[i];

    int l = 0, r =1e5;
    while(l < r)
    {
        int mid = (l + r + 1) >> 1;
        if(check(mid))
            l = mid;
        else
            r = mid - 1;

    }

    cout << l;
    return 0;
}