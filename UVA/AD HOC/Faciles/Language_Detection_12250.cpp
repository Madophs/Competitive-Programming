#include <bits/stdc++.h>

using namespace std;

int main() {
	string saludo;
	int c=0;
	while(cin>>saludo){
		if(saludo=="#")break;
		if(saludo=="HOLA"){
			cout<<"Case "<<++c<<": SPANISH\n";
		}else if(saludo=="HELLO"){
			cout<<"Case "<<++c<<": ENGLISH\n";
		}else if(saludo=="HALLO"){
			cout<<"Case "<<++c<<": GERMAN\n";
		}else if(saludo=="BONJOUR"){
			cout<<"Case "<<++c<<": FRENCH\n";
		}else if(saludo=="CIAO"){
			cout<<"Case "<<++c<<": ITALIAN\n";
		}else if (saludo=="ZDRAVSTVUJTE"){
			cout<<"Case "<<++c<<": RUSSIAN\n";
		}else{
			cout<<"Case "<<++c<<": UNKNOWN\n";
		}
	}
    return 0;
}
