#include <bits/stdc++.h>

using namespace std;

int coinsValues[110], tests, coins, ans, total;
int memo[25010];
int knapsackBottomUp(int index, int capacity){
	for(int i = 0; i <= capacity; i++) memo[i] = 0;
	for(int i = 1; i <= coins; i++){
		for(int j = capacity; j > 0; j--){
			if(coinsValues[i] <= j)
				memo[j] = max(memo[j], coinsValues[i]+memo[j-coinsValues[i]]);
		}
	}
	return memo[capacity];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>tests;
	while(tests-- && cin>>coins){
		total = 0;
		for(int i = 1; i<=coins && cin>>coinsValues[i]; i++) total += coinsValues[i];
		int ret = knapsackBottomUp(0,total/2);
		ans = (total-ret-ret);
		cout<<ans<<"\n";
	}
	return 0;
}