#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int,ii> iii;
typedef unsigned int ui;
typedef vector<string> vs;

int main(){
	int caso=0;
	string cadena;
	while(cin>>cadena && cadena[0]!='*'){
		if(cadena=="Hajj"){
			cout<<"Case "<<++caso<<": "<<"Hajj-e-Akbar\n";
		}else{
			cout<<"Case "<<++caso<<": "<<"Hajj-e-Asghar\n";
		}
	}
	return 0;
}
