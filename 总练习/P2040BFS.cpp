#include<bits/stdc++.h>
using namespace std;

int p[4][4];

// 输入转换为状态整数
int To_state()
{
    int state = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> p[i][j];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(p[i][j])
            {
                state |= (1 << (i * 3 + j));
                // 二维转一维   设置第 i * 3 + j 位为 1
            }
        }
    }
    return state;
}

int click(int state, int r, int c)
{
    int newState = state;
    
    int dr[] = {0, 0, 0, 1, -1};
    int dc[] = {0, 1, -1, 0, 0};

    for (int i = 0; i < 5; ++i)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr >= 0 && nr < 3 && nc >= 0 && nc < 3)
        {
            int pos = nr * 3 + nc;
            newState ^= (1 << pos); // 翻转该位
        }
    }
    return newState;
}

int bfs(int start)
{
    if (start == 511)
        return 0; 

    vector<int> dist(512, -1); // -1 表示未访问
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        int steps = dist[cur];

        // 尝试点击 9 个位置
        for (int r = 0; r < 3; ++r)
        {
            for (int c = 0; c < 3; ++c)
            {
                int nxt = click(cur, r, c);
                if (dist[nxt] == -1)
                {
                    dist[nxt] = steps + 1;
                    if (nxt == 511)
                        return steps + 1;
                    q.push(nxt);
                }
            }
        }
    }
    return -1; 
}

int main()
{
    int start = To_state();
    int ret = bfs(start);
    cout << ret;
    return 0;
}