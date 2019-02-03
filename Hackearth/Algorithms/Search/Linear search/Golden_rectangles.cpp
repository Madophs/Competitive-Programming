#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,ans=0;
	double width, height;
	cin>>n;
	while(n-- && cin>>width>>height){
		double ratio = max(width,height)/min(width, height);
		if(ratio>=1.6 && ratio<=1.7)++ans;
	}	
	cout<<ans<<'\n';
	return 0;
}