#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tests, n, k,p;
	cin>>tests;
	for(int t = 1; t<=tests; t++){
		cin>>n>>k>>p;
		int ans = ((k+p)%n)?((k+p)%n):n;
		cout<<"Case "<<t<<": "<<ans<<"\n";
	}
	return 0;
}