#include <bits/stdc++.h>

using namespace std;

int n, m;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>> >nainong;

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int p, a;
        cin >> p >> a;
        nainong.push({p, a});
    }

    int cost = 0;
    while (n)
    {
        int cur_p = nainong.top().first;
        int cur_a = nainong.top().second;
    
        if(n - cur_a <= 0){
            cur_a = n;
        }

        n -= cur_a;
        cost += cur_p * cur_a;
        nainong.pop();
    }

    cout << cost;
    return 0;
}