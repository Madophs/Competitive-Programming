#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tests, relatives;
	cin>>tests;
	while(tests-- && cin>>relatives){
		vector<int> houses(relatives,0);
		for(int i = 0; i<houses.size() && cin>>houses[i]; i++);
		int ans = 1e9, sum;
		for(int i = 0; i<houses.size(); i++){
			sum = 0;
			for(int j = 0;j<houses.size(); j++){
				if(i == j) continue;
				sum += abs(houses[i]-houses[j]);
			}
			ans = min(ans,sum);
		}
		cout<<ans<<'\n';
	}
	return 0;
}