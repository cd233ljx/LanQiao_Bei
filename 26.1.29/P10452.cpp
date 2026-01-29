#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
const int N = 1e5 + 10;

int n;
LL a[N];

LL calc1(int x){
    LL sum = 0;
    for (int i = 1; i <= n; i++)
        sum += abs(x - a[i]);
    return sum;
}

int main(){
    
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    int median_i = n/2 + 1;
    nth_element(a + 1, a + median_i, a + n + 1); // 求中位数

    cout << calc1(a[median_i]);

    //语法练习：
    // cout << [&]() -> LL {
    //     LL sum = 0;  
    //     for (int i = 1; i <= n; i++)
    //         sum += abs(a[median_i] - a[i]);
    //     return sum; }();

    return 0;
}
