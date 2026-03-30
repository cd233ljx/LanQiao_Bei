#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int T[N];
int D[N];
int L[N];
int n;
bool st[15];
bool flag;

void dfs(int cur_t, int x)
{
    if(x > n)
    {
        flag = true;
        return;
    }

    if (flag)
        return;


    for (int i = 1; i <= n; i++)
    {
        if(!st[i])
        {
            int ear = max(cur_t, T[i]);
            int la = T[i] + D[i];

            if(ear <= la)
            {
                st[i] = true;
                dfs(ear + L[i], x + 1);
                st[i] = false;
            }
        }
    }
}


int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        memset(st, 0, sizeof st);

        flag = false;

        cin >> n;

        for (int i = 1; i <= n;i++)
        {
            cin >> T[i] >> D[i] >> L[i];
        }

        dfs(0, 1);

        if(flag)
        {
            cout << "YES" << "\n";
        }
        else
        {
            cout << "NO" << "\n";
        }

    }

    return 0;
}