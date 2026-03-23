#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int ret = n;
    int pg = n;
    while(pg >= 3)
    {
        ret += pg/3;
        int a = pg / 3;
        pg %= 3;
        pg += a;
    }

    cout << ret;
    return 0;
}