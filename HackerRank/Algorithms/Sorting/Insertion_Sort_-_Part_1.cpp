#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,aux,pos;
	cin>>n;
	int arr[n];
	for(int x=0; x<n; x++)cin>>arr[x];
	aux = arr[n-1];
	pos = n-2;
	while(1){
		if(pos>=0 && arr[pos]>aux){
			arr[pos+1] = arr[pos];
			--pos;
			for(int x=0; x<n; x++){
				if(x!=0)cout<<" ";
				cout<<arr[x];
			}
			cout<<endl;
		}else{
			arr[pos+1] = aux;
			for(int x=0; x<n; x++){
				if(x!=0)cout<<" ";
				cout<<arr[x];
			}
			cout<<endl;
			break;
		}
	}
	return 0;
}