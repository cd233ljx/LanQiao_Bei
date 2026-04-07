// #include <bits/stdc++.h>
// using namespace std;
// typedef long long LL;

// vector<LL> A;
// bool visited[2026];
// LL ret;
// const LL mod = 1e9 + 7;

// void dfs(int pos, int n)
// {
//     if(pos > n)
//     {
//         // for (int i = 1; i <= n; i++)
//         // {
//         //     cout << A[i] << " ";
//         // }
//         // cout << "\n";
//         bool flag = true;
//         for (int i = 1; i <= n;i++)
//         {
//             if(flag)
//             {
//                 for (int j = i; j <= n; j++)
//                 {
//                     if (A[i] * A[j] > i * j + n)
//                     {
//                         flag = false;
//                         break;
//                     }
//                 }
//             }
//         }
//         if(flag)
//             ret++;

//         return;
//     }

//     for (int i = 1; i <= n; i++)
//     {
//         if(!visited[i])
//         {
//             A.push_back(i);
//             visited[i] = true;
//             dfs(pos + 1, n);
//             A.pop_back();
//             visited[i] = false;
//         }
//     }
// }


// int main()
// {
//     A.push_back(-1);
//     for (int n = 1; n <= 10;n++)
//     {
//         ret = 0;
//         dfs(1, n);
//         cout << "n = " << n << ": " << ret % mod << "\n";
//     }
  
//     return 0;
// }

#include<iostream>
using namespace std;
int main()
{
    unsigned long long mod = 1e9 + 7;
    unsigned long long ret =  1;
    // = (1 << 1012) % mod;

    for (int i = 1; i <= 1012;i++)
    {
        ret = (ret * 2) % mod;
    }
        cout << ret % mod;
}