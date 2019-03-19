#include <bits/stdc++.h>

using namespace std;

bool isVocal(char c){
	return tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'o' || tolower(c) == 'u';
}

string pig_latin(string s){
	if(isVocal(s[0])){
		s+="ay";
	}else{
		char c = s[0];
		s+=c;
		s+="ay";
		s.erase(s.begin());
	}
	return s;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string line, ans;
	while(getline(cin,line)){
		ans = "";
		for(int i = 0; i<line.length();){
			if(isalpha(line[i])){
				int j = i+1;
				while(isalpha(line[j])) ++j;
				ans += pig_latin(line.substr(i,j-i));
				i = j;
			}else{
				ans += line[i++];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}