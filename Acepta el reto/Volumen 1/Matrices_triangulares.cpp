#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int filas, valor;
	while(cin>>filas && filas){
		int abajo = 0, arriba = 0;
		for(int fila = 0; fila < filas; fila++){
			for(int col = 0; col < filas; col++){
				cin>>valor;
				if(fila == col) continue;
				if(col > fila) arriba += valor;
				if(col < fila) abajo += valor;
			}
		}
		if(arriba == 0 || abajo == 0){
			cout<<"SI\n";
		}else{
			cout<<"NO\n";
		}
	}
	return 0;
}
