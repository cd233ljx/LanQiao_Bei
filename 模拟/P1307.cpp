#include<bits/stdc++.h>
using namespace std;


int main()
{
    string s;
    cin >> s;
    if(s[0] == '-')
    {
        s.erase(s.begin());
        cout << '-';
    }
    reverse(s.begin(),s.end());
    bool flag = false;
    for (auto ch : s)
    {
        if(ch != '0')
            flag = true;

        if(flag)
            cout << ch;
    }
    if(!flag)
    {
        cout << 0;
    }
        return 0;
}