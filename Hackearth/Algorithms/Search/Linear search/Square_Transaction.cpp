#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t,val,q,target;
	cin>>t;
	vector<int> transactions(t+1);
	for(int x=1; x<=t && cin>>val; x++)transactions[x] = transactions[x-1]+val;
	cin>>q;
	while(q-- && cin>>target){
		if(target > transactions[transactions.size()-1]){
			cout<<-1<<"\n";
		}else{
			int pos = lower_bound(transactions.begin(), transactions.end(), target)-transactions.begin();
			cout<<pos<<"\n";
		}
	}	
	return 0;
}