#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
set<LL> mp;

int main()
{
    ios ::sync_with_stdio(false);

    int m;
    cin >> m;
    while(m--)
    {
        int op;
        LL len;
        cin >> op >> len;
        if(op == 1)
        {
            bool insertBool = mp.insert(len).second;
            if(!insertBool)
            {
                cout << "Already Exist\n";
            }
            
        }
        else
        {
            if(mp.empty())
            {
                cout << "Empty\n";
                continue;
            }

            auto l = mp.lower_bound(len);
            if (l == mp.end())
            {
                cout << *mp.rbegin() <<"\n";
                mp.erase(prev(mp.end()));
            }
            else if (l == mp.begin())
            {
                cout << *mp.begin() << "\n";
                mp.erase(mp.begin());
            }
            else
            {
                auto ans = abs(*l - len) >= abs(*prev(l) - len) ? prev(l) : l;
                cout << *ans << "\n";
                mp.erase(ans);
            }
            
        }
    }

    return 0;
}