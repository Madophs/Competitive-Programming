#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, number;
	cin>>t;
	while(t-- && cin>>number){
		string snumber = to_string(number);
		int ans = 0;
		for(auto iter = snumber.begin(); iter!=snumber.end(); iter++)if(*iter!='0' && number%(*iter-'0')==0)++ans;
		cout<<ans<<endl;
	}	
	return 0;
}