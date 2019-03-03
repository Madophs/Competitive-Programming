#include <bits/stdc++.h>

using namespace std;

int main(){
	string cadena;
	int c,saldo=0;
	cin>>c;
	cin.ignore();
	while(c--){
		getline(cin,cadena);
		string accion;
		stringstream ss(cadena);
		ss>>accion;
		if(accion=="donate"){
			int deposito;
			ss>>deposito;
			saldo+=deposito;
		}else{
			cout<<saldo<<"\n";
		}
	}
	return 0;
}