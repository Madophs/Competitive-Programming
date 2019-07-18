#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string &str){
	for(int i = 0; i < str.length()/2; ++i){
		if(str[i] != str[str.length()-1-i]) return false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string word;
	cin>>word;
	cout<<(isPalindrome(word) ? "Palindrome\n" : "Not Palindrome\n");
	return 0;
}
