#include <bits/stdc++.h>

using namespace std;

int main(){
	string cadena;
	int c=0;
	while(cin>>cadena){
		if(cadena.at(0)=='*')break;
		if(cadena=="Hajj"){
			cout<<"Case "<<++c<<": Hajj-e-Akbar\n";
		}else{
			cout<<"Case "<<++c<<": Hajj-e-Asghar\n";
		}
	}
	return 0;
}
