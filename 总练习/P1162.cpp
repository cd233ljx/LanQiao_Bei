#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 35;

int backup[N][N];// 备份
int a[N][N];// 真实走的
int dx[5] = {0, 1, 0, -1};
int dy[5] = {1, 0, -1, 0};
int n;

void dfs(int x, int y)
{
    int cx = x;
    int cy = y;

    if (cx < 0 || cx > n+1 || cy < 0 || cy > n+1 || a[cx][cy] != 0)
        return;

    a[cx][cy] = 1;
    for (int i = 0; i < 4;i++)
    {
        dfs(x + dx[i], y + dy[i]);
    }
}

int main()
{
    cin >> n;

    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= n;j++)
        {
            cin >> backup[i][j];
            if(backup[i][j] == 0)
                a[i][j] = 0;
            else
                a[i][j] = 1;
        }
    }

    dfs(0, 0);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(a[i][j] == 0)
                cout << 2 << " ";
            else
                cout << backup[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
