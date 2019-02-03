#include <bits/stdc++.h>
using namespace std;

int k = 1e9+7;

long mdsPow(int x, int n) {
    long long res = 1;
	while(n>0){
		if(n&1){
			res = (res*x)%k;
		}
		x = (x*x)%k;
		n = n>>1;
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t,days;
	long ans=0,c;
	long arr[10001];
	memset(arr,0,sizeof(arr));
	cin>>t;
	while(t-- && cin>>c>>days){
		if(arr[days]==0){
			arr[days] = mdsPow(days,3); 
		}
		ans = (c*arr[days])%(k);
		cout<<ans<<"\n";
	}
	return 0;
}