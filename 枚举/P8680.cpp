#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;

int main()
{
    cin >> n;
    LL ret = 0;
    for (int i = 1; i <= n; i++)
    {
        int x = i;
        while (x)
        {
            if (x % 10 == 2 || x % 10 == 0 || x % 10 == 1 || x % 10 == 9)
            {
                ret += i;
                break;
            }
            x /= 10;
        }
    }
    cout << ret;
    return 0;
}