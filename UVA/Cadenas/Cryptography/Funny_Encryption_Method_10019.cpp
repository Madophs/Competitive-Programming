#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int t,number,hexa;cin>>t;
	while(t--){
		cin>>number;
		stringstream tk(to_string(number));
		tk>>hex>>hexa;
		bitset<64> b1(number), b2(hexa);
		cout<<b1.count()<<" "<<b2.count()<<"\n";
	}
	return 0;
}
