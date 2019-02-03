#include <bits/stdc++.h>

using namespace std;

void mdsPartition(int *arr, int n,int pivot, int l, int r){
	while(l!=r){
		for(; l<n && l<r && arr[l]<arr[pivot];l++);
		for(; r>pivot && r>l && arr[r]>arr[pivot]; r--);
		swap(arr[l], arr[r]);
	}
	int middle = arr[l]>arr[pivot]? l-1: l;
	swap(arr[pivot], arr[middle]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int x=0; x<n; x++)cin>>arr[x];
	mdsPartition(arr,n,0,1,n-1);
	for(int x=0; x<n; x++)cout<<arr[x]<<" ";
	return 0;
}