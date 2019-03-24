#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string word, line;
	vector<vector<int>> dic;
	vector<int> lengths;
	while(cin>>word && word!="#"){
		dic.emplace_back(vector<int>(26,0));
		lengths.emplace_back(word.length());
		for(int i = 0; i<word.length(); i++){
			dic.back()[word[i]-'a']++;
		}
	}
	cin.ignore();
	while(getline(cin,line) && line!="#"){
		word = "";
		vector<int> frec(26,0);
		for(int i = 0; i<line.length(); i++){
			if(isalpha(line[i])){
				word+=line[i];
				frec[line[i]-'a']++;
			}
		}
		int ans = 0;
		for(int i = 0; i<dic.size(); i++){
			if(lengths[i] > word.length()) continue;			
			bool canBeCreated = true;
			for(int j = 0; j<26 && canBeCreated; j++){
				if(dic[i][j]>frec[j]) canBeCreated = false;
			}
			ans+=canBeCreated;
		}
		cout<<ans<<"\n";
	}
	return 0;
}