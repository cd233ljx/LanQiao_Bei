#include <bits/stdc++.h>
using namespace std;

vector<int> b;


int cnt = 0;
int n;

bool check(int x, int row)
{
    for (int i = 1; i <= row - 1;i++)
    {
        if(x == b[i])
            return false;

        // (i, b[i])   (row, x)
        if(abs(b[i] - x) == abs(i - row))
            return false;
    }
    return true;
}

void dfs(int row)
{
    if(row > n)
    {
        cnt++;
        if (cnt < 4)
        {
            for (int i = 1; i <= n; i++)
            {
                cout << b[i] << " ";
            }
            cout << "\n";
        }
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if(check(i, row))
        {
            b.push_back(i);
            dfs(row + 1);
            b.pop_back();
        }
    }
}


int main()
{
    cin >> n;

    b.push_back(0);
    dfs(1);

    cout << cnt;
    return 0;
}
