#include <iostream>
#include <cstring>

using namespace std;

const int N = 10; // 行数
int n = 5;        // 每行5位
int a[N];         // 二进制存储
int t[N];

//计算二进制中1的数量
int calc(int x){
    int ret = 0;
    while (x)
    {
        ret++;
        x &= x - 1;
    }
    return ret;
}

int main()
{

    // 读数据
    int T;
    cin >> T;
    while (T--)
    {
        // 初始化
        memset(a, 0, sizeof(a));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                char ch;
                cin >> ch;
                if (ch == '0') // 存成相反的
                    a[i] |= (1 << j);
            }
        }

        int ret = 0x3f3f3f3f; // 统计所有按法中的最小值

        // 枚举第一行所有按法
        for (int st = 0; st < (1 << n); st++)
        {

            memcpy(t, a, sizeof(a));
            int push = st; // 当前行按法
            int cnt = 0;

            // 依次计算后续行结果及按法
            for (int i = 0; i < n; i++)
            {

                // 统计1出现次数
                cnt += calc(push);

                // 核心算法
                t[i] = t[i] ^ push ^ (push << 1) ^ (push >> 1);

                // 消除不小心变的最高位的影响
                t[i] &= (1 << n) - 1;

                // 修改下一行的状态
                t[i + 1] ^= push;

                // 下一行的按法
                push = t[i];
            }

            if (t[n - 1] == 0)
                ret = min(ret, cnt);
        }

        //输出
        if (ret > 6)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << ret << endl;
        }
    }

    return 0;
}