#include <bits/stdc++.h>
using namespace std;

int n;
string x;
vector<int> syb;
bool flag = false;
int out = 0x3f3f3f3f;
int nn;

bool isprime(int x)
{
    if (x == 1 || x == 2)
        return true;

    if (x % 2 == 0)
        return false;

    for (int i = 3; i * i <= x; i++)
    {
        if (x % i == 0)
            return false;
    }

    return true;
}


void dfs(int step)
{
    if (step > nn)
    {

        int nums = stoi(x);
        if (isprime(nums))
        {
            out = min(nums, out);
            flag = true;
        }

        return;
    }

    for (char num = '0'; num <= '9'; num++)
    {
        int idx = syb.back();
        syb.pop_back();
        x[idx] = num;
        dfs(step + 1);
        syb.push_back(idx);
    }
}

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        syb.clear();
        flag = false;
        out = 0x3f3f3f3f;
        cin >> x;
        for (int i = 1; i < x.size(); i++)
        {
            if (x[i] == '*')
            {
                syb.push_back(i);
            }
        }
        nn = syb.size();

        dfs(1);
        
        if(flag)
        {
            cout << out << "\n";
        }
        else
            cout << -1 << "\n";
    }

    return 0;
}
