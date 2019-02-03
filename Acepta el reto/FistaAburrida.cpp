#include <iostream>
#include <cstring>
using namespace std;
int main(){
	string cadena="";
	int casos=0;
	cin>>casos;
	cin.ignore();
	while(casos--){
		getline(cin,cadena);
		string nombre =cadena.substr(4,string::npos)+".";
		cout<<"Hola, "<<nombre<<endl;
	}
	return 0;
}
