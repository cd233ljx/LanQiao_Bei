#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 1e5 + 10;

LL a[N],b[N];

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n;i++)
    {
        cin >> a[i];
    }
    LL ret = 0;

    for (int i = 1; i <= n / 2;i++)
    {
        if (a[i] < a[n - i + 1]) 
            b[i] = a[n - i + 1] - a[i];
        else
            b[n - i + 1] = a[i] - a[n - i + 1]; 
    }

    for (int i = 1; i <= n;i++)
    {
        int nr = min(b[i], b[i + 1]);
        b[i] -= nr;
        b[i+1] -= nr;
        ret += nr;
        ret += b[i];
    }

        cout << ret;
}

// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     long long n, a[100005] = {}, b[100005] = {}, tmp = 0;
//     cin >> n; // 读入
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> a[i];
//     }
//     for (int i = 1; i <= n / 2; i++)
//     {
//         b[i] = a[i] - a[n - i + 1]; // 将对应位置的差存入
//     }
//     for (int i = 1; i <= n / 2; i++)
//     {
//         tmp += abs(b[i]); // 如果是异号单独处理
//         if (b[i] > 0 && b[i + 1] > 0)
//         {
//             b[i + 1] -= min(b[i], b[i + 1]); // 同号一起处理
//         }
//         if (b[i] < 0 && b[i + 1] < 0)
//         {
//             b[i + 1] -= max(b[i], b[i + 1]); // 同号一起处理
//         }
//     }
//     cout << tmp; // 输出
//     return 0;
// }
