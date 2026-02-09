#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 10;

int n, k;
int a[N];

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    deque<int> q; // 存下标

    // 窗口内最小值-单调递增队列
    for (int i = 1; i <= n; i++)
    {
        while (q.size() && a[q.back()] >= a[i])
            q.pop_back();

        q.push_back(i);

        // 判断队列内元素是否合法
        if (q.back() - q.front() + 1 > k)
            q.pop_front();

        if (i >= k)
            cout << a[q.front()] << " ";
    }

    q.clear();
    cout << endl;

    // 窗口内最大值-单调递减队列
    for (int i = 1; i <= n; i++)
    {
        while (q.size() && a[q.back()] <= a[i])
            q.pop_back();

        q.push_back(i);

        // 判断队列内元素是否合法
        if (q.back() - q.front() + 1 > k)
            q.pop_front();

        if (i >= k)
            cout << a[q.front()] << " ";
    }
    return 0;
}