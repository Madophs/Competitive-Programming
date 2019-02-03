#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin.tie();
	cin>>n;
	int arrA[n],arrB[n];
	for(int x=0; x<n; x++)cin>>arrA[x];
	for(int x=0; x<n; x++){
		cin>>arrB[x];
		if(x!=0)cout<<" ";
		cout<<arrA[x]+arrB[x];
	}
	cout<<"\n";
	return 0;
} 