#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int casos, bloques, altura, ant, saltosArriba, saltosAbajo;
	cin>>casos;
	while(casos-- && cin>>bloques){
		saltosArriba = saltosAbajo = 0;
		--bloques;
		cin>>ant;
		while(bloques-- && cin>>altura){
			saltosArriba += (altura > ant);
			saltosAbajo += (altura < ant);
			ant = altura;
		}
		cout<<saltosArriba<<" "<<saltosAbajo<<"\n";
	}	
	return 0;
}
