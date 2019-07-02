#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int piezas, pieza, falta, suma;
	while(cin>>piezas && piezas){
		falta = (piezas * (piezas+1)) / 2;
		suma = 0;
		--piezas;
		while(piezas-- && cin>>pieza) suma += pieza;
		falta -= suma;
		cout<<falta<<"\n";
	}
	return 0;
}
