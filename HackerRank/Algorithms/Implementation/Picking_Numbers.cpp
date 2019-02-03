#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int numbers[102];
	int n,val;
	cin>>n;
	memset(numbers,0,sizeof(numbers));
	for(int x=0; x<n; x++){
		cin>>val;
		++numbers[val];
	}
	int i=0, ans=0;
	for(int x=0; x<n; x++){
		if(numbers[x]==0)continue;
		ans = max(ans,numbers[x]+numbers[x+1]);
	}
	cout<<ans<<endl;
	return 0;
}