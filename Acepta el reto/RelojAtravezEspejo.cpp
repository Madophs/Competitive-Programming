#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
using namespace std;
int main(){
	int casos=0;
	string cadena="";
	cin>>casos;
	while(casos--){
		cin>>cadena;
		string h=cadena.substr(0,2);
		int hora=std::atoi(cadena.substr(0,2).c_str());
		int minuto=std::atoi(cadena.substr(3,string::npos).c_str());
		if((hora==12 && minuto==0) || (hora==6 && minuto==0)){
			cout<<cadena<<endl;
		}else{
			if(minuto!=0 && hora!=12){
				cout<<std::setfill('0')<<setw(2)<<((12-hora)-1==0?12:(12-hora)-1)<<":"<<setw(2)<<(60-minuto)<<endl;
			}else if((hora==12 || hora==6) && minuto!=0){
				cout<<std::setfill('0')<<setw(2)<<((12-1))<<":"<<setw(2)<<(60-minuto)<<endl;
			}else{
				cout<<std::setfill('0')<<setw(2)<<((12-hora))<<":"<<setw(2)<<(minuto)<<endl;
			}
		}
	}
	return 0;
}
