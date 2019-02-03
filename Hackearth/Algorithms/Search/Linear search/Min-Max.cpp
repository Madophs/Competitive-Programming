#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	long long value, minValue=1e13,maxValue =-1e9;
	unsigned long long ans=0;
	cin>>n;
	for(int x=0; x<n; x++){
		cin>>value;
		ans+=value;
		minValue = min(value,minValue);
		maxValue = max(maxValue,value);
	}
	cout<<ans-maxValue<<" "<<ans-minValue<<"\n";
	return 0;
}