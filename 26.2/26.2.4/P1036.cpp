#include <iostream>
using namespace std;

//int sum = 0;
int n, k;
int ret = 0;
int x[25];

/*bool isprime(int x)
{
    if (x == 1)
        return false; 
    for (int i = 2; i * i <= x; ++i)
        if (x % i == 0)
            return false;
    return true;
}*/
bool isprime(int y)
{
    if (y < 2)
        return 0; // 特判
    if (y < 4)
        return 1; // 特判
    if (y % 2 == 0 || y % 3 == 0 || y % 5 == 0)
        return 0; // 特判
    int i = 7;    // 代表第一个6k+1
    while (i * i <= y)
    {
        if (y % i == 0)
            return 0;
        i += 4; // 转换成6k+5
        if (y % i == 0)
            return 0;
        i += 2; // 转换回6k+1
    }
    return 1;
}

void dfs(int pos, int begin, int cur_sum)
{
    if (pos > k)
    {
        if(isprime(cur_sum))
            ret++;
        return;
    }

    // 剪枝：如果剩余元素不够选择k-pos个，则直接返回
    if (n - begin < k - pos + 1)
        return;

    for (int i = begin; i < n; i++)
    {
        //sum += x[i];
        dfs(pos + 1, i + 1, cur_sum + x[i]);
        //sum -= x[i];
    }
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> x[i];
    dfs(1, 0, 0);
    cout << ret;
}