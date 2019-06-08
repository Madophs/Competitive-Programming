#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	unsigned long long num = 3e18, ans;
	int tests;
	cin>>tests;
	while(tests-- && cin>>num){
		num<<=1;
		ans = floor(sqrtl(num));
		if(ans*(ans+1)>num)--ans;
		cout<<ans<<endl;
	}
	return 0;
}