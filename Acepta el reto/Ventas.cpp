#include <bits/stdc++.h>
#define EPSILON 1e-9
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string dias[] = {"MARTES","MIERCOLES","JUEVES", "VIERNES", "SABADO","DOMINGO"};
	double ventas, media,mayor, menor;
	string diaMenor, diaMayor;
	while(cin>>ventas && ventas!=-1){
		media=ventas;
		menor = mayor = ventas;
		diaMayor = diaMenor = "MARTES";
		for(int i = 1; i<6; i++){
			cin>>ventas;
			media+=ventas;
			if(fabs(mayor-ventas) < EPSILON){
				diaMayor = "EMPATE";
			}else if(mayor < ventas){
				mayor = ventas;
				diaMayor = dias[i];
			}
			if(fabs(menor-ventas) < EPSILON){
				diaMenor = "EMPATE";
			}else if(menor > ventas){
				menor = ventas;
				diaMenor = dias[i];
			}
		}
		media/=6.0;
		cout<<diaMayor<<" "<<diaMenor<<(ventas>media?" SI\n":" NO\n");
	}
	return 0;
}