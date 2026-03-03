#include <iostream>
#include <vector>

typedef long long LL;
using namespace std;

const int N = 1e4 + 10;
int n, m, w;

int c[N], d[N];

// 每组c、d
LL cc[N], dd[N];

// 并查集
int fa[N];

int find(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}

void unionset(int x, int y)
{
    int cx = find(x), cy = find(y);
    if (cx != cy)
        fa[find(x)] = find(y);
}

// 背包
LL dp[N];

int main()
{
    cin >> n >> m >> w;

    for (int i = 1; i <= n; i++)
    {
        fa[i] = i; // 并查集初始化
        cin >> c[i] >> d[i];
    }

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        unionset(u, v);
    }

    // 处理数据-将数据连通
    for (int i = 1; i <= n; i++)
    {
        int root = find(i);
        cc[root] += c[i];
        dd[root] += d[i];
    }

    // 统计所有连通块（只取根节点）
    vector<pair<int, int>> groups;
    for (int i = 1; i <= n; i++)
    {
        if (find(i) == i)
            groups.push_back({(int)cc[i], (int)dd[i]});
    }

    // 01背包
    for (auto g :groups){
        LL c = g.first;
        LL d = g.second;
        for (int j = w; j >= c; j--)
            dp[j] = max(dp[j], dp[j - c] + d);
    }
    cout << dp[w];

    return 0;
}