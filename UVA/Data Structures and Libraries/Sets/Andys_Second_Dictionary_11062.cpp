#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string token, word;
	int i;
	bool hyphenated = false;
	set<string> dic;
	while(cin>>token){
		if(!hyphenated){
			word = "";
		}else{
			hyphenated = false;
		}
		for(i = 0; i<token.length(); i++){
			if(isalpha(token[i]) || (token[i] == '-' && i!=token.length()-1)){
				word += tolower(token[i]);
			}else{
				if(!word.empty()){
					if(i == token.length()-1 && token[i]=='-') continue; 
					dic.insert(word);
					word = "";
				}
			}
		}
		if(!word.empty() && token[token.length()-1]!='-'){
			dic.insert(word);
		}else if(!word.empty()){
			hyphenated = true;
		}
	}
	for(auto it = dic.begin(); it!=dic.end(); it++){
		cout<<*it<<"\n";
	}
	return 0;
}