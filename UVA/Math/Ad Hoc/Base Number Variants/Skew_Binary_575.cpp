#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string line;
	while(cin>>line && line != "0"){
		int ans = 0;
		for(int i = line.length()-1, power = 1; i>=0; i--, power++){
			ans += (line[i]-'0')*((1<<power)-1);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
