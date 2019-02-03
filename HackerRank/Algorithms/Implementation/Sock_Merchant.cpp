#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n,val,ans=0;
	unordered_map<int,int> socks;
	cin>>n;
	while(n--){
		cin>>val;
		auto iter = socks.find(val);
		if(iter == socks.end()){
			socks[val] = 1;
		}else{
			++iter->second;
		}
	}
	for(auto iter = socks.begin(); iter!=socks.end(); iter++)ans += iter->second/2;
	cout<<ans<<endl;
	return 0;
}