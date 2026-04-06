// #include<bits/stdc++.h>
// using namespace std;

// int t;
// const long long N = 1e7 + 10;
// int dp[N];  // 下标： 要表达的数字    值： 用的木棍数

// int c[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}; // 0 ~ 9

// int main()
// {

    

//     dp[0] = 6;
//     for (int i = 1; i <= N; i++)
//     {
//         int x = i;
//         while(x)
//         {
//             dp[i] += c[x % 10];
//             x /= 10;
//         }
//     }


//     // cin >> t;
//     // for (int i = 1; i <= t; i++)
//     // {
//     //     // int a;
//     //     // cin >> a;
       

//     // }
//     for (int a = 1; a <= 50; a++)
//     {

     
//         int j = 1;
//         for (; j <= N; j++)
//         {
//             if (dp[j] == a)
//             {
//                 cout << "n = " << a << "时, 表达的数字= " << j <<"\n";
//                 break;
//             }
//         }
    
//     }
//         return 0;
// }

#include <bits/stdc++.h>
using namespace std;
const int f[10] = {0, -1, 1, 7, 4, 2, 6, 8, 10};
int T, n, d, i;
int main()
{
    for (cin >> T; T--;)
    {
        cin >> n;
        if (n <= 8)
            cout << f[n];
        else
        {
            d = n % 7;
            if (!d)
                for (i = 1; i <= n / 7; i++)
                    cout << 8;
            if (d == 1)
            {
                cout << 10;
                for (i = 1; i < n / 7; i++)
                    cout << 8;
            }
            if (d == 2)
            {
                cout << 1;
                for (i = 1; i <= n / 7; i++)
                    cout << 8;
            }
            if (d == 3)
            {
                if (n == 10)
                    cout << 22;
                else
                {
                    cout << 200;
                    for (i = 1; i <= n / 7 - 2; i++)
                        cout << 8;
                }
            }
            if (d == 4)
            {
                cout << 20;
                for (i = 1; i < n / 7; i++)
                    cout << 8;
            }
            if (d == 5)
            {
                cout << 2;
                for (i = 1; i <= n / 7; i++)
                    cout << 8;
            }
            if (d == 6)
            {
                cout << 6;
                for (i = 1; i <= n / 7; i++)
                    cout << 8;
            }
        }
        cout << '\n';
    }
}
