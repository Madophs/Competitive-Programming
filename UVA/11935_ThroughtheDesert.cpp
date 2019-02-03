#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

int main(){
	std::ios_base::sync_with_stdio(false);
	string  cadena;
	while(getline(cin,cadena)){
		if(cadena=="0 Fuel consumption 0") break;
		double tanque=0,aux=0,dist=0;
		int km=0,actual=0,gotera=0,consumo=0,ant=0;
		do{
			std::stringstream tk(cadena);
			tk>>actual;
			string recibe="",desecha="";
			dist=(double)(actual-ant);
			aux+=((double)(consumo*dist)/100)+(dist*gotera);
			tanque =max(aux,tanque);
			tk>>recibe;
			if(recibe=="Fuel"){
				tk>>desecha;
				tk>>consumo;
			}else if(recibe=="Leak"){
				++gotera;
			}else if(recibe=="Gas"){
				tk>>desecha;
				aux=0;
			}else if(recibe=="Mechanic"){
				gotera=0;
			}else{
				tanque=max(tanque,aux);
				break;
			}
			ant=actual;
		}while(getline(cin,cadena));
		cout<<fixed<<setprecision(3)<<tanque<<"\n";
	}
	return 0;
}
