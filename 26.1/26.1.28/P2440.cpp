#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
const int N = 1e5 + 10;

LL n, k;
LL a[N];

LL calc(LL x){
    LL c = 0;
    for (int i = 0; i < n; i++){
        c += a[i] / x;
    }
    return c;
}
int main(){

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    LL left = 0, right = 1e8;
    while(left < right){
        LL mid = left + (right - left + 1) / 2;
        if(calc(mid) >= k)
            left = mid;
            else right = mid - 1;
    }

    cout << left;

    return 0;
}