#include <bits/stdc++.h>
using namespace std;

int p[4][4];
bool st[4][4];
int ans = 0x3f3f3f3f;

bool allon()
{
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            if(p[i][j] == 0)
                return false;
        }
    }

    return true;
}

int dx[] = {0, 0, 0, 1, -1};
int dy[] = {0, 1, -1, 0, 0};

void click(int x, int y)
{
    for (int i = 0; i < 5;i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx > 0 && nx < 4 && ny > 0 && ny < 4)
        {
            p[nx][ny] = 1 - p[nx][ny];
        }
    }
}

void dfs(int step)
{
    if(step >= ans)
        return;

    if(allon())
    {
        ans = step;
        return;
    }

    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            if(!st[i][j])
            {
                st[i][j] = true;
                click(i, j);
                dfs(step + 1);
                click(i, j);// 再点一次就可以恢复
                st[i][j] = false;
            }
        }
    }
}


int main()
{
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            cin >> p[i][j];
        }
    }

    dfs(0);

    cout << ans;

    return 0;
}