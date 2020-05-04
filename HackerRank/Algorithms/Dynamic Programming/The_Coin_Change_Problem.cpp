#include <bits/stdc++.h>

using namespace std;

long memo[255][55];
vector<int> coinTypes;

long numberOfWays(int unit, int index) {
	if(unit < 0 || index == (int)coinTypes.size())
		return 0;
	if(memo[unit][index] != -1)
		return memo[unit][index];
	if(!unit) return memo[unit][index] = 1; 
	return memo[unit][index] = numberOfWays(unit-coinTypes[index], index) + numberOfWays(unit, index+1);
	
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(memo, -1, sizeof(memo));
	int n, m;
	cin >> n >> m;
	coinTypes.resize(m);
	for(int &val : coinTypes) cin >> val;
	cout << numberOfWays(n, 0) << "\n";
	return 0;
}
