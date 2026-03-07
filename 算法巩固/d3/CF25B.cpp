#include <iostream>

using namespace std;

int main()
{
    int n;
    string s;

    cin >> n >> s;

    if (n % 2) // 奇数
    {
        for (int i = 0; i < n; i++)
        {
            cout << s[i];
            if (i % 2 && i < n - 3)
                cout << "-";
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << s[i];
            if (i % 2 && i < n - 2)
                cout << "-";
        }
    }

    return 0;
}