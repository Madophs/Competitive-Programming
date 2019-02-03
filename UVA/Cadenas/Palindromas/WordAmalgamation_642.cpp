#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	unordered_map<string,vector<string>> dictionary;
	string word,aux;
	while(cin>>word){
		if(word=="XXXXXX")break;
		aux=word;
		sort(word.begin(),word.end());
		auto iter = dictionary.find(word);
		if(iter==dictionary.end()){
			vector<string> temp(1,aux);
			dictionary[word]=temp;
		}else{
			iter->second.push_back(aux);
		}
	}
	while(cin>>word){
		if(word=="XXXXXX")break;
		sort(word.begin(),word.end());
		auto iter = dictionary.find(word);
		if(iter==dictionary.end()){
			cout<<"NOT A VALID WORD\n******\n";
		}else{
			sort(iter->second.begin(),iter->second.end());
			for(auto x=iter->second.begin(); x!=iter->second.end(); x++){
				cout<<*x<<"\n";
			}
			cout<<"******\n";
		}
	}
	return 0;
}