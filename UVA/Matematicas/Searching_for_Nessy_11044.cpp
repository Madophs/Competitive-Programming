#include <bits/stdc++.h>

using namespace std;

int main() {
	int t,filas,columnas;
	cin>>t;
	while(t--){
		cin>>filas>>columnas;
		int res=(filas/3)*(columnas/3);
		cout<<res<<"\n";
	}
    return 0;
}
