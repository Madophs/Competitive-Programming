#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int listSize;
	string number;
	cin>>listSize;
	while(listSize-- && cin>>number){
		if(number.length() != 10){
			cout<<"NO\n";
		}else{
			if(regex_match(number, regex("^[1-9][0-9]+$"))){
				cout<<"YES\n";
			}else{
				cout<<"NO\n";
			}
		}
	}
	return 0;
}
