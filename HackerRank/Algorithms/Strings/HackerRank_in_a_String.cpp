#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string hacker = "hackerrank", s;
	int t;
	cin>>t;
	while(t-- && cin>>s){
		int i = 0;
		for(int x=0; x<s.length() && i<hacker.length(); x++)
			if(s[x] == hacker[i]) ++i;
		cout<<(i==hacker.length()?"YES":"NO")<<endl;
	}
	return 0;
}
