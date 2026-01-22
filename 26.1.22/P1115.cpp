#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int a[N];
int sum[N];

//法一：动态规划
int Maximum_Subarray_Sum_DP(int n)
{
    int MAX_SUM = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        // 状态转移：决定是否继承前序子数组
        sum[i] = (sum[i - 1] < 0) ? a[i] : sum[i - 1] + a[i];
        MAX_SUM = max(sum[i], MAX_SUM); // 更新最大值
    }
    return MAX_SUM;
}

//法二：前缀和
int Maximum_Subarray_Sum_Prefix_Sum (int n){

    int Min_Prefix_Sum = 0;
    int ret = INT_MIN;

    for (int i = 1; i <= n; i++){
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];

        ret = max(ret, sum[i] - Min_Prefix_Sum);
        Min_Prefix_Sum = min(Min_Prefix_Sum, sum[i]);
    }
        return ret;
}
int main()
{
    int n;
    cin >> n;
    int Ans = Maximum_Subarray_Sum_Prefix_Sum(n);
    //int Ans = Maximum_Subarray_Sum_DP(n);
    cout << Ans;
    return 0;
}