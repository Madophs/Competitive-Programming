#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string str){
	for(int i = 0; i < str.length()/2; ++i)
		if(str[i] != str[(int)str.length()-1-i]) return false;
	return true;
}

bool isPossible(string &str, int &k){
	if((int)str.length() % k) return false;
	int len = (int)str.length() / k;
	for(int i = 0; i < str.length(); i+=len){
		if(!isPalindrome(str.substr(i,len))) return false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int k, t;
	string line;
	cin>>t;
	while(t-- && cin>>line>>k){
		cout<<(isPossible(line, k) ? "YES\n" : "NO\n");
	}
	return 0;
}
