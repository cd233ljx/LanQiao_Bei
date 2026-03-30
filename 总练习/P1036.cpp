#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int n, k;
LL xx[25];
LL ret = 0;

bool isprime(LL x)
{
    if(x == 1 || x % 2 == 0 && x != 2)
        return false;
    for (LL i = 3; i * i <= x; i++)
    {
        if(x % i == 0)
            return false;
    }

    return true;
}



void dfs(int x, LL sum, int begin)
{
    if(x > k)
    {
        if(isprime(sum))
        {
            ret++;
        }
        return;
    }

    if(n - begin + 1 < k - x + 1)
        return;

    for (int i = begin; i <= n;i++)
    {
        dfs(x + 1, sum + xx[i], i + 1);
    }
}


int main()
{
    cin >> n >> k;

    for (int i = 1; i <= n;i++)
        cin >> xx[i];

    dfs(1, 0, 1);

    cout << ret;
    return 0;
}