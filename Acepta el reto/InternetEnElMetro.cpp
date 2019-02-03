#include <iostream>
#include <algorithm>
using namespace std;
bool ordenamiento(pair<int ,int> p, pair<int, int> p2){
	return p.first<p2.first;
}
int main(){
	std::ios_base::sync_with_stdio(false);
	int tc=0,tunel=0,ant=0;
	pair<int,int> wifi[1001];
	cin>>tc;
	while(tc--){
		cin>>tunel>>ant;
		int val=0,pos=0;
		for(int x=0; x<ant; x++){
			cin>>pos;
			cin>>val;
			wifi[x]=make_pair(pos-val,pos+val);
		}
		sort(wifi,wifi+ant,ordenamiento);
		int i=1e9,j=0;
		bool si=true;
		for(int x=0;x<ant;x++){
			if(wifi[x].first>j && x!=0){
				si=false;
				break;
			}
			if(wifi[x].first<i){
				i=wifi[x].first;
			}
			if(wifi[x].second>j){
				j=wifi[x].second;
			}
		}
		cout<<((si && i<=0 && j>=tunel)?"SI\n":"NO\n");
	}
	return 0;
}
