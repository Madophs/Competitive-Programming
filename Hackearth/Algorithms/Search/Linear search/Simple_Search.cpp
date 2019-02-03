#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int size,number, val;
	cin>>size;
	int arr[size];
	for(int x=0; x<size && cin>>arr[x]; x++);
	cin>>val;
	int pos = 0;
	for(; arr[pos]!=val; pos++);
	cout<<pos<<endl;
	return 0;
}