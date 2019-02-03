#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	string garden;
	cin>>t;
	while(t--){
		cin>>garden;
		int ans = 0;
		for(auto iter = garden.begin(); iter!=garden.end(); iter++)
			if(tolower(*iter)=='a' || tolower(*iter)=='e'|| tolower(*iter)=='i' || tolower(*iter)=='o' || tolower(*iter)=='u')++ans;
		cout<<ans<<"\n";
	}
	return 0;
}