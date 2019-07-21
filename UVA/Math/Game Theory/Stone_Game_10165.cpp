#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int numStones, val, ans;
	while(cin>>numStones && numStones){
		ans = 0;
		while(numStones-- && cin>>val) ans ^= val;
		cout<<(ans ? "Yes\n" : "No\n");
	}
	return 0;
}
