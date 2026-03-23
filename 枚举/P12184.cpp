#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
    LL ret = 0;
    for (int r = 0; r <= 255;r++)
    {
        for (int g = 0; g <= 255;g++)
        {
            for (int b = 0; b <= 255;b++)
            {
                if(b > r && b > g)
                    ret++;
            }
        }
    }
    cout << ret;
    return 0;
}