#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n,k,pay = 0,charge;
	cin>>n>>k;
	int bill[n];
	for(int x=0; x<n; x++){
		cin>>bill[x];
		if(x!=k)pay+=bill[x];
	}
	pay/=2;
	cin>>charge;
	if(charge>pay){
		cout<<charge-pay<<endl;
	}else{
		cout<<"Bon Appetit"<<endl;
	}
	return 0;
}