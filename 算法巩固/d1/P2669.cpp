#include <iostream>
using namespace std;

int cnt,tmp,k;
int ret;

int main()
{
    cin >> k;

    tmp = 1;
    cnt = 1;

    for(int i = 1;i <= k;i++)
    {
        ret += cnt;
        tmp++;
        if(tmp > cnt)
        {
            tmp = 1;
            cnt++;
        }
    }

    cout << ret;
    return 0;
}