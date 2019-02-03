#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,size;
	cin>>n;
	size = n;
	int arr[n];
	while(n-- && cin>>arr[n]);
	sort(arr,arr+size);
	if(size==1){
		cout<<arr[0]<<endl;
	}else{
		int unique=-1;
		for(int x=0, y=1; y<size; x+=2,y+=2){
			int temp = arr[x] ^ arr[y];
			if(temp!=0){
				unique = arr[x];
				break;
			}
		}
		if(unique==-1)unique = arr[size-1];
		cout<<unique<<endl;
	}
	return 0;
}