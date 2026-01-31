#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;

int a[N];

int main()
{

    int T; // 组数
    cin >> T;

    int n; // 雪花数
    while (T--)
    {
        cin >> n;
        int ret = 1;

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i]; // 输入数据
        }

        unordered_map<int, int> hash;
        for (int l = 1, r = 1; r <= n; r++)
        {
            hash[a[r]]++; // 进入窗口

            // 重复-左指针出窗口
            while (hash[a[r]] > 1)
            {
                hash[a[l]]--; // 次数减少
                l++;          // 左指针右移
            }

            ret = max(ret, r - l + 1);
        }
        cout << ret << endl;
    }

    return 0;
}