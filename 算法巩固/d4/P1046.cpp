#include<iostream>
using namespace std;

int a[15];

int main()
{
    for (int i = 1; i <= 10;i++)
        cin >> a[i];

    int h;
    cin >> h;
    h += 30;
    int ret = 0;
    for (int i = 1; i <= 10;i++)
    if(a[i] <= h)
        ret++;

    cout << ret;
    return 0;
}