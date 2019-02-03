#include <iostream>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <set>

using namespace std;
int *examenes;
bool copiasm[100001];
int aux[100001];
int main(){
	int n,k;
	examenes = new int[1000000];
	string cadena;
	while(getline(cin,cadena) && !cadena.empty()){
		stringstream tk(cadena);
		tk>>n;
		tk>>k;
		memset(copiasm,false,sizeof(copiasm));
		memset(aux,0,sizeof(aux));
		int copiones=0,copias=0;
		for(int x=0; x<n;x++){
			scanf("%d",&examenes[x]);
			if(aux[examenes[x]]>=1){
				++copiones;
			}
			++aux[examenes[x]];
			if(copiasm[examenes[x]]){
				++copias;
			}else{
				copiasm[examenes[x]]=true;
			}
			if(x>=k){
				if(aux[examenes[x-k]]==1){
					--aux[examenes[x-k]];
				}else{
					--aux[examenes[x-k]];
				}
			}
		}
		printf("%d %d\n",copias,copiones);
		cin.ignore();
	}
	return 0;
}
