#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int size,rotations,q,val;
	cin>>size>>rotations>>q;
	int rotatedArray[size];
	for(int x=0; x<size; x++){
		cin>>val;
		rotatedArray[(x+rotations)%size] = val;
	}
	while(q--){
		cin>>val;
		cout<<rotatedArray[val]<<endl;
	}
	return 0;
}