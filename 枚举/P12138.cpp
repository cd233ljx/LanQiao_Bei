#include<iostream>
using namespace std;

typedef long long LL;
bool isp(LL x)
{
    for (int i = 2; i <= x/i ;i++)
    {
        if(x % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int cnt = 2;
    LL x = 4;
    while (cnt < 2025)
    {
     if(isp(x))
     {
         cnt++;
     }
     x++;
    }
    cout << --x;

    return 0;
}