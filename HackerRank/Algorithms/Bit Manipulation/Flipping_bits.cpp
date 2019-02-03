#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q;
	unsigned int n;
	cin>>q;
	while(q-- && cin>>n){
		cout<<(n ^ (1<<32)-1)<<endl;
	}	
	return 0;
}