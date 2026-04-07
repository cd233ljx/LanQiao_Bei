#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
    int t;
    ios ::sync_with_stdio(false);

    cin >> t;

    while(t--)
    {
        LL a, b, c, p;
        cin >> a >> b >> c >> p;
        for (int i = 1; i <= p; i++)
        {
            LL aa = a, bb = b, cc = c;
            a = (bb + cc) >> 1;
            b = (aa + cc) >> 1;
            c = (aa + bb) >> 1;
            if(a == b && b == c)
                break;
        }
        cout << a << " " << b << " " << c << "\n";
    }

        return 0;
}