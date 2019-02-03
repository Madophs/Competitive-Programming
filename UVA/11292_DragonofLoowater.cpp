#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	std::ios_base::sync_with_stdio(false);
	int dragons,knights;
	while(cin>>dragons>>knights && (dragons || knights)){
		int cabezas[dragons];
		int espadas[knights];
		int monedas=0;
		for(int x=0; x<dragons; x++)cin>>cabezas[x];
		for(int x=0; x<knights; x++)cin>>espadas[x];
		sort(cabezas, cabezas+dragons);
		sort(espadas, espadas+knights);
		int x=0,y=0;
		while(1){
			if(x<dragons){
				if(cabezas[x]<=espadas[y]){
					monedas+=espadas[y];
					++x;
					++y;
				}else{
					++y;
				}
			}
			if(x==dragons)break;
			if(y==knights)break;
		}
		if(x==dragons){
			cout<<monedas<<"\n";
		}else{
			cout<<"Loowater is doomed!\n";
		}
	}
	return 0;
}
