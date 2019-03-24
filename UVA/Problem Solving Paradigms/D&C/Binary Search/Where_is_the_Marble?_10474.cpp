#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int marbles, queries,val,test = 0;
	while(cin>>marbles>>queries && (marbles || queries)){
		vector<int> values;
		while(marbles-- && cin>>val) values.push_back(val);
		sort(values.begin(), values.end());
		cout<<"CASE# "<<++test<<":\n";
		while(queries-- && cin>>val){
			int pos = lower_bound(values.begin(), values.end(),val) - values.begin();
			if(values[pos] == val){
				cout<<val<<" found at "<<++pos<<"\n";
			}else{
				cout<<val<<" not found\n";
			}
		}
	}
	return 0;
}