#include <bits/stdc++.h>

using namespace std;

int length[35];

void tokenizeString(string str){
	int i = 0, j = 0;
	while(j<str.length()){
		int specials = 0;
		while(isalpha(str[j]) ||  str[j] == '\'' || str[j] == '-') {
			++j;
			if(str[j] == '\'' || str[j] == '-') ++specials;
		}
		++length[j-i-specials];
		i = ++j;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string line, simpleLine;
	while(getline(cin, simpleLine)){
		line = simpleLine;
		memset(length, 0, sizeof length);
		while(getline(cin, simpleLine) && simpleLine[0]!='#'){
			if(line.back() == '-'){
				line += simpleLine;
			}else{
				line += " " + simpleLine;
			}
		}
		stringstream ss(line);
		string token;
		while(ss>>token){
			tokenizeString(token);
		}
		bool block = false;
		for(int i = 1; i<35; i++){
			if(!length[i]) continue;
			cout<<i<<" "<<length[i]<<"\n";
			block = true;
		}
		if(block) cout<<"\n";
	}
	return 0;
}
