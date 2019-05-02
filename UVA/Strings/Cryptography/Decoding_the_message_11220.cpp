#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tests;
	string line;
	cin>>tests;
	cin.ignore();
	cin.ignore();
	for(int t = 0; tests--; t++){
		if(t) cout<<"\n";
		cout<<"Case #"<<t+1<<":\n";
		while(getline(cin,line) && !line.empty()){
			string word = "", secretWord = "";
			stringstream ss(line);
			int index = 0;
			while(ss>>word){
				if(index+1 > word.length()) continue;
				secretWord += word[index++];
			}
			cout<<secretWord<<"\n";
		}
	}
	return 0;
}
