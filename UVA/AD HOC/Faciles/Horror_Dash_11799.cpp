#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int t,creatures,speed,c=0;
	cin>>t;
	while(t--){
		cin>>creatures;
		int ans=-1;
		while(creatures--){
			cin>>speed;
			ans=max(speed,ans);
		}
		cout<<"Case "<<++c<<": "<<ans<<"\n";
	}
    return 0;
}
