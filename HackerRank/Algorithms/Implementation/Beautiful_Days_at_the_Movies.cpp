#include <bits/stdc++.h>

using namespace std;

int reverseNumber(int num){
	string aux = to_string(num);
	for(int x=0; x < aux.length()/2; x++)swap(aux[x],aux[aux.length()-x-1]);
	return atoi(aux.c_str());
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i,j,k,ans=0;
	cin>>i>>j>>k;
	for(int x=i; x<=j; x++)
		if((x-reverseNumber(x))%k==0)++ans;
	cout<<ans<<endl;
	return 0;
}