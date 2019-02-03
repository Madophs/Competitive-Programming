#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int,ii> iii;
typedef unsigned int ui;
typedef vector<string> vs;

int palabra(string &cadena){
	if(cadena.length()==5) return 3;
	if((cadena[1]=='w' && cadena[0]=='t') || (cadena[2]=='o' && cadena[1]=='w') || (cadena[0]=='t' && cadena[2]=='o'))return 2;
	return 1;
}
int main(){
	int tc;
	string cadena;
	cin>>tc;
	while(tc--){
		cin>>cadena;
		cout<<palabra(cadena)<<"\n";
	}
	return 0;
}
