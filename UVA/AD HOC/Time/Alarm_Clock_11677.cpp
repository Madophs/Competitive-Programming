#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int h1,m1,h2,m2;
	while(cin>>h1>>m1>>h2>>m2 && (h1 || m1 || h2 || m2)){
		int ans = 0;
		if(!h1) h1 = 24;
		if(!h2) h2 = 24;
		if(h1 <= h2){
			ans = (h2-h1)*60;
		}else{
			ans = (24*60)-((max(h1,h2)-min(h1,h2))*60);
		}
		if(m1 > m2){
			ans -= m1-m2;
		}else{
			ans += m2-m1;
		}
		if(ans < 0) ans = (24*60) + ans;
		cout<<ans<<endl;
	}
	return 0;
}
