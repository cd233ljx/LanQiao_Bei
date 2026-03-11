#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = (45+1)*45/4;
LL f[45][N];
int n;

int main()
{
    cin >> n;
    int sum = (1 + n) * n / 2;

    if (sum & 1)
    {
        cout << 0;
        return 0;
    }

    int targe = sum / 2;

    f[0][0] = 1;
    
    for (int i = 1; i <= n;i++)
        for (int j = 0; j <= targe;j++)
        {
            f[i][j] = f[i - 1][j];

            if(j >= i)
            {
                f[i][j] += f[i - 1][j - i];
            }
        }

    cout << f[n][targe]/2;

    return 0;
}