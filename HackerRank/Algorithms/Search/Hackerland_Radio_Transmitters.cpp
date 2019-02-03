#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,k,pos;
	cin>>n>>k;
	vector<int> positions;
	while(n-- && cin>>pos)positions.push_back(pos);
	sort(positions.begin(), positions.end());
	int l = -1e9,ans=0,middle=l;
	for(int x=0; x<positions.size(); x++){
		if(positions[x] > middle+k){
			if(positions[x]-k > l){
				++ans;
				l = middle = positions[x];
			}else{
				middle = positions[x];
			}
		}else{
			if(positions[x]-k<=l)
				middle = positions[x];
		}
	}
	cout<<ans<<endl;
	return 0;
}