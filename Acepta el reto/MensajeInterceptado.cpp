#include <iostream>
#include <algorithm>
#include <cstring>
#include <cctype>
using namespace std;
string primerDerivada(string);
string cifrado(string);
int main(){
	string cadena="";
	getline(cin,cadena);
	while(cadena.length()>0){
		cout<<cadena<<" => "<<cifrado(primerDerivada(cadena))<<endl;
		getline(cin,cadena);
	}
	return 0;
}
string cifrado(string codice){
	string aux="",sub="";
	for(int x =0; x<codice.length(); x++){
		if(std::tolower(codice[x])!='a' && std::tolower(codice[x])!='e' && std::tolower(codice[x])!='i' && std::tolower(codice[x])!='o' && std::tolower(codice[x])!='u'){
			sub=codice.substr(x,1)+sub;
		}else{
			if(sub.empty() || sub.length()==1){
				aux+=sub;
				aux+=codice.substr(x,1);
				sub="";
			}else{

				aux+=sub;
				sub="";
				aux+=codice.substr(x,1);
			}
		}
	}
	aux+=sub;
	return aux;
}
string primerDerivada(string codice){
	string aux="",aux2="";
	for(int x=0; x<(codice.length()); x+=2){
		aux+=codice.substr(x,1);
		if(codice.length()%2==0){
			aux2+=codice.substr((codice.length()-1)-x,1);
		}else{
			if(codice.length()-1-x>0){
				aux2+=codice.substr((codice.length()-2)-x,1);
			}
		}
	}
	aux+=aux2;
	return aux;
}
