#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<string> wordList;
	string line;
	while(getline(cin,line) && line != "0"){
		if(line.empty()){
			cout<<"\n";
			continue;
		}
		for(int i = 0; i < line.length();){
			if(isalpha(line[i])){
				int j = i;
				while(j < line.length() && isalpha(line[j])) ++j;
				string word = line.substr(i,j-i);
				wordList.emplace_back(word);
				cout<<word;
				i = j;
			}else{
				if(isdigit(line[i])){
					int j = i;
					while(j < line.length() && isdigit(line[j])) ++j;
					int pos = atoi(line.substr(i,j-i).c_str())-1;
					string word = wordList[((int)wordList.size()-1) - pos];
					cout<<word;
					wordList.erase(wordList.begin() + (((int)wordList.size()-1) - pos));
					wordList.emplace_back(word);
					i = j;
				}else{
					cout<<line[i++];
				}
			}
		}
		cout<<"\n";
	}	
	return 0;
}
