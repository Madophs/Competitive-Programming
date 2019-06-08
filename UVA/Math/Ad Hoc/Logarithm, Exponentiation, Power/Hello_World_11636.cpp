#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int number;
	for(int t = 1; cin>>number && number >= 0; t++){
		cout<<"Case "<<t<<": "<<ceil(log2(number))<<"\n";
	}
	return 0;
}
