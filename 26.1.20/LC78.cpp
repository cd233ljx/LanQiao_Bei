#include <iostream>
#include <vector>
using namespace std;

// ??1：递归回溯
void backtrack(int i, vector<int> &nums, vector<int> &cur, vector<vector<int>> &ans)
{
    if (i == nums.size())
    {
        ans.push_back(cur);
        return;
    }

    // 不??
    backtrack(i + 1, nums, cur, ans);

    // ??
    cur.push_back(nums[i]);
    backtrack(i + 1, nums, cur, ans);
    cur.pop_back();
}
vector<vector<int>> subsets_DiGui(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> cur;
    backtrack(0, nums, cur, ans);
    return ans;
}

// ??2：二进制枚举
vector<vector<int>> subsets_01(vector<int> &nums)
{
    vector<vector<int>> ans;
    int n = nums.size();
    for (int s = 0; s < (1 << n); s++)
    {
        vector<int> tmp;
        for (int i = 0; i < n; i++)
        {
            if ((s >> i) & 1)
                tmp.push_back(nums[i]);
        }
        ans.push_back(tmp);
    }

    return ans;
}
void PrtintAns(vector<vector<int>> &ans)
{
    int n = ans.size();
    int m;
    cout << "[";
    for (int i = 0; i < n; i++)
    {
        cout << "[";
        m = ans[i].size();
        for (int j = 0; j < m; j++)
        {
            cout << ans[i][j];
            if (j != m - 1)
                cout << ",";
        }
        cout << "]";
        if (i != n - 1)
            cout << ",";
    }
    cout << "]" << endl;
}
void In_scanf(vector<int> &v)
{
    int in;
    while (in != -1)
    {
        cin >> in;
        v.push_back(in);
    }
    v.pop_back();
}
int main()
{
    vector<int> v;

    In_scanf(v);
    auto AllAns_1 = subsets_DiGui(v);
    auto AllAns_2 = subsets_01(v);

    cout << "递归法：" << endl;
    PrtintAns(AllAns_1);

    cout << "二进制枚举：" << endl;
    PrtintAns(AllAns_2);
}