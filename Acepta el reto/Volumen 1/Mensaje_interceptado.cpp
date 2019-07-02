#include <bits/stdc++.h>

using namespace std;

bool esVocal(char c){
	c = tolower(c);
	if(c == 'a') return true;
	if(c == 'e') return true;
	if(c == 'i') return true;
	if(c == 'o') return true;
	if(c == 'u') return true;
	return false;
}

string decodificarSegundaFase(string mensaje){
	int l = 0, r = mensaje.length()-1, i = 0;
	string decodificado(mensaje.length(), ' ');
	for(; i < mensaje.length(); i++){
		if(i & 1){
			decodificado[r--] = mensaje[i];
		}else{
			decodificado[l++] = mensaje[i];
		}
	}
	return decodificado;
}

string decodificarPrimerFase(string mensaje){
	for(int i = 0; i<mensaje.length();){
		if(!esVocal(mensaje[i])){
			int j = i;
			while(j < mensaje.length() && !esVocal(mensaje[j])) ++j;
			int limite = (i+j)/2;
			for(int pasos = 0; pasos + i < limite; pasos++){
				swap(mensaje[i+pasos], mensaje[j-1-pasos]);
			}
			i = j;
		}else{
			++i;
		}
	}
	return mensaje;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string linea;
	while(getline(cin,linea)){
		cout<<linea<<" => "<<decodificarPrimerFase(decodificarSegundaFase(linea))<<"\n";
	}
	return 0;
}
