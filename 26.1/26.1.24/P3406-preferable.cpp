#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define LL long long
using namespace std;

const int N = 1e5 + 10;

LL DIF[N];
int main()
{
    int n, m;
    cin >> n >> m;

    // 读移动数据并计算差分数组
    int l, r;
    cin >> l;
    FOR(i, 2, m)
    {
        cin >> r;
        if(l < r){
            DIF[l]++;
            DIF[r]--;
        }else{
            DIF[r]++;
            DIF[l]--;
        }
        l = r;
    }

    // 还原经过次数并计算最小开销
    LL a, b, c;
    LL cost = 0;
    FOR(i, 1, n - 1)
    {
        DIF[i] += DIF[i - 1];
        cin >> a >> b >> c;
        cost += min(a * DIF[i], c + b * DIF[i]);
    }

    cout << cost;
    return 0;
}