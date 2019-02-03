#include <bits/stdc++.h>

using namespace std;

int mdsBinarySearch(int arr[], int size, int search){
	int lower = 0, upper = size-1, middle = 0;
	while(lower<=upper){
		middle = (lower+upper)/2;
		if(arr[middle]<search){
			lower = middle+1;
		}else if(arr[middle]>search){
			upper = middle-1;
		}else{
			return middle+1;
		}
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int size,q,val,search;
	cin>>size;
	int arr[size];
	for(int x=0; x<size && cin>>arr[x]; x++);
	sort(arr,arr+size);
	cin>>q;
	while(q-- && cin>>search){
		cout<<mdsBinarySearch(arr,size,search)<<'\n';
	}
	return 0;
}