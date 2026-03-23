#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
LL c;
unordered_map<LL,LL> a;  //<数字，出现次数>

int main()
{
    cin >> n >> c;
    for (int i = 1; i <= n;i++)
    {
        LL in;
        cin >> in;
        a[in]++;
    }

    LL ret = 0;
    for(auto b : a)
    {
        auto A = b.first + c;
        if (a.find(A) != a.end())
        {
            ret += a[b.first] * a[A];
        }
    }
    cout << ret;
    return 0;
}