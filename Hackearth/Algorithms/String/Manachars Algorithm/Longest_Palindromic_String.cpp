#include <bits/stdc++.h>

using namespace std;

string convertToFormat(string &s){
	string newString = "@";
	for(auto c = s.begin(); c!=s.end(); c++){
		newString+='|';
		newString+=*c;
	}
	newString+="|$";
	return newString;
}

void longestPalindrome(string &s){
	string temp = convertToFormat(s);
	int *pattern = new int[temp.length()+1]();
	int center = 0, r = 0,mirror;
	int longest = 0, indexLongest = 0;
	for(int i = 1; i<temp.length(); i++){
		mirror = 2*center-i;
		if(i < r){
			pattern[i] = min(r-i,pattern[mirror]);
		}
		while(temp[i - 1 - pattern[i]] == temp[i + 1 + pattern[i]])++pattern[i];
		if(i + pattern[i] > r){
			center = i;
			r = i + pattern[i];
		}
		if(pattern[i] > longest){
			longest = pattern[i];
			indexLongest = i;
		}
	}
	cout<<longest<<'\n';
	cout<<s.substr((indexLongest - 1 - longest)/2, longest)<<'\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str;
	cin>>str;
	longestPalindrome(str);
	return 0;
}