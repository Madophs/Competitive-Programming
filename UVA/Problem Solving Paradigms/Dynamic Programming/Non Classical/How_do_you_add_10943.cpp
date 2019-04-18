#include <bits/stdc++.h>

using namespace std;

const int MODULO = 1e6, MAX_N = 200;

int memo[MAX_N][MAX_N];

int ways(int n, int k){
	if(memo[n][k] != -1) return memo[n][k];
	if(k == 1) return memo[n][k] = 1;
	int sum = 0;
	for(int i = 0; i<=n; i++){
		sum += ways(n-i,k-1);
	}
	return memo[n][k] = sum%MODULO;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int num, k;
	memset(memo, -1, sizeof memo);
	while(cin>>num>>k && (num || k)){
		cout<<ways(num,k)<<"\n";
	}
	return 0;
}