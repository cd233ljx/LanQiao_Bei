#include <bits/stdc++.h>
using namespace std;

string board;
//  B 黑下12颗     W 白下13颗
long long ret = 0;

bool check()
{
    // 横着
    for (int i = 0; i <= 20; i += 5)
    {
        string sub = board.substr(i, 5);
        if (sub == "WWWWW" || sub == "BBBBB")
            return false;
    }

    for (int i = 0; i <= 4; i++)
    {
        string sub = string() + board[i] + board[i + 5] + board[i + 10] + board[i + 15] + board[i + 20];

        if (sub == "WWWWW" || sub == "BBBBB")
            return false;
    }

    string dig = "";
    for (int i = 0; i <= 24; i += 6)
    {
        dig += board[i];
    }
    if (dig == "WWWWW" || dig == "BBBBB")
        return false;

    dig.clear();
    for (int i = 4; i <= 20; i += 4)
    {
        dig += board[i];
    }
    if (dig == "WWWWW" || dig == "BBBBB")
        return false;

    return true;
}

void dfs(int Bn, int Wn)
{

    if (Bn == 12 && Wn == 13)
    {
        if (check())
        {
            ret++;
        }
        return;
    }

    if (Bn < 12)
    {
        board.push_back('B');
        dfs(Bn + 1, Wn);
        board.pop_back();
    }

    if (Wn < 13)
    {
        board.push_back('W');
        dfs(Bn, Wn + 1);
        board.pop_back();
    }
}

int main()
{
    dfs(0, 0);

    cout << ret;
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// // 检查某个状态是否合法（无五连珠）
// // mask: 25位的整数，0表示B，1表示W
// bool check(int mask)
// {
//     // 预处理棋盘数组，方便访问
//     // 0是B，1是W
//     int b[25];
//     for (int i = 0; i < 25; i++)
//     {
//         b[i] = (mask >> i) & 1;
//     }

//     // 辅助Lambda：检查5个位置是否颜色相同且非空
//     auto is_five = [&](int i1, int i2, int i3, int i4, int i5)
//     {
//         return (b[i1] == b[i2] && b[i1] == b[i3] &&
//                 b[i1] == b[i4] && b[i1] == b[i5]);
//     };

//     // 1. 检查横向
//     for (int i = 0; i < 25; i += 5)
//     {
//         if (is_five(i, i + 1, i + 2, i + 3, i + 4))
//             return false;
//     }

//     // 2. 检查纵向
//     for (int i = 0; i < 5; i++)
//     {
//         if (is_five(i, i + 5, i + 10, i + 15, i + 20))
//             return false;
//     }

//     // 3. 检查主对角线 (\)
//     if (is_five(0, 6, 12, 18, 24))
//         return false;

//     // 4. 检查副对角线 (/)
//     if (is_five(4, 8, 12, 16, 20))
//         return false;

//     return true;
// }

// int main()
// {
//     // 优化输出速度
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     long long ret = 0;

//     // 1 << 25 = 33,554,432 (约3300万次循环)
//     // 现代CPU可以在1秒左右跑完
//     for (int i = 0; i < (1 << 25); i++)
//     {
//         // __builtin_popcount 是GCC内置函数，用于计算二进制中1的个数
//         // 题目要求白棋(W/1) 刚好 13 颗
//         if (__builtin_popcount(i) == 13)
//         {
//             if (check(i))
//             {
//                 ret++;
//             }
//         }
//     }

//     cout << ret << endl;
//     return 0;
// }