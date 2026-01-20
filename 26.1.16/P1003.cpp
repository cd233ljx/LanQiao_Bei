#include<iostream>
using namespace std;

int n;
const int N = 1e4 + 10;
int a[N], b[N], g[N], k[N];
int x, y;

int find(){
	for(int j = n; j >= 1; j--){
		if(x >= a[j] && x <= a[j] + g[j] && y >= b[j] && y <= b[j] + k[j]){
			return j;
		}
	}
		return -1;
}

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> b[i] >> g[i] >> k[i];
	}
	cin >> x >> y;
	cout << find();
	return 0;
}
