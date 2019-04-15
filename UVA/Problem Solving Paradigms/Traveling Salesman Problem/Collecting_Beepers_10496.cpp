#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 11;
int numBeepers, matrix[MAX_N][MAX_N], memo[MAX_N][1<<MAX_N];

int TravelingSalesmanProblem(int pos, int bitmask){
	if(bitmask == (1<<(numBeepers+1))-1) return matrix[pos][0];
	if(memo[pos][bitmask] != -1) return memo[pos][bitmask];
	int ans = (int) 2e9;
	for(int v = 0; v<=numBeepers; v++){
		if(v != pos && !(bitmask & (1<<v))){
			ans = min(ans, matrix[pos][v] + TravelingSalesmanProblem(v, bitmask | (1<<v) ));
		}
	}
	return memo[pos][bitmask] = ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tests, width, height;
	int x[MAX_N], y[MAX_N];
	cin>>tests;
	while(tests--){
		cin>>width>>height;
		cin>>x[0]>>y[0];
		cin>>numBeepers;
		for(int i = 1; i<=numBeepers; i++) cin>>x[i]>>y[i];
		for(int i = 0; i<=numBeepers; i++){
			for(int j = 0; j<=numBeepers; j++){
				matrix[i][j] = abs(x[i]-x[j]) + abs(y[i] - y[j]);
			}
		}
		memset(memo, -1, sizeof memo);
		cout<<"The shortest path has length "<<TravelingSalesmanProblem(0,1)<<"\n";
	}
	return 0;
}