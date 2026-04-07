#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

string a,b;

int main()
{
    cin >> a >> b;

    int len = a.size();
    int cnt = 0;
    int l = len, r = 0;

    for (int i = 0; i < len; i++)
    {
        if (a[i] == '#' || b[i] == '#')
        {
            l = min(l, i);
            r = max(r, i);
        }
    }

    for (int i = l; i < r; i++)
    {
        if (a[i] == '#' && a[i + 1] == '.' &&b[i] == '.')
        {
            cnt++;
            a[i + 1] = '#';
        }

        if (a[i] == '.' && b[i + 1] == '.' && b[i] == '#')
        {
            cnt++;
            b[i + 1] = '#';
        }

        if(a[i] == '#' && b[i] == '#' && a[i+1] == '.' && b[i+1] == '.')
        {
            int p = i, q = i;
            for (int j = i + 1; j <= r;j++)
            {
                if(a[j] == '#')
                {
                    p = j;
                    break;
                }
                if (b[j] == '#')
                {
                    q = j;
                    break;
                }

            }

            if(p >=q)
            {
                a[i + 1] = '#';
                cnt++;
            }
            else
            {
                b[i + 1] = '#';
                cnt++;
            }
        }
    }
    cout << cnt;

    return 0;
}