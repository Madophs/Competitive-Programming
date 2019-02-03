#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t,ans;
	string str;
	cin>>t;
	while(t-- && cin>>str){
		ans = 0;
		for(auto letter = str.begin(); letter!=str.end(); letter++)
			if(*letter == 'a' || *letter == 'e' || *letter == 'i' || *letter == 'o' || *letter == 'u') ++ans;
		cout<<ans<<'\n';
	}	
	return 0;
}