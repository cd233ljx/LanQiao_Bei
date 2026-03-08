#include<bits/stdc++.h>
using namespace std;

int n, s;
int a, b;

typedef pair<int, int> y_x;

priority_queue<y_x, vector<y_x>, greater<y_x> > que;

int main()
{
    cin >> n >> s;
    cin >> a >> b;
    int H = a + b;

    for (int i = 1; i <= n;i++)
    {
        int x, y;
        cin >> x >> y;
        if(x <= H)
        {
            que.push({y, x});
        }
    }

    int ret = 0;
    while(s && que.size())
    {
        int y = que.top().first;
        if(s - y >= 0)
        {
            s -= y;
            ret++;
            que.pop();
        }
        else
        {
            break;
        }

    }

    cout << ret;
    return 0;
}