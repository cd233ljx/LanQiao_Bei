#include<bits/stdc++.h>
using namespace std;

int main()
{
    int cnt = 0;
    for (int i = 1; i <= 202504;i++)
    {
        int x = i;
        int sum = 0;
        while(x)
        {
            sum += x % 10;
            x /= 10;
        }
        if(sum%5 == 0)
            cnt++;
    }

    cout << cnt;
    return 0;
}