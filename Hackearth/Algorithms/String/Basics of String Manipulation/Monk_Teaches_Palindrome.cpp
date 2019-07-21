#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string &line){
	for(int i = 0; i < line.length()/2; ++i){
		if(line[i] != line[line.length()-1-i]) return false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	string line;
	cin>>t;
	while(t-- && cin>>line){
		if(!isPalindrome(line)){
			cout<<"NO\n";
		}else{
			cout<<"YES ";
			if((int)line.length() & 1){
				cout<<"ODD\n";
			}else{
				cout<<"EVEN\n";
			}
		}
	}
	return 0;
}
