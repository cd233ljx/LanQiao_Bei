#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin >> k;
    string s;
    cin >> s;

    int c = s.size() / k;
    if(s.size() % k != 0)
    {
        cout << -1;
        return 0;
    }

    int ret = 0;
    for (int i = 0; i < c;i++)
    {
        int fre[30] = {0};
        int ma = 0;
        for (int j = i; j < s.size(); j+=c)
        {
            fre[s[j] - 'a']++;
            ma = max(ma, fre[s[j] - 'a']);
        }
        ret += k - ma;
    }

    cout << ret;

    return 0;
}