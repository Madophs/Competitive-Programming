#include <bits/stdc++.h>

using namespace std;

int main(){
	string cadena;
	bool op =true;
	while(getline(cin,cadena) && !cadena.empty()){
		string aux="";
		for(auto iter = cadena.begin(); iter!=cadena.end(); iter++){
			if(*iter=='\"'){
				aux+=(op)?"``":"''";
				op=!op;
			}else{
				aux+=*iter;
			}
		}
		cout<<aux<<endl;
	}
	return 0;
}