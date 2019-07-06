#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int n, m;
    cin>>n>>m;
    n+=(n&1),m+=(m&1);
    int ans = (n*m)/4;
    cout<<ans<<"\n";
	return 0;
}
