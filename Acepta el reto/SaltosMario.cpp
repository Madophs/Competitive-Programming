#include <iostream>
using namespace std;
int main(){
	int casos=0,obs=0,muro=0;
	cin>>casos;
	while(casos--){
		cin>>obs;
		int arriba=0,abajo=0,var=0,ant=0;
		for(int x=0; x<obs; x++){
			cin>>var;
			if(x>0 && ant>var)++abajo;
			if(x>0 && ant<var)++arriba;
			ant=var;
		}
		cout<<arriba<<" "<<abajo<<endl;
	}
	return 0;
}
