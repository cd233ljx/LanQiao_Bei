#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10, P = 131;
typedef unsigned long long ULL;
ULL a[N];
int n;

ULL get_hash(string &s)
{
    ULL ret = 0;
    for (int i = 0; i < s.size(); i++)
    {
        ret = ret * P + s[i];
    }
    return ret;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;

        a[i] = get_hash(s);
    }

    int ret = 1;
    sort(a + 1, a + 1 + n);
    for (int i = 2; i <= n; i++)
    {
        if (a[i] != a[i - 1])
            ret++;
    }
    cout << ret;
    return 0;
}