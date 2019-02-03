#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t,n,sum,val;
	unordered_multimap<int,int> table;
	cin>>t;
	while(t--){
		cin>>sum>>n;
		for(int x=0; x<n && cin>>val; x++)table.emplace(val,x+1);
		int l=0,r=0;
		bool found = false;
		for(auto iter = table.begin(); iter!=table.end() && !found; iter++){
			auto ref = *iter;
			int temp = sum-ref.first;
			if(table.find(temp)!=table.end()){
				l = ref.second;
				auto range = table.equal_range(temp);
				for(auto it = range.first; it!=range.second; it++){
					auto tempPair = *it;
					if(tempPair.second !=l){
						r = tempPair.second;
						found = true;
						break;
					}
				}
			}
		}
		cout<<min(l,r)<<" "<<max(l,r)<<endl;
		table.clear();
	}
	return 0;
}