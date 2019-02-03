#include <bits/stdc++.h>

using namespace std;

/*
 * Algoritmo para incluir tantos eventos como se pueda, dado su
 * hora de inicio y su hora final
 */

bool ordenamiento(pair<int,int> p1, pair<int,int> p2){
	return p1.second<p2.second;//Ordenamos de menor a mayor la hora en la cual se terminan los eventos
}
int main() {
	int eventos,inicio,final,cont=0;
	cout<<"Schedule algorithm"<<endl;
	cout<<"Numero de eventos"<<endl;
	while(cin>>eventos && eventos){
		cont=0;
		vector< pair<int,int> > agenda;
		vector< pair<int,int> > soluciones;
		cout<<"Eventos en formato (Hora_inicio, Hora_final)"<<endl;
		while(eventos--){
			cin>>inicio>>final;
			agenda.push_back(make_pair(inicio,final));
		}
		sort(agenda.begin(),agenda.end(), ordenamiento);//Ordenamos los eventos por hora final
		int j=-1,c=0;
		for(unsigned int x =0; x<agenda.size(); x++){
			if(j<=agenda[x].first){//Verificamos que el siguiente evento inicio despues del actual
				++c;
				j=agenda[x].second;
				soluciones.push_back(agenda[x]);//Guardamos las soluciones optimas
			}
		}
		cout<<"Numero de eventos al que podras asistir"<<endl;
		cout<<c<<endl;
		cout<<"Eventos a los que podras asistir"<<endl;
		for(auto iter = soluciones.begin(); iter!=soluciones.end(); iter++){
			auto ref = *iter;
			cout<<"Evento "<<++cont<<": "<<ref.first<<" "<<ref.second<<endl;
		}
	}

	return 0;
}
/*
 Casos de prueba:
4
1 3
2 5
3 9
6 8
4
1 4
2 7
4 10
8 9
3
1 6
5 8
7 9
3
1 9
2 4
4 6
 */