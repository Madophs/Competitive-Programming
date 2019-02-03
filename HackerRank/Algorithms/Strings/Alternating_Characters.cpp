#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	int t;
	cin>>t;
	while(t-- && cin>>s){
		int deletions = 0;
		for(int x=0, j=1; j<s.length(); x++,j++){
			if(s[x]==s[j])++deletions;
		}
		cout<<deletions<<endl;
	}
	return 0;
}
