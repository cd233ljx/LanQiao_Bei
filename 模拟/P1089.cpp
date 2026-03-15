#include<bits/stdc++.h>
using namespace std;


int main()
{
    int  b = 0, d = 0,x = 0;
    for (int i = 1; i <= 12;i++)
    {
        cin >> b;
        x = x + 300 - b;
        if(x < 0)
        {
            cout << -i;
            return 0;
        }
        int q = x / 100;
        x -= q * 100;
        d += q * 100;
    }

    x += (int)(d * 1.2);
    cout << x;
    return 0;
}