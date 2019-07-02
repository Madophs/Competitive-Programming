#include <bits/stdc++.h>

using namespace std;

char letras[] = {'s', 'p', 'd', 'f'};
int capacidad[] = {2, 6, 10, 14};
int num[] = {0,0,0,0};

void resetear(){
	for(int i = 0, val = 1; i < 4; ++i, ++val) num[i] = val;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string elemento;
	int valor, limite;
	bool espacio;
	while(cin>>elemento && elemento != "Exit" && cin>>valor){
		limite = 0;
		espacio = false;
		resetear();
		if(valor == 0){
			cout<<"1s0\n";
		}else{
			while(valor){
				for(int i = limite; i >= 0 && valor; --i){
					if(espacio) cout<<" ";
					if(valor >= capacidad[i]){
						cout<<num[i]++<<letras[i]<<capacidad[i];
						valor -= capacidad[i];
					}else{
						cout<<num[i]++<<letras[i]<<valor;
						valor = 0;
					}
					espacio = true;
				}
				if(num[0] & 1 && num[0] > 1) ++limite;
			}
			cout<<"\n";
		}
	}
	return 0;
}
