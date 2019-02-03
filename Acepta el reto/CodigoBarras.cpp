#include<iostream>
#include<cstdlib>
using namespace std;
int main(){
	string cadena="";
	cin>>cadena;
	while(cadena!="0"){
		if(cadena.length()<8){
			while(cadena.length()<8){
				cadena="0"+cadena;
			}
		}else if(cadena.length()<13 && cadena.length()>8){
			while(cadena.length()<13){
				cadena="0"+cadena;
			}
		}
		int suma=0;
		for(int x=cadena.length()-2;x>=0; x--){
			if((cadena.length()-x+1)%2!=0){
				suma+=((int)(cadena[x])-'0')*3;
			}else{
				suma+=(int)(cadena.at(x)-'0');
			}
		}
		int fal=(suma%10==0)?0:10-(suma%10);
		if(cadena.length()==8){
			if(fal==((int)(cadena.at(cadena.length()-1)-'0'))){
				cout<<"SI"<<endl;
			}else{
				cout<<"NO"<<endl;
			}
		}else{
			if(fal==((int)(cadena.at(cadena.length()-1)-'0'))){
				cout<<"SI ";
				string s=cadena.substr(0,3);
				if(cadena.substr(0,3)=="380"){
					cout<<"Bulgaria"<<endl;
				}else if(cadena.substr(0,3)=="539"){
					cout<<"Irlanda"<<endl;
				}else if(cadena.substr(0,3)=="560"){
					cout<<"Portugal"<<endl;
				}else if(cadena.substr(0,3)=="759"){
					cout<<"Venezuela"<<endl;
				}else if(cadena.substr(0,3)=="850"){
					cout<<"Cuba"<<endl;
				}else if(cadena.substr(0,3)=="890"){
					cout<<"India"<<endl;
				}else if(cadena.substr(0,2)=="70"){
					cout<<"Noruega"<<endl;
				}else if(cadena.substr(0,1)=="0"){
					cout<<"EEUU"<<endl;
				}else if(cadena.substr(0,2)=="50"){
					cout<<"Inglaterra"<<endl;
				}else{
					cout<<"Desconocido"<<endl;
				}

			}else{
				cout<<"NO"<<endl;
			}
		}
		cin>>cadena;
	}
	return 0;
}
