#include<iostream>

using namespace std;
typedef long long LL;

int main()
{
    ios ::sync_with_stdio(false);
    LL x, y;
    cin >> x >> y;
    LL ret = 0;

    while(x && y)
    {
        LL cnt = x / y;
        ret += cnt * y * 4;
        x %= y;
        swap(x, y);
    }

    cout << ret;
    return 0;
}