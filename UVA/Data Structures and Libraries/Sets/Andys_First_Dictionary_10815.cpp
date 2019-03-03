#include <bits/stdc++.h>

using namespace std;

void transformWord(string str, set<string> &dic){
	string temp = "";
	for(auto it = str.begin(); it!=str.end(); it++){
		if(isalpha(*it)){
			temp+=tolower(*it);
		}else{
			if(!temp.empty()){
				dic.insert(temp);
			}
			temp = "";
		}		
	}
	if(!temp.empty()){
		dic.insert(temp);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string line;
	set<string> diccionary;
	while(cin>>line){
		transformWord(line,diccionary);
	}
	for(auto it = diccionary.begin(); it!=diccionary.end(); it++)
		cout<<*it<<"\n";
	return 0;
}