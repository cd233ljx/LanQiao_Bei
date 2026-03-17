#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

string st[10] =
    {
        "1111110",
        "0110000",
        "1101101",
        "1111001",
        "0110011",
        "1011011",
        "1011111",
        "1110000",
        "1111111",
        "1111011"};

string in[19] =
    {
        "0000011",
        "1001011",
        "0000001",
        "0100001",
        "0101011",
        "0110110",
        "1111111",
        "0010110",
        "0101001",
        "0010110",
        "1011100",
        "0100110",
        "1010000",
        "0010011",
        "0001111",
        "0101101",
        "0110101",
        "1101010"};



int main()
{
    LL ret = 1;

    for (int i = 0; i < 18;i++)
    {
        string ina = in[i];

        int cnt = 0; // ina的可能数
        for (int j = 0; j < 10;j++)
        {
            bool flag = true;
            for (int k = 0; k < 7;k++)
            {
                if(ina[k] == '1' && st[j][k] == '0')
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
                cnt++;
        }
        //cout << cnt << endl;
        ret *= cnt;
    }

    cout << ret;

    return 0;
}