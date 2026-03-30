#include <bits/stdc++.h>
using namespace std;

int p[4][4];
int start;

 


int main()
{
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            cin >> p[i][j];
            start = start * 2 + p[i][j];
        }
    }

    bfs(0);

    cout << ans;

    return 0;
}