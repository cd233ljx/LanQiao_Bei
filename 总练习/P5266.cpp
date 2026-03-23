#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;
string N;
int S;

void Insert()
{
    cin >> N >> S;
    if(N.size() <= 20 && S > 0)
    {
        mp[N] = S;
        cout << "OK" << "\n";
    }
    return;
}

void Find()
{
    cin >> N;
    if(mp.find(N)!= mp.end())
    {
        cout << mp[N] << "\n";
    }
    else
    {
        cout << "Not found" << "\n";
    }
}

void Delete()
{
    cin >> N;
    auto it = mp.find(N);
    if (it != mp.end())
    {
        mp.erase(it);
        cout << "Deleted successfully" << "\n";
    }
    else
    {
        cout << "Not found" << "\n";
    }
}

int main()
{
    ios ::sync_with_stdio(false);
    int q;
    cin >> q;
    while (q--)
    {
        int op;
        cin >> op;

        switch (op)
        {
        case 1:
            Insert();
            break;
        case 2:
            Find();
            break;
        case 3:
            Delete();
            break;
        case 4:
            cout << mp.size() << "\n";
        }
    }

    return 0;
}