#include <bits/stdc++.h>

using namespace std;

string sumaUno(string &numero){
	int i = numero.length() - 1, carry = 0;
	++numero.back();
	for(; i >= 0; --i){
		if(numero[i] <= '9' && numero[i] >= '0') break;
		if(numero[i] <= 'F' && numero[i] >= 'A') break;
		if(numero[i] == '9'+1){
			numero[i] = 'A';
			break;
		}
		if(numero[i] == 'F'+1){
			numero[i] = '0';
			if(i-1 > -1) ++numero[i-1];
			else carry = 1;
		}
	}
	if(carry) numero = "1" + numero;
	return numero;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string numero;
	while(cin>>numero && numero != "FIN"){
		cout<<sumaUno(numero)<<"\n";
	}	
	return 0;
}
