#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,val;
	cin>>n;
	int arr[100];
	memset(arr,0,sizeof(arr));
	while(n-- && cin>>val)++arr[val];
	for(int x=0; x<100; x++){
		while(arr[x]--){
			cout<<x<<" ";
		}
	}
	return 0;
}