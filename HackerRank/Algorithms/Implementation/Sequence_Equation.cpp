#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,var;
	unordered_map<int, int> table;
	cin>>n;
	for(int x=0; x<n && cin>>var; x++)table[var] = x+1;
	for(int x=1; x<=n; x++){
		cout<<table.find(table.find(x)->second)->second<<endl;
	}
	return 0;
}