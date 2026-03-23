#include <bits/stdc++.h>
using namespace std;


int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        string s;
        s.reserve(2 * n);
        cin >> s;
        int Acnt = 0;

        for (int i = 0; i < 2 * n; i+=2)
        {
            if(s[i] == 'A')
                Acnt++;
        }
        int Bcnt = n - Acnt;

        int ret = min(Acnt, Bcnt);
        cout << ret << "\n";
    }

    return 0;
}