#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int n, m;
int r[N];
int d[N], s[N], t[N];

int f[N];
//把【1，x】所有订单处理，判断是否可行
bool check(int x)
{
    //初始化
    for(int i = 1; i <= n;i++)
    {
        f[i] = r[i] - r[i - 1];
    }

    //处理订单
    for (int i = 1; i <= x;i++)
    {
        //s[i] ~ t[i]   -  d[i]
        f[s[i]] -= d[i];
        f[t[i] + 1] += d[i];
    }

    //恢复
    for (int i = 1; i <= n; i++)
    {
        f[i] = f[i - 1] + f[i];
        if(f[i] < 0)
            return false;
    }
    return true;
}



int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        cin >> r[i];
    for (int i = 1; i <= m;i++)
        cin >> d[i] >> s[i] >> t[i];

    int l = 1, r = m;
    while (l <r)
    {
        int mid = (l + r) / 2;
        if(check(mid))
            l = mid + 1;
        else
            r = mid;
    }

    if(check(l))
        cout << 0;
    else
        cout << -1 << endl << l;

        return 0;
}