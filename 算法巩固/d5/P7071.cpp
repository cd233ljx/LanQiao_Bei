#include<iostream>
using namespace std;

int n;

int main()
{
    cin >> n;

    if(n & 1)
    {
        cout << -1;
        return 0;
    }

    for (int i = 30; i >= 0;i--)
    {
        if((n >> i) & 1)
        {
            cout << (1 << i) << " ";
        }
    }

        return 0;
}