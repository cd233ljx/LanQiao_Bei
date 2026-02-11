#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n + 10,vector<int>(m + 10, 0x3f3f));

        dp[0][1] = 0;

        for (int i = 1; i <= n;i++)
        {
            for (int j = 1; j <= m;j++)
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + matrix[i - 1][j - 1];
            }
        }

        return dp[n][m];
    }
};