#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,ans=0;
	cin>>n;
	string s;
	cin>>s;
	for(int x=0, y=1, z=2; z<s.length(); x++,y++,z++){
		if(s[x]=='0' && s[y]=='1' && s[z]=='0'){
			s[z]='1';
			++ans;
		}
	}
	cout<<ans<<endl;
	return 0;
}
