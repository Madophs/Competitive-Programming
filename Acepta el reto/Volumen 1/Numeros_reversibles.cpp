#include <bits/stdc++.h>

using namespace std;

int invertir(int num){
	string numeroInvertido = to_string(num);
	for(int i = 0; i<numeroInvertido.length()/2; i++){
		swap(numeroInvertido[i], numeroInvertido[numeroInvertido.length()-1-i]);
	}
	return (int)atoi(numeroInvertido.c_str());
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int numero;
	while(cin>>numero && numero){
		if(numero % 10 == 0){
			cout<<"NO\n";
		}else{
			numero += invertir(numero);
			bool reversible = true;
			while(numero && reversible){
				if(!((numero % 10) & 1)) reversible = false;
				numero /= 10;
			}
			cout<<(reversible ? "SI\n": "NO\n");
		}
	}
	return 0;
}
