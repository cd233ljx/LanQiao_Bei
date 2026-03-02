#include<iostream>
#include<vector>

using namespace std;

const int N = 1e4 + 10;
int n, m, w;

int c[N], d[N];

//连通量
vector<int> edge[N];
int cnt;
int cc[N], dd[N];

//dfs
bool st[N];

//背包
int dp[N];

void dfs(int a)
{
    st[a] = true;
    cc[cnt] += c[a];
    dd[cnt] += d[a];
    for(auto b : edge[a])
    {
        if(!st[b])
        {
            dfs(b);
        }
    }
}

int main()
{
    cin >> n >> m >> w;

    for (int i = 1; i <= n;i++)
        cin >> c[i] >> d[i];

    for (int i = 1; i <= m;i++)
    {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    //处理数据-数据连通
    for (int i = 1; i <= n;i++)
    {
        if(!st[i])
        {
            cnt++;
            dfs(i);
        }
    }

    //01背包
    for (int i = 1; i <= cnt;i++)
        for (int j = w; j >= cc[i];j--)
            dp[j] = max(dp[j], dp[j - cc[i]] + dd[i]);

    cout << dp[w];

    return 0;
}