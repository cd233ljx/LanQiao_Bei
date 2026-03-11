#include<iostream>
using namespace std;

const int N = 10;

int n, m;
bool st[N][N];

int ret;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
void dfs(int i,int j)
{
    if(i <1 || i>=n || j <1 || j >=m)
    {
        ret++;
        return;
    }

    st[i][j] = true;
    for (int k = 0; k < 4;k++)
    {
        int x = i + dx[k];
        int y = j + dy[k];

        if(!st[x][y])
            dfs(x, y);
    }

    st[i][j] = false;
}


int main()
{
    cin >> n >> m;

    //从上
    for (int j = 1; j < m;j++)
    {
        st[0][j] = true;
        dfs(1, j);
        st[0][j] = false;
    }

    //左
    for (int i = 1; i < n;i++)
    {
        st[i][0] = true;
        dfs(i, 1);
        st[i][0] = false;
    }

    cout << ret;
    return 0;
}