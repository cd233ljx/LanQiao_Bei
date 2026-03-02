#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int n, m;


int main()
{
    cin >> n >> m;

    priority_queue<int, vector<int>, greater<int>> heap;
    for (int i = 1; i <= m;i++)
    {
        heap.push(0);
    }

    int ret = 0;
    for (int i = 1; i <= n;i++)
    {
        int x;
        cin >> x;
 
        int t = heap.top();
        heap.pop();

        t += x;
        heap.push(t);

        ret = max(t, ret);
    }

    cout << ret;

    return 0;
}