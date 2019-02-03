#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int arr[5];
	for(int x=0; x<5; x++)cin>>arr[x];
	long long min = 0, max = 0;
	sort(arr,arr+(sizeof(arr)/sizeof(int)));
	for(int x=0; x<5; x++){
		if(x+1<5)min+=(long long)arr[x];
		if(x>0)max+=(long long)arr[x];
	}
	cout<<min<<" "<<max<<endl;
	return 0;
}