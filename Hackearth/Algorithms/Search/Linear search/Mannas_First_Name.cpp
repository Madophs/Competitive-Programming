#include <bits/stdc++.h>

using namespace std;

pair<int,int> countOcurrences(string &text,string &str , vector<int> &pattern){
	int i=0,j=0;
	int suvo = 0, suvojit = 0;
	while(j<text.length()){
		while(i>=0 && text[j]!=str[i]) i = pattern[i];
		++i,++j;
		if(i==4)++suvo;
		if(i == str.size()){
			++suvojit,--suvo;
			i = pattern[i];
		}
	}
	return make_pair(suvo,suvojit);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string name = "SUVOJIT",word;
	vector<int> p1(name.size()+1,0);
	p1[0] = -1;
	int t;
	cin>>t;
	while(t-- && cin>>word){
		pair<int,int> ans = countOcurrences(word,name,p1);
		cout<<"SUVO = "<<ans.first<<", SUVOJIT = "<<ans.second<<'\n';
	}
	return 0;
}