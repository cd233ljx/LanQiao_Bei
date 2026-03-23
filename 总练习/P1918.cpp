#include <bits/stdc++.h>
using namespace std;

int n;
unordered_map<int, int> mp;
int q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n;i++)
    {
        int x;
        cin >> x;
        mp.emplace(x, i);
    }
    cin >> q;
    for (int i = 1; i <= q;i++)
    {
        int y;
        cin >> y;
        if(mp.find(y) != mp.end())
        {
            cout << mp[y] << "\n";
        }
        else
        {
            cout << 0 << "\n";
        }
    }

        return 0;
}

// // 二分
// int n;
// int q;
// int a[100005];

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> a[i];
//     }
//     cin >> q;
//     for (int i = 1; i <= q; i++)
//     {
//         int y;
//         cin >> y;
//         int l = 1, r = n;
//         while (l < r)
//         {
//             int mid = (l + r) >> 1;
//             if (a[mid] >= y)
//                 r = mid;
//             else
//                 l = mid + 1;
//         }

//         if (a[l] == y)
//             cout << l << "\n";
//         else
//             cout << 0 << "\n";
//     }

//     return 0;
// }