#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin>>s;
	int reductions = 0;
	do{
		reductions = 0;
		for(int x=0, y=1; y<s.length(); x++,y++){
			if(s[x]=='#' || s[y]=='#') continue;
			if(s[x]==s[y]){
				s[x]=s[y]='#';
				++reductions;
			}
		}
		if(reductions) s.erase(remove(s.begin(), s.end(),'#'),s.end());
	}while(reductions);
	cout<<(s.empty()?"Empty String": s)<<endl;
	return 0;
}