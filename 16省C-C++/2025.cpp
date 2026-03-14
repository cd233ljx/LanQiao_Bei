#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long ret = 0;

    for (int i = 1; i <= 20250412; i++)
    {
        int zeron = 0;
        int twon = 0;
        int fiven = 0;
        int x = i;

        while (x)
        {
            int y = x % 10;
            if(y == 0)
                zeron++;
            else if(y == 2)
                twon++;
            else if(y == 5)
                fiven++;
            x /= 10;
        }

        if(zeron >= 1 && twon >= 2 && fiven >= 1)
            ret++;
    }

    cout << ret;

    return 0;
}