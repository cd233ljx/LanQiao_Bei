#include<iostream>

using namespace std;

const int N = 1010;
int dp[N][N];

int main(){
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;

    for (int len = 2; len <= n;len++)
    {
        for (int i = 1; i + len - 1 <= n;i++)
        {
            int j = i + len - 1;
            
            if(s[i] == s[j])
                dp[i][j] = dp[i + 1][j - 1];
            else
                dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
        }
    }

    cout << dp[1][n];

    return 0;
}