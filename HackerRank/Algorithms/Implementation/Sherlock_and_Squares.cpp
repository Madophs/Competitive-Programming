#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q,i,j,ans=0,num;
	cin>>q;
	while(q-- && cin>>i>>j){
		num = floor(sqrt(i)),ans=0;
		int power=0;
		while(power<=j){
			power = num*num;
			++num;
			if(power>=i && power<=j)++ans;
		}
		cout<<ans<<endl;
	}
	return 0;
}