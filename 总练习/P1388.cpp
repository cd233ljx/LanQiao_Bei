#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
int n, k;
LL maxsum = 0;
LL pre[20];
// pre[i]    [1 ,i]
void ini_pre()
{
    pre[0] = 0;
    for (int i = 1; i <= n;i++)
    {
        int x;
        cin >> x;
        pre[i] = pre[i - 1] + x;
    }
}

LL get_presum(int l, int r)
{
    return pre[r] - pre[l - 1]; // [l, r]的和
}

void dfs(int pos, int cur_seg, LL Csum)
{
    if(cur_seg == k + 1)
    {
        if(pos == n + 1)
        {
            maxsum = max(maxsum, Csum);
        }
        return;
    }


    int re_seg = (k + 1) - cur_seg;
    int re_num = n - pos + 1;

    for (int end = pos; end <= n - re_seg + 1; end++)
    {
        LL seg_sum = get_presum(pos, end);
        if(cur_seg == 0)
        {
            dfs(end + 1, cur_seg + 1, seg_sum);
        }
        else
        {
            dfs(end + 1, cur_seg + 1, seg_sum * Csum);
        }
    }
}

int main()
{
    cin >> n >> k; //要切成 k+1 段
    ini_pre();

    dfs(1, 0, 1);

    cout << maxsum << endl;
    return 0;
}