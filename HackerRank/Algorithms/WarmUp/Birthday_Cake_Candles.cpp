#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int candles,max=-1,ans=0,val;
	cin>>candles;
	while(candles--){
		cin>>val;
		if(max==val){
			++ans;
		}else if(max<val){
			ans = 1;
			max = val;
		}
	}
	cout<<ans<<endl;
	return 0;
}