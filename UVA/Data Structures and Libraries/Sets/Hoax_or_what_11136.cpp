#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int days,numBills,value;
	long long ans;
	multiset<int> bills;
	while(cin>>days && days){
		ans = 0;
		bills.clear();
		while(days--){	
			cin>>numBills;
			while(numBills-- && cin>>value) bills.insert(value);
			int lower = *bills.begin(), higher = *(--bills.end());
			bills.erase(bills.begin()), bills.erase(--bills.end());
			ans += higher-lower;
		}
		cout<<ans<<'\n';
	}
	return 0;
}