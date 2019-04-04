#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> garmentPrices;

const int INFINITE_NEGATIVE = -1e9;
int tests, money, numGarmentsAvailable, numGarments, price;
int memo[201][21];

int maximalPossible(int tempMoney, int currentGarment = 0){
	if(tempMoney<0) return INFINITE_NEGATIVE;
	if(currentGarment == garmentPrices.size()) return money-tempMoney;
	if(memo[tempMoney][currentGarment] != -1) return memo[tempMoney][currentGarment];
	int ans = -1;
	for(int i = 0; i<garmentPrices[currentGarment].size(); i++){
		ans = max(ans,maximalPossible(tempMoney-garmentPrices[currentGarment][i],currentGarment+1));
	}
	return memo[tempMoney][currentGarment] = ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>tests;
	while(tests-- && cin>>money>>numGarmentsAvailable){
		garmentPrices.clear();
		memset(memo, -1, sizeof memo);
		while(numGarmentsAvailable-- && cin>>numGarments){
			garmentPrices.emplace_back(vector<int>());
			while(numGarments-- && cin>>price) garmentPrices.back().emplace_back(price);
		}
		int ans = maximalPossible(money);
		if(ans == -1){
			cout<<"no solution\n";
		}else{
			cout<<ans<<"\n";
		}
	}
	return 0;
}