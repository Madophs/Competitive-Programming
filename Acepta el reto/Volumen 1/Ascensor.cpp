#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int longitud, piso, destino, pisoActual;
	while(cin>>pisoActual && pisoActual > -1){
		longitud = 0;
		while(cin>>piso && piso > -1 && cin>>destino){
			longitud += abs(pisoActual - piso) + abs(piso - destino);
			pisoActual = destino;
		}
		cout<<longitud<<"\n";
	}
	return 0;
}
