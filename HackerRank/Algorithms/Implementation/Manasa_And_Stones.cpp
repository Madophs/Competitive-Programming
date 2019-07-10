#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tests, stones, a, b, possible;
	set<int> values;
	cin>>tests;
	while(tests-- && cin>>stones>>a>>b){
		values.clear();
		--stones;
		for(int i = 0, j = stones; i <= stones; ++i, --j){
			possible = (i*a) + (j*b);
			values.insert(possible);
		}
		for(auto val : values){
			cout<<val<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
