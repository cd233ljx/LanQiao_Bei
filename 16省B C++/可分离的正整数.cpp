#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


int main()
{
    int t;
    cin >> t;
    LL ret = 0;

    for (int i = 1; i <= t;i++)
    {
        LL x;
        cin >> x;

        if(x != 1)
        {
            ret++;
        }
       
    }

    cout << ret;

    return 0;
}