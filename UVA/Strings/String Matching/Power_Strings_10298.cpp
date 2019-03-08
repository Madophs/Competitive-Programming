#include <bits/stdc++.h>

using namespace std;

int maxN(string str){
	int i = 0, j = -1;
	vector<int> pattern(str.length()+1,0);
	pattern[0] = -1;
	while(i<str.length()){
		while(j>=0 && str[i]!=str[j]) j = pattern[j];
		++j,++i;
		pattern[i] = j;
	}
	int patLength = str.length()-pattern.back();
	if(pattern.back() == 0) return 1;
	return str.length()/patLength;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str;
	while(cin>>str && str!="."){
		cout<<maxN(str)<<"\n";
	}
	return 0;
}