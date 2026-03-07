#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

// int dis[N];

// int fa[N];

// int ret = 0x3f3f3f3f;

// int find(int x)
// {
//     if (fa[x] == x)
//         return x;

//     int root = find(fa[x]);
//     dis[x] += dis[fa[x]];
//     return root;
// }

// void unionset(int x, int y)
// {
//     int cx = find(x);
//     int cy = find(y);
//     if (cx != cy)
//     {
//         fa[cx] = cy;
//         dis[x] = dis[y] + 1;
//     }
//     else
//     {
//         ret = min(ret, dis[x] + dis[y] + 1);
//     }
// }

// int main()
// {
//     int n;
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         fa[i] = i;
//     }
//     for (int i = 1; i <= n; i++)
//     {
//         int t;
//         cin >> t;
//         unionset(i, t);
//     }

//     cout << ret;
//     return 0;
// }

int n;
int ne[N];
int in[N];//统计入度
bool st[N];

int cnt;//统计路径长度

void dfs(int x)
{
    cnt++;
    st[x] = true;

    int y = ne[x];
    if(!st[y])
        dfs(y);
}


int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ne[i];
        in[ne[i]]++;
    }
    
    //拓扑排序 给环以外的点上标记
    queue<int> q;
    for (int i = 1; i <= n;i++)
    {
        if(in[i] == 0)
            q.push(i);
    }

    while(q.size())
    {
        auto a = q.front();
        q.pop();
        st[a] = true;

        int b = ne[a];
        in[b]--;
        if(in[b] == 0)
            q.push(b);
    }

    //dfs计算环大小
    int ret = n;
    for (int i = 1; i <= n;i++)
    {
        if(!st[i])
        {
            cnt = 0;
            dfs(i);
            ret = min(ret, cnt);
        }
    }

    cout << ret;
    return 0;
}
