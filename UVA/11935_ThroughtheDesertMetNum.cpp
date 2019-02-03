#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <vector>
#define error 1e-9
#define ii pair<int,int>
#define ins pair<int,ii>
#define v vector< ins >
using namespace std;

bool funciona(double sol,v &vec){
	double aux=sol;
	int ant=0,actual=0,gotera=0,c=0;
	for(int x=0; x<vec.size();x++){
		actual=vec[x].first;
		double gasto=(double)((double)((double)(actual-ant)*c)/100)+(double)(gotera*(actual-ant));
		sol-=gasto;
		if(sol<0) return false;
		switch(vec[x].second.first){
		case 1:
			++gotera;
			break;
		case 2:
			sol=aux;
			break;
		case 3:
			gotera=0;
			break;
		}
		ant=actual;
		c=vec[x].second.second;
	}
	return sol>=0;
}
int main(){
	std::ios_base::sync_with_stdio(false);
	string cadena="";
	while(getline(cin,cadena)){
		if(cadena=="0 Fuel consumption 0")break;
		v vec;
		int c=0;
		do{
			int km=0,met=0;
			stringstream tk(cadena);
			string recibe;
			tk>>km;
			tk>>recibe;
			if(recibe=="Fuel"){
				tk>>recibe;
				tk>>c;
			}else if(recibe=="Leak"){
				met=1;
			}else if(recibe=="Gas"){
				tk>>recibe;
				met=2;
			}else if(recibe=="Mechanic"){
				met=3;
			}else{
				met=5;
			}
			ii par = make_pair(met,c);
			ins pro = make_pair(km,par);
			vec.push_back(pro);
			if(met==5)break;
		}while(getline(cin,cadena));
		double alto=10000,bajo=0,media=0, res=0;
		for(int x=0; x<50 && abs(alto-bajo)>error; x++){
			media=(alto+bajo)/2.0;
			if(funciona(media,vec)){
				res=media;
				alto=media;
			}else{
				bajo=media;
			}
		}
		cout<<fixed<<setprecision(3)<<res<<"\n";
	}

	return 0;
}
