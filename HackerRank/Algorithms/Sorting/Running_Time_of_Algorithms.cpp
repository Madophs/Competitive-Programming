#include <bits/stdc++.h>

using namespace std;

int insertionsCount(int arr[], int n){
	int insertions = 0;
	for(int x=1; x<n; x++){
		int aux = x-1, value = arr[x];
		while(aux>=0 && arr[aux]>value){
			arr[aux+1] = arr[aux];
			arr[aux] = value;
			++insertions;
			aux--;
		}
	}
	return insertions;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int arr[n];
	for(int x=0; x<n && cin>>arr[x]; x++);
	cout<<insertionsCount(arr,n)<<endl;
	return 0;
}