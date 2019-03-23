#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tests = 0, numbers, queries, val;
	while(cin>>numbers && numbers){
		vector<int> vecNumbers;
		while(numbers-- && cin>>val) vecNumbers.emplace_back(val);
		cin>>queries;
		cout<<"Case "<<++tests<<":\n";
		while(queries-- && cin>>val){
			int sum = 0, diff = 1e9;
			bool equal = false;
			for(int i = 0; i<vecNumbers.size() && !equal; i++){
				for(int j = 0; j<vecNumbers.size() && !equal; j++){
					if(vecNumbers[i] == vecNumbers[j]) continue;
					if(diff > abs(val-(vecNumbers[i]+vecNumbers[j]))){
						diff = abs(val-(vecNumbers[i]+vecNumbers[j]));
						sum = vecNumbers[i] + vecNumbers[j];
					}
					if(sum == val) equal = true;
				}
			}
			cout<<"Closest sum to "<<val<<" is "<<sum<<".\n";
		}
	}
	return 0;
}