#include <bits/stdc++.h>

using namespace std;

int getAlternatingCount(char c1, char c2, string &s){
	int cont = 0, flagA = -1, flagB = -1;
	for(auto iter = s.begin(); iter!=s.end(); iter++){
		if(*iter!=c1 && *iter!=c2)continue;
		if(flagA == flagB && flagA == -1){
			if(*iter==c1){
				flagA = 1;
				flagB = 0;
			}else{
				flagA = 0;
				flagB = 1;
			}
			++cont;
		}else{
			if(flagA==0 && *iter==c1){
				flagA = 1;
				flagB = 0;
				++cont;
			}else if(flagB==0 && *iter==c2){
				flagA = 0;
				flagB = 1;
				++cont;
			}else{
				cont = 0;
				break;
			}
		}
	}
	return cont;
}
int main(){
	ios_base::sync_with_stdio(false);
	int s, dif=0;
	int frec[26];
	vector<char> letters;
	memset(frec,0,sizeof(frec));
	string word;
	cin>>s;
	cin>>word;
	for(auto iter = word.begin(); iter!=word.end(); iter++)++frec[*iter-'a'];
	for(int x = 0; x<26 ; x++){
		if(frec[x]){
			++dif;
			letters.push_back(x+'a');
		}
	}
	if(dif==1){
		cout<<0<<endl;
	}else{
		int ans=0;
		for(int x=0; x<letters.size()-1; x++){
			for(int y=x+1; y<letters.size(); y++){
				if(abs(frec[letters[x]-'a']-frec[letters[y]-'a'])==1 || abs(frec[letters[x]-'a']-frec[letters[y]-'a'])==0){
					int res = getAlternatingCount(letters[x],letters[y],word);
					ans = max(res,ans);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}