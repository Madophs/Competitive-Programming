#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t,prisoners,candies,chair;
	cin>>t;
	while(t--){
		cin>>prisoners>>candies>>chair;
		--chair;
		int aux = (candies%prisoners)==0? prisoners : candies%prisoners;
		int ans = aux+chair;
		ans = ans>prisoners? abs(prisoners-ans): ans;
		cout<<ans<<endl;
	}
	return 0;
}