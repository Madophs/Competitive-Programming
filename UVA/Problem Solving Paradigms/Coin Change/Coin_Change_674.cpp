#include <bits/stdc++.h>

using namespace std;

int coins[] = {50, 25, 10, 5, 1};
int memo[7][8000];
int numbersOfWays(int money, int index = 0){
	if(money == 0) return 1;
	if(money < 0 || index == 5) return 0;
	if(memo[index][money] != -1) return memo[index][money];
	if(coins[index] > money) return memo[index][money] = numbersOfWays(money, index + 1);
	return memo[index][money] = numbersOfWays(money-coins[index], index) + numbersOfWays(money, index + 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int money;
	memset(memo, -1, sizeof memo);
	while(cin>>money){
		cout<<numbersOfWays(money)<<"\n";
	}
	return 0;
}