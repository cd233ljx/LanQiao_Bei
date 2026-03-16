#include <bits/stdc++.h>
using namespace std;
const int N = 1005;

int a[N];
set<int> s;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++)
    {
        cin >> a[i];
    }
    for (int i = 2; i <= n; i++)
    {
        int diff = abs(a[i] - a[i - 1]);

        if (diff < 1 || diff > n - 1)
        { // 严格检查差值范围

            cout << "Not jolly";

            return 0;
        }
        s.insert(abs(a[i] - a[i - 1]));
    }

    if(s.size() != n -1){
        cout << "Not jolly";
        return 0;
    }

    int cnt = 1;
    for (int x : s)
    {
        if(x != cnt)
        {
            cout << "Not jolly";
            return 0;
        }
            cnt++;
    }
    cout << "jolly";

    return 0;
}