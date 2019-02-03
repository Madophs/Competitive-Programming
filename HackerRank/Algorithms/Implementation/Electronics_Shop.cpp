#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int budget,keyboards, usb;
	cin>>budget>>keyboards>>usb;
	int priceKey[keyboards], priceUsb[usb];
	for(int x=0; x<keyboards; x++)cin>>priceKey[x];
	for(int x=0; x<usb; x++)cin>>priceUsb[x];
	int ans=-1;

	for(int x=0; x<keyboards; x++){
		if(priceKey[x]>=budget)continue;
		for(int y=0; y<usb; y++){
			if(priceKey[x]+priceUsb[y]<=budget && priceKey[x]+priceUsb[y]>ans){
				ans = priceKey[x]+priceUsb[y];
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}