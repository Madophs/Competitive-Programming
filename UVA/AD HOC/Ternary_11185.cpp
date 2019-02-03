#include <bits/stdc++.h>

using namespace std;
string toTernary(int num){
	if(num==0)return "0";
	string res="";
	while(num){
		res=to_string(num%3)+res;
		num/=3;
	}
	return res;
}
int main() {
	int num;
	while(cin>>num){
		if(num<0)break;
		cout<<toTernary(num)<<endl;
	}
	return 0;
}
