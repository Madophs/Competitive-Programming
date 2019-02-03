#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q;
	string anagram;
	cin>>q;
	while(q-- && cin>>anagram){
		if(anagram.length() & 1){
			cout<<-1<<endl;
		}else{
			string s1 = anagram.substr(0, anagram.length()/2), s2 = anagram.substr(anagram.length()/2,string::npos);
			sort(s1.begin(), s1.end());
			sort(s2.begin(), s2.end());
			int i = 0, j = 0, common = 0;
			while(i < s1.length() && j < s1.length()){
				if(s1[i] == s2[j]){
					++i,++j,++common;
				}else if(s1[i] < s2[j]){
					++i;
				}else{
					++j;
				}
			}
			cout<<(s1.length()-common)<<endl;
		}
	}
	return 0;
}
