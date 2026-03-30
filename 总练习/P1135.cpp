#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
int a, b;
int k[205];
//int ret = 0x3f3f3f3f;
//bool visited[205];

// void dfs(int x, int cnt)
// {

//     if (x > n || x < 1 || visited[x])
//     {
//         return;
//     }

//     if (x == b)
//     {
//         ret = min(ret, cnt);
//         return;
//     }

//     visited[x] = true;

//     dfs(x + k[x], cnt + 1);

//     dfs(x - k[x], cnt + 1);

//     visited[x] = false;
// }

queue<int> q;
LL dist[205];
LL bfs()
{

    memset(dist, -1, sizeof(dist));
    q.push(a);

    dist[a] = 0;

    while (!q.empty())
    {
        LL cur = q.front();
        q.pop();

        if(cur == b)
        {
            return dist[cur];
        }

        LL up = cur + k[cur];
        if (up <= n && dist[up] == -1)
        {
            dist[up] = dist[cur] + 1;
            q.push(up);
        }

        LL down = cur - k[cur];
        if (down >= 1 && dist[down] == -1)
        {
            dist[down] = dist[cur] + 1;
            q.push(down);
        }
    }

    return -1;
}

int main()
{
    cin >> n >> a >> b;

    for (int i = 1; i <= n; i++)
    {
        cin >> k[i];
    }

    //dfs(a, 0);
    cout << bfs();

    return 0;
}