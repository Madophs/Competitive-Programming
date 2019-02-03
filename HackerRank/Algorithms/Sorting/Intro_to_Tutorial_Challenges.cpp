#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int num,n,ans=-1,val;
	cin>>num>>n;
	for(int x=0; x<n; x++){
		cin>>val;
		if(ans==-1 && num==val)ans = x;
	}	
	cout<<ans<<endl;
	return 0;
}