#include<bits/stdc++.h>
using namespace std;
typedef long long LL;


int main()
{
    int ret = 0;
    for (int i = 1; i <= 2025;i++)
    {
        int x = ((i % 10) * (i % 10) * (i % 10)) % 10;
        if(x == 3)
            ret++;
    }
    cout << ret;
    return 0;
}