#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int in = 0;
	int n = 0;
	int ret = 0;
	int i = 0;
	cin >> in;
	while(in){
		n = in % 10;
		if(n % 2)
			ret += 1 * pow(10,i);
		i++;
		in /= 10;
	}
	cout << ret;
	return 0;
}
