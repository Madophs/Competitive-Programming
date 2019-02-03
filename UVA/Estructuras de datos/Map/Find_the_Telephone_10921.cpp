#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	unordered_map<char,int> dictionary;
	for(char c='A'; c<='Z'; c++){
		if(c>='A' && c<='C'){
			dictionary[c]=2;
		}else if(c>='D' && c<='F'){
			dictionary[c]=3;
		}else if(c>='G' && c<='I'){
			dictionary[c]=4;
		}else if(c>='J' && c<='L'){
			dictionary[c]=5;
		}else if(c>='M' && c<='O'){
			dictionary[c]=6;
		}else if(c>='P' && c<='S'){
			dictionary[c]=7;
		}else if(c>='T' && c<='V'){
			dictionary[c]=8;
		}else{
			dictionary[c]=9;
		}
	}
	string line;
	while(getline(cin,line) && !line.empty()){
		for(auto iter = line.begin(); iter!=line.end(); iter++){
			if(isalpha(*iter)){
				cout<<dictionary.find(*iter)->second;
			}else{
				cout<<*iter;
			}
		}
		cout<<"\n";
	}
	return 0;
}
