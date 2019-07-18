#include <bits/stdc++.h>

using namespace std;

vector<int> getLetters(string &str){
	vector<int> vec(256,0);
	for(int i = 0; i < str.length(); ++i){
		++vec[(int)str[i]];
	}
	return vec;
}

bool isPossible(string &words, vector<int> letters){
	for(char c : words)
		if(!letters[(int)c]) return false;
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string favorite, word;
	int numWords, ans = 0;
	cin>>favorite;
	cin>>numWords;
	vector<int> letters = getLetters(favorite);
	while(numWords-- && cin>>word){
		ans += isPossible(word, letters);
	}
	cout<<ans<<"\n";
	return 0;
}
