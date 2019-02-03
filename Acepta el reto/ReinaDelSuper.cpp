#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
using namespace std;
int main(){
	int n=0,c=0,tn=0;
	string cadena="";
	getline(cin,cadena);
	while(cadena.length()>0){
		n=atoi(cadena.substr(0,cadena.find(' ')).c_str());
		c=atoi(cadena.substr(cadena.find(' ')+1,string::npos).c_str());
		queue<int> cola;
		while(c--){
			cin>>tn;
			cola.push(tn);
		}
		int cajas[n];
		std::fill(cajas,cajas+n,0);
		for(int x=0; x<n && !cola.empty(); x++){
			cajas[x]+=cola.front();
			cola.pop();
		}
		int minimo=0;
		while(!cola.empty()){
			minimo=*std::min_element(cajas,cajas+n);
			for(int x=0; x<n; x++){
				if(minimo==cajas[x]){
					cajas[x]+=cola.front();
					cola.pop();
					break;
				}
			}
		}
		int ant=cajas[0];
		int pos=0;
		for(int y=0; y<n;y++){
			if(cajas[y]<ant){
				ant=(cajas[y]);
				pos=y;
			}
		}
		cin.ignore();
		cout<<(pos+1)<<endl;
		getline(cin,cadena);
	}
	return 0;
}
