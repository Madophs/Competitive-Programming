#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
	return b==0?a : gcd(b,a%b);
}

int lcm(int a, int b){
	return a*(b/gcd(a,b));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n1,n2, factor=0,divisor=0;
	cin>>n1>>n2;
	int arr[n1],arr2[n2];
	for(int x=0; x<n1 && cin>>arr[x]; x++){
		if(x==0){
			factor=arr[x];
		}else{
			factor = lcm(factor,arr[x]);
		}
	}
	for(int x=0; x<n2 && cin>>arr2[x]; x++){
		if(x==0){
			divisor= arr2[x];
		}else{
			divisor = gcd(divisor, arr2[x]);
		}
	}
	int ans=0,aux=factor;
	while(factor<=divisor){
		if(divisor%factor==0)++ans;
		factor+=aux;
	}
	cout<<ans<<endl;
	return 0;
}