#include <bits/stdc++.h>
using namespace std;

string s1;
string s2;
int cnt = 0;

void Replace(int it)
{
    for (int i = it; i <= it+1; i++)
    {
        if(s1[i] == '*')
        {
            s1[i] = 'o';
        }
        else
            s1[i] = '*';
    }
    cnt++;
}


int main()
{
    
    cin >> s1 >> s2;

    int n = s1.size();
    for (int i = 0; i < n;i++)
    {
        if (s1[i] != s2[i])
        {
            Replace(i);
        }
    }

    cout << cnt;
    return 0;
}