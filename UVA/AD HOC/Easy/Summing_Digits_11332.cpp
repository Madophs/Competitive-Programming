#include <bits/stdc++.h>

using namespace std;

string sumDigits(string num){
	int res=0;
	for(auto iter = num.begin(); iter!=num.end(); iter++)res+=*iter-'0';
	return to_string(res);
}
int main(){
	ios::sync_with_stdio(false);
	string num;
	while(cin>>num){
		if(num=="0")break;
		while(num.length()>1){
			num=sumDigits(num);
		}
		cout<<num<<"\n";
	}
    return 0;
}
