#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int tam;
	int triangular[51][51];
	while(scanf("%d",&tam) && tam){
		int abajo=0,arriba=0,auxDer=0,auxIzq=0;
		for(int x=0; x<tam;x++){
			++auxDer;
			for(int y=0; y<tam; y++){
				scanf("%d",&triangular[x][y]);
				if(y>=auxDer){
					if(triangular[x][y]==0)++arriba;
				}
				if(y<auxIzq){
					if(triangular[x][y]==0)++abajo;
				}
			}
			++auxIzq;
		}
		bool sentencia=((2*abajo+tam)==pow(tam,2)) || (2*arriba+tam==pow(tam,2));
		printf("%s",sentencia?"SI\n":"NO\n" );
	}
	return 0;
}
