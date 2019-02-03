#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	int arr[n];
	for(int x=0; x<n && cin>>arr[x]; x++);
	sort(arr,arr+n);
	int i=0,j=0;
	while(j<n){
		int minValue = arr[i];
		cout<<(n-i)<<endl;
		for(; i<n; i++){
			arr[i]-=minValue;
			if(arr[i]<=0) ++j;
		}
		i=j;
	}
	return 0;
}