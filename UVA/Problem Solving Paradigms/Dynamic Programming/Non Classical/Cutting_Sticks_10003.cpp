#include <bits/stdc++.h>

using namespace std;

const int MAX_CUTS = 55;
int length, num_cuts, value;
int cuts[MAX_CUTS];
int memo[MAX_CUTS][MAX_CUTS];
int minimumCut(int left,int right){
	if(left + 1 == right) return 0;
	if(memo[left][right] != -1) return memo[left][right];
	int ans = 2e9;
	for(int i = left + 1; i<right; i++){
		ans = min(ans, minimumCut(left, i) + minimumCut(i,right) + (cuts[right] - cuts[left]));
	}
	return memo[left][right] = ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cuts[0] = 0;
	while(cin>>length && length){
		cin>>num_cuts;
		for(int i = 1; i<=num_cuts && cin>>cuts[i]; i++);
		cuts[++num_cuts] = length;
		memset(memo, -1, sizeof memo);
		cout<<"The minimum cutting is "<<minimumCut(0,num_cuts)<<".\n";
	}
	return 0;
}