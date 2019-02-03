#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	string word;
	while(cin>>word){
		unordered_set<char> characters;
		unordered_set<string> unique;
		int ans=0;
		for(auto iter = word.begin(); iter!=word.end(); iter++)characters.insert(*iter);
		ans+=characters.size();
		unsigned int l=0,h=word.length();
		while(true){
			string temp =word.substr(l,h);
			bool si=true;
			for(int x=0,y=temp.size()-1; x<=y && temp.size()>1; x++,y--){
				if(temp.at(x)!=temp.at(y)){
					si=false;
					break;
				}
			}
			if(si && temp.size()>1){
				auto iter = unique.find(temp);
				if(iter==unique.end()){
					unique.insert(temp);
					++ans;
				}
			}
			if((l+1)>word.size()){
				l=0,--h;
			}else{
				++l;
			}
			if(h==1)break;
		}
		cout<<"The string '"<<word<<"' contains "<<ans<<" palindromes.\n";
	}

	return 0;
}
