#include <bits/stdc++.h>
using namespace std;

int main() {
	int c;
	cin>>c;
	string cadena;
	while(c--){
		cin>>cadena;
		if(cadena.length()==5){
			cout<<3<<"\n";
			continue;
		}
		if((cadena.at(0)=='t' && cadena.at(2)=='o') || (cadena.at(0)=='t' && cadena.at(1)=='w') || (cadena.at(1)=='w' && cadena.at(2)=='o') ){
			cout<<"2\n";
			continue;
		}
		cout<<"1\n";
	}
    return 0;
}