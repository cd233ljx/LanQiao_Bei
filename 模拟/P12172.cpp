#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


int main()
{
    int w, h, v;
    cin >> w >> h >> v;

    for (int i = 1; i <= h;i++)
    {
        for (int j = 1; j <= w;j++)
        {
            cout << "Q";
        }
        puts("");
    }

    for (int i = 1; i <= w; i++)
    {
        for (int j = 1; j <= w +v; j++)
        {
            cout << "Q";
        }
        puts("");
    }
        return 0;
}