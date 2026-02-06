#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
const int N = 410;
p dx_y[8] = {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};
int n, m, X, Y;
int dis[N][N];

void bfs()
{
    memset(dis, -1, sizeof(dis));

    queue<p> q;
    q.push({X, Y});
    dis[X][Y] = 0;

    while (q.size())
    {
        auto t = q.front();
        q.pop();

        int i = t.first, j = t.second;
        for (int k = 0; k < 8; k++)
        {
            int x = i + dx_y[k].first;
            int y = j + dx_y[k].second;
            if (dis[x][y] != -1)
                continue;
            if (x < 1 || x > n || y < 1 || y > m)
                continue;
            dis[x][y] = dis[i][j] + 1;
            q.push({x, y}); 
        }
    }
    return;
}
int main()
{
    cin >> n >> m >> X >> Y;

    bfs();

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << dis[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}