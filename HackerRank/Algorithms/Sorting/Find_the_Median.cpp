#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int arr[n];
	while(n-- && cin>>arr[n]);
	sort(arr,arr+sizeof(arr)/sizeof(int));
	cout<<arr[(sizeof(arr)/sizeof(int))/2]<<endl;
	return 0;
}