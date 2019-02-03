#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int heights[26];
	string word;
	for(int x=0; x<26; x++)cin>>heights[x];
	cin>>word;
	int maxHeight = -1;
	for(auto iter = word.begin(); iter!=word.end(); iter++)maxHeight = max(maxHeight,heights[*iter-'a']);
	cout<<maxHeight*word.length()<<endl;
	return 0;
}