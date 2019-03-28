#include <bits/stdc++.h>

using namespace std;

int globalIndex = 0;
unordered_map<string, int> wordIndex;

string nextString(int length){
	if(length == 1) return "a";
	string ret = "a";
	while(ret.length() < length) ret+=(ret[ret.length()-1]+1);
	return ret;
}

void generateStrings(string s = "a", int index = 0, char limit = 'z'){
	while(s[index] <= limit){
		if(index+1 == s.length()){
			wordIndex[s] = ++globalIndex;
		}
		if(index+1<s.length()){
			generateStrings(s, index+1,'z'-(s.length()-(index+2)));
		}
		if(s[index] == limit) break;
		if(index+1<s.length()){
			s[index] = s[index]+1;
			for(int i = index+1; i<s.length(); i++){
				s[i] = s[i-1]+1;
			}
		}else{
			s[index] = s[index]+1;
		}
	}
	if(s.length()+1<6 && index == 0){
		string temp = nextString(s.length()+1);
		generateStrings(temp,0,'z'-(temp.length()-1));
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	generateStrings();
	string word;
	while(cin>>word){
		if(wordIndex.find(word) != wordIndex.end()){
			cout<<wordIndex.find(word)->second<<"\n";
		}else{
			cout<<"0\n";
		}
	}
	return 0;
}