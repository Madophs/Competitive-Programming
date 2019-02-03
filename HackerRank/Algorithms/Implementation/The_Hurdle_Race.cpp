#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,k,h,hmax=-1;
	cin>>n>>k;
	while(n-- && cin>>h)hmax = max(h,hmax);
	cout<<(k-hmax<0?hmax-k:0)<<endl;
	return 0;
}