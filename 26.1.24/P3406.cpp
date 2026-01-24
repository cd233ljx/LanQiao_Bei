#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define LL long long
using namespace std;

const int N = 1e5 + 10;

struct Section
{
    int A;
    int B;
    int C;
    LL DIF;
} S[N];

int T[N];

int main()
{
    int n, m;
    cin >> n >> m;

    // 读移动数据
    FOR(i, 1, m)
    {
        cin >> T[i];
    }

    // 读各路段价格
    FOR(i, 1, n - 1)
    {
        cin >> S[i].A >> S[i].B >> S[i].C;
    }

    // 计算差分数组
    int l, r;
    FOR(i, 1, m - 1)
    {
        l = min(T[i], T[i + 1]);
        r = max(T[i], T[i + 1]);
        S[l].DIF += 1;
        S[r].DIF -= 1;
    }

    // 还原经过次数并计算最小开销
    LL cost = 0;
    FOR(i, 1, n - 1)
    {
        S[i].DIF += S[i - 1].DIF;
        cost += min(S[i].A * S[i].DIF, S[i].C + S[i].B * S[i].DIF);
    }

    cout << cost;
    return 0;
}