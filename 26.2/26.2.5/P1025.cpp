#include<bits/stdc++.h>
using namespace std;

int n, k;
int ret;

void dfs(int pos, int begin, int sum){
    if(pos == k){
        if(sum == n)
            ret++;
        return;
    }
    for (int i = begin; i <= n - k + 1; i++){

        if(sum + i * (k - pos) > n)
            return;
            
        dfs(pos + 1, i, sum + i);
    }
}


int main(){
     cin >> n >> k;
     dfs(0, 1, 0);
     cout << ret;
     return 0;
}