#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int m = 1;
    cout << 1;
    while(m < n)
    {
        cout << 0;
        m *= 10;
    }
   
    return 0;
}