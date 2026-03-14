#include <bits/stdc++.h>
using namespace std;

int n1, n2, m;
list<int> q1, q2;
unordered_map<int, list<int>::iterator> mp1, mp2;

int main()
{
    cin >> n1 >> n2;
    cin >> m;

    while (m--)
    {
        int x;
        cin >> x;

        if (mp1.count(x))
        {
            q1.erase(mp1[x]);
            mp1.erase(x);
            q1.push_front(x);
            mp1[x] = q1.begin();
        }
        else if (mp2.count(x))
        {
            q2.erase(mp2[x]);
            mp2.erase(x);
            q1.push_front(x);
            mp1[x] = q1.begin();
        }
        else
        {
            q2.push_front(x);
            mp2[x] = q2.begin();
        }

        if (q1.size() > n1)
        {
            x = *q1.rbegin();
            q1.pop_back();
            mp1.erase(x);
            if (q2.size() <= n2)
            {
                q2.push_front(x);
                mp2[x] = q2.begin();
            }
        }
        if (q2.size() > n2)
        {
            x = *q2.rbegin();
            q2.pop_back();
            mp2.erase(x);
        }
    }

    for (auto x :q1)
    {
        cout << x << " ";
    }
    cout << endl;

    for (auto x : q2)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}