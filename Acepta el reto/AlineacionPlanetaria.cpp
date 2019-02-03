#include <iostream>
#include <cstring>
using namespace std;

int maximoComunMultiplo(int);
bool operacion(int);
int planetas[5];
int primos[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};
int main(){
	int p=0;
	while(scanf("%d",&p) && p){
		memset(planetas,-1,sizeof(planetas));
		for(int x=0; x<p;x++){
			scanf("%d",&planetas[x]);
		}
		printf("%d\n",maximoComunMultiplo(p));
	}
	return 0;
}

int maximoComunMultiplo(int tam){
	int res=1,pos=0;
	bool op=false;
	while(operacion(tam)){
		for(int x=0; x<tam; x++){
			if(planetas[x]%primos[pos]==0 && planetas[x]!=1){
				planetas[x]/=primos[pos];
				op=true;
			}
		}
		if(op){
			res*=primos[pos];
		}else{
			++pos;
		}
		op=false;
	}
	return res;
}
bool operacion(int tam){
	for(int x=0; x<tam; x++){
		if(planetas[x]!=1) return true;
	}
	return false;
}
