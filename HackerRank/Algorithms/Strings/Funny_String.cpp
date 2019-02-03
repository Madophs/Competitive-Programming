#include <bits/stdc++.h>

using namespace std;

string isFunny(string &s){
	vector<int> difA,difB;
	for(auto x=s.begin(), y=s.begin()+1, i=s.end()-1, j=s.end()-2; y!=s.end(); x++,y++,i--,j--){
		difA.push_back(abs(*x-*y));
		difB.push_back(abs(*i-*j));
	}
	return difA==difB?"Funny": "Not Funny";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int q;
	string word;
	cin>>q;
	while(q--){
		cin>>word;
		cout<<isFunny(word)<<endl;
	}
	return 0;
}