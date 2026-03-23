#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
    LL ret = 0;

    for (int a = 1; a <= 2025; a++)
    {
        for (int b = a + 1; b <= 2025; b++)
        {
            for (int c = b + 1; c <= 2025; c++)
            {
                if (2 * b == a + c)
                    ret++;
            }
        }
    }

    cout << ret * 2;
    return 0;
}