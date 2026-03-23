#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<int> v;
int sum = 0;
int n;
int cnt = 0;
vector<vector<int>> a;

void dfs(int x)
{
    if (sum + (10 - x + 1) * 3 < n)
        return; 

    if (sum + (10 - x + 1) * 1 > n)
        return;

    if(x == 11 && sum == n)
    {
        cnt++;
        a.push_back(v);
    }

    for (int i = 1; i <= 3;i++)
    {
        v.push_back(i);
        sum += i;
        dfs(x + 1);
        v.pop_back();
        sum -= i;
    }
}



int main()
{
    ios ::sync_with_stdio(false);
    cin >> n;
    dfs(1);
    cout << cnt << "\n";
    for (auto& aa : a)
    {
        for(auto& b : aa)
        {
            cout << b << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}