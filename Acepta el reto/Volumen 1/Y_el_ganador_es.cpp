#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int equipos, globosEntregados, equipo;
	string color;
	int scoreboard[25];
	while(cin>>equipos>>globosEntregados && (equipos || globosEntregados)){
		memset(scoreboard, 0, sizeof scoreboard);
		int maximum = 0, ganador = equipos == 1? 1 : -1;
		while(globosEntregados-- && cin>>equipo>>color){
			++scoreboard[equipo];
			if(scoreboard[equipo] >= maximum){
				if(scoreboard[equipo] > maximum){
					ganador = equipo;
				}else{
					ganador = -1;
				}
				maximum = max(scoreboard[equipo], maximum);
			}
		}
		if(ganador < 0){
			cout<<"EMPATE\n";
		}else{
			cout<<ganador<<"\n";
		}
	}
	return 0;
}