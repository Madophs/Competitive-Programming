#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
ull power(int var, int exp){

	if(exp==0)return 1;
	//Algoritmo para elevar un numero a la potencia n modulo
	if(exp%2==0){
		ull res = power(var,exp/2);
		return ((res%131071)*(res%131071))%131071;
		//return res*res;
	}else{
		ull res = power(var,(exp-1)/2);
		return ((((res%131071)*(res%131071))%131071)*(var%131071))%131071;
		//return res*res*var;
	}
}
bool isDivisible(string cadena){
	ull res=0;
	for(int x=0; x<cadena.size()-1; x++){
		int pos = cadena.size()-2-x;//Calculacmos la potencia
		if(cadena.at(cadena.size()-2-pos)=='1'){//Calcular la posicion en la cadena
			res+=power(2,pos);
		}
	}
	return res%131071==0;
}

int main(){
	string input,cadena="";
	while(cin>>input){
		cadena+=input;
		if(input.at(input.size()-1)=='#'){
			cout<<(isDivisible(cadena)?"YES\n":"NO\n");
			cadena="";
		}
	}
	return 0;
}