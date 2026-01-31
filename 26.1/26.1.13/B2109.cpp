#include<iostream>
#include<string>
using namespace std;

int main(){
	string s;
	getline(cin, s);
	int cnt = 0;
	for(auto c : s){
		if(isdigit(c)){
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
