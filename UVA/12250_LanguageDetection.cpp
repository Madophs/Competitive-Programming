#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int,ii> iii;
typedef unsigned int ui;
typedef vector<string> vs;

int main(){
	int caso=0;
	string cadena;
	while(cin>>cadena && cadena[0]!='#'){
		if(cadena=="HELLO"){
			cout<<"Case "<<++caso<<": ENGLISH\n";
		}else if(cadena=="HOLA"){
			cout<<"Case "<<++caso<<": SPANISH\n";
		}else if(cadena=="HALLO"){
			cout<<"Case "<<++caso<<": GERMAN\n";
		}else if(cadena=="BONJOUR"){
			cout<<"Case "<<++caso<<": FRENCH\n";
		}else if(cadena=="CIAO"){
			cout<<"Case "<<++caso<<": ITALIAN\n";
		}else if(cadena=="ZDRAVSTVUJTE"){
			cout<<"Case "<<++caso<<": RUSSIAN\n";
		}else{
			cout<<"Case "<<++caso<<": UNKNOWN\n";
		}
	}
	return 0;
}
