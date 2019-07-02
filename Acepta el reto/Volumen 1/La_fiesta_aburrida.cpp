#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int casos;
	string soy, nombre;
	cin>>casos;
	while(casos-- && cin>>soy>>nombre){
		cout<<"Hola, "<<nombre<<".\n";
	}
	return 0;
}
