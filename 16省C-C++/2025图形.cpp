#include <bits/stdc++.h>
using namespace std;

int num[] = {2, 0, 2, 5};

int main()
{
    int h, w;
    cin >> h >> w;

    int cnt = 0;

    for (int i = 1; i <= h; i++)
    {
        cnt = (i - 1) % 4;
        for (int j = 1; j <= w; j++)
        {
            cout << num[cnt % 4];
            cnt++;
        }
        cout << endl;
    }

    return 0;
}