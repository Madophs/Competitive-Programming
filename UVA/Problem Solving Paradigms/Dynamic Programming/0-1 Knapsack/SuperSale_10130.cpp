#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1010, MAX_W = 35;

int numProducts, price[MAX_N], weight[MAX_N], memo[MAX_N][MAX_W];

int getMaximum(int index, int capacity){
	if(index == numProducts || capacity == 0) return 0;
	if(memo[index][capacity] != -1) return memo[index][capacity];
	if(weight[index] > capacity) return memo[index][capacity] = getMaximum(index+1, capacity);
	return memo[index][capacity] = max(getMaximum(index+1,capacity), price[index] + getMaximum(index+1, capacity-weight[index]));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tests, people, capacity, ans;
	cin>>tests;
	while(tests--){
		cin>>numProducts;
		for(int i = 0; i<numProducts; i++) cin>>price[i]>>weight[i];
		cin>>people;
		ans = 0;
		memset(memo,-1,sizeof memo);
		while(people-- && cin>>capacity){
			ans += getMaximum(0,capacity);
		}
		cout<<ans<<"\n";
	}
	return 0;
}