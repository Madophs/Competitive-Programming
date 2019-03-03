#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int t,farmers;
	cin>>t;
	while(t--){
		cin>>farmers;
		int farmyard,animals,degree,ans=0;
		while(farmers--){
			cin>>farmyard>>animals>>degree;
			ans+=farmyard*degree;
		}
		cout<<ans<<"\n";
	}
    return 0;
}
