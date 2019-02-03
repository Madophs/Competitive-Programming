#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;
int main(){
	string cadena="";
	getline(cin,cadena);
	while(cadena!="XXX"){
		string aux="";
		char *p=std::strtok((char*)cadena.c_str()," ");
		while(p!=NULL){
			aux+=p;
			p=std::strtok(NULL," ");
		}
		string::reverse_iterator iter=aux.rbegin();
		bool cierto =true;
		for(int x=0; x<aux.length(); x++){
			if(std::tolower(aux[x])!=std::tolower(*iter)){
				cierto=false;
				break;
			}
			++iter;
		}
		cout<<((cierto)?"SI":"NO")<<endl;
		getline(cin,cadena);
	}
	return 0;
}
