#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tests, days, val;
	cin>>tests;
	while(tests-- && cin>>days){
		vector<int> money;
		while(days-- && cin>>val) money.emplace_back(val);
		int sum = 0, frec = 0;
		for(int i = 1; i<money.size(); i++){
			frec = 0;
			for(int j = 0; j<i; j++){
				frec+=(money[j]<=money[i]);
			}
			sum+=frec;
		}
		cout<<sum<<"\n";
	}
	return 0;
}