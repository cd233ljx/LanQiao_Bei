#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 1e6 + 10;
int n;
char g[2][N];

int dist[2][N];
bool st[2][N];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int bfs(int i, int j)
{
    int ret = 0;
    memset(dist, 0x3f, sizeof dist);
    deque<pair<int, int>> q;
    q.push_back({i, j});
    dist[i][j] = 0;

    while (q.size())
    {
        auto t = q.front();
        int a = t.first;
        int b = t.second;
        q.pop_front();
        if (st[a][b])
            continue;

        st[a][b] = true;

        if (g[a][b] == '#')
            ret = max(ret, dist[a][b]);

        for (int k = 0; k < 4; k++)
        {
            int x = a + dx[k];
            int y = b + dy[k];

            if (x < 0 || x >= 2 || y < 0 || y >= n || st[x][y])
                continue;

            int w = g[x][y] == '#' ? 0 : 1;
            dist[x][y] = min(dist[a][b] + w, dist[x][y]);

            if (w)
                q.push_back({x, y});
            else
                q.push_front({x, y});
        }
    }

    return ret;
}

int main()
{
    cin >> g[0] >> g[1];
    n = strlen(g[0]);

    for (int j = 0; j < n; j++)
    {
        if (g[0][j] == '#')
        {
            cout << bfs(0, j) << "\n";
            return 0;
        }
        if (g[1][j] == '#')
        {
            cout << bfs(1, j) << endl;
            return 0;
        }
    }

    cout << 0 << endl;

    return 0;
}