#include <iostream>
using namespace std;
int main(){
	int dias[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int casos=0,dia=0,mes=0;
	cin>>casos;
	while(casos--){
		cin>>dia>>mes;
		int faltan=0;
		for(int x=mes-1; x<12; x++){
			faltan+=dias[x];
		}
		cout<<(faltan-dia)<<endl;
	}
	return 0;
}
