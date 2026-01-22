#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int a[N];
int sum[N];
int main(){
    int n;
    cin >> n;
    int MAX_SUM = INT_MIN;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        if (sum[i - 1] < 0)
        {
            sum[i] = a[i];
        }
        else
        {
            sum[i] = sum[i - 1] + a[i];
        }

        MAX_SUM = max(sum[i], MAX_SUM);
    }
    
    cout << MAX_SUM;
    return 0;
}