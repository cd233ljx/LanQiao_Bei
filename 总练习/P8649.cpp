#include<bits/stdc++.h>
using namespace std;

typedef long long LL;


int n, k;
const int N = 1e5 + 10;
LL s = 0, x;
int cnt[N];

int main()
{
    cin >> n >> k;

    cnt[0] = 1;

    LL ret = 0;

    for (int i = 1; i <= n;i++)
    {
        cin >> x;
        s = (s + x) % k;

        ret += cnt[s];
        cnt[s]++;
    }

    cout << ret;
    return 0;
}