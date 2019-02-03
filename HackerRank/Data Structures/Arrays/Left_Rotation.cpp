#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int size, rotations;
	cin>>size>>rotations;
	int numbers[size];
	for(int x=0; x<size; x++){
		cin>>numbers[x-rotations<0?size-rotations+x: x-rotations];
	}
	for(int x=0; x<size; x++){
		if(x!=0)cout<<" ";
		cout<<numbers[x];
	}
	cout<<endl;
	return 0;
}