#include <bits/stdc++.h>
#define lsb(n) n&-n


using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long num;
	while(cin>>num){
		int ans = 0;
		while(num){
			++ans;
			num^=lsb(num);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
