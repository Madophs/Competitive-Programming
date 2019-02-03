#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int size,q,power;
	cin>>size;
	int arr[size],sumArray[size+1];
	sumArray[0]=0;
	for(int x=0; x<size && cin>>arr[x]; x++);
	sort(arr, arr+size);
	for(int x=0; x<size; x++)sumArray[x+1] = sumArray[x]+arr[x];
	cin>>q;
	while(q-- && cin>>power){
		auto it = upper_bound(arr,arr+size,power);
		int pos = it-arr;
		cout<<pos<<" "<<sumArray[pos]<<'\n';
	}
	return 0;
}