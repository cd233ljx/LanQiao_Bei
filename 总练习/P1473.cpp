#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
int n;

void dfs(int idx, string path)
{
    if (idx == n - 1)
    {
        LL total = 0;
        LL cur = 1;
        char last_op = '+';

        for (int i = 0; i < n - 1; i++)
        {
            if (path[i] == ' ')
            {
                cur = cur * 10 + (i + 2);
            }
            else
            {
                if (last_op == '+')
                    total += cur;
                else
                    total -= cur;
                    
                last_op = path[i];
                cur = i + 2;
            }
        }

        if (last_op == '+')
            total += cur;
        else
            total -= cur;

        if (total == 0)
        {
            for (int i = 1; i <= n; i++)
            {
                cout << i;
                if (i < n)
                    cout << path[i - 1];
            }
            cout << "\n";
        }
        return;
    }

    //注意ASCII顺序
    dfs(idx + 1, path + ' ');
    dfs(idx + 1, path + '+');
    dfs(idx + 1, path + '-');
}


int main()
{
    cin >> n;

    dfs(0, "");

    return 0;
}