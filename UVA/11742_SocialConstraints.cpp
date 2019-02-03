#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int permutacion(int p){
	int res=1;
	for(int x=1; x<=p; x++){
		res*=x;
	}
	return res;
}
int main(){
	int n,m;
	int p[]={0,1,2,3,4,5,6,7};
	int reglas[20][3];
	while(cin>>n>>m && (n ||m)){
		if(m==0){
			cout<<permutacion(n)<<endl;
			continue;
		}
		for(int x=0; x<m; x++){
			cin>>reglas[x][0]>>reglas[x][1]>>reglas[x][2];
		}
		int cont=0;
		do{
			bool cumple=true;
			for(int x=0; x<m; x++){
				int p1=0,p2=0;
				for(int y=0; y<n; y++){
					if(p[y]==reglas[x][0]){
						p1=y;
						break;
					}
				}
				for(int y=0; y<n; y++){
					if(p[y]==reglas[x][1]){
						p2=y;
						break;
					}
				}
				if(reglas[x][2]>0){
					if(abs(p1-p2)>reglas[x][2]){
						cumple=false;
					}
				}
				if(reglas[x][2]<0){
					if(abs(p1-p2)<abs(reglas[x][2])){
						cumple=false;
					}
				}
			}
			if(cumple)++cont;
		}while(next_permutation(p,p+n));
		cout<<cont<<endl;
	}
	return 0;
}
