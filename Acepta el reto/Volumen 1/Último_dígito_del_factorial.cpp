#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int numero, casos;
	cin>>casos;
	while(casos-- && cin>>numero){
		if(numero > 4){
			cout<<0<<"\n";
		}else if(numero == 0 || numero == 1){
			cout<<1<<"\n";
		}else if(numero == 2){
			cout<<2<<"\n";
		}else if(numero == 3){
			cout<<6<<"\n";
		}else{
			cout<<4<<"\n";
		}
	}
	return 0;
}
