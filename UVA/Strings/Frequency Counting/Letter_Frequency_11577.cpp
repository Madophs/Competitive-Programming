#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tests;
	int letters[27];
	string line;
	cin>>tests;
	cin.ignore();
	while(tests-- && getline(cin,line)){
		memset(letters, 0, sizeof letters);
		for(int i = 0; i<line.length(); i++){
			if(isalpha(line[i])){
				++letters[tolower(line[i])-'a'];
			}
		}
		string ans = "";
		int maximum = 1;
		for(int i = 0; i<26; i++){
			if(maximum<=letters[i]){
				if(maximum<letters[i]){
					maximum = letters[i];
					ans = (char)(i+'a');
				}else{
					ans+=(char)(i+'a');
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}