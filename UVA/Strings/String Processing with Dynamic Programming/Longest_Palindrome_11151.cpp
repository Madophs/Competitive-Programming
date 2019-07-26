#include <bits/stdc++.h>

using namespace std;

const int MAX_VALUE = 1005;

int memo[MAX_VALUE][MAX_VALUE];
string line;

int largestPalindrome(int l, int r){
	if(l > r) return 0;
	if(memo[l][r] != -1){
		return memo[l][r];
	}else if(l == r){
		return memo[l][r] = 1;
	}else if(l+1 == r){
		if(line[l] == line[r]){
			return memo[l][r] = 2;
		}else{
			return memo[l][r] = 1;
		}
	}else if(line[l] == line[r]){
		return memo[l][r] = 2 + largestPalindrome(l+1, r-1);
	}
	return memo[l][r] = max(largestPalindrome(l, r-1), largestPalindrome(l+1, r));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	cin.ignore();
	while(t-- && getline(cin,line)){
		memset(memo, -1, sizeof memo);
		cout<<largestPalindrome(0, line.length()-1)<<"\n";
	}
	return 0;
}
