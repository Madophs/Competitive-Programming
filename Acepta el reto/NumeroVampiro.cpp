#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdlib>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int tc;
	cin>>tc;
	while(tc--){
		string cadena;
		cin>>cadena;
		if(cadena.length()%2!=0){
			cout<<"NO\n";
			continue;
		}
		int num =atoi(cadena.c_str());
		bool si=false;
		do{
			string der=cadena.substr(0,cadena.length()/2),izq=cadena.substr(cadena.length()/2,string::npos);
			if(atoi(der.c_str())*atoi(izq.c_str())==num && (der[der.length()-1]!='0' || izq[izq.length()-1]!='0')){
				int num2=atoi(der.c_str()),num1=atoi(izq.c_str());
				std::stringstream tk,tk2;
				string cad="",cad2="";
				tk<<num1;
				cad=tk.str();
				tk2<<num2;
				cad2=tk2.str();
				if(cad.length()!=cad2.length())continue;
				si=true;
				break;
			}
		}while(std::next_permutation(cadena.begin(),cadena.end()));
		cout<<(si?"SI\n":"NO\n");
	}
	return 0;
}
