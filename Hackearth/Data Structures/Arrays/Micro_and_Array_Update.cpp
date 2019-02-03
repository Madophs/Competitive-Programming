#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int t,n,k,res,val;
	cin>>t;
	while(t--){
		cin>>n>>k;
		res = 0;
		while(n--){
			cin>>val;
			if(val>=k)continue;
			res = max(res,abs(k-val));
		}
		cout<<res<<endl;
	}
	return 0;
}