#include <bits/stdc++.h>
using namespace std;

int n1, n2, m;
deque<int> q1, q2;
unordered_set<int> in_q1, in_q2; 

int main()
{
    cin >> n1 >> n2;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;

        // 情况1：x 在 q1 中（热点数据被再次访问）
        if (in_q1.count(x))
        {
            // 1. 从 q1 中删除旧位置
            q1.erase(find(q1.begin(), q1.end(), x));
            in_q1.erase(x);
            // 2. 插入到 q1 首部
            q1.push_front(x);
            in_q1.insert(x);
        }
        // 情况2：x 在 q2 中（冷数据被访问，提升为热点）
        else if (in_q2.count(x))
        {
            // 1. 从 q2 中删除
            q2.erase(find(q2.begin(), q2.end(), x));
            in_q2.erase(x);
            // 2. 插入到 q1 首部
            q1.push_front(x);
            in_q1.insert(x);
        }
        // 情况3：x 不在任何队列中（新数据）
        else
        {
            // 直接插入到 q2 首部
            q2.push_front(x);
            in_q2.insert(x);
        }

        // --- 容量控制 ---

        // 处理 q1 超容
        while (q1.size() > n1)
        {
            int t = q1.back();
            q1.pop_back();
            in_q1.erase(t);

            // 如果 q2 没满，把淘汰的元素移到 q2 首部
            if (q2.size() < n2)
            {
                q2.push_front(t);
                in_q2.insert(t);
            }
            // 否则直接丢弃（不用做额外操作）
        }

        // 处理 q2 超容（直接淘汰尾部）
        while (q2.size() > n2)
        {
            int t = q2.back();
            q2.pop_back();
            in_q2.erase(t);
        }
    }

    // 输出 q1
    for (int i = 0; i < q1.size(); i++)
    {
        if (i > 0)
            cout << " ";
        cout << q1[i];
    }
    cout << endl;

    // 输出 q2
    for (int i = 0; i < q2.size(); i++)
    {
        if (i > 0)
            cout << " ";
        cout << q2[i];
    }
    cout << endl;

    return 0;
}