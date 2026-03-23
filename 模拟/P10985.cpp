#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL Nsum(LL x)
{
    LL sum = 0;
    while(x)
    {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int main()
{
    LL n;
    cin >> n;
    LL ret = 0;


    while(n)
    {
        n = n - Nsum(n);
        ret++;
    }

    cout << ret;
    return 0;
}