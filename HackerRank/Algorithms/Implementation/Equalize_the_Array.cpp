#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,val,maxValue=0,size;
	int arr[101];
	memset(arr,0,sizeof arr);
	cin>>n;
	size = n;
	while(n-- && cin>>val){
		++arr[val];
		maxValue = max(maxValue,arr[val]);
	}
	cout<<(size-maxValue)<<endl;
	return 0;
}