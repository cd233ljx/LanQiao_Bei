#include<bits/stdc++.h>
using namespace std;

int k;
string n;

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= k;i++)
    {
        bool flag = false;
        for (int j = 0; j < n.size() - 1;j++)
        {
            if(n[j] > n[j+1])
            {
                n.erase(j, 1);
                flag = true;
                break;
            }
        }
        if(!flag)
            n.pop_back();
    }

    //前导0
    while (n.size() > 1 && n[0] == '0')
        n.erase(0, 1);

    cout << n;
    return 0;
}