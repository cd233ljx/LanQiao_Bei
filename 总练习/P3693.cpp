#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;

const int N = 1e3 + 10;
int T;
LL a[N][N];
LL sum[N][N];

int main()
{
    cin >> T;
    while(T--)
    {
        LL n, m, q;
        cin >> n >> m >> q;
        for (int i = 1; i <= n;i++)
        {
            for (int j = 1; j <= m;j++)
            {
                cin >> a[i][j];
                sum[i][j] = sum[i][j - 1] + a[i][j] + sum[i-1][j] - sum[i-1][j-1];
            }
        }
        
        
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cout << sum[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}